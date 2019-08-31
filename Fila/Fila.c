#include<stdio.h>
#include<stdlib.h>

typedef struct no{
   int info;
   struct no* ant;
}no;

typedef struct fila{
   struct no* inicio;
   struct no* fim;
}fila;
fila* init(){
   fila* fila = malloc(sizeof(fila));
   fila->inicio = NULL;
   fila->fim = NULL;
   return fila;
}
void insert(fila* fila,int num){
   no* novo = malloc(sizeof(no));
   novo->info = num;
   novo->ant = NULL;
   if(fila->inicio == NULL){
       fila->inicio = novo;
       fila->fim = novo;
   }else{
       fila->inicio->ant = novo;
       fila->inicio= novo;
   }
}
int remove_fila(fila* fila){
   if(fila->fim != NULL){
       no* temp = fila->fim;
       fila->fim = temp->ant;
       return temp->info;
   }
}

void imprimir(fila* fila){
    no* cursor = fila->fim;
    while(cursor->ant != NULL){
        printf("%d\n", cursor->info);
        cursor = cursor->ant;
    }
     printf("%d\n", cursor->info);
}
int main(){
   fila* fila = init();
   insert(fila,11);
   insert(fila,12);
   insert(fila,23);
   insert(fila,14);
   insert(fila,18);
   insert(fila,29);
   insert(fila,10);


   imprimir(fila);


}

