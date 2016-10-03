#ifndef EXPERT_H
# define EXPERT_H

# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include <ctype.h>
# include "Rule.class.h"
# include "Var.class.h"

using namespace std;

vector<string>	readFile(string fileName);

vector<Var*>	makeVars(vector<string> data);

Var				*getVar(char varName, vector<Var*> vars);

bool			checkLine(char *line);

bool			exprVal(string expr, vector<Var*> vars);

string			removeWhite(string str);

bool			isOp(char c);

int				countOp(string expr);

string			getExpr(string expr, string op);

string			getSub(string expr, int *start, int *count);

#endif
