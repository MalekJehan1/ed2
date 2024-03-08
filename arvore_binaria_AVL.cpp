#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

typedef struct arv
{
    int info;
    int fb;
    arv *sae;
    arv *sad;
}arvore;

arvore* cria_arvore();
int testa_vazia(arvore *p);
void inserir(arvore **p, int num);
void mostra(arvore *p);
void mostra_em_ordem(arvore *p);
void mostra_pos(arvore *p);
void mostra_fator(arvore *p);
arvore* remover(arvore **p, int num);
arvore * limpa_arvore(arvore *p);
int altura(arvore *p);
int fator_bal (arvore *p);
void calcula_fb(arvore *p);
int verifica_avl(arvore *p);
arvore* rotacionar_esq_esq (arvore *p);
arvore* rotationar_esq_dir (arvore *p);
arvore* rotacionar_dir_esq (arvore *p);
arvore* rotacionar_dir_dir (arvore *t);
arvore* balancear_node (arvore *p );

main()
{
    arvore *t = cria_arvore();
    int menu = -1, valor;
    do{
       system("cls");
       cout << "0 - SAIR" << endl;
       cout << "1 - INCLUIR" << endl;
       cout << "2 - MOSTRAR" << endl;
       cout << "3 - EXCLUIR" << endl;
       cout << "4 - LIMPA ARVORE" << endl;
       cout << "5 - ALTURA DA ARVORE" << endl;
       cout << "Sua escolha: ";
       cin >> menu;
       fflush(stdin);
       switch(menu)
       {
          case 0 :
              system("cls");
              cout << "Programa finalizado.";
              getchar();
              break;
          case 1 :
              system("cls");
              cout << "Informe o valor a ser inserido: ";
              cin >> valor;
              fflush(stdin);
              inserir(&t,valor);
              cout << "VALOR INSERIDO COM SUCESSO!";
              calcula_fb(t);
              if(verifica_avl(t) != 0)
                 {
                     cout << "\n\nARVORE NAO BALANCEADA";
                     t = balancear_node(t);
                     calcula_fb(t);
                 }
                 else
                     cout << "\n\nARVORE BALANCEADA";
              getchar();
              break;
          case 2 :
              system("cls");
              if(testa_vazia(t))
                 cout << "ARVORE VAZIA.";
              else
              {
                 cout << "ELEMENTOS NA ARVORE PRE-FIXA: " << endl;
                 mostra(t);
                 cout << "\n\nELEMENTOS NA ARVORE EM ORDEM: " << endl;
                 mostra_em_ordem(t);
                 cout << "\n\nELEMENTOS NA ARVORE POS-FIXA: " << endl;
                 mostra_pos(t);
                 cout << "\n\nELEMENTOS NA ARVORE COM FB: " << endl;
                 mostra_fator(t);
              }
              getchar();
              break;
          case 3 :
              system("cls");
              if(testa_vazia(t))
                 cout << "ARVORE VAZIA.";
              else
              {
                 cout << "Informe o elemento a ser removido: ";
                 cin >> valor;
                 fflush(stdin);
                 remover(&t, valor);
                 calcula_fb(t);
              }
              getchar();
              break;
            case 4 :
              system("cls");
              if(testa_vazia(t))
                 cout << "ARVORE VAZIA.";
              else
              {
                 t = limpa_arvore(t);
                 cout << "ARVORE LIMPA COM SUCESSO.";
              }
              getchar();
              break;
            case 5 :
              system("cls");
              if(testa_vazia(t))
                 cout << "ARVORE VAZIA.";
              else
              {
                 cout << "ALTURA DA ARVORE: " << altura(t) << endl;
                 if(verifica_avl(t) != 0)
                 {
                     cout << "\n\nARVORE NAO BALANCEADA";
                     t = balancear_node(t);
                     calcula_fb(t);
                 }
                 else
                     cout << "\n\nARVORE BALANCEADA";
              }
              getchar();
              break;
          default :
              system("cls");
              cout << "OPCAO INVALIDA.";
              getchar();
              break;
       };
    }while(menu != 0);
}


arvore* cria_arvore()
{
    return NULL;
}

int testa_vazia(arvore *p)
{
    if(p == NULL)
        return 1;
    if(p->info == NULL)
        return 1;
    return 0;
}

void inserir(arvore **p, int num)
{
    if(*p == NULL)
    {
        *p = new arvore;
        (*p)->sae = NULL;
        (*p)->sad = NULL;
        (*p)->info = num;
    }
    else
    {
        if(num < (*p)->info)
            inserir(&(*p)->sae, num);
        else
            inserir(&(*p)->sad, num);
    }
}

void mostra(arvore *p)
{
    cout << "<";
    if(!testa_vazia(p))
    {
       cout << p->info;
       mostra (p->sae);
       mostra (p->sad);
    }
    cout << ">";
}

void mostra_em_ordem(arvore *p)
{
    cout << "<";
    if(!testa_vazia(p))
    {
       mostra_em_ordem (p->sae);
       cout << p->info;
       mostra_em_ordem (p->sad);
    }
    cout << ">";
}

void mostra_pos(arvore *p)
{
    cout << "<";
    if(!testa_vazia(p))
    {
       mostra_pos (p->sae);
       mostra_pos (p->sad);
       cout << p->info;
    }
    cout << ">";
}

