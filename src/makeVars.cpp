#include <expert.h>

bool		isVar(vector<Var*> vars, char varName)
{
	for (int i = 0; i < vars.size(); i++)
	{
		if (vars.at(i)->getName() == varName)
			return (true);
	}
	return (false);
}

vector<Var>	makeVars(vector<string> data)
{
	char			*line;
	char			varName;
	int				k;
	bool			isTruth;
	vector<Var*>	vars;

	for (int i = 0; i < data.size(); i++)
	{
		k = 0;
		isTruth = false;
		line = (char *)data.at(i).c_str();
		cout << "LINE: " << line << endl;
		while (line[k])
		{
			if (line[k] == '=')
				isTruth = true;
			if (isalpha(line[k]))
				if (isupper(line[k]))
				{
					varName = line[k];
					if (!isVar(vars, varName))
						vars.push_back(new Var(isTruth, varName));
					else if (isTruth)
					{
						
					}
					cout << "VAR: " << varName << endl;
				}
			if (line[k] == '#')
				break;
			k++;
		}
	}
}