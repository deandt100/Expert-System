#include <expert.h>

bool	resolveQuery(char query, vector<Rule*> rules, vector<Var*> vars, vector<Rule*> allRules)
{
	bool	result;
	bool	oldResult;
	Var		*var;
	int		negatePos;

	var = getVar(query, vars);
	result = var->getState();
	for (int i = 0; i < rules.size(); i++)
	{
		oldResult = result;
		if (!isFinal(rules.at(i)->getExpr(), vars))
		{
			while (!isFinal(rules.at(i)->getExpr(), vars))
			{
				var = getNonFinal(rules.at(i)->getExpr(), vars);
				var->setState(resolveQuery(var->getName(), getRelatedRules(var->getName(), allRules), vars, allRules));
				var->setFinal(true);
			}
		}
		if (isFinal(rules.at(i)->getExpr(), vars))
		{
			result = exprVal(rules.at(i)->getExpr(), vars);
			negatePos = -1;
			while ((negatePos = rules.at(i)->getConc().find('!', negatePos + 1)) != string::npos)
			{
				if (rules.at(i)->getConc()[negatePos + 1] == query)
				{
					if (result == true)
						result = false;
					else
						result = true;
					oldResult = result;
				}
			}
		}
		if (i > 0 && oldResult != result)
		{
			cout << "ERROR: Bad rule" << endl;
			exit (0);
		}
	}
	return (result);
}

void	resolveQueries(string queries, vector<Rule*> rules, vector<Var*> vars)
{
	int		i;
	bool	result;
	Var		*var;

	i = 0;
	result = false;
	while (i < queries.length())
	{
		result = resolveQuery(queries[i], getRelatedRules(queries[i], rules), vars, rules);
		var = getVar(queries[i], vars);
		var->setState(result);
		var->setFinal(true);
		if (result == true)
			cout << queries[i] << " is true" << endl;
		else
			cout << queries[i] << " is false" << endl;
		i++;
	}
}