#include <expert.h>

bool	getVarValue(char name, vector<Var*> vars)
{
	for (int i = 0 ; i < vars.size(); i++)
	{
		if (vars[i]->getName() == name)
			return vars[i]->getState();
	}
	cerr << "Value for " << name << " not found, returning false" << endl;
	return (false);	
}

bool	isOp(char c)
{
	return (c == '+' || c == '|' || c == '^');
}

/*
** Takes a single expression eg. 'A|!B' and gets the value.
** assumes no whitespaces.
*/

bool	subExpr(string expr, vector<Var*> vars)
{
	bool	v1;
	bool	n1 = false;
	bool	v2;
	bool	n2 = false;
	char	op;
	int		i = 0;

	if (expr.length() == 1)
		return (getVarValue(expr[0], vars));
	//get value of var 1
	if (expr[i] == '!')
	{
		n1 = true;
		i++;
	}
	v1 = (n1) ? !getVarValue(expr[i++], vars) : getVarValue(expr[i++], vars);
	if (!isOp(expr[i]))
		cerr << "Error with expression " << expr << "\n" << endl;
	op = expr[i++];
	if (expr[i] == '!')
	{
		n2 = true;
		i++;
	}
	v2 = (n2) ? !getVarValue(expr[i++], vars) : getVarValue(expr[i++], vars);
	cout << "v1 = " << v1 << " v2 = " << v2 << endl;
	switch (op)
	{
		case '+' :
			return (v1 & v2);
			break;
		case '|' :
			return (v1 | v2);
			break;
		case '^' :
			return (v1 ^ v2);
			break;
		default :
			cerr << "Operator Error : " << op;
			return (false);
	}
}

bool	exprVal(string expr, vector<Var*> vars)
{
	cout << expr << endl;

	cout << ((subExpr(removeWhite(expr), vars)) ? "true" : "false") << endl;
	return (true);
}