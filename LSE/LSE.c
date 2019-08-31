#include <stdio.h>
#include <stdlib.h>


typedef struct no{
    int info;
    struct no* prox;
}no;

typedef struct lista{
    struct no* inicial;

}lista;


lista* inicializar(){
    lista* nova = (lista*) malloc(sizeof(lista));
    nova->inicial=NULL;
    return nova;
}

void inserir(lista* lista, int inteiro){
    no* novoNo = (no*) malloc(sizeof(no));
    novoNo->info = inteiro; //no que vai receber o inteiro e ser adicionado na lista
    if(lista->inicial==NULL){
        lista->inicial = novoNo; //adiciona o primeiro elemento
        novoNo->prox = NULL;
    }else{
        no* cursor = lista->inicial;
        while(cursor->prox!=NULL){
            cursor = cursor->prox;
        }
        novoNo->prox = NULL; // vai ser o ultimo da lista
        cursor->prox = novoNo;

    }
}

void imprimir(lista* lista){
    no* cursor;
    for(cursor=lista->inicial;cursor!=NULL;cursor= cursor->prox){
        printf("%d\n", cursor->info);
    }
}

int main(){

    int inteiro,n;
    lista* lista = inicializar();
    inserir(lista,1);
    inserir(lista,2);
    inserir(lista,3);
    inserir(lista,4);
    inserir(lista,5);
    imprimir(lista);
    return 0;

