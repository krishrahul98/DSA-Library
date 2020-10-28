// Heap Sort Implementation - C++
#include <iostream>

using namespace std;

void heapify(int data[], int size, int pos)
{
    // Indexes for left and right children
    int iLargest = pos;
    int iLeft = pos * 2 + 1;
    int iRight = pos * 2 + 2;

    // Check if a left child exists and if it has a larger value
    if (iLeft < size && data[iLeft] > data[iLargest])
        iLargest = iLeft;

    if (iRight < size && data[iRight] > data[iLargest])
        iLargest = iRight;

    // Swap values if the root is not the largest
    if (iLargest != pos)
    {
        swap(data[pos], data[iLargest]);
        heapify(data, size, iLargest);
    }
}

int* heapSort(int data[], int size)
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; --i)
        heapify(data, size, i);

    // Begin sorting
    for (int i = size - 1; i >= 0; --i)
    {
        // Swap first (largest) element to last available position
        swap(data[0], data[i]);

        // Set index 0 to largest available value
        heapify(data, i, 0);
    }

    return data;
}

int main()
{
    int* values;
    int size;

    // Get size of array
    cout << "Enter the number of elements: ";
    cin >> size;
    values = new int[size];

    // Get elements to sort
    cout << "Enter the values to be sorted:" << endl;
    for (int i = 0; i < size; ++i)
    {
        cout << "[" << i << "]>>> ";
        cin >> values[i];
    }
    cout << endl;

    // Sort array
    values = heapSort(values, size);

    // Print sorted array
    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; ++i)
        cout << values[i] << " ";

    cout << endl;
}
