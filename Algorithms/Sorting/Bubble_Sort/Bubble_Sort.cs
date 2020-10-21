/*
Example Output:

    Total Elements: 10
    Unsorted Array: 5, -4, -10, 13, 11, 8, -7, 13, -15, 1

    Sorting using Bubble sort.

    Sorted Array  : -15, -10, -7, -4, 1, 5, 8, 11, 13, 13

*/
using System;
using System.Linq;

namespace BubbleSort
{
    class Program
    {
        public static int[] BubbleSort(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
                for (int j = 0; j < (array.Length - i - 1); j++)
                    if (array[j] > array[j + 1])
                    {
                        int tmp = array[j];
                        array[j] = array[j+1];
                        array[j+1] = tmp;
                    }

            return array;
        }
        static void Main(string[] args)
        {
            Random rand = new Random();

            // create an array with a random number of elements between 10 and 20.
            // fill the array with randomly generated values between -5 and 50.
            int[] array = Enumerable.Range(-5,50).OrderBy(r => rand.NextDouble()).Take(rand.Next(10, 20)).ToArray<int>();

            // fill the array with randomly generated values between -15 and 15.
            for (int i = 0; i < array.Length; i++) array[i] = rand.Next(-15, 15);
            Console.WriteLine($"Total Elements: {array.Length}");
            Console.WriteLine($"Unsorted Array: {string.Join(", ", array)}");
            Console.WriteLine("\nSorting using Bubble sort.\n");

            var sortedArray = BubbleSort(array);

            Console.WriteLine($"Sorted Array  : {string.Join(", ", array)}");
        }
    }
}
