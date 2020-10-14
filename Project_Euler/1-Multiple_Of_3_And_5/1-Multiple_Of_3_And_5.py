sum = 0 
# If i is divisible by 3 or 5, add to sum
for i in range(100):
    if (i%3 == 0 or i%5==0):
        sum += i
 
# Print answer
print('The sum is: ' + str(sum))
