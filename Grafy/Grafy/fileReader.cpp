#include "fileReader.h"



fileReader::fileReader()
{
	start_read();
}
bool fileReader::file_read_line(ifstream &file, int tab[], int size)
{
	string s;
	getline(file, s);

	if (file.fail() || s.empty())
		return(false);

	istringstream in_ss(s);

	for (int i = 0; i < size; i++)
	{
		in_ss >> tab[i];
		if (in_ss.fail())
			return(false);
	}
	return(true);
}

void fileReader::file_read_graph(string file_name)
{
	elListy a;
	ifstream file;
	int tab[4];
	file.open(file_name.c_str());

	if (file.is_open())
	{
		if (file_read_line(file, tab, 4))
		{
			data[0] = tab[0];				//krawedzie
			data[1] = tab[1];				//wierzcholki
			data[2] = tab[2];				//wierzcholek poczatkowy
			data[3] = tab[3];				//wierzcholek koncowy
			for (int i = 0; i <data[1]; i++)
				if (file_read_line(file, tab, 3))
				{
					tablica.push_back(a = { tab[0],tab[1],tab[2]});
				}
				else
				{
					cout << "File error - READ EDGE" << endl;
					break;
				}
		}
		else
			cout << "File error - READ INFO" << endl;
		file.close();
	}
	else
		cout << "File error - OPEN" << endl;
}void fileReader::start_read(){	cout << "Podaj nazwe pliku" << endl;	cin >> fileName;	file_read_graph(fileName);}