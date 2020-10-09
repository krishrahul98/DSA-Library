import java.util.*;
class Rotate_Array_L{
	 public static void main(String[] args) {
	    int n,s;  
	 	Scanner sc= new Scanner(System.in);
	 	System.out.print("Enter size of Array:");
        s= sc.nextInt();
        int [] arr = new int [s];  
        System.out.println("Enter elements of Array:");
        for (int i=0;i<s;i++ ) {
        	arr[i]=sc.nextInt();
        	}
        System.out.print("How many times You want to left rotate an array?");
        n=sc.nextInt();
        for(int i = 0; i < n; i++){  
            int j, first;  
            
            first = arr[0];  
            for(j = 0; j < arr.length-1; j++){  
                arr[j] = arr[j+1];  
            }  
           
            arr[j] = first;  
        }  
        System.out.println();  
        System.out.println("Array after left rotation: ");  
        for(int i = 0; i< arr.length; i++){  
            System.out.print(arr[i] + " ");  
        }  
        System.out.println();
    }  
}