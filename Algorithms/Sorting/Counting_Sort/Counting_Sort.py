def countSort(arr):
	maxl=max(arr)
	cntarray=[]
	cumuarray=[]#this list stores cumulative count which helps in placing final sorted array
	finalOut=[]
	for i in range(len(arr)):
		finalOut.append(0)
	
	for i in range(maxl+1):
		cntarray.append(0)
		cumuarray.append(0)
		
		
	for i in arr:
		cntarray[i]=cntarray[i]+1
		
	for i in range(len(cntarray)):
		if(i>0 and i<maxl+1):
			cumuarray[i]=cumuarray[i-1]+cntarray[i]
	for i in arr:
		finalOut[cumuarray[i]-1]=i
		cumuarray[i]=cumuarray[i]-1
			
	print(cntarray)
	print(cumuarray)
	print(finalOut)
	
countSort([4,2,2,8,3,3,1])
			
	
		
