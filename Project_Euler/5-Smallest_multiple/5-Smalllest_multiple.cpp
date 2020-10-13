#include <bits/stdc++.h>
using namespace std;

bool prime(int a)
{
    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0)
            return false;
    return true;
}

int main()
{
    int T, N, i, c;
    long long int ans;
    cin >> T;
    while (T--)
    {
        ans = 1;
        cin >> N;
        for (i = 2; i <= sqrt(N); ++i)
            if (prime(i))
            {
                c = log(N) / log(i);
                ans *= pow(i, c);
            }
        for (; i <= N; ++i)
            if (prime(i))
                ans *= i;
        cout << ans << endl;
    }
    return 0;
}