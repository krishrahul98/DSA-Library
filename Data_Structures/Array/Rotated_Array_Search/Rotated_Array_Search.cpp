#include <stdio.h> 
using namespace std; 
  
int binarySearch(int arr[], int low, 
                 int high, int key) 
{ 
    if (high < low) 
        return -1; 
  
    int mid = low+ (high - low) / 2;
    
    if (key == arr[mid]) 
        return mid;
    else if (key > arr[mid]) 
        return binarySearch(arr, (mid + 1), high, key); 
    else 
    return binarySearch(arr, low, (mid - 1), key); 
} 
  
int findPosition(int arr[], int low, int high) 
{  
    if (high < low) 
        return -1; 
    if (high == low) 
        return low; 
  
   int mid = low+ (high - low) / 2;
    if (mid < high && arr[mid] > arr[mid + 1]) 
        return mid; 
  
    if (mid > low && arr[mid] < arr[mid - 1]) 
        return (mid - 1); 
  
    if (arr[low] >= arr[mid]) 
        return findPosition(arr, low, mid - 1); 
  
    return findPosition(arr, mid + 1, high); 
} 
  
int BinarySearchPosition(int arr[], int n, int key) 
{ 
    int pos = findPosition(arr, 0, n - 1); 
    if (pos == -1) 
        return binarySearch(arr, 0, n - 1, key); 
    else if (arr[pos] == key) 
        return pos; 
  
    if (arr[0] <= key) 
        return binarySearch(arr, 0, pos - 1, key); 
  
    return binarySearch(arr, pos + 1, n - 1, key); 
} 
int main() 
{ 
    // Let us search 3 in below array 
    int arr1[] = { 5, 6, 7, 1, 2, 3 }; 
    int n = sizeof(arr1) / sizeof(arr1[0]); 
    int key = 6; 
  
    cout << "Index of the element is : "
         <<BinarySearchPosition(arr1, n, key); 
  
    return 0; 
} 
