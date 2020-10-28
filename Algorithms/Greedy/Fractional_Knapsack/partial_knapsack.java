// I have tried solving fractional knapsack using Dp 
//though its a little cumbersome then greedy but for a better understanding of Dp its a good question. */



import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {

Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
int wti[]=new int[n];            // weight of the items 
float vi[]=new float[n];        // value of the items

for(int i=0;i<n;i++)   // array input for weight
{
    vi[i]=sc.nextInt();
}
for(int i=0;i<n;i++)   // array inuts for values
{
    wti[i]=sc.nextInt();
}
int max=sc.nextInt();
float dp[][]=new float[n+1][max+1];    // created a 2d array to store max amount
for(int i=1;i<n+1;i++)
{
    for(int j=1;j<max+1;j++)
    {

      if(j>=wti[i-1])    // if weight of the item is less the max capacity if the bag
      {
        int rw=j-wti[i-1];
        float val=dp[i-1][rw];
        if((val+vi[i-1])>=dp[i-1][j])
        {
        dp[i][j]=val+vi[i-1];
        System.out.print(dp[i][j]+"    "); 
        }
    else
    {
        dp[i][j]=dp[i-1][j];
    }}
    else   // if weight of the item is greater then the max capacity of the bag
          {
              if((j*(vi[i-1]/wti[i-1]))>=dp[i-1][j])
          {
          dp[i][j]=j*(vi[i-1]/wti[i-1]);    
          }
         else
         {
        dp[i][j]=dp[i-1][j];  
         }
    }
}   
}
System.out.print(dp[n][max]);    // max amount earned 
}
}
