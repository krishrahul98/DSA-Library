import java.util.Arrays;

class CountingSort {
  void countSort(int array[], int size) {
    int[] output = new int[size + 1];

   
    int max = array[0];
    for (int i = 1; i < size; i++) {
      if (array[i] > max)
        max = array[i];
    }
    int[] count = new int[max + 1];

    
    for (int i = 0; i < max; ++i) {
      count[i] = 0;
    }

    
    for (int i = 0; i < size; i++) {
      count[array[i]]++;
    }

    
    for (int i = 1; i <= max; i++) {
      count[i] += count[i - 1];
    }

  
    for (int i = size - 1; i >= 0; i--) {
      output[count[array[i]] - 1] = array[i];
      count[array[i]]--;
    }

    
    for (int i = 0; i < size; i++) {
      array[i] = output[i];
    }
  }

  
  public static void main(String args[]) {
    int[] data = { 4, 2, 2, 8, 3, 3, 1 };
    int size = data.length;
    CountingSort cs = new CountingSort();
    cs.countSort(data, size);
    System.out.println("Sorted Array in Ascending Order: ");
    System.out.println(Arrays.toString(data));
  }
}