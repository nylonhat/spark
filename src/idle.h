#ifndef IDLE_H
#define IDLE_H

#include "state.h"
#include <cstdint>

struct Idle{
	uint8_t frame : 7 = 0;
	uint8_t alive : 1 = 0;
};

State transition(Idle old);
void update(Idle old);
char sprite(Idle old);

#endif
