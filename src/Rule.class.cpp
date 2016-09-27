#include <Rule.class.h>

Rule::Rule(char *expr, char *conc)
{
	this->expr = expr;
	this->conc = conc;
	this->used = false;
}