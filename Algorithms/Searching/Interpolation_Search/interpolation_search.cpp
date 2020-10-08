//This program performs interpolation search in an array
#include<bits/stdc++.h>
using namespace std;

int interpol(int a[], int low, int high, int key)
{
  int loc;
  if(low<=high && key>=a[low] && key<=a[high])	//Since it is a sorted array
  {
    loc = low + ((( high - low ) / (a[high] - a[low])) * (key - a[low])); 
    
    if(a[loc]==key)
    return loc;
    
    if(a[loc]<key)
    return interpol(a,loc+1,high,key);
    
    if(a[loc]>key)
    return interpol(a,low,loc-1,key);
  }
  //If not found
  return -1;
}

int main()
{
  int n,k,i,ans;
  cout<<"Enter the number of elements in the array:- ";
  cin>>n;
  int arr[n];
 
  cout<<"Enter "<<n<<" uniformly distributed elements\n";
  for(i=0;i<n;++i)
  cin>>arr[i];
     
  cout<<"Enter the element to be searched:- ";
  cin>>k;
  
  ans = interpol(arr,0,n-1,k);
  if(ans==-1)
  cout<<k<<" not found\n";
  else
  cout<<k<<" found at index "<<ans<<endl;
  return 0; 
}
