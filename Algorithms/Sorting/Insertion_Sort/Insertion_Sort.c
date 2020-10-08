// Ascending order
// Insertion Sort

#include <stdio.h>
#include <time.h>

void insertion_sort(int arr[], int l);
void main()
{
	int n;
	scanf("%d",&n);
	int arr[n], i, l;
	printf("\nEnter the elements of array: ")
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("\nThe given array is : \n");
	for(i=0; i<n; i++)
	{
		printf("%d  ", arr[i]);
	}
	insertion_sort(arr, n);
	printf("\n\n\n The sorted array is : \n");
	for(i=0; i<n; i++)
	{
		printf("%d  ", arr[i]);
	}
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
