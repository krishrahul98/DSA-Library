#include<iostream>
using namespace std;

int  main()
{
    int n; 
    cin>>n;
    int a[n];
    int output[n];
	
    int max_ele = 0;

    for(int i=0;i<n;i++){
      cin>>a[i];
      if(a[i]>max_ele)
	 max_ele = a[i]; 
     }
   
    int size = max_ele + 1;
    int c[size]={0};
	    
    for(int i=0;i<n;i++) {
       c[a[i]] = c[a[i]] + 1;
    }
 
    for(int i=1;i<size;i++){
       c[i] = c[i] + c[i-1];
    }

    for(int i=n-1;i>=0;i--){
       output[c[a[i]]-1] = a[i];
       c[a[i]]--;
    }

   for(int i=0;i<n;i++){
     cout<<output[i]<<" ";
   }

   return 0;
}


