//Complexity Analysis of this approach

//Time Complexity: O(n^2), Two nested loops are needed to traverse the array from start to end so the Time complexity is O(n^2)
//Space Complexity:O(1), No extra space is required.

// C++ program to Count Inversions
// in an array
#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)
{
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				inv_count++;

	return inv_count; // return total number of inversions
}

int main()
{
	int n;
	cin >> n; // i/p size of array
	int arr[n]; // array declaration of size n
	for(int i=0;i<n;i++){
		cin >> arr[i]; 
	}
	cout << " Number of inversions are " << getInvCount(arr, n); // function calling -> (getInvCount(arr,n))
	return 0;
}



