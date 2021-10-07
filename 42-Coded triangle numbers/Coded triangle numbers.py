word=input().lower()
summ=0
d=0
L=list(word)
for ele in L:
    num=int(ord(ele)-96)
    summ+=num
for i in range (0,summ):
    if i*(i+1)/2==summ:
        print("triangle word")
        d+=1
if d==0:
    print("not a triangle word")
    
