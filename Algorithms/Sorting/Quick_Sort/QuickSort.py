def splitting(arr, start, end):
    pivot = arr[start]
    low = start + 1
    high = end

    while True:
        while low<= high and arr[high]>= pivot:
            high = high - 1
        while low<= high and arr[low]<= pivot:
            low = low + 1
        if low <= high:
            arr[low],arr[high]=arr[high],arr[low]

        else:
           
            break

    arr[start],arr[high]=arr[high],arr[start]

    return high
def quicksort(arr, start, end):
    if start >= end:
        return

    p = splitting(arr, start, end)
    quicksort(arr, start, p-1)
    quicksort(arr, p+1, end)
arr = [29,27,41,66,28,44,58,88,83,12,21,44]

quicksort(arr, 0, len(arr) - 1)
print(arr)
