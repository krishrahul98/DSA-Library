#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void printArray(int* array, int size) {
  printf("[");
  for (int i = 0; i < size; i += 1) {
    if (i > 0) {
      printf(", ");
    }
    printf("%d", array[i]);

  }
  printf("]\n");
}

void swap(int* lhs, int* rhs) {
  int tmp = *lhs;
  *lhs = *rhs;
  *rhs = tmp;
}

int partition(int* array, int low, int high, int pivotIndex, int n) {
  int pivotValue = array[pivotIndex];
  swap(&array[pivotIndex], &array[high]);
  int storeIndex = low;
  // Move all elements small than the pivot to the left
  for (int i = low; i < high; i += 1) {
    if (array[i] < pivotValue) {
      swap(&array[storeIndex], &array[i]);
      storeIndex += 1;
    }
  }
  // Move all elements equal to the pivot
  int storeIndexEq = storeIndex;
  for (int i = storeIndex; i < high; i += 1) {
    if (array[i] == pivotValue) {
      swap(&array[storeIndexEq], &array[i]);
      storeIndexEq += 1;
    }
  }
  // Move pivot to its final place
  swap(&array[high], &array[storeIndexEq]);
  if (n < storeIndex) {
    // n is in the group of smaller elements
    return storeIndex;
  } else if (n <= storeIndexEq) {
    // n is in the group equal to the pivot
    return n;
  } else {
    // in the the group of larger elements
    return storeIndexEq;
  }
}

int partitionK(int* array, int low, int high) {
  int i = low + 1;
  while (i <= high) {
    for (int j = i; j > low && array[j - 1] > array[j]; j -= 1) {
      swap(&array[j - 1], &array[j]);
    }
    i += 1;
  }
  return (low + high) / 2;
}

// Pre-declaration because of the mutual recursion between medianOfMedian and pivot
int medianOfMedian(int*, int, int, int);

int pivot(int* array, int low, int high) {
  if (high - low < 5) {
    return partitionK(array, low, high);
  } else {
    for (int i = low; i <= high; i += 5) {
      int innerHigh = MIN(i + 4, high);
      int median5 = partitionK(array, i, innerHigh);
      swap(&array[median5], &array[low + (i - low) / 5]);
    }
    int nextHigh = low + (high - low) / 5;
    int mid = (high - low) / 10 + low + 1;
    return medianOfMedian(array, low, nextHigh, mid);
  }
}

int medianOfMedian(int* array, int low, int high, int n) {
  for (;;) {
    if (low == high) {
      return low;
    }
    int pivotIndex = pivot(array, low, high);
    pivotIndex = partition(array, low, high, pivotIndex, n);
    if (n == pivotIndex) {
      return n;
    } else if (n < pivotIndex) {
      high = pivotIndex - 1;
    } else {
      low = pivotIndex + 1;
    }
  }
}

void example(int* array, int size, int n) {
  // Create a copy as the array will be mutated
  int byteSize = size * sizeof(array[0]);
  int* copy = (int*) malloc(byteSize);
  memcpy(copy, array, byteSize);

  // Decrement n because the algorithm is 0-based but we speak of n-th in 
  // a 1-based language
  int position = medianOfMedian(copy, 0, size, n + 1);

  printf("%dth smallest element [%d] = %d\n", n, position, copy[position]);

  free(copy);
}

int main() {
  int array[] = {
    1, 55, 3, 45, 8,
    6, 35, 24, 0, 9,
    1334, 8};
  int size = sizeof(array) / sizeof(array[0]);
  printf("Sorting array of size %d with elements:\n", size);
  printArray(array, size);

  example(array, size, 5);
  example(array, size, 1);
  example(array, size, size - 3);

  return 0;
}

