#ifndef _HPP_ARVORE_BINARIA
#define _HPP_ARVORE_BINARIA
#include <iostream>

using namespace std;

typedef struct arv
{
    int info;
    arv *sae;
    arv *sad;

} arvore;

void informaVazia()
{
    cout << "Arvore vazia!" << endl;

}


bool testa_vazia(arv *t)
{
    if(t == NULL)
    {
        return true;
    }
    else
        return false; //caso não estiver vazia, retorna false
}

void inserir(arv **t, int num)
{
    if(*t == NULL) //caso não tiver elemento na arvore
    {
        *t = new arv;
        (*t)->sae = nullptr;
        (*t)->sad = nullptr;
        (*t)->info = num;
    }
    else
    {
        if(num < (*t)->info) //verifica se é menor que o elemento presente no NÓ;
            inserir(&(*t)->sae, num);
        else
            inserir(&(*t)->sad, num);
    }
}

void mostraPre(arvore *t)
{
    cout << "<";
    if(!testa_vazia(t))
    {
        cout << t->info;
        mostraPre(t->sae);
        mostraPre(t->sad);
    }
    cout << ">";
}

void mostraOrdem(arvore *t)
{
    cout << "<";
    if(!testa_vazia(t))
    {
        mostraOrdem(t->sae);
        cout << t->info;
        mostraOrdem(t->sad);
    }
    cout << ">";
}

void mostraPos(arvore *t)
{
    cout << "<";
    if(!testa_vazia(t))
    {
        mostraPos(t->sae);
        mostraPos(t->sad);
        cout << t->info;
    }
    cout << ">";
}

void mostraParag(arvore *t)
{
    cout << "*";
    if(!testa_vazia(t))
    {
        cout << t->info << endl;
        if(!testa_vazia(t->sae))
        {
            cout << "*";
            mostraParag(t->sae);
        }
        if(!testa_vazia(t->sad))
        {
            cout << "*";
            mostraParag(t->sad);
        }
    }
}
void parag(arvore *t, int nivel)
{
    if (t != NULL)
    {
        for (int i = 0; i < nivel; ++i) {
            cout << " * ";
        }
        cout << t->info << endl;

        parag(t->sae, nivel + 1);
        parag(t->sad, nivel + 1);
    }
}





arvore* remover(arvore **t, int num)
{
    arv *temp = (*t);
    if(num < (*t)->info)
        remover(&(*t)->sae, num);
    else if(num > (*t)->info)
        remover(&(*t)->sad, num);
    else
    {
        arvore *aux = *t;

        if(((*t)->sae == NULL) && ((*t)->sad == NULL))
        {
            delete(aux);
            (*t) = NULL;
        }
        else if((*t)->sae == NULL)
        {
            (*t) = (*t)->sad;
            aux->sad = NULL;
            delete(aux);
            aux = NULL;
        }
        else if((*t)->sad == NULL)
        {
            (*t) = (*t)->sae;
            aux->sae = NULL;
            delete(aux);
            aux = NULL;
        }
        else
        {
            aux = (*t)->sae;
            while(aux->sad != NULL)
            {
                aux = aux->sad;
            }
            (*t)->info = aux->info;
            aux->info = num;
            (*t)->sae = remover(&(*t)->sae, num);
        }
    }
    return temp;
}




///Funções backups que não deram certo - inicio
/*
int encAlturaEsq(arv **t)
{
    int altura = 0;

    while((*t) != NULL)
    {
        altura++;
        (*t) = (*t)->sae;
    }
    return altura;
}

int encAlturaDir(arv **t)
{
    int altura = 0;

    while((*t) != NULL)
    {
        altura++;
        (*t) = (*t)->sad;
    }
    return altura;
}*/
///Funções backups que não deram certo - fim

int alturaAt(arv **t)
{
    if((*t) == nullptr)
        return 0;
    else
    {
        int esq = alturaAt(&(*t)->sae);
        int dir = alturaAt(&(*t)->sad);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}

int limparArvore(arv **t, int* cont)
{

    if((*t) == NULL)
    {
        return 0;
    }
    else
    {
        int esq = limparArvore(&(*t)->sae, cont);
        int dir = limparArvore(&(*t)->sad, cont);
        if(esq > dir)
        {
            //(*t) = nullptr;
            return esq + 1;
        }
        else if((*t)->sae == NULL && (*t)->sad == NULL)
        {
            //cout << "oi";
            (*t) = nullptr;
            (*cont)++;
            delete((*t));
            return (*cont);
        }
        else
            //(*t) = nullptr;
            return dir + 1;
    }
}

//bool findValue(arv** t, int valor, int* cont)
bool buscaValor(arv** t, int valor)
{
    if((*t) == nullptr)
        return false;
    else if((*t)->info == valor)
        return true;
    else if((*t)->info < valor)
    {
        return buscaValor(&(*t)->sad, valor);
    }
    else
    {
        return buscaValor(&(*t)->sae, valor);
    }
}

int qualNivel(arv **t, int valor)
{
    cout << (*t)->info;
    if((*t) == NULL)
        return 0;
    else if((*t)->info == valor)
    {
        return 0;
    }
    else if(valor < (*t)->info)
    {
        return 1 + qualNivel(&(*t)->sae, valor);
    }
    else
    {
        return 1 + qualNivel(&(*t)->sad, valor);
    }
}

///Tentativas fracassadas de encontrar o valor e o nivel kkk
/*
int nivel(arv **t, int valor)
{
    Lista l = Lista();

    insereFinalL(&l, (*t));

    int contNivel =0;

    while(!vaziaL(&l))
    {
        arv* removido = removeInicioL(&l);
        cout << removido->info << ",";
        if(removido->info == valor)
            return contNivel;
        if(removido->sae != nullptr)
        {
            insereFinalL(&l, removido->sae);
        }
        if(removido->sad != nullptr)
        {
            insereFinalL(&l, removido->sad);
        }
    }
    cout << endl;
    return contNivel;
}*/
///Tentativas fracassadas de encontrar o valor e o nivel FIM


int contFolhas(arv** t)
{
    if((*t) == NULL)
        return 0;
    else if((*t)->sae == NULL && (*t)->sad == NULL)
        return 1;
    else
        return contFolhas(&(*t)->sae) + contFolhas(&(*t)->sad);
}

bool arvoreCompletaUtil(arvore *raiz, int nivel, int alturaArvore) {
    if (raiz == NULL)
        return true;

    // Se o nível atual for o último nível, então o nó não pode ter nenhum filho
    if (nivel == alturaArvore)
        return (raiz->sae == NULL && raiz->sad == NULL);

    // Se o nó não tiver um filho direito, todos os nós à sua direita também devem ser folhas
    if (raiz->sad == NULL && raiz->sae != NULL)
        return false;

    // Recursivamente verifica os filhos esquerdo e direito
    return arvoreCompletaUtil(raiz->sae, nivel + 1, alturaArvore) &&
           arvoreCompletaUtil(raiz->sad, nivel + 1, alturaArvore);
}

void formaMatriz(arv* t, int i, int j, int mat[5][5])
{
    if(!testa_vazia(t))
    {
        mat[i][j] = t->info;
        formaMatriz(t->sae, i+1, j, mat);
        formaMatriz(t->sad, i+1, j, mat);
    }
}

#endif
