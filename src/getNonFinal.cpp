#include <expert.h>

Var	*getNonFinal(string expr, vector<Var*> vars)
{
	int	i;
	Var	*var;

	i = 0;
	while (i < expr.length())
	{
		var = getVar(expr[i], vars);
		if (var != NULL)
		{
			if (var->getFinal() == false)
				return (var);
		}
		i++;
	}
	return (NULL);
}