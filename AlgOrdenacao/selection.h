int * selectionSort(int b[],int n){
    int i,z,menor;
    for(i=0;i<n;i++){
        for(z=i;z<n;z++){
            if(b[i] > b[z]){
                menor = b[i];
                b[i] = b[z];
                b[z] = menor;
            }
        }
    }
    return b;
}
