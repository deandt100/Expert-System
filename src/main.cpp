#include <expert.h>

int	main(int argc, char **argv)
{
	vector<string>	data;

	if (argc == 2)
	{
		data = readFile(argv[1]);
		for (int i = 0; i < data.size(); i++)
		{
			cout << "LINE: " << data.at(i) << endl;
		}
	}
	else
	{
		cout << "Error: Incorrect parameters" << endl;
	}
	return 0;
}