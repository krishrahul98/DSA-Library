word=input().lower()
sum=0
d=0
L=list(word)
for ele in L:
    num=int(ord(ele)-96)
    sum+=num
for i in range (0,sum):
    if i*(i+1)/2==sum:
        print("triangle word")
        d+=1
if d==0:
    print("not a triangle word")
    
