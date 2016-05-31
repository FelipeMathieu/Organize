#include "mPaths.h"

using namespace std;

void main()
{
	mPaths *mP = new mPaths();
	int n;

	n = mP->countPath(L"BaseDeTxt/*.txt");

	cout << "Numero de arquivos: " << n << endl;

	free(mP);
}