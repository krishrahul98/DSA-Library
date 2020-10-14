import java.util.*; 
import java.io.*;   
class BucketSort  
{
    static void bucketSort(float arr[]) 
    { 
        if (arr.length>0) 
        {  
            ArrayList<Float>[] bucket=new ArrayList[arr.length];
            int ele,k=0;
            for(int i=0;i<arr.length;i++)
            bucket[i]=new ArrayList<Float>();
            for (int i=0;i<arr.length;i++) 
            { 
                ele= (int)(arr[i]*arr.length)%arr.length; 
                bucket[ele].add(arr[i]);
            } 
            for(int i=0;i<arr.length;i++)
            {
                Collections.sort(bucket[i]);
            }
            for(int i=0;i<arr.length;i++)
            {
                for(int j=0;j<bucket[i].size();j++)
                {
                     arr[k++]=bucket[i].get(j);
                }
            }
        }
    }
    public static void main(String args[]) throws IOException
    { 
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n;
        System.out.println("ENTER LENGTH OF ARRAY");
        n=Integer.parseInt(br.readLine());
        float arr[]=new float[n];
        System.out.println("ENTER VALUES OF THE ARRAY");
        for (int i=0;i<n;i++) 
          arr[i]=Float.parseFloat(br.readLine());
        bucketSort(arr); 
        System.out.println("Sorted array is "); 
        for (int i=0;i<n;i++)
          System.out.print(arr[i] + " "); 
    } 
} 
