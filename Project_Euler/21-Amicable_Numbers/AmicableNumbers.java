class AmicableNumbers
{
    // returns the sum of all divisors up to n
    static long sum_divisors(int n) {
        long long int res = 1;
        int limit = (1 + (int)(Math.sqrt(n)));
        
        for (int i = 2; i < limit; i++) {
            if ((n % i) == 0) {
                res += i;
                if (n != (i * i)) {
                    res += (int)(n / i);
                }
            }
        }
    
        return res;
    }
    
	public static void main(String[] args) {
		long sum_of_divisors[10000];
        for (int i = 2; i < 10000; i++) {
            sum_of_divisors[i] = sum_divisors(i);
        }
        
        long ans;
        for (int i = 2; i < 10000; i++) {
            if (sum_of_divisors[i] < 10000 && sum_of_divisors[i] != i && sum_of_divisors[sum_of_divisors[i]] == i) {
                ans += i;
            }
        }
        
        System.out.println(ans);
    
        return 0;
	}
}
