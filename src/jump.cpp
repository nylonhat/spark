#include "jump.h"

State transition(Jump old){
	old.frame++;
	if(old.frame < 7){
		return old;
	}
	return Idle{};	
}

void update(Jump old){
	return;
}

char sprite(Jump old){
	return '^';
}


