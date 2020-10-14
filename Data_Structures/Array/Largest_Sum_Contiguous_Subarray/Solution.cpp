/*
BASICALLY THIS PROBLEM CAN BE SOLVED USING KADANES ALGORITHM 
THIS PROBLEM HAS BASE CASE THAT IF ALL ELEMENTS ARE -vE IN THAT CASE PRINT LEAST -ve NUMBER
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,c=0;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]<0)
		c++;
	}
	int cn=0,cs=0;
	for(int i=0;i<n;i++){
		cn+=arr[i];
		if(cn<0)cn=0;
		if(cs<cn)cs=cn;
	}
	if(c==n){
		sort(arr,arr+n);
		cs=arr[n-1];
		cout<<cs<<endl;
	}
	else{
		cout<<cs<<endl;
	}
	return 0;
}
