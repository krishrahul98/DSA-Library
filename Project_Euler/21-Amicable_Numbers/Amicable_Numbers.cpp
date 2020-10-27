#include <iostream>
#include <math.h>
using namespace std;

long long int sum_div(int n) {
    long long int res = 1;
    int lim = (1 + (int)(sqrt(n)));
    for (int i = 2; i < lim; i++) {
        if (!(n % i)) {
            res =res + i;
            if (n != (i * i)) {
                res =res + (int)(n / i);
            }
        }
    }
    
    return res;
}
int main() {	
	long long int sum_of_divisors[10000];
    for (int i = 2; i < 10000; i++) {
        sum_of_divisors[i] = sum_div(i);
    }
    
    long long int ans;
    for (int i = 2; i < 10000; i++) {
        if (sum_of_divisors[i] < 10000 && sum_of_divisors[i] != i && sum_of_divisors[sum_of_divisors[i]] == i) {
            ans = ans + i;
        }
    }
    cout<<ans<<endl;
	return 0;
}
