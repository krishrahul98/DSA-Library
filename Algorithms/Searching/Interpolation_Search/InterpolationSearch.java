class InterpolationSearch 
{ 
 
    // If x is present in arr[0..n-1], then returns index of it, else returns -1. 
    static int interpolationSearch(int[] arr, int x) 
    { 
        // Find indexes of two corners 
        int lowerLimit = 0, higherLimit = (arr.length - 1); 
       
        // Since array is sorted, an element present in array must be in range defined by corner 
        while (lowerLimit <= higherLimit && x >= arr[lowerLimit] && x <= arr[higherLimit]) 
        {         
  
            if (lowerLimit == higherLimit) 
            { 
                if (arr[lowerLimit] == x) return lowerLimit; 
                return -1; 
            } 
         
            // Probing the position with keeping uniform distribution in mind. 
              
            int pos = lowerLimit + (((hi-lowerLimit) / 
                  (arr[higherLimit]-arr[lowerLimit]))*(x - arr[lowerLimit])); 
       
            // Condition of target found 
            if (arr[pos] == x) 
                return pos; 
       
            // If x is larger, x is in upper part 
            if (arr[pos] < x) 
                lowerLimit = pos + 1; 
       
            // If x is smaller, x is in the lower part 
            else
                higherLimit = pos - 1; 
        } 
        return -1; 
    } 
    
    // main  
    public static void main(String[] args)  
    { 
         Scanner sc = new Scanner(System.in);
         int n = sc.nextInt(); // array size
         
         int[] arr = new int[n];
         for(int i=0; i<n; i++) {
               arr[i] = sc.nextInt();
         }
         
         int x = sc.nextInt(); // Element to be searched 
         int index = interpolationSearch(arr, x); 
           
         // If element was found 
         if (index != -1) 
               System.out.println("Element " + x + " found at index " + index); 
            else
               System.out.println("Element " + x + " not found."); 
    } 
} 


