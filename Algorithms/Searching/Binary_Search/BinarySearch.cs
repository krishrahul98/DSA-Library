using System;

namespace Algorithms
{
    internal class BinarySearch
    {
        /// <summary>
        /// Performs a binary search for an element in a sorted list.
        /// </summary>
        /// <param name="arr">Array from which to search</param>
        /// <param name="element">Element to search</param>
        /// <returns>Index of element in the list if present, else -1</returns>
        public static int search(int[] arr, int x)
        {
            var l = 0;
            var r = arr.Length - 1;

            // Keep searching from both ends
            while (l <= r)
            {
                int mid = l + (r - l) / 2;

                if (arr[mid] == x)
                {
                    return mid;
                }

                if (arr[mid] < x)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }

            return -1;
        }

        public static void Main(string[] args)
        {
            int[] arr = { 1, 2, 3, 5 };
            int size = arr.Length;
            int element = 3;
            
            Console.WriteLine("Position of {0} in the list [{1}] is {2}",
                element, string.Join(", ", arr), search(arr, element));

            Console.ReadKey();
        }
    }
}
