#ifndef _HPP_LISTA_DUPLA
#define _HPP_LISTA_DUPLA
#include "arvoreBinaria.hpp"
#include <iostream>

using namespace std;

typedef struct arv
{
    int info;
    arv *sae;
    arv *sad;

} arvore;


typedef struct No
{
    arv *dado;
    No *prox;
    No *ant;
    No() // construtor
    {
        prox = nullptr;
        ant = nullptr;
    }
} Node;

struct Lista
{
    No *inicio;
    Node *fim;
    int tamanho;
    Lista() /// construtor
    {
        //cout << "\n executando o construtor...\n";
        inicio = nullptr;
        fim = nullptr;
        tamanho =0;
    }
};


/// quando cout receber uma struct No
ostream& operator<<(ostream& os, const No *n)
{
    /// cout << n
    return os << n->dado;
}

/// quanto cout receber uma struct Lista
ostream& operator << (ostream& os, const Lista &l)
{
    No *n = l.inicio;
    os << "L[" << l.tamanho << "]:{";
    while(n)
    {
        os << n;
        n = n->prox;
        if(n)
            os << ", ";
    }
    os << "}";
    return os;
}

void destroiL(Lista *l)
{
    No *n = l->inicio;
    while(n)
    {
        No *aux = n;
        n = n->prox;
        delete aux;
    }
    l->fim = NULL;
    l->inicio = NULL;
    l->tamanho = 0;
}

bool vaziaL(Lista *lista)
{
    if(! (lista->inicio) )
        return true;
    else
        return false;
}

void mostraL(Lista *lista)
{
    No *n = lista->inicio;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n;
        n = n->prox;
        if(n)
            cout << ", ";
    }
    cout << "}\n";
}

void mostrarInversoL(Lista *lista)
{
    No *n = lista->fim;
    cout << "L[" << lista->tamanho << "]:{";
    while(n)
    {
        cout << n;
        n = n->ant;

        if(n)
            cout << ", ";
    }
    cout << "}" << endl;
}


///insere no início da lista
bool insereInicioL(Lista *lista, arv* valor)
{

    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->ant = nullptr; //Se o novo nó será adicionado no início da lista, o ponteiro *ant do primeiro nó sempre é nulo
    novo->prox = lista->inicio;

    if (!lista->fim) //lista vazia?
        lista->fim = novo;
    else
        lista->inicio->ant = novo;

    lista->inicio = novo;
    lista->tamanho++;

    return true;
}
/*
No* buscaL(Lista *lista, int valor)
{
    No *n = lista->inicio;
    while (n)
    {
        if (n->dado == valor)
            return n;

        n = n->prox;
    }

    return nullptr;
}*/

bool removerNoL(Lista *lista, No *no)
{
    if(!no || !lista || vaziaL(lista))
        return false;

    if (!no->ant) /// se anterior é igual a NULL, o elemento a ser excluído está no início da lista
    {
        lista->inicio = no->prox;
        if (!lista->inicio) ///lista ficou vazia ?
            lista->fim = nullptr;
        else
            lista->inicio->ant = nullptr;

    }
    else   /// elemento está no meio ou no fim
    {

        no->ant->prox = no->prox;
        if (!no->prox)/// se for retirado último da lista
            lista->fim = no->ant;
        else
            no->prox->ant = no->ant;

    }

    /// libera a memória do elemento
    lista->tamanho--;
    delete(no);
    return true;
}
/*
bool removeL(Lista *lista, int valor)
{
    No* no = buscaL(lista, valor);

    if(!no)
        return false;

    removerNoL(lista, no);

    return true;
}
*/
///Minhas funções

bool insereFinalL(Lista* lista, arv* valor)
{
    No *novo = new No();
    if (!novo)
        return false;

    novo->dado = valor;
    novo->prox = nullptr;

    if(!lista->fim)
    {
        novo->ant = nullptr;
        lista->inicio = novo;
    }
    else
    {
        novo->ant = lista->fim;
        lista->fim->prox = novo;
    }

    lista->fim = novo;

    lista->tamanho++;

    return true;
}

arv* removeInicioL(Lista* lista)
{
    arv* valor;

    No* del;

    del = lista->inicio;
    valor = del->dado;

    if(del->prox == nullptr)
    {
        lista->inicio = nullptr;
        lista->fim = nullptr;
    }
    else
    {

        lista->inicio = del->prox;
        lista->inicio->ant = nullptr;
    }

    delete(del);
    lista->tamanho--;

    return valor;
}
/*
arv* removeFinalL(Lista* lista)
{
    arv* valor;

    No* del;

    del = lista->fim;
    valor = del->dado;

    if(del->ant == nullptr)
    {
        lista->inicio = nullptr;
        lista->fim = nullptr;
    }
    else
    {

        lista->fim = del->ant;
        lista->fim->prox = nullptr;
    }

    delete(del);
    lista->tamanho--;

    return valor;
}
/*
void removeTodos(Lista *lista, int valor)
{
    No* no = lista->inicio;
    No* excluir;

    while(no != NULL)
    {
        cout << "oi";
        if(no->dado == valor)
        {

            if(!no->ant)
            {
                excluir = no;
                lista->inicio = no->prox;
                lista->inicio->ant = nullptr;
                no = no->prox;
                delete(excluir);

            }
            else
            {
                excluir = no;
                no->ant->prox = no->prox;
                if (!no->prox) /// se for retirado último da lista
                {
                    lista->fim = no->ant;
                    delete(excluir);
                    lista->tamanho--;

                }
                else
                {
                    no->ant->prox = no->prox;
                    no->prox->ant = no->ant;
                    no = no->ant;
                    lista->tamanho--;
                    delete(excluir);
                }

            }
        }
        no = no->prox;
    }
}

Lista leMaiores(Lista *L, int K)
{
    No* no= L->inicio;

    int cont=0;

    Lista lista = Lista();

    if(L->tamanho > K)
    {

        while(cont != K)
        {
            no = L->inicio;
            int maior = L->inicio->dado;
            while(no != NULL)
            {
                if(no->dado > maior)
                    maior = no->dado;
                no = no->prox;
            }
            if(!buscaL(&lista, maior))
            insereFinalL(&lista, maior);
            cont++;

        }
    }
    else
    {

    }
    return lista;
}*/


#endif // _HPP_LISTA_DUPLA



