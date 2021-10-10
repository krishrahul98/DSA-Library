#include <stdio.h>

/**
 * Runs a binary search of the value in the array to look for the position
 * where the item could be inserted.
 *
 * If the item is found, it returns the position at which it was found.
 * If the item is not present in the array, it returns a negative value
 * encoding the position at which the item should be inserted. The position is
 * encoded as `-1 - position`. It is easy to obtain that value using
 * `-1 - result`.
 */
int binarySearch(int* array, int size, int value) {
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int middleIndex = (low + high) / 2;
    int middleValue = array[middleIndex];

    if (middleValue < value) {
      low = middleIndex + 1;
    } else if (middleValue > value) {
      high = middleIndex - 1;
    } else {
      return middleIndex;
    }
  }
  return -(low + 1);
}

/**
 * Inserts the given value at the specified position, shifting the elements
 * coming after .
 *
 * @param size size of the array, including the value to move.
 */
void insertAt(int* array, int size, int position, int value) {
  for (int i = size - 1; i > position; i -= 1) {
    array[i] = array[i - 1];
  }
  array[position] = value;
}

/**
 * Runs insertion sort with a binary search in-place on the provided array.
 */
void insertionSort(int* array, int size) {
  for (int i = 1; i < size; i += 1) {
    int value = array[i];
    int position = binarySearch(array, i, value);
    if (position < 0) {
      int at = -position - 1;
      insertAt(array, i + 1, at, value);
    } else {
      // The item is already present, just insert the current item after the identical item
      insertAt(array, i + 1, position + 1, value);
    }
  }
}

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

int main() {
  int array[] = {1, 55, 3, 45, 8, 6, 35, 24, 0, 9, 1334, 8};
  int size = sizeof(array) / sizeof(array[0]);
  printf("Sorting array of size %d with elements:\n", size);
  printArray(array, size);

  insertionSort(array, size);

  printf("Sorted array:\n");
  printArray(array, size);

  return 0;
}
