// Sorting Algorithm - C++
#include <iostream>

using namespace std;

int main()
{
    int *array, *count, size;
    int max = 0;
    int last = 0;

    // Get data

    cout << "Enter the number of elements to sort: ";
    cin >> size;
    array = new int[size];

    cout << "Enter the integers (positive only) to be sorted: ";
    for (int i = 0; i < size; ++i)
    {
        cin >> array[i];

        if (array[i] < 0)
        {
            cout << "Entered a negative integer, taking the absolute value." << endl;
            array[i] = abs(array[i]);
        }

        if (array[i] > max)
            max = array[i];
    }

    // Sort
    ++max;
    count = new int[max];

    // Add one to corresponding array index
    for (int i = 0; i < size; ++i)
        count[array[i]] += 1;

    // Sum elements from left starting at index 1
    for (int i = 1; i < max; ++i)
        count[i] += count[i - 1];

    // Shift elements over to the right
    for (int i = max; i >= 0; --i)
        count[i] = count[i - 1];

    cout << endl;

    // Start sorting
    size = 0;
    for (int i = 0; i < max; ++i)
    {
        while (count[i] - count[i + 1] != 0)
        {
            array[size] = i;
            ++count[i];
            ++size;
        }
    }

    cout << "Sorted:" << endl;
    for (int i = 0; i < size; ++i)
        cout << array[i] << " ";

    cout << endl;
}
