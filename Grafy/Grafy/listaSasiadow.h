#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <fstream>
using namespace std;

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
	vector< list<elListy> > tabList;

public:
	listaSasiadow(int wie,int kra,vector<elListy> dane);
	void showElements();
	~listaSasiadow();
};

