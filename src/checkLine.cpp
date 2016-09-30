#include <expert.h>

bool	checkLine(char *line)
{
	int		i;
	bool	foundAssign;
	bool	foundChar;
	bool	isQuery;
	bool	isFact;

	i = 0;
	foundAssign = false;
	foundChar = false;
	isFact = false;
	isQuery = false;
	while (line[i])
	{
		cout << line[i] << " " << isalpha(line[i]) << endl;
		cout << line[i + 1] << " " << isalpha(line[i + 1]) << endl;
		if (line[i] == '#')
			break;
		if (isalpha(line[i]) && !isalpha(line[i + 1]))
		{
			if (isupper(line[i]))
				foundChar = true;
			else
				return (false);
		}
		else if (isalpha(line[i]) && isalpha(line[i + 1]) && !isFact && !isQuery)
			return (false);
		if (line[i] == '=' && line[i + 1] != '>')
		{
			foundAssign = true;
			isFact = true;
		}
		if (line[i] == '?')
		{
			if (foundChar)
				return (false);
			foundAssign = true;
			isQuery = true;
		}
		if (line[i] == '=' && line[i + 1] == '>')
		{
			if (foundChar == false)
				return (false);
			if (foundAssign == true)
				return (false);
			foundAssign = true;
			foundChar = false;
		}
		i++;
	}
	if (foundAssign && foundChar)
		return (true);
	else
		return (false);
}