#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <array>
#include "ring_buffer.h"

struct GameState{
	std::array<State, 16> states = {Idle{}, Jump{}, Sprint{}, Idle{}, Jump{}, Sprint{}, Idle{}, Jump{}, Sprint{}, Idle{}, Jump{}, Sprint{}};
};

using GameBuffer = RingBuffer<GameState, 16>;



#endif
