countSort(array):
	maxl= max element in the given array
	initialize a final output array with all zeros with size maxl+1
	initialize countarray and cumulative array with all zeros with size len(array)
	for i in array
		store count of each element in array in count array
	for i in range(len(count array))
		store cumulative count i.e present i and i-1
		#we can store directly in count array also 
	for i in array:
		find the index of i in cumulative array
		store i in final output array as finaloutput[index-1]=i
		decrease count in cumuative array
	
here instead of taking many arrays we can deal using only 2 arrays. instead of cumulative array we can update or restore inside count array and instead of final output array we can restore inside given array and finally print it.

This code I have developed for when the given array as integers in it.
if the fiven array has strings or characters, we need to do the sorting based on their ascii code. instead of integers store their ascii values and the process is same. Use ord('A') for ascii conversion. 
