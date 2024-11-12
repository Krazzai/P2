#include <stdio.h>

//insertion sort
void insertionSort(int v[], int tam){
    for(int i=1; i<tam; ++i){
        int temp= v[i];
        int j=i-1;
        while(j>=0 && temp<v[j]){
            v[j+1]=v[j];
            --j;
        }
        v[j+1]=temp;
    }
}

//selection sort

void selectionSort(int v[], int tam){
    for(int i=0;i<tam-1;++i){
        int menor=1;
        for(int j=i+1;j<tam;++j){
            if(v[j]<v[menor]){
                menor=j;
            }
        }
        int aux=v[i];
        v[i]=v[menor];
        v[menor]=aux;
    }
}

//bubble sort

void bubbleSort(int v[],int tam){
    for(int r=1;r<tam;++r){
        for(int i=0;i<i<tam-1-r;++1){
            if(v[i]>v[i+1]){
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;               
            }
        }
    }
}