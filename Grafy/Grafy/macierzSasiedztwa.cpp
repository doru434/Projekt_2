#include "macierzSasiedztwa.h"



macierzSasiedztwa::macierzSasiedztwa(int wie, int kra, vector<elListy> dane)
{
	wierzcholki = wie;
	krawedzie = kra;

	for (int i = 0; i < wierzcholki; i++) 
	{
		vector<int> row; 
		for (int j = 0; j < wierzcholki; j++)
		{
			row.push_back(0); 
		}
		macierz.push_back(row); 
	}

	for (int i = 0; i < dane.size(); i++)
	{
		macierz.at(dane.at(i).elPoczatkowy).at(dane.at(i).elDocelowy) = dane.at(i).waga;
	}
}
void macierzSasiedztwa::showMatrix()
{
	for (int i = 0; i < macierz.size(); i++)
	{
		for (int j = 0; j < macierz.at(i).size(); j++)
		{
			cout << macierz.at(i).at(j) << "  ";
		}
		cout << endl;
	}
}
macierzSasiedztwa::~macierzSasiedztwa()
{
}
