#include <bits/stdc++.h>
using namespace std;

int search(int a[], int x, int n)
{

     for (int i = 0; i < n; i++)
     {
          if (a[i] == x)
          {
               return i;
          }
     }
     return -1;
}

int main()
{

     int a[] = {4, 7, 8, 0, 2, 9};
     int n = sizeof(a) / sizeof(a[0]);
     int x = 3;
     int ans = search(a, x, n);
     if (ans == -1)
     {
          cout << "Element " << x << " not found "
               << "\n";
     }
     else
     {
          cout << "Element " << x << " found at index " << ans << "\n";
     }
     return 0;
}