#include <expert.h>

bool	isFinal(string expr, vector<Var*> vars)
{
	int	i;
	Var	*var;

	while (i < expr.length())
	{
		var = getVar(expr[i], vars);
		if (var != NULL)
		{
			if (var->getFinal() == false)
				return (false);
		}
		i++;
	}
	return (true);
}