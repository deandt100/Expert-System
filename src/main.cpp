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
		resolveQueries(query, rules, vars);
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