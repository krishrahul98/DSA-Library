#include <bits/stdc++.h>
using namespace std;

void selectionSort(int a[], int n)
{
     //moving the boundary
     for (int i = 0; i < n - 1; i++)
     { //value
          int min_idx = i;
          for (int j = i + 1; j < n; j++)
          {
               if (a[j] < a[min_idx])
               {
                    min_idx = j;
               }
          }
          //swap
          int temp = a[min_idx];
          a[min_idx] = a[i];
          a[i] = temp;
     }
}

int main()
{

     int a[] = {4, 5, 2, 6, 7, 9, 1, 11};
     int n = sizeof(a) / sizeof(a[0]);
     selectionSort(a, n);
     for (int i = 0; i < n; i++)
     {
          cout << a[i] << " ";
     }

     return 0;
}
