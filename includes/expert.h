#ifndef EXPERT_H
# define EXPERT_H

# include <iostream>
# include <string>
# include <fstream>
# include <vector>
# include "Rule.class.h"
# include "Var.class.h"

using namespace std;

vector<string>	readFile(string fileName);

vector<Var>		makeVars(vector<string> data);

#endif
