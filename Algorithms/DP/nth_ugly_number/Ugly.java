
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class Ugly {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();//is the value of n
		sc.close();
		int[] arr = new int[n];
		int counter = 0;
		int val = 1;
		while(arr[n-1]==0) {//gets all the Ugly nums
			Set<Integer> in = primeFactors(val);
			if(in.contains(2)&&in.contains(3)&&in.contains(5)&&in.size()==3) {
				arr[counter] = val;
				counter++;
			}
			val++;
		}
		System.out.println(arr[n-1]);
	}
	public static Set<Integer> primeFactors(long number) {//code for finding primes
        Set<Integer> primefactors = new HashSet<>();
        long copyOfInput = number;

        for (int i = 2; i <= copyOfInput; i++) {
            if (copyOfInput % i == 0) {
                primefactors.add(i); // prime factor
                copyOfInput /= i;
                i--;
            }
        }
        return primefactors;
    }
	
}

