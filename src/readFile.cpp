#include <expert.h>

vector<string>	readFile(string fileName)
{
	ifstream		file;
	string			line;
	vector<string>	fileData;

	file.open(fileName);
	if (!file)
	{
		cout << "Error: File could not be opened" << endl;
		exit (-1);
	}
	while (!file.eof())
	{
		getline(file, line);
		fileData.push_back(line);
	}
	file.close();
	return (fileData);
}