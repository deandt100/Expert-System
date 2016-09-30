#include <expert.h>

int	main(int argc, char **argv)
{
	vector<string>	data;
	vector<Var*>	vars;

	if (argc == 2)
	{
		data = readFile(argv[1]);
		vars = makeVars(data);
		for (int i = 0; i < vars.size(); i++)
		{
			cout << "VAR: " << vars.at(i)->getName() << endl << "STATE: " << vars.at(i)->getState() << endl;
		}
	}
	else
	{
		cout << "Error: Incorrect parameters" << endl;
	}
	return 0;
}