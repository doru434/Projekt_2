#include "listaSasiadow.h"



listaSasiadow::listaSasiadow(int wie, int kra, vector<elListy> dane)
{
	wierzcholki = wie;
	krawedzie = kra;
	

	for (int i = 0; i < wierzcholki; i++)
	{
		list<elListy> row;
		for (int j = 0; j < krawedzie; j++)
		{
			if (dane.at(j).elPoczatkowy == i)
			{
				row.push_back(dane.at(j));
			}

		}
		if (row.size() != 0)
		{
			tabList.push_back(row);
		}
	}
}
void listaSasiadow::showElements()
{
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << "El[" << i << "] = ";

		if(i<tabList.size())
		{
			list <elListy> a = tabList.at(i);

			std::list<elListy>::const_iterator l_front = a.begin();
			std::list<elListy>::const_iterator l_back = a.end();

			//cout << l_front->elPoczatkowy << '\t';
			cout << l_front->elDocelowy << ' ';
			//cout << l_front->waga << '\n';
			l_front++;

			while (l_front!=l_back)
			{
				//cout << l_front->elPoczatkowy << '\t';
				cout << l_front->elDocelowy << ' ';
				//cout << l_front->waga << '\n';
				l_front++;
			}
			cout << endl;
		}
	}
}
void listaSasiadow::Dijkstra(int startowy)
{
	// Tworzymy tablice dynamiczne

	int *d = new int[wierzcholki];              // Tablica koszt�w doj�cia
	int *p = new int[wierzcholki];              // Tablica poprzednik�w
	bool *QS = new bool[wierzcholki];           // Zbiory Q i S

	int *S = new int[wierzcholki];              // Stos
	int sptr = 0;							    // Wska�nik stosu

	// Inicjujemy tablice dynamiczne

	for (int i = 0; i < wierzcholki; i++)
	{
		d[i] = MAXINT;
		p[i] = -1;
		QS[i] = false;
	}

	d[startowy] = 0;							// Koszt doj�cia v jest zerowy

	// Wyznaczamy �cie�ki

	for (int i = 0; i < wierzcholki; i++)
	{
		elListy pw;
		int j, u,x=0;
		
		// Szukamy wierzcho�ka w Q o najmniejszym koszcie d

		for (j = 0; QS[j]; j++);
		for (u = j++; j < wierzcholki; j++)
			if (!QS[j] && (d[j] < d[u])) 
				u = j;

		// Znaleziony wierzcho�ek przenosimy do S

		QS[u] = true;

		// Modyfikujemy odpowiednio wszystkich s�siad�w u, kt�rzy s� w Q
		bool z = tabList.at(u).empty();
		if (z==false)
		{
			list<elListy>::iterator ith_iterator = tabList.at(u).begin();
			int w = tabList.at(u).size();
			for (int index = 0; index < tabList.at(u).size(); index++)
			{
				if (index < tabList.at(u).size() - 1)
				{
					advance(ith_iterator, index);
					elListy& pw = *ith_iterator;
					if (!QS[pw.elDocelowy] && (d[pw.elDocelowy] > d[u] + pw.waga))
					{
						d[pw.elDocelowy] = d[u] + pw.waga;
						p[pw.elDocelowy] = u;
					}
				}
				else
				{
					elListy& pw = tabList.at(u).back();
					if (!QS[pw.elDocelowy] && (d[pw.elDocelowy] > d[u] + pw.waga))
					{
						d[pw.elDocelowy] = d[u] + pw.waga;
						p[pw.elDocelowy] = u;
					}
				}
			}
		}
	}
	cout << endl << "Start = " << startowy << endl;
	cout << "End   " << "Dist  " << "Path  " << endl;
	//wyniki
	for (int i = 0; i < wierzcholki; i++)
	{
		cout <<" "<< i << "  |   ";

		// �cie�k� przechodzimy od ko�ca ku pocz�tkowi,
		// Zapisuj�c na stosie kolejne wierzcho�ki

		for (int j = i; j > -1; j = p[j]) 
			S[sptr++] = j;
		
		// Wypisujemy jej koszt

		cout << d[i] << "  | ";
		// Wy�wietlamy �cie�k�, pobieraj�c wierzcho�ki ze stosu

		while (sptr) 
			cout << S[--sptr] << " ";

		cout << endl;
	}
}

