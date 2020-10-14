public class Merge_Sort{
        
     public static void main(String[] args){

          int[] a ={12,4,3,5,2,1,7};
          mergeSort(a, 0 ,a.length-1);
          for(int i=0;i<a.length;i++){
               System.out.print(a[i] + " ");
          }
     }

     public static void mergeSort(int [] a,int l,int r){

          if(r>l){
               //Find mid
               int mid=(l+r)/2;
               //Divide
               mergeSort(a,l,mid);
               mergeSort(a,mid+1,r);
               //Merge
               merge(a,l,mid,r);
          }
     }
     private static void merge(int [] a, int l ,int mid,int r){
          //2 pointer approach

          int[] temp=new int[a.length];

          int i=l;
          int j=mid+1;

          //for temp array
          int k=0;

          while(i<=mid && j<=r){
               if(a[i]<=a[j]){
                    temp[k]=a[i];
                    i++;
                    k++;
               }else{
                    temp[k]=a[j];
                    k++;
                    j++;
               }
          }

          while(i<=mid){
               temp[k]=a[i];
                    i++;
                    k++;
          }
          while(j<=r){
               temp[k]=a[j];
                    k++;
                    j++;
          }
          //copying elements back to original array
          for(int m=l,p=0;m<=r;m++,p++){
               a[m]=temp[p];
          }
     }
}
