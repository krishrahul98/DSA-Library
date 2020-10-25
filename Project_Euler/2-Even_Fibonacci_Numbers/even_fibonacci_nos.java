import java.io.*;
class even_fibonacci_nos
{
    public static void main(String[] args)throws IOException
    {
        //0,1,1,2,3,5,8,13,..... is the fibonacci series
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        long sum=0;
        int a=0,b=1,c=1;
        System.out.println("ENTER NUMBER OF TERMS");
        int l=Integer.parseInt(br.readLine());
        for(int i=1;i<=l;i++)
        {
            c=a+b;
            if(a%2==0)
            sum+=a;
            a=b;
            b=c;
        }
        System.out.println("SUM OF EVEN NOS OF FIBONACCI SERIES TILL "+l+" TERMS IS "+sum);
    }
}
