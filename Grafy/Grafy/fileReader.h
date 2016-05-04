#include "listaSasiadow.h"

class fileReader
{
public:
	string fileName;
	vector<elListy> tablica;
	int data[4]; //ilosc wierzcholow, ilosc krawedzi, wierzcholek poczatkowy, wierzcholek koncowy
public:
	fileReader();

	void start_read();
	bool file_read_line(ifstream &file, int tab[], int size);
	void file_read_graph(string file_name);
};
