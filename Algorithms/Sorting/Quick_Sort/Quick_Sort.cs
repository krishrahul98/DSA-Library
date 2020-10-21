/*
Example Output:

    Total Elements: 12
    Unsorted Array: 2, 4, 16, 27, 32, 6, 19, 31, 29, 18, 23, 41

    Sorting using Quick Sort.

    Sorted Array  : 2, 4, 6, 16, 18, 19, 23, 27, 29, 31, 32, 41

*/
using System;
using System.Linq;

namespace quicksort
{
    class Program
    {
        public static int Partition(int[] array, int left, int right)
        {
            int pivot = array[left];

            while (true)
            {
                while (array[left] < pivot) left++;
                while (array[right] > pivot) right--;

                if (left < right)
                {
                    if (array[left] == array[right]) return right;

                    int temp = array[left];
                    array[left] = array[right];
                    array[right] = temp;
                }
                else
                {
                    return right;
                }
            }
        }

        public static void QuickSort(int[] array, int left, int right)
        {
            if (left < right)
            {
                int pivot = Partition(array, left, right);
                if (pivot > 1) QuickSort(array, left, pivot - 1);
                if (pivot + 1 < right) QuickSort(array, pivot + 1, right);
            }

        }

        static void Main(string[] args)
        {
            Random rand = new Random();

            // create an array with a random number of elements between 10 and 20.
            // fill the array with randomly generated values between -5 and 50.
            int[] array = Enumerable.Range(-5, 50).OrderBy(r => rand.NextDouble()).Take(rand.Next(10, 20)).ToArray<int>();

            Console.WriteLine($"Total Elements: {array.Length}");
            Console.WriteLine($"Unsorted Array: {string.Join(", ", array)}");
            Console.WriteLine("\nSorting using Quick Sort.\n");

            QuickSort(array, 0, array.Length - 1);

            Console.WriteLine($"Sorted Array  : {string.Join(", ", array)}");
        }
    }
}
