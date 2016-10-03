#include <expert.h>

bool	getVarValue(char name, vector<Var*> vars)
{
	if (name == '1')
		return true;
	if (name == '0')
		return false;
	for (int i = 0 ; i < vars.size(); i++)
	{
		if (vars[i]->getName() == name)
			return vars[i]->getState();
	}
	cerr << "Value for " << name << " not found, returning false" << endl;
	return (false);	
}


/*
** Takes a single expression eg. 'A|!B' and gets the value.
** assumes no whitespaces - use removeWhite().
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
//	cout << "v1 = " << v1 << " v2 = " << v2 << endl;
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

string	doNext(string expr, vector<Var*> vars)
{
	int		start;
	int		count;
	string	sub;
	string	val;

	if (expr.find("+") != -1)
	{
		start = expr.find("+") - 1;
		sub = getSub(expr, &start, &count);
		cout << "found : "<< sub << endl;
	}
	else if (expr.find("|") != -1)
	{
		start = expr.find("|") - 1;
		sub = getSub(expr, &start, &count);
	//	sub = expr.substr(start, 3);
		cout << "found : "<< sub << endl;
	}
	else if (expr.find("^") != -1)
	{
		start = expr.find("^") - 1;
	//	sub = expr.substr(start, 3);
		sub = getSub(expr, &start, &count);
		cout << "found : "<< sub << endl;
	}
	else
		return expr;
	val = (subExpr(sub, vars)) ? "1" : "0";
	expr.replace(start, count, val);
	cout << "new : "<< expr << endl;
}

bool	exprVal(string expr, vector<Var*> vars)
{
	expr = removeWhite(expr);
	//cout << ((subExpr(expr, vars)) ? "true" : "false") << endl;
	
	/*while (countOp(expr) > 1)
	{
		expr = doNext(expr, vars);
	}*/
	doNext("A|!B+C", vars);
	cout << "expr : "<< expr << endl;
	return (true);
}