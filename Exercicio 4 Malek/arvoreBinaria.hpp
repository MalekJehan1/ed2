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
        return false; //caso n�o estiver vazia, retorna false
}

void inserir(arv **t, int num)
{
    if(*t == NULL) //caso n�o tiver elemento na arvore
    {
        *t = new arv;
        (*t)->sae = nullptr;
        (*t)->sad = nullptr;
        (*t)->info = num;
    }
    else
    {
        if(num < (*t)->info) //verifica se � menor que o elemento presente no N�;
            inserir(&(*t)->sae, num);
        else
            inserir(&(*t)->sad, num);
    }
    cout << "inserido o valor: " << num << endl;
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

arvore* minValorNo(arvore* no) {
    arvore* c = no;
    while (c && c->sae != NULL) c = c->sae;
    return c;
}

arvore* remover(arvore* t, int num, bool &encontrado) {
    encontrado = true;
    if (t == NULL) {
        encontrado = false;
        return NULL;
    }
    if (num < t->info) t->sae = remover(t->sae, num, encontrado);
    else if (num > t->info) t->sad = remover(t->sad, num, encontrado);
    else {
        if (t->sae == NULL) {
            arvore* temp = t->sad;
            delete t;
            return temp;
        }
        else if (t->sad == NULL) {
            arvore* temp = t->sae;
            delete t;
            return temp;
        }

        arvore* temp = minValorNo(t->sad);
        t->info = temp->info;
        t->sad = remover(t->sad, temp->info, encontrado);
    return t;
}
}


///Fun��es backups que n�o deram certo - inicio
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
///Fun��es backups que n�o deram certo - fim

int alturaAt(arv **t)
{
    if((*t) == nullptr)
        return 1;
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
    else{
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



#endif
