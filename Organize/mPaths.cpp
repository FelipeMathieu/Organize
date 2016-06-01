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
	wchar_t *file = wC, *file2;
	WIN32_FIND_DATA ffd, ffd2;
	HANDLE hFind = INVALID_HANDLE_VALUE, hFind2 = INVALID_HANDLE_VALUE;
	string nameFile, nomeDiretorio;
	wstring nome;

	hFind = FindFirstFile(file, &ffd);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			nome = ffd.cFileName;
			nameFile.append(nome.begin(), nome.end());

			if (nameFile.compare("...") != 0 && nameFile.compare(".") != 0)
			{
				nameFile = "";
				nome = ffd.cFileName;
				nameFile.append(nome.begin(), nome.end());
				cout << "Nome do arquivo: " << nameFile << endl;

				nomeDiretorio = diretorio + nameFile + "/";
				nameFile = diretorio + nameFile + "/*.txt";
				nome = L"";
				nome.append(nameFile.begin(), nameFile.end());
				file2 = (wchar_t *)nome.c_str();
				hFind2 = FindFirstFile(file2, &ffd2);

				if (hFind2 != INVALID_HANDLE_VALUE)
				{
					do
					{
						nameFile = "";
						nome = ffd2.cFileName;
						nameFile.append(nome.begin(), nome.end());
						cout << " ----Nome do arquivo: " << nameFile << endl;
						cW = countWordFile(nomeDiretorio + nameFile);
						cout << " ----Numero de palavras no arquivo: " << cW << endl << endl;
						countP++;

					} while (FindNextFile(hFind2, &ffd2));
					FindClose(hFind2);
				}
				else
				{
					nameFile = "";
					nome = ffd.cFileName;
					nameFile.append(nome.begin(), nome.end());
					cW = countWordFile(diretorio + nameFile);
					cout << "Numero de palavras no arquivo:  " << cW << endl << endl;
					countP++;
					cW = 0;
					nameFile = "";
				}
			}
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
	ifstream f;
	int countW = 0;
	string word;

	//cout << nF;

	if (nF.substr(nF.find_last_of(".") + 1) == "txt")
	{
		f.open(name.c_str());

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
	}

	return countW;
}