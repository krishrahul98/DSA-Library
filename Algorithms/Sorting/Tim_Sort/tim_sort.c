#include <stdio.h>

void insertion_sort(int* array, int size) {
    for(int i = 0; i < size; i++) {
        int currentElement = array[i];
        int j = i -1;
        while(j > 0 && array[j] > currentElement) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = currentElement;
    }
}


int main() {
    int array[5] = {2, 3, 1, 10, 4};
    int n = sizeof(array) / sizeof(int);

    printf("Before sorting the elements in the array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ",array[i]);
    }
        printf("\n");

    insertion_sort(array, n);

    printf("After sorting the array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ",array[i]);
    }
        printf("\n");
}
