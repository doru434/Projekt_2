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
listaSasiadow::listaSasiadow(int wie, int kra, vector<elListy> &dane,int x)
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
			else if (dane.at(j).elDocelowy == i)
			{
				row.push_back(dane.at(j));
			}

		}
		if (row.size() != 0)
		{
			cout << "row.size(): " << row.size();
			tabList.push_back(row);
		}
	}
}
void listaSasiadow::showElements()
{
	cout << endl << "Lista Sasiadow" << endl;
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

	d = new int[wierzcholki];              // Tablica kosztów dojœcia
	p = new int[wierzcholki];              // Tablica poprzedników
	bool *S = new bool[wierzcholki];       // Zbior S


	for (int i = 0; i < wierzcholki; i++)
	{
		d[i] = MAXINT;
		p[i] = -1;
		S[i] = false;
	}

	d[startowy] = 0;							

	// Wyznaczamy œcie¿ki

	for (int i = 0; i < wierzcholki; i++)
	{
		elListy pw;
		int j, u,x=0;
		
		//zzukamy wierzcholka w Q o najmniejszym koszcie d

		for (j = 0; S[j]; j++);
		for (u = j++; j < wierzcholki; j++)
			if (!S[j] && (d[j] < d[u])) 
				u = j;

		//znaleziony wierzcho³ek przenosimy do S

		S[u] = true;
		list<elListy>::iterator ith_iterator;
		// modyfikujemy odpowiednio wszystkich sasiadow u, ktorzy s¹ w Q
		if (u==tabList.size())
		{
			ith_iterator = tabList.back().begin();
		
			for (int index = 0; index < tabList.back().size(); index++)
			{
				if (index < tabList.back().size() - 1)
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
					elListy& pw = tabList.back().back();
					if (!S[pw.elDocelowy] && (d[pw.elDocelowy] > d[u] + pw.waga))
					{
						d[pw.elDocelowy] = d[u] + pw.waga;
						p[pw.elDocelowy] = u;
					}
				}
			}
		}
		else
		{
			ith_iterator = tabList.at(u).begin();

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
	cout <<endl<< "Dijkstra dla listy Sasiadow";
	int *Stos = new int[wierzcholki];           // Stos
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
void listaSasiadow::ShowF(int startowy, bool check)
{
	cout << endl<<"Bellman-Ford dla listy Sasiadow";
	if (check)
	{
		int *Stos = new int[wierzcholki];           // Stos
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
bool listaSasiadow::BellmanFord(int startowy)
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
			list<elListy>::iterator ith_iterator;
			// Modyfikujemy odpowiednio wszystkich s¹siadów u, którzy s¹ w Q
			//bool z = tabList.at(u).empty();
			if (x == tabList.size())
			{
				ith_iterator = tabList.back().begin();

				for (int index = 0; index < tabList.back().size(); index++)	// Przegl¹damy listê s¹siadów wierzcho³ka x
				{
					if (index < tabList.back().size() - 1)
					{
						advance(ith_iterator, index);
						elListy& pw = *ith_iterator;
						if (d2[pw.elDocelowy] > d2[x] + pw.waga)	// Sprawdzamy warunek relaksacji
						{
							test = false;							
							d2[pw.elDocelowy] = d2[x] + pw.waga;	// Relaksujemy krawêdŸ z x do jego s¹siada
							p[pw.elDocelowy] = x;					// Poprzednikiem s¹siada bêdzie x
						}
					}
					else
					{
						elListy& pw = tabList.back().back();
						if (d2[pw.elDocelowy] > d2[x] + pw.waga)	// Sprawdzamy warunek relaksacji
						{
							test = false;							
							d2[pw.elDocelowy] = d2[x] + pw.waga;	// Relaksujemy krawêdŸ z x do jego s¹siada
							p[pw.elDocelowy] = x;					// Poprzednikiem s¹siada bêdzie x
						}
					}
				}
			}
			else
			{
				ith_iterator = tabList.at(x).begin();

				for (int index = 0; index < tabList.at(x).size(); index++)	// Przegl¹damy listê s¹siadów wierzcho³ka x
				{
					if (index < tabList.at(x).size() - 1)
					{
						advance(ith_iterator, index);
						elListy& pw = *ith_iterator;
						if (d2[pw.elDocelowy] > d2[x] + pw.waga)	// Sprawdzamy warunek relaksacji
						{
							test = false;							
							d2[pw.elDocelowy] = d2[x] + pw.waga;	// Relaksujemy krawêdŸ z x do jego s¹siada
							p[pw.elDocelowy] = x;					// Poprzednikiem s¹siada bêdzie x
						}
					}
					else
					{
						elListy& pw = tabList.at(x).back();
						if (d2[pw.elDocelowy] > d2[x] + pw.waga)	// Sprawdzamy warunek relaksacji
						{
							test = false;							
							d2[pw.elDocelowy] = d2[x] + pw.waga;	// Relaksujemy krawêdŸ z x do jego s¹siada
							p[pw.elDocelowy] = x;					// Poprzednikiem s¹siada bêdzie x
						}
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
		list<elListy>::iterator ith_iterator = tabList.at(x).begin();
		for (int index = 0; index < tabList.at(x).size(); index++)	// Przegl¹damy listê s¹siadów wierzcho³ka x
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
	list<elListy>::iterator ith_iterator;
	for (int x = 0; x < wierzcholki; x++)
	{
		if (x == tabList.size())
		{
			ith_iterator = tabList.back().begin();
			for (int index = 0; index < tabList.back().size(); index++)	// Przegl¹damy listê s¹siadów wierzcho³ka x
			{
				if (index < tabList.back().size() - 1)
				{
					advance(ith_iterator, index);
					elListy& pw = *ith_iterator;
					L.push_back(pw);
				}
				else
				{
					elListy& pw = tabList.back().back();
					L.push_back(pw);
				}
			}
		}
		else
		{
			ith_iterator = tabList.at(x).begin();
			for (int index = 0; index < tabList.at(x).size(); index++)	// Przegl¹damy listê s¹siadów wierzcho³ka x
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
	int mst=0;
	l_front = T.begin();
	l_back = T.end();

	cout << endl<<"Kruskal dla list:" << endl;
	cout << "Edge     Weight" << endl << endl;

	cout << "(" << l_front->elPoczatkowy << "," << l_front->elDocelowy << ")" << "   " << l_front->waga << endl;
	mst = mst + l_front->waga;
	l_front++;
	while (l_front != l_back)
	{

		cout << "(" << l_front->elPoczatkowy << "," << l_front->elDocelowy << ")" << "   " << l_front->waga << endl;
		mst = mst + l_front->waga;
		l_front++;
	}
	cout << endl << "MST = " << mst << endl << endl;
	
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

	vector <elListy> v;
	elListy z,temp;

	for (int i = 0; i < wierzcholki; i++)
	{
		tab[i] = false;
	}

	tab[startowy] = true;
	list<elListy>::iterator ith_iterator;
	for (int x = 0; x < wierzcholki -1 ; x++)
	{
		if (startowy == tabList.size())
		{
			ith_iterator = tabList.back().begin();
			for (int index = 0; index < tabList.back().size(); index++)	// Przegl¹damy listê s¹siadów wierzcho³ka x
			{
				//cout << endl << "tabList.at(startowy).size(): " << tabList.back().size() << endl;
				if (index < tabList.back().size() - 1)
				{
					advance(ith_iterator, index);
					elListy& pw = *ith_iterator;
					if (!tab[pw.elDocelowy])
					{
						z.elPoczatkowy = startowy;                 // to tworzymy krawêdŸ
						z.elDocelowy = pw.elDocelowy;
						z.waga = pw.waga;
						v.push_back(z);
					}
				}
				else
				{
					elListy& pw = tabList.back().back();
					if (!tab[pw.elDocelowy])
					{
						z.elPoczatkowy = startowy;
						z.elDocelowy = pw.elDocelowy;
						z.waga = pw.waga;
						v.push_back(z);
					}
				}
			}
			sort(v.begin(), v.end(), myobject);
			for (int i = 0; i < v.size(); i++)
			{
				cout << ":" << v.at(i).waga;
			}
			cout << endl;
			for (int i = 0; i < v.size(); i++)
			{
				z = v.at(i);
				if (!tab[z.elDocelowy])
				{
					temp = v.at(v.size() - 1);
					v.at(v.size() - 1) = v.at(i);
					v.at(i) = temp;
					v.pop_back();
					break;
				}
			}
			T.push_back(z);
			startowy = z.elDocelowy;
			tab[z.elDocelowy] = true;
		}
		else
		{
			ith_iterator = tabList.at(startowy).begin();
			for (int index = 0; index < tabList.at(startowy).size(); index++)	// Przegl¹damy listê s¹siadów wierzcho³ka x
			{
				//cout << endl << "tabList.at(startowy).size(): " << tabList.at(startowy).size() << endl;
				if (index < tabList.at(startowy).size() - 1)
				{
					advance(ith_iterator, index);
					elListy& pw = *ith_iterator;
					if (!tab[pw.elDocelowy])
					{
						z.elPoczatkowy = startowy;                 // to tworzymy krawêdŸ
						z.elDocelowy = pw.elDocelowy;
						z.waga = pw.waga;
						v.push_back(z);
					}
				}
				else
				{
					elListy& pw = tabList.at(startowy).back();
					if (!tab[pw.elDocelowy])
					{
						z.elPoczatkowy = startowy;
						z.elDocelowy = pw.elDocelowy;
						z.waga = pw.waga;
						v.push_back(z);
					}
				}
			}
			sort(v.begin(), v.end(), myobject);
			for (int i = 0; i < v.size(); i++)
			{
				cout << ":" << v.at(i).waga;
			}
			cout << endl;
			for (int i = 0; i < v.size(); i++)
			{
				z = v.at(i);
				if (!tab[z.elDocelowy])
				{
					temp = v.at(v.size() - 1);
					v.at(v.size() - 1) = v.at(i);
					v.at(i) = temp;
					v.pop_back();
					break;
				}
			}
			T.push_back(z);
			startowy = z.elDocelowy;
			tab[z.elDocelowy] = true;
		}
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