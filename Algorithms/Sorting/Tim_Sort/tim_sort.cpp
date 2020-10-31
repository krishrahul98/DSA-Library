#include <bits/stdc++.h>
#define RUN 32

void insertion_sort(int array[], int start_idx, int end_idx) {
    for(int i = start_idx; i <= end_idx; i++) {
        int currentElement = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > currentElement) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentElement;
    }
}

void merge_runs(int array[], int start, int mid, int end) {  
    int first_array_size = mid - start + 1, second_array_size = end - mid;  
    int array1[first_array_size], array2[second_array_size];  
    int i = 0, j = 0, k = 0;

    // Building the two sub arrays from the array to merge later
    for (int i = 0; i < first_array_size; i++)  array1[i] = array[start + i];  
    for (i = 0; i < second_array_size; i++)  array2[i] = array[mid + 1 + i];  
   
    i = 0;
    j = 0;
    k = start;  
   
    while (i < first_array_size && j < second_array_size) {
        if (array1[i] <= array2[j])  { 
            array[k] = array1[i];  
            i++;  
        }
        else {
            array[k] = array2[j];
            j++;  
        }  
        k++;
    }

    while (i < first_array_size) {  
        array[k] = array1[i];  
        k++;
        i++;
    }  
   
    while (j < second_array_size) {  
        array[k] = array2[j];
        k++;
        j++;
    }  
}


int min(int num1, int num2) {
    return (num1 > num2 ? num2 : num1);
}

void algorithm(int arr[], int array_size) {
    // Applying insertion sort on RUNS.
    for(int i = 0; i < array_size; i+=RUN) insertion_sort(arr, i, min(i + RUN, (array_size - 1)));

    for (int split = RUN; split < array_size; split = 2*split) {  
        for (int start_idx = 0; start_idx < array_size; start_idx += 2*split){  
            int mid = start_idx + split - 1;  
            int end_idx = min((start_idx + 2*split - 1), (array_size-1));  

            merge_runs(arr, start_idx, mid, end_idx);  
        }
    }
}

int main() {
int array[] = {130, 473, 267, 3, 540, 406, 994, 750, 569, 107, 501, 490, 781, 232, 245, 964, 458, 841, 826, 110, 511, 994, 235, 27, 189, 112, 284, 832, 743, 903, 880, 379, 704, 159, 91, 782, 45, 810, 554
    , 32, 886, 784, 415, 22, 255, 50, 232, 151, 436, 169, 771, 458, 950, 974, 342, 972, 534, 383, 148, 988};

    int s1 = sizeof(array) / sizeof(int);
    algorithm(array, s1);
    printf("After sorting...\n");
    for(int i = 0; i < s1; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
