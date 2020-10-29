#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std; 

int low_com_seq(char *s1,char *s2, int m, int n )  
{  
    if (m == 0 || n == 0)  
        return 0;  
    if (s1[m-1] == s2[n-1])  
        return 1 + low_com_seq(s1,s2, m-1, n-1);  
    else
        return max(low_com_seq(s1,s2, m, n-1), low_com_seq(s1,s2, m-1, n));  
}  
  
int max(int a, int b)  
{  
    return (a > b)? a : b;  
}  
  
int main()  
{  
    char stra[]="hello";
    char strb[]="heya";
      
    int la= strlen(stra);
    int lb= strlen(strb);
    cout<<"Length of Lowest common subsequence is "<< low_com_seq(stra,strb,la,lb); 
      
    return 0;  
}  
