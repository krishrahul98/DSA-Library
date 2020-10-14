#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n, i, sum = 0, t;
    scanf("%llu", &t);
    while (t--)
    {
        scanf("%lld", &n);
        --n;
        unsigned long long n1, n2, n3;
        n1 = n / 3;
        n2 = n / 5;
        n3 = n / 15;
        sum = (3 * n1 * (n1 + 1)) / 2 + (5 * n2 * (n2 + 1)) / 2 - (15 * n3 * (n3 + 1)) / 2;
        printf("%lld\n", sum);
    }
    return 0;
}