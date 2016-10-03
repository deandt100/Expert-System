#include "Rule.class.h"

Rule::Rule(string expr, string conc)
{
	this->expr = expr;
	this->conc = conc;
	this->used = false;
}