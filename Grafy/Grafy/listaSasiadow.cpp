#include "listaSasiadow.h"



listaSasiadow::listaSasiadow(int wie, int kra, vector<elListy> &dane)
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

	d = new int[wierzcholki];              // Tablica koszt�w doj�cia
	p = new int[wierzcholki];              // Tablica poprzednik�w
	bool *S = new bool[wierzcholki];           // Zbior S

	// Inicjujemy tablice dynamiczne

	for (int i = 0; i < wierzcholki; i++)
	{
		d[i] = MAXINT;
		p[i] = -1;
		S[i] = false;
	}

	d[startowy] = 0;							// Koszt doj�cia v jest zerowy

	// Wyznaczamy �cie�ki

	for (int i = 0; i < wierzcholki; i++)
	{
		elListy pw;
		int j, u,x=0;
		
		// Szukamy wierzcho�ka w Q o najmniejszym koszcie d

		for (j = 0; S[j]; j++);
		for (u = j++; j < wierzcholki; j++)
			if (!S[j] && (d[j] < d[u])) 
				u = j;

		// Znaleziony wierzcho�ek przenosimy do S

		S[u] = true;

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
					if (!S[pw.elDocelowy] && (d[pw.elDocelowy] > d[u] + pw.waga))
					{
						d[pw.elDocelowy] = d[u] + pw.waga;
						p[pw.elDocelowy] = u;
					}
				}
				else
				{
					elListy& pw = tabList.at(u).back();
					if (!S[pw.elDocelowy] && (d[pw.elDocelowy] > d[u] + pw.waga))
					{
						d[pw.elDocelowy] = d[u] + pw.waga;
						p[pw.elDocelowy] = u;
					}
				}
			}
		}
	}
}
void listaSasiadow::ShowD(int startowy)
{
	int *Stos = new int[wierzcholki];              // Stos
	int sptr = 0;							    // Wska�nik stosu

	cout << endl << "Start = " << startowy << endl;
	cout << "End   " << "Dist  " << "Path  " << endl;
	//wyniki
	for (int i = 0; i < wierzcholki; i++)
	{
		cout << " " << i << "  |   ";

		// �cie�k� przechodzimy od ko�ca ku pocz�tkowi,
		// Zapisuj�c na stosie kolejne wierzcho�ki

		for (int j = i; j > -1; j = p[j])
			Stos[sptr++] = j;

		// Wypisujemy jej koszt

		cout << d[i] << "  | ";
		// Wy�wietlamy �cie�k�, pobieraj�c wierzcho�ki ze stosu

		while (sptr)
			cout << Stos[--sptr] << " ";

		cout << endl;
	}
}
void listaSasiadow::ShowF(int startowy, bool check)
{
	if (check)
	{
		int *Stos = new int[wierzcholki];              // Stos
		int sptr = 0;							    // Wska�nik stosu

		cout << endl << "Start = " << startowy << endl;
		cout << "End   " << "Dist  " << "Path  " << endl;
		//wyniki
		for (int i = 0; i < wierzcholki; i++)
		{
			cout << " " << i << "  |   ";

			// �cie�k� przechodzimy od ko�ca ku pocz�tkowi,
			// Zapisuj�c na stosie kolejne wierzcho�ki

			for (int j = i; j > -1; j = p[j])
				Stos[sptr++] = j;

			// Wypisujemy jej koszt

			cout << d2[i] << "  | ";
			// Wy�wietlamy �cie�k�, pobieraj�c wierzcho�ki ze stosu

			while (sptr)
				cout << Stos[--sptr] << " ";

			cout << endl;
		}
	}
	else
		cout << "Ujemny cykl!" << endl;
}
bool listaSasiadow::BellmanFord(int startowy)
{
	int i, x;
	bool test;
	elListy *pw;

// Tworzymy tablice dynamiczne

	d2 = new long long[wierzcholki];              // Tablica koszt�w doj�cia
	p = new int[wierzcholki];              // Tablica poprzednik�w

 // Inicjujemy tablice dynamiczne

	for (int i = 0; i < wierzcholki; i++)
	{
		d2[i] = MAXINT;
		p[i] = -1;
	}

	d2[startowy] = 0;                       // Zerujemy koszt doj�cia do v

	for (i = 1; i < wierzcholki; i++)          // P�tla relaksacji
	{
		test = true;                  // Oznacza, �e algorytm nie wprowadzi� zmian do d i p
		for (x = 0; x < wierzcholki; x++) // Przechodzimy przez kolejne wierzcho�ki grafu
		{
			list<elListy>::iterator ith_iterator = tabList.at(x).begin();
			int w = tabList.at(x).size();
			for (int index = 0; index < tabList.at(x).size(); index++)	// Przegl�damy list� s�siad�w wierzcho�ka x
			{
				if (index < tabList.at(x).size() - 1)
				{
					advance(ith_iterator, index);
					elListy& pw = *ith_iterator;
					if (d2[pw.elDocelowy] > d2[x] + pw.waga)		// Sprawdzamy warunek relaksacji
					{
						test = false;							// Jest zmiana w d i p
						d2[pw.elDocelowy] = d2[x] + pw.waga;		// Relaksujemy kraw�d� z x do jego s�siada
						p[pw.elDocelowy] = x;					// Poprzednikiem s�siada b�dzie x
					}
				}
				else
				{
					elListy& pw = tabList.at(x).back();
					if (d2[pw.elDocelowy] > d2[x] + pw.waga)		// Sprawdzamy warunek relaksacji
					{
						test = false;							// Jest zmiana w d i p
						d2[pw.elDocelowy] = d2[x] + pw.waga;		// Relaksujemy kraw�d� z x do jego s�siada
						p[pw.elDocelowy] = x;					// Poprzednikiem s�siada b�dzie x
					}
				}
			}
		}
		if (test)
			return true;         // Je�li nie by�o zmian, to ko�czymy
	}

	// Sprawdzamy istnienie ujemnego cyklu

	for (x = 0; x < wierzcholki; x++)
	{
		list<elListy>::iterator ith_iterator = tabList.at(x).begin();
		for (int index = 0; index < tabList.at(x).size(); index++)	// Przegl�damy list� s�siad�w wierzcho�ka x
		{
			if (index < tabList.at(x).size() - 1)
			{
				advance(ith_iterator, index);
				elListy& pw = *ith_iterator;
				if (d2[pw.elDocelowy] > d2[x] + pw.waga)
				{
					return false; // ujemny cykl!!
				}
			}
			else
			{
				elListy& pw = tabList.at(x).back();
				if (d2[pw.elDocelowy] > d2[x] + pw.waga)
				{
					return false; // ujemny cykl!!
				}
			}
		}
	}
	return true;
}
bool compare(elListy i, elListy j)
{
	return (i.waga<j.waga);
}
void listaSasiadow::Kruskal(int startowy)
{				

	int *tab = new int[wierzcholki];
	for (int i = 0; i < wierzcholki; i++)
	{
		tab[i] = i;
	}
	list <elListy> L,T;
	for (int x = 0; x < wierzcholki; x++)
	{
		list<elListy>::iterator ith_iterator = tabList.at(x).begin();
		for (int index = 0; index < tabList.at(x).size(); index++)	// Przegl�damy list� s�siad�w wierzcho�ka x
		{
			if (index < tabList.at(x).size() - 1)
			{
				advance(ith_iterator, index);
				elListy& pw = *ith_iterator;
				L.push_back(pw);
			}
			else
			{
				elListy& pw = tabList.at(x).back();
				L.push_back(pw);
			}
		}
	}
	L.sort(compare);



	int temp1,temp2;

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

	cout << "Dla list:" << endl;
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

struct myclass {
	bool operator() (elListy i, elListy j)
	{ 
		return (i.waga<j.waga); 
	}
} myobject;
void listaSasiadow::Prime(int startowy)
{
	bool *tab = new bool[wierzcholki];
	list <elListy> T;
	//std::priority_queue<elListy, std::vector<elListy>, greaterWeight> Q;
	vector <elListy> v;
	elListy z;

	for (int i = 0; i < wierzcholki; i++)
	{
		tab[i] = false;
	}

	tab[startowy] = true;

	for (int x = 0; x < wierzcholki -1 ; x++)
	{
		list<elListy>::iterator ith_iterator = tabList.at(x).begin();
		for (int index = 0; index < tabList.at(x).size(); index++)	// Przegl�damy list� s�siad�w wierzcho�ka x
		{
			if (index < tabList.at(x).size() - 1)
			{
				advance(ith_iterator, index);
				elListy& pw = *ith_iterator;
				if (!tab[pw.elDocelowy])
				{
					v.push_back(pw);
				}
			}
			else
			{
				elListy& pw = tabList.at(x).back();
				if (!tab[pw.elDocelowy])          // Je�li s�siad jest nieodwiedzony,
				{
					v.push_back(pw);                // Dodajemy j� do kolejki priorytetowej
				}
			}
		}
		cout << "v.size(): " << v.size() << " top: " << Q.top().waga << endl;
		sort(v.begin(), v.end(), myobject);
		do
		{
			z = Q.top();              // Pobieramy kraw�d� z kolejki
			Q.pop();
		} while (tab[z.elDocelowy]);       // Kraw�d� prowadzi poza drzewo?
		T.push_back(z);

		tab[z.elDocelowy] = true;         // Oznaczamy drugi wierzcho�ek jako odwiedzony
	}

	cout << "Dla list(prime):" << endl;
	std::list<elListy>::const_iterator l_front = T.begin();
	std::list<elListy>::const_iterator l_back = T.end();


	cout <<"waga: "<< l_front->waga << " ";
	cout <<"powczatkowy: "<< l_front->elPoczatkowy << " ";
	cout <<"docelowy: "<< l_front->elDocelowy << endl;
	l_front++;
	while (l_front != l_back)
	{

		cout << "waga: " << l_front->waga << " ";
		cout << "powczatkowy: " << l_front->elPoczatkowy << " ";
		cout << "docelowy: " << l_front->elDocelowy << endl;
		l_front++;
	}
	cout << endl;
}