#include <expert.h>

vector<Rule*>	makeRules(vector<string> data)
{
	string			expr;
	string			conc;
	string			temp;
	vector<Rule*>	rules;

	for (int i = 0; i < data.size(); i++)
	{
		temp = removeWhite(data.at(i));
		if (temp[0] == '=' || temp[0] == '?')
			break;
		expr = temp.substr(0, temp.find("=>"));
		if (temp.find("#"))
			conc = temp.substr(temp.find("=>") + 2, temp.find("#") - (temp.find("=>") + 2));
		else
			conc = temp.substr(temp.find("=>") + 2, temp.length() - (temp.find("=>") + 2));
		cout << "EXPR: " << expr << endl;
		cout << "CONC: " << conc << endl;
		rules.push_back(new Rule(expr, conc));
	}
	if (rules.empty())
	{
		cout << "ERROR: No rules supplied" << endl;
		exit(-1);
	}
	return (rules);
}