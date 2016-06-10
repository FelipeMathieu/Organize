#include "Gerencia.h"

Gerencia::Gerencia()
{
}

Gerencia::~Gerencia()
{
}

int Gerencia::GerenciaFiles(wchar_t *wC, string diretorio)
{
	int countP = 0, cW = 0;
	wchar_t *file = wC;
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE, hFind2 = INVALID_HANDLE_VALUE;
	string nameFile;
	wstring nome;
	ifstream nFiles("Save/NameFiles.txt");
	vector<string> compareNameFiles;

	hFind = FindFirstFile(file, &ffd);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			nome = ffd.cFileName;
			nameFile.append(nome.begin(), nome.end());
			//cW = countWordFile(diretorio + nameFile);
			//this->meAjuda += cW;
			//countP++;
			//cout << "Numero de palavras no arquivos: " << cW << endl << endl;
			//cW = 0;
			//NameFiles << nameFile << " ";
			//nameFile = "";
			this->nameFiles.push_back(nameFile);
			nameFile = "";
		} while (FindNextFile(hFind, &ffd) == TRUE);
	}
	else
	{
		cout << "Failed to find path" << endl;
	}
	
	if (nFiles.is_open())
	{
		while (getline(nFiles, nameFile))
		{
			compareNameFiles = this->split(nameFile);
		}
	}
	else
	{
		return 0;
	}
	nFiles.close();

	if (this->nameFiles.size() == compareNameFiles.size())
	{
		if (this->nameFiles == compareNameFiles)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

Gerencia *Gerencia::newG()
{
	ifstream idf("Save/IDF.txt"), u("Save/TF_IDF.txt"), palavras("Save/Palavras_nao_repitidas.txt"), Freq_Palavras("Save/Freq_Palavras.txt");
	vector<double> uG;
	string p;
	vector<string> aux, aux3, aux4;
	int freq, j = 0;

	if (idf.is_open())
	{
		while (getline(idf, p))
		{
			aux = this->split(p);
		}
		for (int i = 0; i < aux.size(); i++)
		{
			this->IDFg.push_back(stod(aux.at(i)));
		}
	}
	else
	{
		cout << "Erro." << endl;
	}
	p = "";

	if (palavras.is_open())
	{
		while (!palavras.eof())
		{
			palavras >> p;
			if (find(this->words.begin(), this->words.end(), p) == this->words.end())
			{
				this->words.push_back(p);
			}
		}
	}
	else
	{
		cout << "Erro." << endl;
	}
	p = "";

	if (Freq_Palavras.is_open())
	{
		while (getline(Freq_Palavras, p))
		{
			aux3 = this->split(p);
			for (int i = 0; i < aux3.size(); i++)
			{
				//aux4.push_back(stoi(aux3.at(i), nullptr, 10));
				this->freqWords[this->Get_NameFiles().at(j)].push_back(stoi(aux3.at(i), nullptr, 10));
			}
			j++;
		}
	}
	else
	{
		cout << "Erro." << endl;
	}
	p = "";
	j = 0;

	this->Ug.first = this->nameFiles;
	this->Ug.second = vector<vector<double>>(this->nameFiles.size());

	if (u.is_open())
	{
		while (getline(u, p))
		{
			aux4 = this->split(p);
			for (int i = 0; i < aux4.size(); i++)
			{
				this->Ug.second.at(j).push_back(stod(aux4.at(i)));
			}
			j++;
		}
	}
	else
	{
		cout << "Erro." << endl;
	}

	idf.close();
	palavras.close();
	Freq_Palavras.close();
	u.close();

	return this;
}

vector<string> Gerencia::split(const string &s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	// invariant: we have processed characters [original value of i, i) 
	while (i != s.size())
	{
		// ignore leading blanks
		// invariant: characters in range [original i, current i) are all spaces
		while (i != s.size() && isspace(s[i]))
			++i;

		// find end of next word
		string_size j = i;
		// invariant: none of the characters in range [original j, current j)is a space
		while (j != s.size() && !isspace(s[j]))
			j++;
		// if we found some nonwhitespace characters 
		if (i != j) {
			// copy from s starting at i and taking j - i chars
			ret.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return ret;
}
