
#include "listaSasiadow.h"

class macierzSasiedztwa
{
private:
	int wierzcholki;
	int krawedzie;
	vector< vector<int> > macierz;
public:
	macierzSasiedztwa(int wie, int kra, vector<elListy> dane);
	void showMatrix();
	~macierzSasiedztwa();
};

