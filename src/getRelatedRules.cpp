#include <expert.h>

vector<Rule*>	getRelatedRules(char query, vector<Rule*> rules)
{
	vector<Rule*>	ret;
	string			conc;

	for (int i = 0; i < rules.size(); i++)
	{
		conc = rules.at(i)->getConc();
		if (conc.find(query) != string::npos)
			ret.push_back(rules.at(i));
	}
	return (ret);
}