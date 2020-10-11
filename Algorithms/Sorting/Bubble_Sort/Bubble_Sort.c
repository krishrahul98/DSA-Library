// Bubble Sort Implementation in C


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZEOF_ARR(x) sizeof(x)/sizeof(x[0])

#define PRINT_ARR(n, x) for(int i=0;i<n;++i){printf("%d\n",x[i]);}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}


void bubble_sort(size_t size, int *arr) {
  while (size > 1) {
    int newn = 0;
    for (int i = 1; i <= size - 1; ++i) {
      if (arr[i-1] > arr[i]) {
        swap(&arr[i-1], &arr[i]);
        newn = i;
      }
    }
    size = newn;
  }
}



int main(void) {
  srand(time(NULL));

  size_t size;
  printf("Enter array size: ");
  scanf("%lu", &size);

  int rand_values[size];
  for (int i = 0; i < size; ++i) {
    rand_values[i]=rand()%100;
  }

  printf("Unsorted:\n");
  PRINT_ARR(size, rand_values);
  
  bubble_sort(size, rand_values);

  printf("\nSorted:\n");
  PRINT_ARR(size, rand_values);
}
