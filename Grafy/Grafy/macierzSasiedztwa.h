
#include "listaSasiadow.h"

class macierzSasiedztwa
{
private:
	int wierzcholki;
	int krawedzie;
	int *d;              // Tablica koszt�w doj�cia
	int *p;              // Tablica poprzednik�w
	vector< vector<int> > macierz;
public:
	macierzSasiedztwa(int wie, int kra, vector<elListy> dane);
	void showMatrix();
	void Dijkstra(int startowy);
	void DijkstraShow(int startowy);
};

