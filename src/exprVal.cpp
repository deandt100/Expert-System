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
	if (expr.length() == 2 && expr[0] == '!')
		return (!getVarValue(expr[1], vars));
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
	}
	else if (expr.find("|") != -1)
	{
		start = expr.find("|") - 1;
		sub = getSub(expr, &start, &count);
	}
	else if (expr.find("^") != -1)
	{
		start = expr.find("^") - 1;
		sub = getSub(expr, &start, &count);
	}
	else
		return expr;
	//cout << "found : "<< sub << endl;
	val = (subExpr(sub, vars)) ? "1" : "0";
	expr.replace(start, count, val);
	return (expr);
	
}

string	doBracket(string expr, vector<Var*> vars)
{
	int		start;
	int		end;
	int		len;
	string	temp;

	start = expr.rfind("(");
	if (start != -1)
	{
		temp = expr.substr(start);
		end = temp.find(")");
		temp = temp.substr(1, end - 1);
	}
	else
		return expr;
	//cout << "temp : "<< temp << endl;
	while (countOp(temp) > 0)
	{
		temp = doNext(temp, vars);
	}
	expr.replace(start, end + 1, temp);
	return expr;
}

bool	exprVal(string expr, vector<Var*> vars)
{
	expr = removeWhite(expr);
	//cout << ((subExpr(expr, vars)) ? "true" : "false") << endl;
	while (hasBrackets(expr))
	{
		expr = doBracket(expr, vars);
	}
	while (countOp(expr) > 0)
	{
		expr = doNext(expr, vars);
	}
	if (expr[0] != '0' && expr[0] != '1')
		expr = (subExpr(expr, vars)) ? '1' : '0';
	cout << "expr : "<< expr << endl;
	return (expr[0] == '1');
}