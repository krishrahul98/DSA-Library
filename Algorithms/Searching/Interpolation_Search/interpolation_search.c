#include<stdio.h> 
  
// If x is present in arr[0..n-1], then returns it's index, else returns -1. 
int interpolationSearch(int arr[], int n, int x) 
{ 
    // Find indexes of two corners 
    int lowerLimit = 0, higherLimit = (n - 1); 
  
    // Since array is sorted, an element present in array must be in range defined by corner 
    while (lowerLimit <= higherLimit && x >= arr[lowerLimit] && x <= arr[higherLimit]) 
    { 
        if (lowerLimit == higherLimit){ 
            if (arr[lowerLimit] == x) return lowerLimit; 
            return -1; 
        } 
        // Probing the position with keeping uniform distribution in mind. 
        int pos = lowerLimit + (((double)(higherLimit-lowerLimit) / 
              (arr[higherLimit]-arr[lowerLimit]))*(x - arr[lowerLimit])); 
  
        // Condition of target found 
        if (arr[pos] == x) 
            return pos; 
  
        // If x is larger, x is in upper part 
        if (arr[pos] < x) 
            lowerLimit = pos + 1; 
  
        // If x is smaller, x is in the lower part 
        else
            higherLimit = pos - 1; 
    } 
    return -1; 
} 
  
// main 
int main() 
{
    int n;
    scanf("%d", &n); // size of array
    
    // Array of items on which search will be conducted. 
    int arr[n]; 
    for(int i=0; i<n; i++) {
        scanf("%d", (arr + i));
    }

  
    int x; // Element to be searched 
    scanf("%d", &x);
    
    
    int index = interpolationSearch(arr, n, x); 
  
    // If element was found 
    if (index != -1) 
        printf("Element %d found at index %d", x, index); 
    else
        printf("Element %d not found.", x); 
    return 0; 
} 
