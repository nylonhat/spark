#include "sprint.h"

State transition(Sprint old){
	old.frame++;
	if(old.frame < 3){
		return old;	
	}
	return Jump{};	
}

void update(Sprint old){
	return;
}

char sprite(Sprint old){
	return '>';
}
