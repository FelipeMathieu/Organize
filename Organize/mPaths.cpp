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
				//cout << "Nome do arquivo: " << nameFile << endl;

				nomeDiretorio = diretorio + nameFile + "/";
				nameFile = diretorio + nameFile + "/*.txt";
				nome = L"";
				nome.append(nameFile.begin(), nameFile.end());
				file2 = (wchar_t *)nome.c_str();
			//	wcout << file2;
								
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
					this->meAjuda += cW;
					countP++;
					//cout << "Numero de palavras no arquivos: " << cW << endl << endl;
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

				word = filtraPalavra(word);

				if (find(this->words.begin(), this->words.end(), word) == this->words.end())
				{
					this->words.push_back(word);
				}
				countW++;
			}
		}
		f.close();
	}

	return countW;
}

string mPaths::filtraPalavra(string p)
{
	char c[] = "().,;:{}[]";

	for (unsigned int i = 0; i < p.size(); ++i)
	{
		p.erase(remove(p.begin(), p.end(), c[i]), p.end());
	}

	//transform(p.begin(), p.end(), p.begin(), tolower);

	return p;
}

void mPaths::gravaPalavras()
{
	ofstream palavras("Palavras_nao_repitidas.txt");
	string aux;

	if (palavras.is_open())
	{
		for (int i = 0 ; i < this->words.size(); i++)
		{
			palavras << this->words.at(i) << " ";
		}
	}
	else
	{
		cout << "Bugou ai." << endl;
	}

	palavras.close();
}

int mPaths::verificaPalavra(string p)
{
	if (find(p.begin(), p.end(), '.') != p.end() || find(p.begin(), p.end(), ',') != p.end() || find(p.begin(), p.end(), ';') != p.end() || find(p.begin(), p.end(), ':') != p.end())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}