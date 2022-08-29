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
    //Loop through the array while the item on the index i is lesser or equal to the end of the array
    for(int i = start; i <= end-1; i++){
        //If the item on index i is lesser or equal to the pivot(End of array) then increment on "index" and swap the element on index "i" with the element on index "index"
        if(array[i] <= pivot){
            index++;
            swap(&array[i], &array[index]);
         }
    }
    //When the loop is done, swap the pivot to the correct position on the array and return his index
    swap(&array[index + 1], &array[end]);//
    return (index + 1);
}


void quicksort(int array[], int start, int end){
    if(start < end){
        int pivot = partition(array, start, end);
        quicksort(array, start, pivot-1); //Verifica a parte esquerda
        quicksort(array, pivot+1, end); //Verifica a parte direita
    }
}

void printArray(int array[], int size){
    for(int i = 0; i < size-1; i++){
        printf("%d ", array[i]);
    }
}

int main(){
    int size = 25;
    int array[size];
    srand(time(NULL));
    for(int i=0; i<size-1; i++){
        array[i] = rand() % 100;
    }
    clock_t t;
    printf("Antes do quicksort: \n\n");
    printArray(array,size);

    printf("Depois do quicksort: \n\n");
    t = clock();
    quicksort(array, 0, size-1);
    t = clock() - t;

    printArray(array, size);

    //printf ("It took me %d clicks (%f seconds).\n",t,((double)t)/CLOCKS_PER_SEC);
    printf("\n\n");
}