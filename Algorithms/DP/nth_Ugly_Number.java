import java.util.*;
  
class UglyNumber 
{ 
    /* Function to get the nth ugly number*/
    public static int getugly(int n) 
    { 
        int ugly[] = new int[n];  // To store ugly numbers 
        int i2 = 0, i3 = 0, i5 = 0; 
        int multi2 = 2,multi3=3,multi5=5; 
        int next_ugly = 1; 
          
        ugly[0] = 1; 
          
        for(int i = 1; i < n; i++) 
        { 
            next_ugly = Math.min(multi2,Math.min(multi3,multi5)); 
            ugly[i] = next_ugly; 
            if (next_ugly == multi2) 
            { 
               i2 = i2+1; 
               multi2 = ugly[i2]*2; 
            } 
            if (next_ugly == multi3) 
            { 
               i3 = i3+1; 
               multi3 = ugly[i3]*3; 
            } 
            if (next_ugly ==multi5) 
            { 
               i5 = i5+1; 
              multi5= ugly[i5]*5; 
            } 
        } 
        return next_ugly; 
    } 
  
    
    public static void main(String args[]) 
    { 
        Scanner sc= new Scanner(System.in);
        int num=sc.nextInt();
       // int ans=getugly(num);
        System.out.println(getugly(num)); 
    } 
} 
