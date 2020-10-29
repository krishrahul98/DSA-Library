import math


def jump_search(array, search_element):
    # Get The Jump Value

    jump = math.sqrt(len(array))
    current_part = 0

    # Get Which Part Of The Jumps x is

    while array[int(min(jump, len(array)) - 1)] < search_element:
        current_part = jump
        jump += math.sqrt(len(array))

        # Return -1 because x is bigger than any one the list

        if current_part >= len(array):
            return -1

    # Linear Search At The Part Of Jump

    jump = int(jump)
    current_part = int(current_part)
    final_part = current_part+jump

    for i in range(current_part, final_part):
        if array[i] == search_element:
            return i
        if current_part == min(jump, len(array)):
            return -1


# Test Code

lst = [
    1,
    2,
    3,
    5,
    6,
    12,
    13,
    15,
    16,
    19,
    213
]
print('Number to Search: ')
x = int(input())
ans = jump_search(lst, x)

# Prints pos if there is a result, and -1 if theres none

print(ans)
