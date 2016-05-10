
#include "listaSasiadow.h"

class macierzSasiedztwa
{
private:
	int wierzcholki;
	int krawedzie;
	int *d;              // Tablica kosztów dojœcia
	int *p;              // Tablica poprzedników
	vector< vector<int> > macierz;
public:
	macierzSasiedztwa(int wie, int kra, vector<elListy> dane);
	void showMatrix();
	void Dijkstra(int startowy);
	void DijkstraShow(int startowy);
};

