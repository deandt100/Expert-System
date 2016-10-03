#include <expert.h>

int	main(int argc, char **argv)
{
	vector<string>	data;
	vector<Var*>	vars;
	vector<Rule*>	rules;
	vector<Rule*>	temp;
	string			query;

	if (argc == 2)
	{
		data = readFile(argv[1]);
		vars = makeVars(data);
		rules = makeRules(data);
		query = getQuery(data);
		
		int	i;
		i = 0;
		while (i < query.length())
		{
			temp = getRelatedRules(query[i], rules);
			if (!temp.empty())
			{
				for (int k = 0; k < temp.size(); k++)
				{
					cout << "QUERY: " << query[i] << " RULE: " << temp.at(k)->getExpr() << endl;
				}
			}
			i++;
		}
	}
	else
	{
		cout << "Error: Incorrect parameters" << endl;
	}
	exprVal(removeWhite("A	+B"), vars);
	exprVal(removeWhite("A^! 	B"), vars);
	exprVal(removeWhite("!	A |! 	B"), vars);
	return 0;
}