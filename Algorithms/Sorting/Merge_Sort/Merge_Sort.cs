using System;
class Merge_Sort
{
    // Merges two subarrays of []array.
    // First subarray is array[leftLimit..mid]
    // Second subarray is array[mid+1..rightLimit]
    void merge (int[]array, int leftLimit, int mid, int rightLimit)
    {
        // Find sizes of two 
        // subarrays to be merged
        int num1 = mid - leftLimit + 1;
        int num2 = rightLimit - mid;
        
        // Create temp arrays
        int[] L = new int[num1];
        int[] R = new int[num2];
        int i, j;
        
        // Copy data to temp arrays
        for (i = 0; i < num1; ++i) {
            L[i] = array[leftLimit + i];
        }
        for (j = 0; j < num2; ++j) {
            R[j] = array[mid + 1 + j];
        }
        
        // Merge the temp arrays
        
        // Initial indexes of first 
        // and second subarrays
        i = 0;
        j = 0;
        
        // Initial index of merged 
        // subarry array
        int k = leftLimit;
        while (i < num1 && j < num2)
        {
            if (L[i] <= R[j])
            {
                array[k] = L[i];
                i++;
            }
            else
            {
                array[k] = R[j];
                j++;
            }
            k++;
        }
        
        // Copy remaining elements 
        // of L[] if any 
        while (i < num1)
        {
            array[k] = L[i];
            i++;
            k++;
        }
        
        // Copy remaining elements 
        // of R[] if any 
        while (j < num2)
        {
            array[k] = R[j];
            j++;
            k++;
        }
    }
    
    // Main function that 
    // sorts array[leftLimit..rightLimit] using
    // merge()
    void sort (int[]array, int leftLimit, int rightLimit)
    {
        if (leftLimit < rightLimit)
        {
            // Find the middle 
            // point
            int mid = (leftLimit + rightLimit) / 2;
            
            // Sort first and 
            // second halves
            sort (array, leftLimit, mid);
            sort (array, mid + 1, rightLimit);
            
            // Merge the sorted halves
            merge (array, leftLimit, mid, rightLimit);
        }
    }
    
    // A utility function to 
    // print array of size n 
    static void printArray(int[]array)
    {
        int n = array.Length;
        for (int i = 0; i < n; ++i) {
            Console.Write(array[i] + " ");
        }
        Console.WriteLine();
    }
    
    // main
    public static void Main (String[]args)
    {
        Random r = new Random();
        int arrSize = r.Next(10,15);
        Console.WriteLine ("Array Size = {0}, enter your array elements", arrSize);
        int[] array = new int[arrSize];
        for(int i=0; i<arrSize; i++)  
        {  
    	    array[i] = Convert.ToInt32(Console.ReadLine());  		
        }
        Console.WriteLine ("Given Array");
        printArray(array);
        Merge_Sort ob = new Merge_Sort();
        ob.sort(array, 0, array.Length - 1);
        Console.WriteLine("\nSorted array");
        printArray(array);
    }
}
