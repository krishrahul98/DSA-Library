#include<stdio.h>

int main()
{
    // Initialising the Variables
    int array[100] ;
    int i,find,number;

    printf("\nEnter the number of elements in your array:- ");
    scanf("%d",&number);
     
    printf("\nEnter the array elements with SPACE as separator:- ");
    for(i=0;i<number;++i)
        scanf("%d",&array[i]);
     
    printf("\nEnter element to be searched:- ");
    scanf("%d",&find);
     
    // Checking for the presence of the element in out array 
    for(i=0;i<number;++i)
        if(array[i]==find)
            break;
     
    if(i<number)
        printf("\nWoah,The Element %d found at index %d",find,i);
    else
        printf("\nSorry,The Element %d is not found",find);
  
    return 0;
}