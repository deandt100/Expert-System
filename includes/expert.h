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

vector<Rule*>	makeRules(vector<string> data);

Var				*getVar(char varName, vector<Var*> vars);

bool			checkLine(char *line);

bool			exprVal(string expr, vector<Var*> vars);

string			removeWhite(string str);

bool			isOp(char c);

int				countOp(string expr);

 bool			hasBrackets(string expr);

string			getExpr(string expr, string op);

string			getSub(string expr, int *start, int *count);

string			getQuery(vector<string> data);

vector<Rule*>	getRelatedRules(char query, vector<Rule*> rules);

void			resolveQueries(string queries, vector<Rule*> rules, vector<Var*> vars);

#endif
