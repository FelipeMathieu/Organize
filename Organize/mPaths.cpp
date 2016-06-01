#include "mPaths.h"

mPaths::mPaths()
{
}

mPaths::~mPaths()
{
}

int mPaths::countPath(wchar_t *wC)
{
	int countP = 0, countW = 0;
	wchar_t *file = wC;
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	string word;
	ifstream f;
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
			countP++;
			nameFile = "";
		} while (FindNextFile(hFind, &ffd) == TRUE);

		/*f.open(nameFile.c_str());

		while (!f.eof())
		{
			f >> word;
			countW++;
		}

		f.close();*/
	}
	else
	{
		cout << "Failed to find path" << endl;
	}

	//cout << "Numero total de palavras em todos os arq: " << countW << endl;

	FindClose(hFind);

	return countP;
}