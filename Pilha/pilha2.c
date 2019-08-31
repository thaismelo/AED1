#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* proximo;
}no;

typedef struct pilha{
    struct no* topo;
}pilha;

pilha* inicializa(){
    pilha* pilha = (pilha*)malloc(sizeof(pilha));
    pilha->topo = NULL;
    return pilha;
}


void push(pilha* pilhaInicializada, int valor){
    no* noDaPilha = (no*)malloc(sizeof(no));
    noDaPilha->info = valor;

    if(pilhaInicializada==NULL){
        pilhaInicializada->topo = noDaPilha;
        noDaPilha->proximo = NULL;
    }else{
        no* ultimo = pilhaInicializada->topo;
        pilhaInicializada->topo = valor;
        noDaPilha->proximo = ultimo;

    }

}

void pop(pilha* pilhaList,int valor){
    no* cursor = pilhaList->topo;
    while(cursor!= valor){
        cursor = cursor->proximo;
        pilhaList->topo->info = cursor->proximo->info;
    }
}

void imprimir(pilha* pilha){
  no* cursor;
  for(cursor=pilha->topo;cursor!=NULL;cursor= cursor->proximo){
      printf("%d\n", cursor->info);
  }
}

int main(){

    pilha* pilha = inicializa();
    push(pilha,1)
    push(pilha,2)
    push(pilha,3)
    imprimir(pilha);
    pop(pilha,2);


return 0;
}
