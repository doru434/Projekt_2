#include "fileReader.h"

int main()
{
	fileReader reader;
	listaSasiadow sasiedzi(reader.data[0], reader.data[1], reader.tablica);
	sasiedzi.showElements();
	sasiedzi.Dijkstra(reader.data[2]);
	cout << endl << endl;
	
	macierzSasiedztwa macierz(reader.data[0], reader.data[1], reader.tablica);
	macierz.showMatrix();

	system("Pause");
	return 0;
}