
#include "listaSasiadow.h"

class macierzSasiedztwa
{
private:

	int wierzcholki;
	int krawedzie;
	int *d;              // Tablica kosztów dojœcia 
	long long *d2;       // Tablica kosztów dojœcia ford
	int *p;              // Tablica poprzedników

	vector< vector<int> > macierz;

public:
	macierzSasiedztwa(int wie, int kra, vector<elListy> &dane);
	void showMatrix();
	void Dijkstra(int startowy);
	void DijkstraShow(int startowy);
	bool BellmanFord(int startowy);
	void ShowF(int startowy, bool check);
	void Kruskal(int startowy);
};

