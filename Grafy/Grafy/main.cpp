#include "fileReader.h"

int main()
{
	fileReader reader;
	listaSasiadow sasiedzi(reader.data[0], reader.data[1], reader.tablica);
	sasiedzi.showElements();
	
	cout << endl << endl;
	
	macierzSasiedztwa macierz(reader.data[0], reader.data[1], reader.tablica);
	macierz.showMatrix();

	system("Pause");
	return 0;
}