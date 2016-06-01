#include "mPaths.h"

mPaths::mPaths()
{
}

mPaths::~mPaths()
{
}

int mPaths::countPath(wchar_t *wC, string diretorio)
{
	int countP = 0, cW = 0;
	wchar_t *file = wC;
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	string nameFile;
	wstring nome;

	hFind = FindFirstFile(file, &ffd);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{	
			nome = ffd.cFileName;
			nameFile.append(nome.begin(), nome.end());
			cout << "Nome do arquivo: " << nameFile << endl;
			cW = countWordFile(diretorio+nameFile);
			cout << "Numero de palavras no arquivo: " << cW << endl << endl;
			countP++;
			cW = 0;
			nameFile = "";
		} while (FindNextFile(hFind, &ffd) == TRUE);
	}
	else
	{
		cout << "Failed to find path" << endl;
	}

	FindClose(hFind);

	return countP;
}

int mPaths::countWordFile(string name)
{
	string nF = name;
	ifstream f(nF.c_str());
	int countW = 0;
	string word;

	if (!f.is_open())
	{
		cout << "Erro ao abrir arquivo." << endl;
	}
	else
	{
		while (!f.eof())
		{
			f >> word;
			countW++;
		}
	}
	f.close();

	return countW;
}