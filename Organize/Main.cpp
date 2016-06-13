#include "mPaths.h"
#include "Index.h"
#include <locale>
#include "SearchFile.h"
#include <string>
#include <iostream>
#include "Gerencia.h"
#include "SearchDirectory.h"

using namespace std;

void main()
{
	int n, escolha;
	mPaths mP;
	string w, typeF, local_Type;
	string pesquisa = "";
	wchar_t *d;
	wstring_convert<codecvt<wchar_t, char, mbstate_t>> conv;
	wstring wstr;
	Index ind;
	SearchFile *s;
	Gerencia g;
	SearchDirectory sD;

	cout << "(1) Busca;" << endl;
	cout << "(2) Desafio;" << endl;
	cout << "O que deseja executar: ";
	cin >> escolha;

	switch (escolha)
	{
	default:
		break;
	case 1:
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

		if (g.GerenciaFiles(d, w + '/'))
		{
			cout << "Carregando base..." << endl << endl;
			g = *g.newG();
			ind.IndexG(g.GetSize(), g);
			//ind.geraDF(g.Get_WordsG().size());

			cout << "Informe o que deseja procurar: ";
			cin.ignore(256, '\n');
			getline(cin, pesquisa);

			s = new SearchFile(pesquisa, ind);
			s->freqPesquisa();
			break;
		}
		else
		{
			n = mP.countPath(d, w + '/');

			//ind.IndexS(n, mP);

			//	cout << "Numero de arquivos: " << ind.Get_qtdeArq() << endl;
			//	cout << "Numero de palavras totais: " << mP.Get_meAjuda() << endl;
			//	cout << "Numero de palavras nao repitidas: " << mP.Get_Words().size() << endl << endl;

			cout << "Salvando..." << endl;
			mP.gravaPalavras();
			mP.comparaPalavras(d, w + '/');
			ind.IndexS(n, mP);
			ind.geraDF(mP.Get_Words().size());

			cout << "Informe o que deseja procurar: ";
			cin.ignore(256, '\n');
			getline(cin, pesquisa);

			s = new SearchFile(pesquisa, ind);
			s->freqPesquisa();
			break;
		}
	case 2:
		cout << "Insira o nome do diretorio: ";
		cin >> w;
		cout << "Insira o tipo do arquivo: ";
		cin >> typeF;
		cout << endl;

		local_Type = w + "/*." + typeF;
		wstr = conv.from_bytes(local_Type);
		d = (wchar_t *)wstr.c_str();

		sD.dirSearch(d, w + '/');

		cout << "Numero de diretorios: " << sD.Get_nDir() << endl;
		cout << "Numero de arquivos: " << sD.Get_nFiles() << endl;
		break;
	}
}
