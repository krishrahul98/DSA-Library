/*
Example Output:

    Total Elements: 12
    Unsorted Array: 7798, 612, 8358, 3961, 6782, 1505, 727, 955, 8394, 2586, 5203, 7633

    Sorting using Radix sort.


            Pass: 1  Exponent: 1    Array: 3961, 612, 6782, 5203, 7633, 8394, 1505, 955, 2586, 727, 7798, 8358

            Pass: 2  Exponent: 10    Array: 5203, 1505, 612, 727, 7633, 955, 8358, 3961, 6782, 2586, 8394, 7798

            Pass: 3  Exponent: 100    Array: 5203, 8358, 8394, 1505, 2586, 612, 7633, 727, 6782, 7798, 955, 3961

            Pass: 4  Exponent: 1000    Array: 612, 727, 955, 1505, 2586, 3961, 5203, 6782, 7633, 7798, 8358, 8394

    Final Sorted Array  : 612, 727, 955, 1505, 2586, 3961, 5203, 6782, 7633, 7798, 8358, 8394

*/
using System;
using System.Linq;

namespace Sort
{
    class Sort
    {
        public static void RadixSort(int[] array)
        {
            int length = array.Length;
            int max = array.Max();
            int pass= 1;

            for (int i = 1; max / i > 0; i *= 10)
            {
                Console.WriteLine($"");               
                CountingSort(array, length, i);
                Console.WriteLine($"\tPass: {pass++}  Exponent: {i}    Array: {string.Join(", ", array)}");                
            }
        }

        public static void CountingSort(int[] array, int length, int exponent)
        {
            int[] output = new int[length];
            int[] buckets = new int[10] { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // counting array

            for (int i = 0; i < length; i++)
            {
                buckets[(array[i] / exponent) % 10]++;
            }
            
            for(int i=1; i < 10; i++)
            {
                buckets[i] += buckets[i-1];
            }

            for(int i = length -1; i >=0; i--)
            {
                int newIndex = buckets[(array[i] / exponent) % 10]-1;
                output[newIndex] = array[i];
                buckets[(array[i] / exponent) % 10]--;
            }

            for(int i=0; i<length; i++) array[i] = output[i];
        }
        static void Main(string[] args)
        {
            Random rand = new Random();

            // create an array with a random number of elements between 10 and 20.
            // fill the array with randomly generated values between 10 and 9999.
            int[] array = Enumerable.Range(10, 9999).OrderBy(r => rand.NextDouble()).Take(rand.Next(10, 20)).ToArray<int>();
            
            Console.WriteLine();
            Console.WriteLine($"Total Elements: {array.Length}");
            Console.WriteLine($"Unsorted Array: {string.Join(", ", array)}");
            Console.WriteLine("\nSorting using Radix sort:");

            RadixSort(array);

            Console.WriteLine($"\nFinal Sorted Array  : {string.Join(", ", array)}");
        }
    }
}
