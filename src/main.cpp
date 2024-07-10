#include <print>
#include <ranges>
#include <algorithm>

#include "system.h"
#include "range_formatter.h"
#include "rate_limiter.h"
#include "game_state.h"

namespace stdr = std::ranges;
namespace stdv = std::views;

void tick(GameBuffer& game_buffer){
	auto& now = game_buffer.now();

	//simulation
	auto transition_v = stdv::transform(now.states, sys::transition);
	//stdr::for_each(transition_v, sys::update);

	//save new game state
	auto& next = game_buffer.next();
	stdr::copy(transition_v, next.states.begin());
	
	//rotate buffer
	game_buffer.rotate();

}

void render(GameState& game_state){
	auto sprites = stdv::transform(game_state.states, sys::sprite);
	std::println("\33[1F\33[2K{}", sprites);
}

int main(){

	auto game_buffer = RingBuffer<GameState, 16>();

	RateLimiter tick_limiter(8);
	RateLimiter render_limiter(8);
	
	while(true){
		if(tick_limiter.shouldTick()){
			tick(game_buffer);
		}

		if(render_limiter.shouldTick()){
			render(game_buffer.now());
		}
	}
		
}

