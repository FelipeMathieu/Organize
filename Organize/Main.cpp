#include "mPaths.h"

using namespace std;

void main()
{
	mPaths *mP = new mPaths();
	ifstream f2;
	int n, countF2 = 0;
	string w;

	n = mP->countPath(L"BaseDeTxt/*.txt");

	cout << "Numero de arquivos: " << n << endl << endl;

	f2.open("BaseDeTxt/D11.txt");
	if (f2.is_open())
	{
		while (!f2.eof())
		{
			f2 >> w;
			countF2++;
		}
		cout << "Numero de palavras em D11: " << countF2 << endl;
	}
	else
	{
		cout << "Erro ao abrir arquivo." << endl;
	}
	f2.close();
	free(mP);
}