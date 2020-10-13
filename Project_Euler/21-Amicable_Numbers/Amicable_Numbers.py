def sum_divisors(n):
    # return the sum of proper divisors of n
    
    res = 1
    
    for i in range(2,1+int(n**0.5)):
        if n%i==0:
            res+=i
            if n!=i*i: # if proper square, just add once
                res+=int(n/i)
        
    return res

sum_of_divisors = [0]*10000 # store sum of divisors

for i in range(2,10000):
    sum_of_divisors[i] = sum_divisors(i)

ans = 0
for i in range(2,10000):
    if sum_of_divisors[i]<10000 and sum_of_divisors[i]!=i and sum_of_divisors[sum_of_divisors[i]]==i:
        ans += i

print(ans)
