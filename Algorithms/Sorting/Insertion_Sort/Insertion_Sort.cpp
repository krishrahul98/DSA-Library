// Ascending order
// Insertion Sort

#include <bits/stdc++.h>

using namespace std;

void insertion_sort(int arr[], int l);
int main()
{
	int n;
    cout<<"Enter number of elements: ";
	cin>>n;
	int arr[n], i, l;
	cout<<"\nEnter the elements of array: ";
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"\nThe given array is : "<<endl;
	for(i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	insertion_sort(arr, n);
	cout<<"\n\n\n The sorted array is : "<<endl;
	for(i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}

    return 0;
}

void insertion_sort(int arr[], int l)
{
	int i, j, current;
	for(i=1; i<l; i++)
	{
		current = arr[i];
		j = i;
		
		while(j>0 && current<arr[j-1])
		{
			arr[j] = arr[j-1];
			arr[j-1] = current;
			j--;
		}
	}
	
}

