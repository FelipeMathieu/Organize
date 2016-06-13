#include "SearchDirectory.h"

SearchDirectory::SearchDirectory()
{
}

SearchDirectory::~SearchDirectory()
{
}

bool SearchDirectory::dirSearch(wchar_t *dirName_in, string diretorio)
{
	//int countDir = 0, countFile = 0;
	wchar_t *dirN = dirName_in, *aux;
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	string nameFile, nomeDiretorio;
	wstring nome;
	//ofstream NameFiles("Save/NameFiles.txt");
	//DWORD f_typ = GetFileAttributes(dirN);

	hFind = FindFirstFile(dirN, &ffd);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		return false;
	}

		do
		{
			nome = ffd.cFileName;
			nameFile.append(nome.begin(), nome.end());
			aux = (wchar_t*)nome.c_str();
			
			if (wcscmp(ffd.cFileName, L".") != 0 && wcscmp(ffd.cFileName, L"..") != 0)
			{
				this->countDir += 1;
				this->dirSearch(aux, nameFile + '/');
			}
			else
			{
				this->countFiles++;
				//this->meAjuda += cW;
				//countP++;
				//cout << "Numero de palavras no arquivos: " << cW << endl << endl;
				//cW = 0;
				//NameFiles << nameFile << " ";
				nameFile = "";
			}
		} while (FindNextFile(hFind, &ffd) == TRUE);

	FindClose(hFind);
}
