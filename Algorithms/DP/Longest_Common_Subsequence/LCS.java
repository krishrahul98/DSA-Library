import java.util.Scanner;

class LCS
{ 
  
  /* Returns length of LCS for str1[0..len1-1], str2[0..len2-1] */
  int lcs( char[] str1, char[] str2, int len1, int len2 ) 
  { 
    int L[][] = new int[len1+1][len2+1]; 
  
    /* Following steps build L[len1+1][len2+1] in bottom up fashion. Note that L[i][j] contains length of LCS of str1[0..i-1] and str2[0..j-1] */
    for (int i=0; i<=len1; i++) 
    { 
      for (int j=0; j<=len2; j++) 
      { 
        if (i == 0 || j == 0) 
            L[i][j] = 0; 
        else if (str1[i-1] == str2[j-1]) 
            L[i][j] = L[i-1][j-1] + 1; 
        else
            L[i][j] = max(L[i-1][j], L[i][j-1]); 
      } 
    } 
  return L[len1][len2]; 
  } 
  
  /* Utility function to get max of 2 integers */
  int max(int a, int b) 
  { 
    return (a > b)? a : b; 
  } 
  
  public static void main(String[] args) 
  { 
    Scanner sc = new Scanner(System.in);
    LCS lcs = new LCS(); 
    String s1 = sc.nextLine(); 
    String s2 = sc.nextLine(); 
  
    char[] str1=s1.toCharArray(); 
    char[] str2=s2.toCharArray(); 
    int len1 = str1.length; 
    int len2 = str2.length; 
  
    System.out.println("Length of LCS is" + " " + lcs.lcs( str1, str2, len1, len2 ) ); 
  } 
  
} 