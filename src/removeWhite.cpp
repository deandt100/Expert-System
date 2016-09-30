#include <expert.h>

string	removeWhite(string str)
{
	int		i;
	string	ret;

	i = 0;
	while (i < str.length())
	{
		if (!isspace(str[i]))
		{
			ret.push_back(str[i]);
		}
		i++;
	}
	return (ret);
}