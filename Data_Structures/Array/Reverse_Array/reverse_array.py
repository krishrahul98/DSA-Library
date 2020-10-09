def reverse(lst):
    if lst == []:
        return []
    
    lst_rev = reverse(lst[1:])
    lst = lst[0:1]
    rev = lst_rev + lst
    return rev
def main():
    print(reverse([1,2,3,4,5]))

if __name__ == '__main__':
    main()