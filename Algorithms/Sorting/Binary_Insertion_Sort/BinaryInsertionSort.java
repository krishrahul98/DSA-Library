import java.util.Arrays;
import java.util.Scanner;

public class BinaryInsertionSort {

        // Main function
        public static void main (String[] args) {
            Scanner inp = new Scanner(System.in);
            System.out.print("Enter the number of elements: ");
            int n = inp.nextInt();

            int[] Arr = new int[n];
            System.out.println("Enter n space-separated integers: ");
            for(int i = 0; i < n; ++i){
                Arr[i] = inp.nextInt();
            }
            inp.close();

            insertionSort(Arr, n);

            System.out.println("Sorted array:");
            System.out.println(Arrays.toString(Arr));
        }
        static int binarySearch(int A[], int target, int low, int high) {
            // Binary Search to find the correct position where target should be inserted
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (target == A[mid])       // if target matches an element in the sorted array
                    return mid + 1;    // then it is to be inserted at mid+1 (just after the matched element)
                else if (target > A[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            return low;
        }

        // Function to sort an array Arr[] of size 'n'
        static void insertionSort(int[] Arr, int n) {
            int i, j, selectedElement;

            for (i = 1; i < n; ++i) {
                j = i - 1;              // j represents the upper index of sorted part of array from beginning
                selectedElement = Arr[i];   // selectedElement is the element just after the wall,
                // i.e. first element from unsorted part of the array

                // finding the location where selectedElement is to be placed in sorted part (using BinarySearch O(log2N))
                int pos = binarySearch(Arr, selectedElement, 0, j);

                // shifting the elements to insert the selectedElement at desired index in sorted array
                while (j >= pos) {
                    Arr[j + 1] = Arr[j];
                    j--;
                }
                // insert the selectedElement at its right location in sorted part
                Arr[j + 1] = selectedElement;
            }
        }
}
