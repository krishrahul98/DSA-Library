//This program rotates an integer array left or right by k elements
#include<bits/stdc++.h>
using namespace std;

void leftshift(int a[], int n, int k)
{
  int buff[k],i;
  for(i=0;i<k;++i)
  buff[i]=a[i];
  for(i=k;i<n;++i)
  a[i-k]=a[i];
  for(i=0;i<k;++i)
  a[n-k+i] = buff[i];
}

void rightshift(int a[], int n, int k)
{
  int buff[k],j=0,i;
  for(i=n-k;i<n;++i,++j)
  buff[j]=a[i];
  for(i=n-k-1;i>=0;--i)
  a[i+k]=a[i];
  for(i=0;i<k;++i)
  a[i]=buff[i];
}

int main()
{
  int i,n,k,c;
  cout<<"Enter the size of the array - ";
  cin>>n;
  int a[n];
  cout<<"Enter "<<n<<" elements:-\n";
  for(i=0;i<n;++i)
  cin>>a[i];
  cout<<"Enter the value of k (0<k<n) = ";
  cin>>k;
  cout<<"1 : Left shift by k elemets\n2 : Right shift by k elements\nEnter your choice : ";
  cin>>c;
  switch(c)
  {
    case 1: leftshift(a,n,k);
    	    break;
    case 2: rightshift(a,n,k);
    	    break;
  }
  cout<<"The modified array is - \n";
  for(i=0;i<n;++i)
  cout<<a[i]<<" ";
  return 0;
}
