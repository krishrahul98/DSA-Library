# Python program for implementation of Insertion Sort 

def insertionSort(arr): 

	for i in range(1, len(arr)): 

		key = arr[i] 
		j = i-1
		while j >= 0 and key < arr[j] : 
				arr[j + 1] = arr[j] 
				j -= 1
		arr[j + 1] = key 


# Driver code to test above 

n=int(input("Enter number of elements: "))
print("Enter the elements: ")
arr = list(map(int,input().split())) 
insertionSort(arr) 
print("\nSorted array is: ")
for i in range(n): 
	print (arr[i], end=" ") 
