#ifndef SPRINT_H
#define SPRINT_H

#include "state.h"
#include <cstdint>

struct Sprint{
	uint8_t frame = 0;
};

State transition(Sprint old);
void update(Sprint old);
char sprite(Sprint old);



#endif
