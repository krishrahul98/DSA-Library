import java.util.*;
import java.io.*;

class Bubble_Sort 
{ 
    void bubbleSort(int arr[]) 
    { 
        int n = arr.length; 
        for (int i = 0; i < n-1; i++) 
            for (int j = 0; j < n-i-1; j++) 
                if (arr[j] > arr[j+1]) 
                {
                    int temp = arr[j]; 
                    arr[j] = arr[j+1]; 
                    arr[j+1] = temp; 
                } 
    } 

    void printArray(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; ++i) 
            System.out.print(arr[i] + " "); 
        System.out.println(); 
    } 

    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter array length : ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter array elements : ");
        
        for (int i=0;i<n ;i++ ) {
            arr[i] = sc.nextInt();
        }

        Bubble_Sort bs = new Bubble_Sort(); 
        bs.bubbleSort(arr); 
        System.out.println("Sorted array"); 
        bs.printArray(arr); 
    } 
} 