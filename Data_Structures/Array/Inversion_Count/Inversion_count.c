#include <stdio.h> 
#include <stdlib.h> 

//function to count the number of inversions
int invC(int arr[], int n) 
{ 
    int inv_c = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_c++; 
  
    return inv_c; 
} 


int main() 
{ 
    int arr[] = { 1,9,2,8,3,7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    printf(" Number of inversions in the array are %d \n",invC(arr, n)); 
    return 0; 
} 
