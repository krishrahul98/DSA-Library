from math import *

def is_prime(x):
    if x == 2:
        return True
    if x < 2 or x % 2 == 0:
        return False

    for y in range(3, ceil(sqrt(x)) + 1, 2):
        if x % y == 0:
            return False

    return True

def largest_prime_factor(number):
    for x in range(ceil(sqrt(number)), 0, -1):
        if number % x == 0 and is_prime(x):
            return x
    return None

print(largest_prime_factor(600851475143))
