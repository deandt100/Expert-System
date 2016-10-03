#include <expert.h>

bool	resolveQuery(char query, vector<Rule*> rules, vector<Var*> vars, vector<Rule*> allRules)
{
	return (false);
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