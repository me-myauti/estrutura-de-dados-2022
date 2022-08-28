#include <stdio.h>
#include <time.h>

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int array[], int start, int end){
    int pivot = array[end];
    int index = (start - 1);
    for(int i = start; i <= end-1; i++){
        if(array[i] <= pivot){
            index++;
            swap(&array[i], &array[index]);
         }
    }
    swap(&array[index + 1], &array[end]);
    return (index + 1);
}


void quicksort(int array[], int start, int end){
    if(start < end){
        int pivot = partition(array, start, end);
        quicksort(array, start, pivot-1);
        quicksort(array, pivot+1, end);
    }
}

void printArray(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
}

int main(){
    int size = 500000;
    int array[size];
    srand(time(NULL));
    for(int i=0; i<size-1; i++){
        array[i] = rand() % 200000;
    }
    clock_t t;

    t = clock();
    quicksort(array, 0, size-1);
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((double)t)/CLOCKS_PER_SEC); //Contagem de clock não funciona caso o tempo de execucao pra essa parte do codigo for mto baixa

    printf("\n\n");
}