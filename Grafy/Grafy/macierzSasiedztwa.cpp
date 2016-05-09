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
	// Tworzymy tablice dynamiczne

	int *d = new int[wierzcholki];              // Tablica kosztów dojœcia
	int *p = new int[wierzcholki];              // Tablica poprzedników
	bool *QS = new bool[wierzcholki];           // Zbiory Q i S

	int *S = new int[wierzcholki];              // Stos
	int sptr = 0;							    // WskaŸnik stosu

												// Inicjujemy tablice dynamiczne

	for (int i = 0; i < wierzcholki; i++)
	{
		d[i] = MAXINT;
		p[i] = -1;
		QS[i] = false;
	}

	d[startowy] = 0;							// Koszt dojœcia v jest zerowy

												// Wyznaczamy œcie¿ki

	for (int i = 0; i < wierzcholki; i++)
	{
		elListy pw;
		int j, u, x = 0;

		// Szukamy wierzcho³ka w Q o najmniejszym koszcie d

		for (j = 0; QS[j]; j++);
		for (u = j++; j < wierzcholki; j++)
			if (!QS[j] && (d[j] < d[u]))
				u = j;

		// Znaleziony wierzcho³ek przenosimy do S

		QS[u] = true;

		// Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q

		vector<int> temp = macierz.at(u);

		for (int index = 0; index < macierz.size(); index++)
		{
			if (temp.at(index) != 0)
			{
				if (!QS[index] && (d[index] > d[u] + temp.at(index)))
				{
					d[index] = d[u] + temp.at(index);
					p[index] = u;
				}
			}
		}
		
	}
	cout << endl << "Start = " << startowy << endl;
	cout << "End   " << "Dist  " << "Path  " << endl;
	//wyniki
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << " " << i << "  |   ";

		// Œcie¿kê przechodzimy od koñca ku pocz¹tkowi,
		// Zapisuj¹c na stosie kolejne wierzcho³ki

		for (int j = i; j > -1; j = p[j])
			S[sptr++] = j;

		// Wypisujemy jej koszt

		cout << d[i] << "  | ";
		// Wyœwietlamy œcie¿kê, pobieraj¹c wierzcho³ki ze stosu

		while (sptr)
			cout << S[--sptr] << " ";

		cout << endl;
	}
}

