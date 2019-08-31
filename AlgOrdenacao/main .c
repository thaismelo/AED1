#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bubble.h"
#include "insertion.h"
#include "selection.h"
#include "merge.h"
#include "quicksort.h"
int main()
{
    int p,n=300;
    for(p=0;p<3;p++){
        int i;
        printf("Execucao com %d\n",n);
        int a[n],b[n],c[n],d[n],e[n];

        for(i=0;i<n;i++){
            a[i] = rand()%10000;
            b[i] = a[i];
            c[i] = a[i];
            d[i] = a[i];
            e[i] = a[i];
        }
        time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);
        bubbleSort(a,n);
        time_t mytime2;
        mytime2 = time(NULL);
        struct tm tm2 = *localtime(&mytime2);
        printf("\nBubble Sort: %d:%d:%d\n", tm2.tm_hour-tm.tm_hour, tm2.tm_min-tm.tm_min, tm2.tm_sec-tm.tm_sec);

    //
        mytime = time(NULL);
        tm = *localtime(&mytime);
        insertionSort(b,n);
        mytime2 = time(NULL);
        tm2 = *localtime(&mytime2);
        printf("Insertion Sort: %d:%d:%d\n", tm2.tm_hour-tm.tm_hour, tm2.tm_min-tm.tm_min, tm2.tm_sec-tm.tm_sec);
    //
        mytime = time(NULL);
        tm = *localtime(&mytime);
        selectionSort(c,n);
        mytime2 = time(NULL);
        tm2 = *localtime(&mytime2);
        printf("Selection Sort: %d:%d:%d\n", tm2.tm_hour-tm.tm_hour, tm2.tm_min-tm.tm_min, tm2.tm_sec-tm.tm_sec);
    //
        mytime = time(NULL);
        tm = *localtime(&mytime);
        mergeSort(d,0,n-1);
        mytime2 = time(NULL);
        tm2 = *localtime(&mytime2);
        printf("Merge Sort: %d:%d:%d\n\n", tm2.tm_hour-tm.tm_hour, tm2.tm_min-tm.tm_min, tm2.tm_sec-tm.tm_sec);
    //

        mytime = time(NULL);
        tm = *localtime(&mytime);
        quicksort(e,0,n-1);
        mytime2 = time(NULL);
        tm2 = *localtime(&mytime2);
        printf("Quicksort: %d:%d:%d\n\n", tm2.tm_hour-tm.tm_hour, tm2.tm_min-tm.tm_min, tm2.tm_sec-tm.tm_sec);
        n = n*10;
    }

}
