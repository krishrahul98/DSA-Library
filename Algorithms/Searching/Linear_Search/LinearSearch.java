public class LinearSearch{

public static int linearsearch(int arr[],int ele){

for(int i=0;i<arr.length;i++)
{
if(arr[i]==ele){
return i;
}
}
return -1;
}
public static void main(String args[]){
int[] arr = new int[]{ 1,2,3,4,5,6,7,8,9,10 };
System.out.print("Poistion of element is:") ;
System.out.print(linearsearch(arr,5));

}




}