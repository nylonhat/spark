#include "rate_limiter.h"

RateLimiter::RateLimiter(int tick_rate_hz): 	
	tick_dt((long long)(1e9/tick_rate_hz)), 
	accumulator(0)
{
	this->tick_rate_hz = tick_rate_hz;
	this->previous_time_check = std::chrono::steady_clock::now();

}

bool RateLimiter::shouldTick(){
	auto new_time_check = std::chrono::steady_clock::now();
	auto elapsed_time = new_time_check - previous_time_check;
	previous_time_check = new_time_check;

	accumulator += elapsed_time;

	//if accumulator goes over the allowed time, then allow tick
	if (accumulator >= tick_dt){
		accumulator -= tick_dt;
		return true;
	}else{
		return false;
	}

}

void RateLimiter::setRate(int new_tick_rate_hz){
	this->tick_rate_hz = tick_rate_hz;
	this->tick_dt = std::chrono::nanoseconds((long long)(1e9/new_tick_rate_hz));
}

void RateLimiter::resetAccumulator(){
	while(accumulator >= tick_dt){
		accumulator -= tick_dt;
	}

}

float RateLimiter::getInterpolationRatio(){
	return accumulator.count()/ (float)tick_dt.count();
}


