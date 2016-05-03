#include "listaSasiadow.h"

int main()
{
	vector<elListy> tablica;
	elListy a;
	tablica.push_back(a = { 0,1,2 });
	tablica.push_back(a = { 1,2,4 });
	tablica.push_back(a = { 2,0,8 });
	tablica.push_back(a = { 2,3,2 });
	tablica.push_back(a = { 3,0,6 });

	listaSasiadow sasiedzi(4,5,tablica);
	sasiedzi.showElements();
	system("Pause");
	return 0;
}