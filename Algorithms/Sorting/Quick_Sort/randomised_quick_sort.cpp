#include <iostream>
#include<cstdlib>
using namespace std;

int partition(int arr[], int start, int end)
{

    int arr_range=end-start;
    int randomnum = rand()%arr_range + start;
    int p_index = start;
    int pivot = randomnum;
    //Swap last element and pivot element
    int temp=arr[pivot];
    arr[pivot]=arr[end];
    arr[end]=temp;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= arr[end])
        {
            // Swap arr[i] and arr[p_index]
            int temp = arr[i];
            arr[i] = arr[p_index];
            arr[p_index] = temp;
            p_index += 1;
        }
    }
    //swap arr[end] and arr[p_index]
    temp = arr[end];
    arr[end] = arr[p_index];
    arr[p_index] = temp;

    return p_index;
}

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int p_index = partition(arr, start, end);
    quick_sort(arr, start, p_index - 1);
    quick_sort(arr, p_index + 1, end);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}