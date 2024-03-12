#include <iostream>
#include "arvoreBinaria.hpp"
#include <time.h>

using namespace std;


int main()
{
    system("color f6");
    setlocale(LC_ALL,"Portuguese");
    arv *a = NULL;
    fflush(stdin);

    int opcao;
    /*
    //30, 17, 26, 8, 23, 11, 5, 14, 25, 52, 6, 40, 28, 59, 20
    */
    inserir(&a, 30);
    inserir(&a, 17);
    inserir(&a, 26);
    inserir(&a, 8);
    inserir(&a, 23);
    inserir(&a, 11);
    inserir(&a, 5);
    inserir(&a, 14);
    inserir(&a, 25);
    inserir(&a, 52);
    inserir(&a, 6);
    inserir(&a, 40);
    inserir(&a, 28);
    inserir(&a, 59);
    inserir(&a, 20);


    do
    {
        int *cont = new int(0);
        cout << endl <<"Menu" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Incluir" << endl;
        cout << "2 - Mostrar pr�-ordem" << endl;
        cout << "3 - Mostrar ordem sim�trica" << endl;
        cout << "4 - Mostrar p�s-ordem" << endl;
        cout << "5 - Mostrar altura da sub-arvore ESQUERDA" << endl;
        cout << "6 - Mostrar altura da sub-arvore DIREITA" << endl;
        cout << "7 - Mostrar altura da ARVORE RAIZ" << endl;
        cout << "8 - Limpar todos os n�s da arvore, liberando mem�ria" << endl;
        cout << "9 - Encontrar um valor e verificar qual nivel se encontra" << endl;
        cout << "Informe a op��o: ";
        cin >> opcao;

        switch(opcao)
        {
        case 1:
            system("cls");
            int valor;
            cout << "Informe um n�mero inteiro para adicionar � arvore: ";
            cin >> valor;

            inserir(&a,valor);

            break;
        case 2:
            system("cls");
            if(!testa_vazia(a))
            {
                cout << "Pr�-Ordem: " << endl;
                mostraPre(a);
            }
            else
            {
                informaVazia();
            }
            break;
        case 3:
            system("cls");
            if(!testa_vazia(a))
            {
            cout  << "Ordem Sim�trica: " << endl;
            mostraOrdem(a);
            }
            else
                informaVazia();
            break;
        case 4:
            system("cls");
            if(!testa_vazia(a))
            {
            cout  <<  "P�s-Ordem: " << endl;
            mostraPos(a);
            }
            else
                informaVazia();
            break;
        case 5:
            system("cls");
            //int altura = alturaAt(&a->sae) + 1;
            if(a->sae != NULL)
                cout << "Altura da sub-arvore esquerda: " << alturaAt(&a->sae);
            else
                cout << "Altura da sub-arvore esquerda � NULO" << endl;
            break;
        case 6:
            system("cls");
            //int altura = alturaAt(&a->sad) + 1;
            if(a->sad != nullptr)
                cout << "Altura da sub-arvore direita: " << alturaAt(&a->sad);
            else
                cout << "Altura Sub-arvore direita � NULO" << endl;
            break;
        case 7:
            system("cls");
            if(!testa_vazia(a)){
            cout << "Altura da arvore: " << alturaAt(&a);
            }
            else
                informaVazia();
            break;
        case 8:
            system("cls");
            if(!testa_vazia(a)){
            cout << "Limpando �rvore..." << endl;
            cout << "�rvore limpa!" << endl;
            cout << "N�mero de n�s removidos: " << limparArvore(&a, cont);
            }
            else
                informaVazia();
            break;
        case 9:
            system("cls");
            if(!testa_vazia(a))
            {
                int valor;
                cout << "Informe o valor que deseja procurar: ";
                cin >> valor;
                if(buscaValor(&a,valor))
                {
                    //if(findValue(&a, valor))
                    cout << "valor encontrado!"<< endl;
                    cout << "nivel: " << qualNivel(&a, valor)<< endl;
                }
                else
                    cout << "Valor n�o encontrado!" << endl;
            }
            else
            {
                cout << "Arvore Vazia!" << endl;
            }
            break;
        case 0:
            system("cls");
            cout << endl << "Encerrando programa..." << endl;
            break;
        default:
            system("cls");
            cout << endl << "Op��o informada n�o reconhecida!" << endl;
        }
    }
    while(opcao != 0);

    delete(a);
    return 0;
}

