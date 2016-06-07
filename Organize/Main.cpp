#include "mPaths.h"
#include "Index.h"
#include <locale>
#include "SearchFile.h"
#include <string>
#include <iostream>

using namespace std;

void main()
{
	int n;
	mPaths mP;
	string w, typeF, local_Type;
	string pesquisa = "";
	wchar_t *d;
	wstring_convert<codecvt<wchar_t, char, mbstate_t>> conv;
	wstring wstr;
	Index ind;
	SearchFile *s;

	cout << "Insira o nome do diretorio: ";
	cin >> w;
	cout << "Insira o tipo do arquivo: ";
	cin >> typeF;
	cout << endl;

	local_Type = w + "/*." + typeF;
	wstr = conv.from_bytes(local_Type);
	d = (wchar_t *)wstr.c_str();

	/*wcout << endl << d << endl;
	wcout << wstr << endl;*/

	n = mP.countPath(d, w + '/');

	ind.IndexS(n);

	cout << "Numero de arquivos: " << ind.Get_qtdeArq() << endl;
	cout << "Numero de palavras totais: " << mP.Get_meAjuda() << endl;
	cout << "Numero de palavras nao repitidas: " << mP.Get_nWords() << endl << endl;

	cout << "Salvando..." << endl;
	mP.gravaPalavras();
	mP.comparaPalavras(d, w + '/');

	ind.geraDF(mP.Get_nWords(), mP);

	cout << "Informe o que deseja procurar: ";
	cin.ignore(256, '\n');
	getline(cin, pesquisa);

	s = new SearchFile(pesquisa, mP, ind);
	s->freqPesquisa();
}