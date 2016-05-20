#include "fileReader.h"

int main()
{
	bool check;
	fileReader reader;
	//listaSasiadow sasiedzi(reader.data[0], reader.data[1], reader.tablica);
	listaSasiadow sasiedzi2(reader.data[0], reader.data[1], reader.tablica, reader.data[2]);
	//sasiedzi.showElements();
	//sasiedzi.Dijkstra(reader.data[2]);
	//sasiedzi.ShowD(reader.data[2]);

	sasiedzi2.Prime(reader.data[2]);
	sasiedzi2.showElements();
	
	//check=sasiedzi.BellmanFord(reader.data[2]);
	//sasiedzi.ShowF(reader.data[2],check);

	//sasiedzi.Kruskal(reader.data[2]);

	//macierzSasiedztwa macierz(reader.data[0], reader.data[1], reader.tablica);
	macierzSasiedztwa macierz2(reader.data[0], reader.data[1], reader.tablica,reader.data[2]);
	//macierz.showMatrix();
	macierz2.showMatrix();
	macierz2.Prime(reader.data[2]);
	//macierz.Dijkstra(reader.data[2]);
	//macierz.DijkstraShow(reader.data[2]);
	//check = macierz.BellmanFord(reader.data[2]);
	//macierz.ShowF(reader.data[2], check);
	/*
	macierz.Kruskal(reader.data[2]);
	*/
	system("Pause");
	return 0;
}