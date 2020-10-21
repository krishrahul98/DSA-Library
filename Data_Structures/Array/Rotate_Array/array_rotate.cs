

using System; 
  
class Main{ 
    static void rightRotate(int[] arr, int d, 
                           int n) 
    { 
        for (int i = 0; i < d; i++) 
            rightRotatebyOne(arr, n); 
    } 
  
    static void rightRotatebyOne(int[] arr, int n) 
    { 
        int i, temp = arr[n-1]; 
        for (i = n-1; i > 0; i--) 
            arr[i] = arr[i-1]; 
  
        arr[i] = temp; 
    } 
  
    static void leftRotate(int[] arr, int d, 
                           int n) 
    { 
        for (int i = 0; i < d; i++) 
            leftRotatebyOne(arr, n); 
    } 
  
    static void leftRotatebyOne(int[] arr, int n) 
    { 
        int i, temp = arr[0]; 
        for (i = 0; i < n - 1; i++) 
            arr[i] = arr[i + 1]; 
  
        arr[i] = temp; 
    } 
  
    static void printArray(int[] arr, int size) 
    { 
        for (int i = 0; i < size; i++) 
            Console.Write(arr[i] + " "); 
    } 
  
    public static void Main() 
    { 
        int[] arr = { 1, 2, 3, 4, 5, 6, 7 }; 
        leftRotate(arr, 2, 7); 
        printArray(arr, 7); 
        Console.Write("\n");
        rightRotate(arr,2,7);
        printArray(arr,7);
    } 
} 
