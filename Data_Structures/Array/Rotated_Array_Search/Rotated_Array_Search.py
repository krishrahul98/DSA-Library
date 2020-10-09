def search(arr, target):
   l = 0
   r = len(arr)
   while l<r:
         mid = l + (r-l)//2
         if arr[mid] == target:
            return mid
         if arr[l]<=arr[mid]:
            if target >=arr[l] and target <arr[mid]:
               r = mid
            else:
               l = mid+1
         else:
            if target<=arr[r-1] and target>arr[mid]:
               l = mid+1
            else:
               r = mid
   return -1
print("enter an array:")
li=list(map(int,input().split(" ")))
print("Element you want to search:")
s=int(input())
position=search(li,s)
if position==-1:
   print("Given element is not present in Array")
else:
   print("Given element is present at position ",position+1)