#Function to print the permutation of a given input string

#function inputs a string as list, the start location and the end location
def stringPermute(per,left,right):
    if left==right:
        print("".join(per))
    else:
        for i in range(left,right+1):
            per[left], per[i] = per[i], per[left] 
            stringPermute(per, left+1, right) 
            per[left], per[i] = per[i], per[left]

string=input("Enter a string- ")  #give input string
init_index=0  #initial index
last_index=len(string)-1  #index of last element
print("Permutations are- ")
stringPermute(list(string),init_index,last_index) 