void mostra_fator(arvore *p)
{
  cout << "<";
  if(!testa_vazia(p))
  {
     mostra_fator(p->sae);
     cout << p->info << "(" << p->fb << ")";
     mostra_fator(p->sad);
  }
  cout << ">";
}

arvore* remover(arvore **p, int num)
{
    if(*p == NULL)
    {
        cout << "ELEMENTO NAO ENCONTRADO.";
        return *p;
    }

    if(num < (*p)->info)
        remover(&(*p)->sae, num);
    else if(num > (*p)->info)
        remover(&(*p)->sad, num);
    else{
        arvore *aux = *p;
        //se for um nodo folha
        if(((*p)->sae == NULL) && ((*p)->sad == NULL))
        {
            delete(aux);
            (*p) = NULL;
        }
        else if((*p)->sae == NULL)
        {
            //só tem filho a direita
            (*p) = (*p)->sad;
            aux->sad =  NULL;
            delete(aux);
            aux = NULL;
        }
        else if((*p)->sad == NULL)
        {
            //só tem filho a esquerda
            (*p) = (*p)->sae;
            aux->sae =  NULL;
            delete(aux);
            aux = NULL;
        }
        else{
            aux = (*p)->sae;
            while(aux->sad != NULL)
                aux = aux->sad;
            (*p)->info = aux->info;
            aux->info = num;
            (*p)->sae = remover(&(*p)->sae, num);
        }
        cout << "ELEMENTO REMOVIDO COM SUCESSO.";
    }
    return *p;
}

arvore * limpa_arvore(arvore *p)
{
    if(p != NULL)
    {
        limpa_arvore(p->sae);
        limpa_arvore(p->sad);
        delete(p);
    }
    return  NULL;
}

int altura(arvore *p)
{
    if(p == NULL)
        return 0;
    else
    {
        int he = altura(p->sae);
        int hd = altura(p->sad);
        if(he < hd)
            return (hd + 1);
        else
            return (he + 1);
    }
}

int fator_bal (arvore *p)
{
	int fator = 0;

	if (p->sae)
		fator += altura(p->sae);

	if (p->sad)
		fator -= altura (p->sad);

	return fator;
}

// Rotina para o cálculo de FB de cada nó chama a função fator_bal
void calcula_fb(arvore *p)
{
  if(!testa_vazia(p))
  {
     p->fb = fator_bal(p);
     if(p->sae != NULL)
        calcula_fb(p->sae);
     if(p->sad != NULL)
        calcula_fb(p->sad);
  }
}

int verifica_avl(arvore *p)
{
    if(!testa_vazia(p))
    {
       if((p->fb > 1) || (p->fb < -1))
       {
          cout << "\nFB: " << p->fb << endl;
          return p->fb;
       }
       if(p->sae != NULL)
          verifica_avl(p->sae);
       else
          return 0;
       if(p->sad != NULL)
          verifica_avl(p->sad);
       else
          return 0;
    }
}

arvore* rotacionar_esq_esq (arvore *p)
{
	arvore * temp_ptr = p;
	arvore * esq_ptr = temp_ptr->sae;

	temp_ptr->sae = esq_ptr->sad;
	esq_ptr->sad = temp_ptr;

	return esq_ptr;
}

arvore* rotationar_esq_dir (arvore *p)
{
	arvore* temp_ptr = p;
	arvore* esq_ptr = temp_ptr->sae;
	arvore* dir_ptr = esq_ptr->sad;

	temp_ptr->sae = dir_ptr->sad;
	esq_ptr->sad = dir_ptr->sae;
	dir_ptr->sae = esq_ptr;
	dir_ptr->sad = temp_ptr;

	return dir_ptr;
}

arvore* rotacionar_dir_esq (arvore *p)
{
	arvore *temp_ptr = p;
	arvore *dir_ptr = temp_ptr->sad;
	arvore *esq_ptr = dir_ptr->sae;

	temp_ptr->sad = esq_ptr->sae;
	dir_ptr->sae = esq_ptr->sad;
	esq_ptr->sad = dir_ptr;
	esq_ptr->sae = temp_ptr;

	return esq_ptr;
}

arvore* rotacionar_dir_dir (arvore *t)
{
	arvore *temp_ptr = t;
	arvore *dir_ptr = temp_ptr->sad;

	temp_ptr->sad = dir_ptr->sae;
	dir_ptr->sae = temp_ptr;

	return dir_ptr;
}

arvore* balancear_node (arvore *p )
{
	arvore *node_balanceado = NULL;

	if (p->sae)
		p->sae = balancear_node (p->sae);

	if (p->sad)
		p->sad = balancear_node (p->sad);

	int fator = fator_bal(p);


	if (fator >= 2)
	{
		/* pesando pra esquerda */

		if (fator_bal(p->sae) <= -1 )
			node_balanceado = rotationar_esq_dir (p);
		else
			node_balanceado = rotacionar_esq_esq (p);

	}
	else if (fator <= -2)
	{
		/* pesando pra direita */

		if (fator_bal(p->sad) >= 1 )
			node_balanceado = rotacionar_dir_esq (p);
		else
			node_balanceado = rotacionar_dir_dir (p);
	}
	else
	{
		node_balanceado = p;
	}

	return node_balanceado;
}

