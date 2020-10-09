#include <stdio.h> 
int BinarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
        if (arr[m] == x) 
            return m; 
 
        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    } 
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = { 12, 3, 4, 15, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 15; 
    int result = BinarySearch(arr, 0, n - 1, x); 
   if(result==-1)
   {
   	printf("Element is not present in the array");
   }
   else
   {
   	 printf("Element is present at index %d",result);
   }
    return 0; 
} 

