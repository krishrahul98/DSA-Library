# cook your dish here
def radixSort(arr):
    rad= 10
    maxlen = False
    
    tmp=-1
    placement=1
    
    while not maxlen:
        maxlen = True
        buckets = [list() for _ in range(rad)]
        for  i in arr:
            tmp = i // placement
            buckets[tmp % rad].append(i)
            if maxlen and tmp > 0:
                maxlen = False

        a = 0
        for b in range(rad):
            buck = buckets[b]
            for i in buck:
                arr[a] = i
                a=a+1
        placement =placement*rad
    return arr
    
arr= [10,26,41,11,19]
print(radixSort(arr))
