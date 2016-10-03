#include <expert.h>

string	getQuery(vector<string> data)
{
	string	temp;

	for (int i = 0; i < data.size(); i++)
	{
		temp = removeWhite(data.at(i));
		if (temp[0] == '?')
			return (temp.substr(1, temp.length()));
	}
	cout << "ERROR: Query not found" << endl;
	exit(-1);
}