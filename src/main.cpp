#include <expert.h>

int	main(int argc, char **argv)
{
	vector<string>	data;
	vector<Var>		vars;

	if (argc == 2)
	{
		data = readFile(argv[1]);
		vars = makeVars(data);
	}
	else
	{
		cout << "Error: Incorrect parameters" << endl;
	}
	return 0;
}