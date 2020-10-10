import java.util.Scanner;

class ShellSort 
{ 
    // prints out the array
    static void display(int arr[]) 
    { 
        int n = arr.length; 
        for (int i=0; i<n; i++) 
        {
            System.out.print(arr[i] + " "); 
        }
        System.out.println(); 
    } 
  
    // implement shell sorting
    int shellSort(int arr[]) 
    { 
        int n = arr.length; 
  
        // Start with a big gap, then reduce the gap until 1 
        for (int gap = n/2; gap > 0; gap /= 2) 
        { 
            // Do a gapped insertion sort for this gap size. 
            // The first gap elements a[0..gap-1] are already 
            // in gapped order keep adding one more element 
            // until the entire array is gap sorted 
            for (int i = gap; i < n; i += 1) 
            { 
                // add a[i] to the elements that have been gap 
                // sorted save a[i] in temp and make a hole at 
                // position i 
                int temp = arr[i]; 
  
                // shift earlier gap-sorted elements up until 
                // the correct location for a[i] is found 
                int j; 
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                    arr[j] = arr[j - gap]; 
  
                // put temp (the original a[i]) in its correct 
                // location 
                arr[j] = temp; 
            } 
        } 
        return 0; 
    } 
  
    // main
    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt(); // number of elements in the array
        int[] arr; 
        
        for(int i=0; i<N; i++) {
            arr[i] = sc.nextInt(); // the array elements
        }
        
        System.out.println("Array before sorting: "); 
        display(arr); 
  
        ShellSort ob = new ShellSort(); 
        ob.shellSort(arr); 
  
        System.out.println("Array after sorting: "); 
        display(arr); 
    } 
} 
