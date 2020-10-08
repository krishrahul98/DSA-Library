#include<bits/stdc++.h>

using namespace std;

int partition(int arr[], int low, int high) 
{
    int temp;
    int pivot = arr[high]; // assuming last element of the array as the pivot element
    int i = (low - 1); // assuming the index of i pointer as one position less than the first element 
    for (int j = low; j <= high - 1; j++) // assuming the index of j pointer as the first position
    { 

        // If current element is smaller than or equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++; // increment index of i pointer and swap the elemets at index i and j
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } 
    } 

    // swapping the pivot (last) element and element at i + 1 index
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // returning the index of pivot element having lesser elements to the left and greater elements to the right
    return (i + 1); 
} 

void quick_sort(int arr[], int low, int high) 
{
    if (low < high) 
    { 

        // partitioning the single array into two sub-arrays 
        int pi = partition(arr, low, high); 

        // sorting the sub-arrays
        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high); 
    } 
} 

void print(int arr[], int n)
{
    cout<<"Array after sorting: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n, i;
    cout<<"Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout<<"Enter the elements of the array: \n";
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    print(arr, n);
}