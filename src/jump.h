#ifndef JUMP_H
#define JUMP_H

#include "state.h"
#include <cstdint>

struct Jump {
	uint8_t frame = 0;
};


State transition(Jump old);
void update(Jump old);
char sprite(Jump old);

#endif
