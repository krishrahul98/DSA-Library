#include<stdio.h> 
#include<time.h>
#include<stdlib.h>
  
// A utility function to swap two elements 
void swap(int* first, int* second) 
{ 
    int t = *first; 
    *first = *second; 
    *second = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int array[], int low, int high) 
{ 
    int pivot = array[high];    // pivot 
    int small_index = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (array[j] < pivot) 
        { 
            small_index++;    // increment index of smaller element 
            swap(&array[small_index], &array[j]); 
        } 
    } 
    swap(&array[small_index + 1], &array[high]); 
    return (small_index + 1); 
} 

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int array[], int low, int high)
{
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);
 
    // Swap A[random] with A[high]
    swap(&array[random], &array[high]);
 
    return partition(array, low, high);
}
  
/* The main function that implements QuickSort 
 array[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int array[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, array[p] is now 
           at right place */
        int pi = partition_r(array, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(array, low, pi - 1); 
        quickSort(array, pi + 1, high); 
    } 
} 
  
/* Function to print an array */
void print_array(int array[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", array[i]); 
    printf("\n"); 
} 
  
// main
int main() 
{ 
    int n;
    printf("Size of array: \n"); 
    scanf("%d", &n); //  size of array
    int array[n]; 
    printf("Enter array elements: \n"); 
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    quickSort(array, 0, n-1); 
    printf("Sorted array: \n"); 
    print_array(array, n); 
    return 0; 
} 
