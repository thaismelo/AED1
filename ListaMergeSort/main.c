#include <stdio.h>
#include <stdlib.h>
typedef struct no{
   int info;
   struct no* prox;
}no;

typedef struct lista{
   struct no* inicial;
}lista;

lista* init(){
   lista* lista = malloc(sizeof(lista));
   lista->inicial = NULL;
   return lista;
}

void inserir(lista* lista,int num){
   no* novo = malloc(sizeof(no));
   novo->info = num;
   novo->prox = NULL;
   if(lista->inicial == NULL){
       lista->inicial = novo;
   }else{
       no* cursor = lista->inicial;
       while(cursor->prox != NULL){
           cursor = cursor->prox;
       }
       cursor->prox = novo;
   }
}
void remover(lista* lista, int num){
   no* cursor = lista->inicial;
    if(cursor->info == num){
        lista->inicial = cursor->prox;
        }
    while(cursor->prox->info != num && cursor->prox->prox!=NULL){
        cursor = cursor->prox;
    }
    if(cursor->prox->info==num){
        cursor->prox = cursor->prox->prox;
    }
}
lista* selectionSort(lista* lista){
    no* pMin;
    no* p = lista->inicial;
    no* pProx;
    int temp;
    while(p->prox!=NULL){
        pMin=p;
        pProx = p->prox;
        while( pProx!=NULL){
            if(pMin->info>pProx->info){
                temp = pMin->info;
                pMin->info = pProx->info;
                pProx->info = temp;
            }
            pProx = pProx->prox;
        }
        if(pMin!=p){
            temp = p->info;
            p->info = pMin->info;
            pMin->info = temp;
        }
        p = p->prox;

    }
    return lista;
}

void print(lista* lista){
   no* cursor = lista->inicial;
   if(lista->inicial!=NULL){
        while(cursor->prox != NULL){
            printf("%d\n",cursor->info);
            cursor = cursor->prox;
        }
        printf("%d\n",cursor->info);
   }else{
       printf("lista vazia\n");
   }

}
lista* merge(lista* l1,lista* l2){
    no *p1 = l1->inicial;
    no *p2 = l2->inicial;
    lista* nova = init();

    while(p1!=NULL && p2!=NULL){
        inserir(nova,p1->info);
        inserir(nova,p2->info);
        p1 = p1->prox;
        p2 = p2->prox;

    }
    if(p2==NULL){
        while(p1!=NULL){
            inserir(nova,p1->info);
            p1=p1->prox;
        }
    }

    if(p1==NULL){
        while(p2!=NULL){
            inserir(nova,p2->info);
            p2=p2->prox;
        }
    }
    return nova;

}

int main()
{
    lista* l1 = init();
    lista* l2 = init();
    inserir(l1,9);
    inserir(l1,3);
    inserir(l1,2);
    inserir(l2,8);
    inserir(l2,5);
    inserir(l2,4);
    printf("L1:\n");
    print(l1);
    printf("L2:\n");
    print(l2);
    printf("Lista Merge:\n");
    print(merge(l1,l2));
    printf("Lista Ordenada:\n");
    print(selectionSort(merge(l1,l2)));

    return 0;
}
