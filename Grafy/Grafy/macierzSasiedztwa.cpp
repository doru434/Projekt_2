#include "macierzSasiedztwa.h"



macierzSasiedztwa::macierzSasiedztwa()
{
	wierzcholki = 4;
	krawedzie = 4;
	for (int i = 0; i < wierzcholki; i++) 
	{
		vector<int> row; 
		for (int j = 0; j < krawedzie; j++) 
		{
			row.push_back(i * j); 
		}
		macierz.push_back(row); 
	}
}


macierzSasiedztwa::~macierzSasiedztwa()
{
}
