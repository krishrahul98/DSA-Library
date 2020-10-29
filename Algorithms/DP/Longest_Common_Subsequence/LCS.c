#include <stdio.h> 
#include <string.h>
   
int max(int a, int b); 
   
/* Returns length of LCS for str1[0..len1-1], str2[0..len2-1] */
int lcs( char *str1, char *str2, int len1, int len2 ) 
{ 
   int L[len1+1][len2+1]; 
   int i, j; 
   
   /* Following steps build L[len1+1][len2+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of str1[0..i-1] and str2[0..j-1] */
   for (i=0; i<=len1; i++) 
   { 
     for (j=0; j<=len2; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (str1[i-1] == str2[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
     
   /* L[len1][len2] contains length of LCS for str1[0..len2-1] and str2[0..len1-1] */
   return L[len1][len2]; 
} 
   
/* Utility function to get max of 2 integers */
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
   
/* Driver program to test above function */
int main() 
{
  int len1, len2;
  printf("Enter the lengths of the strings..:\n");
  scanf("%d %d", &len1, &len2);
  getchar();
  char str1[len1+1]; 
  char str2[len2+1];
  printf("Enter the first string\n");
  fgets(str1, len1, stdin);
  printf("Enter the second string\n");
  getchar();
  getchar();
  fgets(str2, len2, stdin);
  printf("Length of LCS is %d", lcs( str1, str2, len1, len2 ) ); 
  
  return 0; 
} 