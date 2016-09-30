#include <expert.h>

bool	checkLine(char *line)
{
	int		i;
	bool	foundAssign;
	bool	foundChar;

	foundAssign = false;
	foundChar = false;
	while (line[i])
	{
		if (isalpha(line[i] && !isalpha(line[i + 1])))
		{
			if (isupper(line[i]))
			{
				foundChar = true;
			}
			else
				return (false);
		}
		else
			return (false);
		if (line[i] == '=' && line[i + 1] != '>')
			foundAssign = true;
		if (line[i] == '=' && line[i + 1] == '>')
		{
			if (foundChar == false)
				return (false);
			if (foundAssign == true)
				return (false);
			foundAssign = true;
			foundChar = false;
		}
	}
	cout << "HERE" << endl;
	if (foundAssign && foundChar)
		return (true);
	else
		return (false);
}