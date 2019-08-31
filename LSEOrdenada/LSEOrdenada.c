
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
  no* aux;
  no* ant;
  no* novoNo = (no*) malloc(sizeof(no));
  novoNo->info = inteiro; //no que vai receber o inteiro e ser adicionado na lista
  no* primeiroTemp;
  if(lista->inicial==NULL){
      lista->inicial = novoNo; //adiciona o primeiro elemento
      novoNo->prox = NULL;
  }else if(novoNo->info < lista->inicial->info){//adiciona elemento se for menor que a cabeça da lista
      primeiroTemp = lista->inicial;//guarda o no inicial da lista
      lista->inicial = novoNo;// sobrescrevi o no inicial da lista
      novoNo->prox = primeiroTemp;//atualiza o prox do novoNo inicial da lista
  }else{
       aux = lista->inicial;//cabeca
      while(aux->prox != NULL && aux->info <= novoNo->info){ //quer dizer que ele é o maior e tem que ser adicionado no final
          ant = aux;
          aux = aux->prox;
      }
      //final
      if(aux->info < novoNo->info){
          aux->prox = (no*)malloc(sizeof(no));//quando sair do while isso eh nulo, por isso aloca
          aux = aux->prox;
          aux->info = novoNo->info;
          aux->prox = NULL;
      }
      //no meio
      else{
          ant->prox = (no*)malloc(sizeof(no));
          ant = ant->prox;
          ant->info = novoNo->info;
          ant->prox = aux;
      }
   }
   aux = NULL;
   aux = ant;
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

  inserir(lista,-2);
  inserir(lista,3);
  inserir(lista,5);
  inserir(lista,4);
  inserir(lista,8);
  inserir(lista,6);
  inserir(lista,7);
  inserir(lista,100);
  inserir(lista,9);
  inserir(lista,10);
  inserir(lista,-1);
  inserir(lista,0);
  inserir(lista,90);
  inserir(lista,120);
  inserir(lista,80);

  imprimir(lista);
  return 0;

}
