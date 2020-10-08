def bubblesort(arr):
	for i in range(len(arr)):
		for j in range(len(arr)-i-1):
			if(arr[j+1] < arr[j]):
				p=arr[j]
				arr[j]=arr[j+1]
				arr[j+1]=p
				#swaping if number less is found
	print(arr)

bubblesort([10,2,3,5,2,1,0])

#algorithm :
#bubblesort(array):
#	for i=0 to len(array): #checking entire array
#		for j=0 to index of last unsorted element(len(arr)-i)-1
#			if previous element > current element
#				swap both
	
