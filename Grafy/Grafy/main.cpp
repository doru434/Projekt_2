#include "fileReader.h"

int main()
{
	bool check;
	fileReader reader;
	listaSasiadow sasiedzi(reader.data[0], reader.data[1], reader.tablica);
	//sasiedzi.showElements();
	//sasiedzi.Dijkstra(reader.data[2]);
	//sasiedzi.DijkstraShow(reader.data[2]);
	cout << endl << endl;

	cout << "FORD FORD FORD" << endl;

	check=sasiedzi.BellmanFord(reader.data[2]);
	sasiedzi.ShowF(reader.data[2],check);
	
	macierzSasiedztwa macierz(reader.data[0], reader.data[1], reader.tablica);
	//macierz.showMatrix();
	//macierz.Dijkstra(reader.data[2]);
	//macierz.DijkstraShow(reader.data[2]);
	system("Pause");
	return 0;
}