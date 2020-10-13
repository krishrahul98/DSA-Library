// Java program to print largest contiguous array sum 
/* 
    Problem: Write an efficient program to find the sum of contiguous subarray 
              within a one-dimensional array of numbers which has the largest sum.
    Solution: Kadane's Algorithm
              Simple idea of the Kadane’s algorithm is to look for all positive contiguous segments of the array (max_ending_here is used for this). And keep track of maximum sum contiguous segment among all positive segments (max_so_far is used for this). 
              Each time we get a positive sum compare it with max_so_far and update max_so_far if it is greater than max_so_far  
    */
   
import java.io.*; 
import java.util.*; 

public class LSCA
{ 
	public static void main (String[] args) 
	{ 
	    Scanner input=new Scanner(System.in);
	    System.out.println("Enter size of array:");
	    int size;
	    size=input.nextInt();
		int [] a = new int[size];
		for(int i=0;i<size;i++){
		    	System.out.println("Enter number for "+i+"th index in array");
		    	a[i]=input.nextInt();
		}
		System.out.println();
		System.out.println("Maximum contiguous sum is " + 
									largestSumContiguousSubarray(a)); 
	} 

	public static int largestSumContiguousSubarray(int a[]) 
	{ 
		int size = a.length; 
		int max_so_far = Integer.MIN_VALUE, max_ending_here = 0; 

		for (int i = 0; i < size; i++) 
		{ 
			max_ending_here = max_ending_here + a[i]; 
			if (max_so_far < max_ending_here) 
				max_so_far = max_ending_here; 
			if (max_ending_here < 0) 
				max_ending_here = 0; 
		} 
		return max_so_far; 
	} 
} 
