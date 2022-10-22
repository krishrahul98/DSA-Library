#include <iostream>
using namespace std;

void maxSubarray(int *a, int n)
{
    int maxsum = a[0],m,l;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + a[j];
            if (sum > maxsum)
            {
                m = i;
                l = j;
                maxsum = sum;
            }
        }
    }
    cout<<"\nThe maximum subarray is :\n";
    for (int i = m; i <= l; i++)
    {
        cout<<"\t"<<a[i];
    }
    cout<<"\nThe maximum sum is : "<<maxsum<<endl<<endl;
}
int main()
{
    int n;
    cout<<"\nEnter the number of elements in the array : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the array elements :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    maxSubarray(a,n);
    return 0;
}
