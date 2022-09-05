#include <stdio.h>
#include <time.h>
 
int partition(int* arr, int low, int high, int* lp);
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void DualPivotQuickSort(int* arr, int low, int high)
{
    if (low < high) {
        // lp means left pivot, and rp means right pivot.
        int lp, rp;
        rp = partition(arr, low, high, &lp);
        DualPivotQuickSort(arr, low, lp - 1);
        DualPivotQuickSort(arr, lp + 1, rp - 1);
        DualPivotQuickSort(arr, rp + 1, high);
    }
}
 
int partition(int* arr, int low, int high, int* lp)
{
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high - 1, k = low + 1, p = arr[low], q = arr[high];
    while (k <= g) {
 
        // if elements are less than the left pivot
        if (arr[k] < p) {
            swap(&arr[k], &arr[j]);
            j++;
        }
 
        else if (arr[k] >= q) {
            while (arr[g] > q && k < g)
                g--;
            swap(&arr[k], &arr[g]);
            g--;
            if (arr[k] < p) {
                swap(&arr[k], &arr[j]);
                j++;
            }
        }
        k++;
    }
    j--;
    g++;
    swap(&arr[low], &arr[j]);
    swap(&arr[high], &arr[g]);
    *lp = j;
    return g;
}

void printArray(int array[], int size){
    for(int i = 0; i < size-1; i++){
        printf("%d ", array[i]);
    }
}
 
int main()
{
    int size = 500000;
    int arr[size];
    srand(time(NULL));
    for(int i=0; i<size-1; i++){
        arr[i] = rand() % 1000000;
    }
    clock_t t;
    t = clock();
    DualPivotQuickSort(arr, 0, size-1);
    t = clock() - t;
   printArray(arr, size-1);
    printf ("It took me %d clicks (%f seconds).\n",t,((double)t)/CLOCKS_PER_SEC);
    return 0;
}