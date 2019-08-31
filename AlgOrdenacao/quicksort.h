int partition(int v[],int inicio, int fim){

    int pivo = v[fim];
    int j;
    int i = inicio-1;
    int temp = 0;
    for(j=inicio; j<fim;j++){
        if(v[j]<=pivo){
            i = i+1;
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    temp = v[i+1];
    v[i+1] = v[fim];
    v[fim] = temp;
    return i+1;
}

void quicksort(int v[],int inicio,int fim){
    int q;
    if(inicio<fim){
        q = partition(v,inicio,fim);
        quicksort(v,inicio,q-1);
        quicksort(v,q+1,fim);
    }
}
