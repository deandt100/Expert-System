#include <expert.h>

int	getType(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (isOp(c))
		return (2);
	if (c == '(')
		return (3);
	if (c == ')')
		return (4);
	if (c == '!')
		return (5);
	else
		return (0);
}

void	ruleErr(int code, int line)
{
	switch (code)
	{
		case 1 :
			cerr << "Line " << line <<" ERROR : invalid character following / preceeding variable." << endl;
			exit(-1);
		case 2 :
			cerr << "Line " << line <<" ERROR : invalid character following / preceeding operator." << endl;	
			exit(-1);
	}
}

bool	opCheck(string str, int line)
{
	for (int i = 0; i < str.length(); i++)
	{
		//cout << "str[i] = " << str[i] << endl;
		switch (getType(str[i]))
		{
			case 1:
			{
				if (i > 0 && getType(str[i - 1]) != 2 && getType(str[i - 1]) != 3 && getType(str[i - 1]) != 5)
					ruleErr(1, line);
				if (i < str.length() - 1 && getType(str[i + 1]) != 2 && getType(str[i + 1]) != 4)
					ruleErr(1, line);
				break;
			}
			case 2:
			{
				if (i >= str.length() - 1 || i == 0)
					ruleErr(2, line);
				if (i > 0 && getType(str[i - 1]) != 1 && getType(str[i - 1]) != 4)
					ruleErr(2, line);
				if (i < str.length() - 1 && getType(str[i + 1]) != 1 && getType(str[i + 1]) != 3 && getType(str[i + 1]) != 5)
					ruleErr(2, line);
					
				break;
		}
		}
	}
	return (true);
}

void	ruleLCheck(string expr, string conc, int line)
{
	bool			op;
	vector<char>	rvars;
	int				i;

	if (hasBrackets(conc))
	{
		cerr << "Line " << line <<" ERROR : Brackets not valid in conclusion." << endl;
		exit(-1);
	}
	opCheck(expr, line + 1);
	opCheck(conc, line + 1);
	//Check variable logic
	i = 0;
	while (i < conc.length())
	{
		if (getType(conc[i]) == 1)
			rvars.push_back(conc[i]);
		i++;
	}
	i = 0;
	while (i < expr.length())
	{
		if (find(rvars.begin(), rvars.end(), expr[i]) != rvars.end())
		{
			cerr << "Line " << line <<" ERROR : Cannot have concusion variable in expression." << endl;
			exit(-1);
		}
		i++;
	}

}