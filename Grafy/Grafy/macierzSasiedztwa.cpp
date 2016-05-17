#include "macierzSasiedztwa.h"



macierzSasiedztwa::macierzSasiedztwa(int wie, int kra, vector<elListy> &dane)
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

	d[startowy] = 0;							// Koszt dojœcia v jest zerowy

	// Wyznaczamy œcie¿ki

	for (int i = 0; i < wierzcholki; i++)
	{
		elListy pw;
		int j, u, x = 0;

		// Szukamy wierzcho³ka w Q o najmniejszym koszcie d

		for (j = 0; S[j]; j++);
		for (u = j++; j < wierzcholki; j++)
			if (!S[j] && (d[j] < d[u]))
				u = j;

		// Znaleziony wierzcho³ek przenosimy do S

		S[u] = true;

		// Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q

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
	int sptr = 0;							    // WskaŸnik stosu

	cout << endl << "Start = " << startowy << endl;
	cout << "End   " << "Dist  " << "Path  " << endl;
	//wyniki
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << " " << i << "  |   ";

		// Œcie¿kê przechodzimy od koñca ku pocz¹tkowi,
		// Zapisuj¹c na stosie kolejne wierzcho³ki

		for (int j = i; j > -1; j = p[j])
			Stos[sptr++] = j;

		// Wypisujemy jej koszt

		cout << d[i] << "  | ";
		// Wyœwietlamy œcie¿kê, pobieraj¹c wierzcho³ki ze stosu

		while (sptr)
			cout << Stos[--sptr] << " ";

		cout << endl;
	}
}
void macierzSasiedztwa::ShowF(int startowy, bool check)
{
	if (check)
	{
		int *Stos = new int[wierzcholki];              // Stos
		int sptr = 0;							    // WskaŸnik stosu

		cout << endl << "Start = " << startowy << endl;
		cout << "End   " << "Dist  " << "Path  " << endl;
		//wyniki
		for (int i = 0; i < wierzcholki; i++)
		{
			cout << " " << i << "  |   ";

			// Œcie¿kê przechodzimy od koñca ku pocz¹tkowi,
			// Zapisuj¹c na stosie kolejne wierzcho³ki

			for (int j = i; j > -1; j = p[j])
				Stos[sptr++] = j;

			// Wypisujemy jej koszt

			cout << d2[i] << "  | ";
			// Wyœwietlamy œcie¿kê, pobieraj¹c wierzcho³ki ze stosu

			while (sptr)
				cout << Stos[--sptr] << " ";

			cout << endl;
		}
	}
	else
		cout << "Ujemny cykl!" << endl;
}
bool macierzSasiedztwa::BellmanFord(int startowy)
{
	int i, x;
	bool test;
	elListy *pw;

	// Tworzymy tablice dynamiczne

	d2 = new long long[wierzcholki];              // Tablica kosztów dojœcia
	p = new int[wierzcholki];              // Tablica poprzedników

										   // Inicjujemy tablice dynamiczne

	for (int i = 0; i < wierzcholki; i++)
	{
		d2[i] = MAXINT;
		p[i] = -1;
	}

	d2[startowy] = 0;                       // Zerujemy koszt dojœcia do v

	for (i = 1; i < wierzcholki; i++)          // Pêtla relaksacji
	{
		test = true;                  // Oznacza, ¿e algorytm nie wprowadzi³ zmian do d i p
		for (x = 0; x < wierzcholki; x++) // Przechodzimy przez kolejne wierzcho³ki grafu
		{
			vector<int> temp = macierz.at(x);

			for (int index = 0; index < macierz.size(); index++)
			{
				if (temp.at(index) != 0)
				{
					if (d2[index] > d2[x] + temp.at(index))
					{
						test = false;
						d2[index] = d2[x] + temp.at(index);
						p[index] = x;
					}
				}
			}
		}
		if (test)
			return true;         // Jeœli nie by³o zmian, to koñczymy
	}

	// Sprawdzamy istnienie ujemnego cyklu

	for (x = 0; x < wierzcholki; x++)
	{
		vector<int> temp = macierz.at(x);

		for (int index = 0; index < macierz.size(); index++)
		{
			if (temp.at(index) != 0)
			{
				if (d2[index] > d2[x] + temp.at(index))
				{
					return false; // ujemny cykl!!
				}
			}
		}
	}
	return true;
}
bool compare2(elListy i, elListy j)
{
	return (i.waga<j.waga);
}
void macierzSasiedztwa::Kruskal(int startowy)
{

	int *tab = new int[wierzcholki];
	for (int i = 0; i < wierzcholki; i++)
	{
		tab[i] = i;
	}
	list <elListy> L, T;
	elListy p;
	for (int i = 0; i < macierz.size(); i++)
	{
		for (int j = 0; j < macierz.at(i).size(); j++)
		{
			if (macierz.at(i).at(j) != 0)
			{
				p.elDocelowy = j;
				p.elPoczatkowy = i;
				p.waga = macierz.at(i).at(j);
				L.push_back(p);
			}
		}
	}
	L.sort(compare2);

	
	int temp1, temp2;

	std::list<elListy>::const_iterator l_front = L.begin();
	std::list<elListy>::const_iterator l_back = L.end();

	if (tab[l_front->elPoczatkowy] != tab[l_front->elDocelowy])
	{
		tab[l_front->elDocelowy] = tab[l_front->elPoczatkowy];
		T.push_back(*l_front);
	}
	l_front++;
	while (l_front != l_back)
	{
		if (tab[l_front->elPoczatkowy] != tab[l_front->elDocelowy])
		{
			temp1 = tab[l_front->elPoczatkowy];
			temp2 = tab[l_front->elDocelowy];

			for (int i = 0; i < wierzcholki; i++)
			{
				if (tab[i] == temp2)
				{
					tab[i] = temp1;
				}
			}
			T.push_back(*l_front);

		}
		l_front++;
	}

	cout << "Dla macierzy:" << endl;
	l_front = T.begin();
	l_back = T.end();


	cout << l_front->waga << " ";
	l_front++;
	while (l_front != l_back)
	{

		cout << l_front->waga << " ";
		l_front++;
	}
	cout << endl;
	
}