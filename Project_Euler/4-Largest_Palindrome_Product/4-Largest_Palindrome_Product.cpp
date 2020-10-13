#include <bits/stdc++.h>
using namespace std;

bool isPal(long int n)
{
    int a = n, b = 0, c = 1;
    while (n >= c * 10)
    {
        c *= 10;
    }
    while (n >= 1)
    {
        b += (n % 10) * c;
        n /= 10;
        c /= 10;
    }
    return (a == b);
}

int main()
{
    int T, j;
    long int N, i;
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (i = N - 1; i >= 10000; --i)
            if (isPal(i))
            {
                for (j = 100; j < 1000; ++j)
                    if (i % j == 0 && i / j > 99 && i / j < 1000)
                    {
                        goto endLoop;
                    }
            }
    endLoop:
        cout << i << endl;
    }
    return 0;
}