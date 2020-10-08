#include <bits/stdc++.h>
using namespace std;

int main() {

    // Taking the length of the array
    int n;
    cin >> n;

    vector<int> arr(n);

    // Taking the array elements and storing it in arr.
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    // Printing the input array without sort
    cout << "Your unsorted array: ";    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }    
    cout << endl;

    make_heap(arr.begin(), arr.end()); // Building the heap from the array.
    sort_heap(arr.begin(), arr.end()); // Sorting the heap

    // Printing the sorted array
    cout << "Your sorted array: "; 
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
} 
