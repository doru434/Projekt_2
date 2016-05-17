#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm> 
using namespace std;

const int MAXINT = 99999;

struct elListy {
	int elPoczatkowy;
	int elDocelowy;
	int	waga;
};
class listaSasiadow
{
private:	
	int wierzcholki;
	int krawedzie;
	int *d;              // Tablica koszt�w doj�cia dijkstra
	long long *d2;       // Tablica koszt�w doj�cia ford
	int *p;              // Tablica poprzednik�w

	vector< list<elListy> > tabList;

public:
	listaSasiadow(int wie,int kra,vector<elListy> &dane);
	listaSasiadow(int wie, int kra, vector<elListy> &dane, int x);
	void showElements();
	void Dijkstra(int startowy);
	void ShowD(int startowy);
	void ShowF(int startowy, bool check);
	bool BellmanFord(int startowy);
	void Kruskal(int startowy);
	void Prime(int startowy);
};

