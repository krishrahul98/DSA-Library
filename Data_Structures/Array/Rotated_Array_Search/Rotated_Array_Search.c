#include <stdio.h>

// returns the position of the element 
int search(int[] array, int length, int target) {
    
    // base case
    if(array == null || length == 0) {
        return -1;
    }
    
    // binary search logic
    int startIndex = 0, endIndex = length-1;
    while(startIndex < endIndex) {
        int mid = (startIndex+endIndex)/2;
        if(array[mid] > array[endIndex]) {
            startIndex = mid+1;
        } else {
            endIndex = mid;
        }
    }
    
    int temp = startIndex;
    startIndex = 0;
    endIndex = length-1;
    
    // match with target
    if(target >= array[temp] && target <= array[endIndex]) {
        startIndex = temp;
    } else {
        endIndex = temp;
    }
    
    // find the index
    int ans = -1;
    while(startIndex <= endIndex) {
        int mid = (startIndex+endIndex)/2;
        if(array[mid] == target) {
            ans = mid;
            break;
        } else if(array[mid] < target) {
            startIndex = mid+1;
        } else {
            endIndex = mid-1;
        }
    }
    
    return ans;
}


// main
int main()
{
    int length;
    printf("Enter the size of the array:-\n");
    scanf("%d", &length);
    printf("Enter the elements of the array in reverse sorted order:-\n");
    int array[];
    for (int i = 0; i < length; i++) {
        scanf("%d", &array[i]);
    }
    int searched;
    printf("Enter the element to be searched in the array:-\n");
    scanf("%d", &searched);
    int finalIndex = search(array, length, searched);
    if(finalIndex >= 0) {
        printf("Element %d found at %dth position\n", searched, (finalIndex + 1));
    } else {
        printf("Element %d NOT FOUND\n", searched);
    }
    
    return 0;
}
