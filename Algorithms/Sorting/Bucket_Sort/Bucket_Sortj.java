import java.util.*; 
import java.io.*; 
  
class Bucket{ 
  
    static void bucketSort(float arr[], int n) 
    { 
        if (n <= 0) 
            return; 
  
        Vector<Float>[] buckets = new Vector[n]; 
  
        for (int i = 0; i < n; i++) { 
            buckets[i] = new Vector<Float>(); 
        } 
  
        for (int i = 0; i < n; i++) { 
            float idx = arr[i] * n; 
            buckets[(int)idx].add(arr[i]); 
        } 
  
        for (int i = 0; i < n; i++) { 
            Collections.sort(buckets[i]); 
        } 
  
        int index = 0; 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < buckets[i].size(); j++) { 
                arr[index++] = buckets[i].get(j); 
            } 
        } 
    }  
    public static void main(String args[]) 
    { 
        float arr[] = { (float)0.895, (float)0.678, 
                        (float)0.567, (float)0.1280, 
                        (float)0.655, (float)0.3421 }; 
  
        int n = arr.length; 
        bucketSort(arr, n); 
  
        System.out.println("Sorted array is "); 
        for (float el : arr) { 
            System.out.print(el + " "); 
        } 
    } 
} 