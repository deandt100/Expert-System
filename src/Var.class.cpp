#include "Var.class.h"

Var::Var(bool state, char name)
{
	this->state = state;
	this->isFinal = state;
	this->name = name;
}