#include <expert.h>

bool	isOp(char c)
{
	return (c == '+' || c == '|' || c == '^');
}

int		countOp(string expr)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < expr.length())
	{
		if (isOp(expr.at(i)))
			count++;
		i++;
	}
	return (count);
}

string	getExpr(string expr, string op)
{
	if (expr.find(op) != -1)
		return (expr.substr(expr.find(op) - 1, 3));
	else
		return expr;
}

string	getSub(string expr, int *start, int *count)
{
	*count = 3;
	if (expr[*start + 2] == '!')
			*count = *count + 1;
	if (expr[*start - 1] == '!')
	{
		*start = *start - 1;
		*count = *count + 1;
	}
	return (expr.substr(*start, *count));
}