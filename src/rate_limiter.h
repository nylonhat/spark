#ifndef LUSUS_RATE_LIMITER_H
#define LUSUS_RATE_LIMITER_H

#include <chrono>

class RateLimiter {
private:
	
	int tick_rate_hz; // Tick rate limit in ticks per second
	std::chrono::nanoseconds tick_dt; // Nanoseconds between ticks according to tick rate
	std::chrono::time_point<std::chrono::steady_clock> previous_time_check;
	std::chrono::nanoseconds accumulator;


public:
	RateLimiter(int tick_rate_hz);
	bool shouldTick();
	void setRate(int tick_rate_hz);
	void resetAccumulator();
	float getInterpolationRatio();


};


#endif
