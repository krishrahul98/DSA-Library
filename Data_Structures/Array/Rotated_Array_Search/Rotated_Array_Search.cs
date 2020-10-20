using System;

namespace DataStructures
{
    public class RotatedArraySearch
    {
        // Returns index if target found, -1 if not found
        public static int Search(int[] arr, int target)
        {
            // preliminary check
            if (arr == null || arr.Length == 0)
            {
                return -1;
            }


            int left = 0, right = arr.Length - 1;

            // first determine the point at which sorted array is rotated
            // based on a binary search-like approach
            while (left < right)
            {
                int midp = left + (right - left) / 2;

                if (arr[midp] > arr[right])
                {
                    left = midp + 1;
                }
                else
                {
                    right = midp;
                }
            }

            int limit = left;
            left = 0;
            right = arr.Length - 1;

            // now we know from what point the main arr is sorted
            // so we can set the limits on a subarray in which to search
            if (target >= arr[limit] && target <= arr[right])
            {
                left = limit;
            }
            else
            {
                right = limit;
            }

            int idx = -1;

            // now a normal binary search on the subarray
            while (left <= right)
            {
                int midp = left + (right - left) / 2;

                if (arr[midp] == target)
                {
                    idx = midp;
                    break;
                }
                else if (arr[midp] < target)
                {
                    left = midp + 1;
                }
                else
                {
                    right = midp - 1;
                }
            }

            return idx;
        }

        public static void Main(String[] args)
        {
            Console.WriteLine("Enter the size of the array: ");
            int n = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Enter the sorted rotated array: ");
            int[] arr = new int[n];

            for (int i = 0; i < n; i++)
            {
                arr[i] = Convert.ToInt32(Console.ReadLine());
            }

            Console.WriteLine("Enter the element to be searched: ");
            int target = Convert.ToInt32(Console.ReadLine());

            int idx = Search(arr, target);

            if (idx == -1)
            {
                Console.WriteLine("Element not found in the array!");
            }
            else
            {
                Console.WriteLine("Element found at index: " + idx);
            }
        }

    }
}
