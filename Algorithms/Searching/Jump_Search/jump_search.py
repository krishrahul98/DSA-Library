import math
def jumpSearch(lst, x):
    #Get The Jump Value
    jump = math.sqrt(len(lst))
    currentPart = 0

    #Get Which Part Of The Jumps x is
    while lst[int(min(jump, len(lst))-1)] < x:
        currentPart = jump
        jump += math.sqrt(len(lst))
        #Return -1 because x is bigger than any one the list
        if currentPart >= len(lst):
            return -1
    #Linear Search At The Part Of Jump
    for i in range(int(currentPart), int(currentPart) + int(jump), 1):
        if lst[i] == x:
            return x
        if currentPart == min(jump, len(lst)):
            return -1
#Test Code
lst = [1,2,3,4,5,6,7,8,9,10,11,12,13,15,16,19,213]
x = eval(input("Number To Search"))
ans = jumpSearch(lst, x)
#Prints x if there is a result, and -1 if theres none
print(ans)