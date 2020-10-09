using System; 
  
class InsertionSort { 

    // Insertion Sort Function
    void insertion_sort(int[] arr) 
    { 
        int array_Length = arr.Length; 
        for (int i = 1; i < array_Length; ++i) { 
            int key = arr[i]; 
            int j = i - 1; 
            
            while (j >= 0 && arr[j] > key) { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key; 
        } 
    } 
    
    // Test Code 
    public static void Main() 
    { 
        //The Array That You Want To Sort
        int[] arr = { 9, 12, 11, 13, 5, 6, 99, 1, 2, 2, 4, 112, 44, 1}; 
        //Create Object To Call Function On
        InsertionSort obj = new InsertionSort(); 
        //Sort The Array
        obj.insertion_sort(arr); 
        //Prints Array
        Console.WriteLine(string.Join(" ", arr));
    } 
} 