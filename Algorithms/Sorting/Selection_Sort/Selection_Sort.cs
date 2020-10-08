using System; 
  
class Selection_Sort 
{  
    static void sort(int []arr) 
    { 
        int n = arr.Length;
        for (int i = 0; i < n - 1; i++) 
        { 
            int min_index = i; 
            for (int j = i + 1; j < n; j++) 
                if (arr[j] < arr[min_index]) 
                    min_index = j;
            int temp = arr[min_index]; 
            arr[min_index] = arr[i]; 
            arr[i] = temp; 
        } 
    }

    static void printArray(int []arr) 
    { 
        int n = arr.Length; 
        for (int i=0; i<n; ++i) 
            Console.Write(arr[i]+" "); 
        Console.WriteLine(); 
    } 

    public static void Main() 
    { 
        Console.WriteLine("Enter array size : ");   
        int n = Convert.ToInt32(Console.ReadLine());
        int[] arr = new int[n]; 

        Console.WriteLine("Enter array elements : ");
        
        for(int i=0; i<n; i++){
            arr[i] = Convert.ToInt32(Console.ReadLine());
        } 
        sort(arr); 
        Console.WriteLine("Sorted array"); 
        printArray(arr); 
    } 
  
} 