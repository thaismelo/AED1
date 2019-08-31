void merge(int vetor[], int inicio, int fim){
    int tamanho,i=0,k;
    int meio = (inicio+fim)/2;
    tamanho = fim-inicio+1;
    int primeiroV = inicio;
    int segundoV= meio+1;
    int * vetorFinal = (int)malloc(sizeof(int)*tamanho);

    while(primeiroV<=meio || segundoV<=fim){
        if(primeiroV>meio){
            vetorFinal[i]=vetor[segundoV];
            segundoV++;
        }else if(segundoV>fim){
            vetorFinal[i]= vetor[primeiroV];
            primeiroV++;

        }else if(vetor[primeiroV]<vetor[segundoV]){
            vetorFinal[i] = vetor[primeiroV];
            primeiroV++;
        }else{
            vetorFinal[i] = vetor[segundoV];
            segundoV++;
        }
        i++;
    }

    for(k=inicio;k<fim+1;k++){
        vetor[k] = vetorFinal[k-inicio];
    }

    free(vetorFinal);

}

void mergeSort(int vetor[], int inicio,int fim){
    int meio = (fim+inicio)/2;
    if(inicio<fim){
        mergeSort(vetor,inicio,meio);
        mergeSort(vetor,meio+1,fim);
        merge(vetor,inicio,fim);
    }
}
