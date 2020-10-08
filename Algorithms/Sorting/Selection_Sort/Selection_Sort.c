#include<stdio.h>
int main(){
   int i, j, n, temp, val[25];

   printf("Enter the number of elements: ");
   scanf("%d",&n);

   printf("Enter %d elements: ", n);

   for(i=0;i<n;i++)
      scanf("%d",&val[i]);


   for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
         if(val[i]>val[j]){
            temp=val[i];
            val[i]=val[j];
            val[j]=temp;
         }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
