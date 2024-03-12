#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#include "arvoreBinaria.hpp"

int main()
{
    arv* a = nullptr;

    ifstream ler;
    setlocale(LC_ALL, "Portuguese");

    ler.open("entrada.txt", ios::in);

    if(ler.is_open())
    {
        string word;

        while(!ler.eof())
        {
            string linha="";
            stringstream strBuffer;
            getline(ler, linha);
            strBuffer = stringstream(linha);
            strBuffer >> word;
            if(linha != "")
            {
                if(word == "inserir")
                {
                    string par;

                    strBuffer >> par;

                    int num = stoi(par);

                    inserir(&a, num);
                }
                else if(word == "remover")
                {
                    string par;

                    strBuffer >> par;

                    int num = stoi(par);
                    bool encontrado;
                    arv *e = remover(a, num, encontrado);
                    cout << "Removido: " << e->info;

                }
                else if(word == " ")
                {

                }
            }

        }
    }
}

