#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#include "arvoreBinaria.hpp"

int main()
{
    arv* a = NULL;

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

                    cout << "Valor: " << num << " inserido!" << endl;
                }
                else if(word == "remover")
                {
                    string par;

                    strBuffer >> par;

                    int num = stoi(par);
                    remover(&a, num);
                    cout << "Valor: " << num << " removido!" << endl;

                }
                else if(word == "mostra")
                {
                    mostraPre(a);
                    cout << endl;
                }
                else if(word == "contFolhas")
                {
                    cout << "Total de elementos folhas: " << contFolhas(&a) << endl;
                }
                else if(word == "maiorNivel")
                {
                    cout << "O maior nível da árvore é: " << alturaAt(&a) - 1<< endl ;
                }
                else if(word == "mostraParagrafação")
                {
                    parag(a, 0);
                }
                else if(word == "verificaCompleta")
                {
                    if(arvoreCompletaUtil(a, 0, alturaAt(&a)))
                        cout << "Arvore completa" << endl;
                    else
                        cout << "Arvore não é completa" << endl;
                }
                else if(word == "matriz")
                {
                    int matriz[5][5];

                    int *mat = &matriz[5][5];

                    formaMatriz(a, 0, 0, matriz);


                    for(int i=0; i<5; i++)
                    {
                        for(int j=0; j<5; j++)
                        {
                            cout << matriz[i][j];
                            cout << "\t";
                        }
                        cout << "\n";
                    }


                }
            }
        }
    }
}

