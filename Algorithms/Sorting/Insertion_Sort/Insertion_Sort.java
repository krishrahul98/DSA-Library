public class Insertion_Sort{

     public static void main(String[] args) {
          
          int[] a = {12, 11, 3, 2, 5, 7};
          sort(a, a.length);
          for (int i = 0; i < a.length; i++)
          {
               System.out.print(a[i] + " ");
          }
     }
     public static void sort(int[] a,int length) {
          
          int n = a.length;

          for (int i = 0; i < n; i++)
          {
               int key = a[i];
               //start of sorted region
               int j = i - 1;
               while (j >= 0 && a[j] > key)
               {
                    //shift
                    a[j + 1] = a[j];
                    j = j - 1;
               }
               a[j + 1] = key;
          }
     }
}
