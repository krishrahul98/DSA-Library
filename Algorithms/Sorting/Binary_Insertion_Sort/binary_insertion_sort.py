# Goal: Sort a given integer array using binary insertion approach

def binary_search(given_array, key, start, end):
    if end - start <= 1:
        if key < given_array[start]:
            return start - 1
        return start
    mid = (start + end) // 2
    if given_array[mid] < key:
        return binary_search(given_array, key, mid, end)
    if given_array[mid] > key:
        return binary_search(given_array, key, start, mid)
    return mid


def insertion_sort(given_array):
    for i in range(1, len(given_array)):
        temp = given_array[i]
        pos = binary_search(given_array, temp, 0, i) + 1
        for k in range(i, pos, -1):
            given_array[k] = given_array[k - 1]
        given_array[pos] = temp


array_to_sort = [1, 55, 3, 45, 8, 6, 35, 24, 0, 9, 1334]
insertion_sort(array_to_sort)
print(array_to_sort)
