#ifndef STATE_H
#define STATE_H

#include <variant>

struct Idle;
struct Jump;
struct Sprint;

using State = std::variant<Idle, Jump, Sprint>;

#include "idle.h"
#include "jump.h"
#include "sprint.h"

#endif
