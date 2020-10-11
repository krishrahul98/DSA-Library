using System;
class Reverse_Array {
   static void Main() {
      int[] arr = { 7,9,4,2,5,1 };
      
      Console.WriteLine("Original: ");
      foreach (int i in arr) 
      {
         Console.WriteLine(i);
      }
      
      #Reversal of Array
      Array.Reverse(arr);
      Console.WriteLine("Reverse: ");
      foreach (int i in arr) 
      {
         Console.WriteLine(i);
      }
      Console.ReadLine();
   }
}
