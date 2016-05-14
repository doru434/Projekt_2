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

	for (int i = 0; i < krawedzie; i++)
	{
		macierz.at(dane.at(i).elPoczatkowy).at(dane.at(i).elDocelowy) = dane.at(i).waga;
	}
}
void macierzSasiedztwa::showMatrix()
{
	for (int i = 0; i < macierz.size(); i++)
	{
		cout << "El[" << i << "] = ";
		for (int j = 0; j < macierz.at(i).size(); j++)
		{
			cout << macierz.at(i).at(j) << "  ";
		}
		cout << endl;
	}
}
void macierzSasiedztwa::Dijkstra(int startowy)
{
	d = new int[wierzcholki];
	p = new int[wierzcholki];

	// Tworzymy tablice dynamiczne

	bool *S = new bool[wierzcholki];           // Zbior S

	// Inicjujemy tablice dynamiczne

	for (int i = 0; i < wierzcholki; i++)
	{
		d[i] = MAXINT;
		p[i] = -1;
		S[i] = false;
	}

	d[startowy] = 0;							// Koszt dojúcia v jest zerowy

	// Wyznaczamy úcieøki

	for (int i = 0; i < wierzcholki; i++)
	{
		elListy pw;
		int j, u, x = 0;

		// Szukamy wierzcho≥ka w Q o najmniejszym koszcie d

		for (j = 0; S[j]; j++);
		for (u = j++; j < wierzcholki; j++)
			if (!S[j] && (d[j] < d[u]))
				u = j;

		// Znaleziony wierzcho≥ek przenosimy do S

		S[u] = true;

		// Modyfikujemy odpowiednio wszystkich sπsiadÛw u, ktÛrzy sπ w Q

		vector<int> temp = macierz.at(u);

		for (int index = 0; index < macierz.size(); index++)
		{
			if (temp.at(index) != 0)
			{
				if (!S[index] && (d[index] > d[u] + temp.at(index)))
				{
					d[index] = d[u] + temp.at(index);
					p[index] = u;
				}
			}
		}
		
	}
}
void macierzSasiedztwa::DijkstraShow(int startowy)
{
	int *Stos = new int[wierzcholki];              // Stos
	int sptr = 0;							    // Wskaünik stosu

	cout << endl << "Start = " << startowy << endl;
	cout << "End   " << "Dist  " << "Path  " << endl;
	//wyniki
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << " " << i << "  |   ";

		// åcieøkÍ przechodzimy od koÒca ku poczπtkowi,
		// Zapisujπc na stosie kolejne wierzcho≥ki

		for (int j = i; j > -1; j = p[j])
			Stos[sptr++] = j;

		// Wypisujemy jej koszt

		cout << d[i] << "  | ";
		// Wyúwietlamy úcieøkÍ, pobierajπc wierzcho≥ki ze stosu

		while (sptr)
			cout << Stos[--sptr] << " ";

		cout << endl;
	}
}

