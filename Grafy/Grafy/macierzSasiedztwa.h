
#include "listaSasiadow.h"

class macierzSasiedztwa
{
private:

	int wierzcholki;
	int krawedzie;
	int *d;              // Tablica koszt�w doj�cia 
	long long *d2;       // Tablica koszt�w doj�cia ford
	int *p;              // Tablica poprzednik�w

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

