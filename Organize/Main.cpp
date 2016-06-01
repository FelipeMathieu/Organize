#include "mPaths.h"
#include <locale>

using namespace std;

void main()
{
	mPaths *mP = new mPaths();
	int n, countF2 = 0;
	string w, typeF, local_Type;
	wchar_t *d;
	wstring_convert<codecvt<wchar_t, char, mbstate_t>> conv;
	wstring wstr;

	cout << "Insira o nome do diretorio: ";
	cin >> w;
	cout << "Insira o tipo do arquivo: ";
	cin >> typeF;

	local_Type = w + "/*." + typeF;
	wstr = conv.from_bytes(local_Type);
	d = (wchar_t *)wstr.c_str();

	/*wcout << endl << d << endl;
	wcout << wstr << endl;*/

	n = mP->countPath(d, w + '/');

	cout << "Numero de arquivos: " << n << endl << endl;

	free(mP);
}