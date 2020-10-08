/* Merge Sort code contributed by Debarshi Mitra */

#include<iostream>
using namespace std;

/* MERGE FUNCTION-
This function merges two subarrays of the array arr[],
Subarrays have indices starting from arr[l..m] and arr[m+1..r]...
*/
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	i = 0;  
	j = 0;  
	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) { 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* 
This function divides the array into two subarrays and sort them individually
and them merges them...
this function calls itself using tail recursion...
*/
void merge_sort(int arr[], int l, int r) 
{ 
	if (l < r) { 
		int m = l + (r - l) / 2; 

		merge_sort(arr, l, m); 
		merge_sort(arr, m + 1, r); 

		merge(arr, l, m, r); 
	} 
} 

int main() 
{ 
	int n = 5; // Size of the array...

    // Elements of the array...
    int arr[] = {5,3,2,1,4}; 

	merge_sort(arr, 0, n-1); 

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
	
	return 0; 
} 
