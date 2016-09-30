#include <expert.h>

Var	*getVar(char varName, vector<Var*> vars)
{
	for (int i = 0; i < vars.size(); i++)
	{
		if (varName == vars.at(i)->getName())
			return (vars.at(i));
	}
	return (NULL);
}