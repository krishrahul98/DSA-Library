#include <stdio.h>

int countSort(int array[], int size) {
  int result[100];
int i;
  int max = array[0];
  for (i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  //Finding the count of each element in array
  int c[max];
  for (i = 0; i <= max; ++i) {
    c[i] = 0;
  }
  for (i = 0; i < size; i++) {
    c[array[i]]++;
  }
// code for changing the count array such that each element at each index stores the sum of previous counts. 
  for (i = 1; i <= max; i++) {
    c[i] += c[i - 1];
  }
  
 
//Sorting the elements of array based on count 
  for (i = size - 1; i >= 0; i--) {
    result[c[array[i]] - 1] = array[i];
    c[array[i]]--;
  }

  for (i = 0; i < size; i++) {
    array[i] = result[i];
  }
  
  for (i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
  
}


int main() {
  int i,n;
  printf("enter number of elements:");
  scanf("%d",&n);
  int arr[n];
  printf("enter array elements:");
  for (i=0;i<n;i++)
  {
  	scanf("%d",&arr[i]);
  }
  int n1 = sizeof(arr) / sizeof(arr[0]);
  countSort(arr, n1);
 
}
