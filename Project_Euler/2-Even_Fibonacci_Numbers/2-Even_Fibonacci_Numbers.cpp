#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, i, j;
    cin >> t;

    while (t--)
    {
        long long n;
        long long sum = 2;
        cin >> n;
        long long f = 1, s = 2, th;
        for (i = 0;; i++)
        {
            th = f + s;
            if (th > n)
            {
                break;
            }
            if (th % 2 == 0)
            {
                sum += th;
            }
            f = s;
            s = th;
        }
        cout << sum << "\n";
    }
    return 0;
}