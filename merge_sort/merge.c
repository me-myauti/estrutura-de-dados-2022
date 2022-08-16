#include <stdio.h>

void merge_sort(int a[], int length);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);


int main(){
    int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = 10;

    merge_sort(array, length);

    for(int i = 0; i< length; i++){
        printf("%d", array[i]);
    }

    return 0;
}

void merge_sort(int a[], int length){
    merge_sort_recursion(a, 0, length - 1);
}

void merge_sort_recursion(int a[], int l, int r){
    if(l < r){
        int m = l + (r-l) / 2; // Defines the middle of the portion of the array
        merge_sort_recursion(a, l, m); // Call to the recursive function on the left portion
        merge_sort_recursion(a, m+1, r); // Call to the recursive function on the right portion
        
        merge_sorted_arrays(a, l, m, r); //Funtion to merge the arrays back
    }
}

void merge_sorted_arrays(int a[], int l, int m, int r){
    // l variable defines the left portion of the array
    //

    int left_length = m - l + 1;  // middle - left + 1 gives us the length of the left portion 
    int rigth_length = r - m; // right - middle gives us the length of the rigth portion

    //Creating two temporary arrays to store the two portions of the array
    int temp_left[left_length];
    int temp_right[rigth_length];

    int i, j, k;

    // Copying the items on the array on the position left + 1 (To get the items of the left portion)
    for(int i=0; i<left_length; i++){
        temp_left[i] = a[l+i];
    }

    // Copying the items on the array on the position middle + 1 + i (To get the items of the rigth portion)
    for(int i=0; i<rigth_length; i++){
        temp_right[i] = a[m+i+1];
    }
    


    //K will be the index of the array that we are sorting (the main one)
    for(i=0, j=0, k=l; k<=r; k++){

        if((i<left_length) && (j>=rigth_length || temp_left[i] <= temp_right[j])){
            a[k] = temp_left[i];
            i++;
        }else{
            a[k] = temp_right[j];
            j++;
        }
    }
}