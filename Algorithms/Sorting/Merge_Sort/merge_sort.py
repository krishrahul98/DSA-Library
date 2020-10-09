def merge_sort(seq, start, mid, stop):
    lst = []
    i = start
    j = mid

    while i < mid and j<stop:
        if seq[i] < seq[j]:
            lst.append(seq[i])
            i += 1
        else:
            lst.append(seq[j])
            j+=1
    
    while i<mid:
        lst.append(seq[i])
        i+=1
    while j<stop:
        lst.append(seq[j])
        j+=1
    
    for i in range(len(lst)):
        seq[start + i] = lst[i]

def main():
    q = [12, 32, 24, 54, 87,98,65,22]
    mid = len(q)//2
    merge_sort(q,0,mid,len(q))
if __name__ == '__main__':
    main()