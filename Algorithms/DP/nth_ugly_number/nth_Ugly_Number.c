#include <stdio.h>

int min(int num1, int num2) {
	return (num1 > num2) ? num2 : num1;
}

int get_nth_ugly_number(int n) {
	int dp[n];
	dp[0] = 1;
	int index2 = 0, index3 = 0, index5 = 0;
	int next2 = 2, next3 = 3, next5 = 5;
	for(int i = 1; i < n; i++) {
		dp[i] = min(next2, min(next3, next5));
		if(dp[i] == next2) next2 = 2 * dp[++index2];
		if(dp[i] == next3) next3 = 3 * dp[++index3];
		if(dp[i] == next5) next5 = 5 * dp[++index5];
	}
	return dp[n-1];
}

int main(void) {
	int n;
	printf("Enter the n!\n");
	scanf("%d", &n);
	int ans = get_nth_ugly_number(n);
	printf("%dth ugly number is: %d\n", n, ans);
	return 0;
}