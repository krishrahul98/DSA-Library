#Function to left rotate arr[] of size n by k/ 
def leftRotate(arr, k): 
    n=len(arr)
    for i in range(k): 
        temp = arr[0] 
        for i in range(n-1): 
            arr[i] = arr[i+1] 
        arr[n-1] = temp 
    return arr
    
#Function to right rotate arr[] of size n by k/  
def rightRotate(arr, k): 
    arr2 = [] 
      
    # Will add values from n to the new list 
    for item in range(len(arr) - k, len(arr)): 
        arr2.append(arr[item]) 
      
    # Will add the values before 
    # n to the end of new list     
    for item in range(0, len(arr) - k):  
       arr2.append(arr[item])           
    return arr2
  
    
n = int(input("Enter number of elements : ")) 
arr = list(map(int,input("Enter Array: ").strip().split()))[:n]
d = input("Enter l or r : ")
k = int(input("Enter k: "))
if d=='r':
    s=rightRotate(arr, k) 
else:
    s=leftRotate(arr,k)
print(s) 