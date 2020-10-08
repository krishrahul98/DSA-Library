/* Bubble Sort implemented by Sebastian Mossberg */
#include <iostream>

// This function swaps the the x value with the y value with a temp acting
// as a small placeholder.
void swap_value(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// This function sorts the given array with bubble sort
// first parameter is the array and second is the length of the array
void bubble_sort(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++)

        // The last i elements is already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap_value(&arr[j], &arr[j + 1]);
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);

    std::cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " " << std::endl;
    }
    return 0;
}