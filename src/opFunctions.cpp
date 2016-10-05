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
		if (isOp(expr[i]))
			count++;
		i++;
	}
	return (count);
}

bool	hasBrackets(string expr)
{
	int	i;

	i = 0;
	while (i < expr.length())
	{
		if (expr[i] == '(' || expr[i] == ')')
			return (true);
		i++;
	}
	return (false);
}

string	ignoreComment(string str)
{
	int	pos;

	pos = str.find("#");
	if (pos != -1)
	{
		str = str.substr(0, pos);
	}
	return (str);
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