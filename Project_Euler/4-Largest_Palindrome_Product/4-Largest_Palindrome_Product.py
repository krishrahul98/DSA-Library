def find_palindrome():
    all_palindromes = (i * j
                       for i in reversed(range(100, 1000))
                       for j in reversed(range(100, 1000))
                       if str(i * j) == str(i * j)[::-1]
                       )

    return max(all_palindromes)

result = find_palindrome()
print('result: ', result)
