#ifndef SYSTEM_H
#define SYSTEM_H

#include "state.h"

//defaults
State transition(auto s){
	return {s};
}

void update(auto s){
	return;
}

char sprite(auto s){
	return ' ';
}


namespace sys{

State transition(const State& old_state){
	auto visitor = [](const auto& v){
		return transition(v);
	};
	return std::visit(visitor, old_state);
}

auto update(const State& old_state){
	auto visitor = [](auto& v){
		return update(v);
	};
	return std::visit(visitor, old_state);
}

auto sprite(const State& old_state){
	auto visitor = [](auto& v){
		return sprite(v);
	};
	return std::visit(visitor, old_state);
}

}

#endif
