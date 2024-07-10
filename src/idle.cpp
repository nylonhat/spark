#include "idle.h"

State transition(Idle old){
	old.frame++;
	if(old.frame < 5){
		return old;	
	}
	return Sprint{};	
}

void update(Idle old){
	return;
}

char sprite(Idle old){
	return '-';
}
