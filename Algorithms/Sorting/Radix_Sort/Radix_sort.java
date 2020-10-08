public class RadixSort {
  public static void main(String[] args) {
    int[] arr = {40, 25, 206, 65, 457, 4, 81, 74, 58, 6};
    System.out.println("Original Array- " + Arrays.toString(arr));
    radixSort(arr);
    System.out.println("Sorted array after Radix sort- " + Arrays.toString(arr));
  }
	
  private static void radixSort(int[] arr){
    //get max element in array
    int max = getMaxElementInArray(arr);
    int position = 1;
    // move from least significant digit 
    // to most significant digit
    while(max/position > 0){
      countingSort(arr, position);
      position *= 10;
    }        
  }
    
  private static int getMaxElementInArray(int[] arr){
    int max = arr[0];
    for(int i = 1; i < arr.length; i++){
      if (arr[i] > max){
          max = arr[i];
      }
    }
    return max;
  }
    
  // Counting sort used to sort array in each pass
  private static void countingSort(int[] arr, int position){
    int n = arr.length;
    int[] output = new int[n];
    int[] count = new int[n];
        
    //Calculate frequency of each element, put it in count array
    for(int i = 0; i < arr.length; i++){
      count[(arr[i]/position)%10]++;
    }
    // Modify count array to get the final position of elements
    for(int i = 1; i < n; i++){
      count[i] = count[i] + count[i-1];
    }
    
    // Add elements to output array for this pass
    for(int i = n-1; i >=0; i--){
      output[count[(arr[i]/position)%10] - 1] = arr[i];
      count[(arr[i]/position)%10]--;
    }
    // Copy output array to the input for 
    // the next pass of counting sort
    for(int i = 0; i < output.length; i++){
      arr[i] = output[i];
    }
    System.out.println("Array after Counting sort at position " + position 
        		        + " " + Arrays.toString(arr));
  }
}