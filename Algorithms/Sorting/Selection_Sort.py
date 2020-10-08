def Selection_Sort(arr):
	for i in range(len(arr)):
		mins=i
		for k in range(i+1,len(arr)):
			if(arr[k] < arr[mins]):
				mins=k
				
		
		q=arr[i]
		arr[i]=arr[mins]
		arr[mins]=q
		#swapping is donr
	print(arr)
	
Selection_Sort([4,2,4,2,1,0,6,7])

#Algorith followed is:
#selection_Sort(array):
#	for i=0 to len(array):
#		mins=initial value of the given array
#		for k=i+1 to len(array):
#			if (any elemnet in array is less than our selected value in mins)
#				store its index in mins
#		swap the index i value with new mins value 
		#repeat the same thing for next set of array removing already sorted elements
