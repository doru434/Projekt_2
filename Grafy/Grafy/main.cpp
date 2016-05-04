#include "fileReader.h"

int main()
{
	fileReader reader;
	listaSasiadow sasiedzi(reader.data[0], reader.data[1], reader.tablica);

	sasiedzi.showElements();
	system("Pause");
	return 0;
}