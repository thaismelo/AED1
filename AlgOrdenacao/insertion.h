int * insertionSort(int c[],int n){
    int flag,i,j,aux;

    for(i=0;i<n-1;i++){
        flag = i;
        for(j=i+1;j>0;j--){
            if(c[flag]>c[j]){
                aux = c[flag];
                c[flag]=c[j];
                c[j] = aux;
            }else{
                break;
            }
            flag-=1;
        }
    }
    return c;
}
