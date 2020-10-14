// C++ program to implement Jump Search

#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int find_element(int element);
int arr[MAX],n;
int main()
{
   int i,element,result;
  cout<<"\nEnter the number of elements: ";
  cin>>n;
   cout<<"\nEnter the elements of array: \n";
   for(i=0;i<n;i++)
   {
         cin>>arr[i];
   }
      cout<<"\n\nEnter the element you want to search: ";
      cin>>element;
      result=find_element(element);
      if(result==-1)
      {
            cout<<"\nElement is not found in the array !\n";
      }
      else
      {
            cout<<"\nElement "<<element<<" is present at position " << result;
      }
      return 0;
}
int find_element(int element)
{
   int jump_step,prev=0;
   jump_step=floor(sqrt(n));
   /* Finding block in which element lies, if it is present */
   while(arr[prev]<element)
   {
       if(arr[jump_step]>element || jump_step>=n)
       {
            break;
       }
       else
       {
                prev=jump_step;
                jump_step=jump_step+floor(sqrt(n));
       }
   }
   /*Finding the element in the identified block */
   while(arr[prev]<element)
   {
        prev++;
   }
   if(arr[prev]==element)
   {
        return prev+1;
   }
   else
   {
        return -1;
   }
}
