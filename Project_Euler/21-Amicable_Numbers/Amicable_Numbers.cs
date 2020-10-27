using System;

namespace _21_Amicable_Numbers
{
    class Amicable_Numbers
    {
        static void Main(string[] args)
        {
            const int value = 10000;
            long answer = 0;
            long[] sum_of_divisors = new long[value];
            
            for (int i = 2; i < value; i++)
            {
                sum_of_divisors[i] = Sum_Divisors(i);
            }

            for (int i = 2; i< value; i++)
            {
                if (sum_of_divisors[i] < value && sum_of_divisors[i] != i && sum_of_divisors[sum_of_divisors[i]] == i)
                {
                    answer += i;
                }
            }

            Console.WriteLine("The sum of amicable numbers in 10000 is {0}", answer);
        }

        //Returns the sum of all divisors of n, but n;
        static long Sum_Divisors (int n)
        {
            long result = 1;
            int limit = (1 + (int)(Math.Sqrt(n)));
            for(int i = 2; i < limit; i++)
            {
                if(n % i == 0)
                {
                    result += i;
                    if(n != i * i)
                    {
                        result += (n / i);
                    }
                }
            }
            return result;
        }
    }
}
