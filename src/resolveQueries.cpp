#include <expert.h>

bool	resolveQuery(char query, vector<Rule*> rules, vector<Var*> vars, vector<Rule*> allRules)
{
	bool	result;
	bool	oldResult;

	result = false;
	for (int i = 0; i < rules.size(); i++)
	{
		oldResult = result;
		if (isFinal(rules.at(i)->getExpr(), vars))
			result = exprVal(rules.at(i)->getExpr(), vars);
		else
		{
			while (!isFinal(rules.at(i)->getExpr(), vars))
			{
				
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

	i = 0;
	result = false;
	while (i < queries.length())
	{
		result = resolveQuery(queries[i], getRelatedRules(queries[i], rules), vars, rules);
		cout << queries[i] << ": " << result << endl;
		i++;
	}
}