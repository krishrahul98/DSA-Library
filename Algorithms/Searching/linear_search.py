def linearSearch(arr,ele):
	for i in range(len(arr)):
		if arr[i]==ele:
			return i
	return -1
	
print(linearSearch([1,4,2,5,6,7,3],3))

#Algorithm:
#linearSearch(array,element to search(ele)):
#	for i=0 to len(array):
#		if check whether the given element matched at any index
#			return corresponding i
#	#if nothing found
#	return -1

