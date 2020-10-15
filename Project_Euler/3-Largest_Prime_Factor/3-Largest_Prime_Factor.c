/* 
Author : Sanjay Marreddi

Largest prime factor

Problem Statement :- 

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ? 

*/

#include <stdio.h>
#include <math.h>

int Largest_Prime_Factor(long long int n){

    long long i;
    long long largest = 0;

    while (n % 2 == 0)
    {
        largest = 2;
        n = n / 2;
    }

    for (i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            if (largest < i)
                largest = i;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    {
        if (largest < n)
            largest = n;
    }

    return largest ;

return 0;

}

int main()
{
    long long int Result = Largest_Prime_Factor(600851475143);
    printf("\n The largest prime factor of the number 600851475143 is %d", Result);
}