/* 
Author : Sanjay Marreddi

Multiples of 3 and 5

Problem Statement :- 

If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>

int main(){

    int i=0,j ;
    int arr[1000];

    
    for(j=1; j < 1000; j++){

        if ((j % 3 == 0 ) || (j % 5 == 0 )){
            arr[i] = j ;
            i++;
        }
    }

    int sum = 0;
    int k ;
    for  (k=0; k<=i;k++){
        sum+= arr[k];

    }

    printf("%d",sum);

        
}


