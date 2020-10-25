import java.io.*;
class hq1
{
    public static void main(String[] args)throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        long sum=0;
        System.out.println("ENTER START VALUE");
        int s=Integer.parseInt(br.readLine());
        System.out.println("ENTER END VALUE");
        int l=Integer.parseInt(br.readLine());
        for(int i=s;i<=l;i++)
        {
            if(i%3==0 || i%5==0)
            sum+=i;
        }
        System.out.println("SUM OF NOS DIVISIBLE BY 3 OR 5 BETWEEN "+s+" and "+l+" is "+sum);
    }
}
