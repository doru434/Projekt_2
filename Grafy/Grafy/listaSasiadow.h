#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>
#include <iterator>
using namespace std;

const int MAXINT = 2147483647;

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
	int *d;              // Tablica kosztów dojœcia dijkstra
	long long *d2;       // Tablica kosztów dojœcia ford
	int *p;              // Tablica poprzedników

	vector< list<elListy> > tabList;

public:
	listaSasiadow(int wie,int kra,vector<elListy> dane);
	void showElements();
	void Dijkstra(int startowy);
	void ShowD(int startowy);
	void ShowF(int startowy, bool check);
	bool BellmanFord(int startowy);
};

