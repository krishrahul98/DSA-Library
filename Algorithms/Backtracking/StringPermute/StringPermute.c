#include <stdio.h> 
#include <string.h> 

/* Function to swap values at two pointers */
void swap(char *x, char *y) 
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 

/* Function to print permutations of string 
   l -> starting index of the string
   r -> ending index of the string */
void permute(char *str, int l, int r) 
{ 
    int i; 
    if (l == r) 
        printf("%s\n", str); 
    else
    { 
        for (i = l; i <= r; i++) 
        { 
            swap((str+l), (str+i)); 
            permute(str, l+1, r); 
            swap((str+l), (str+i)); 
        } 
    } 
} 

int main() 
{ 
	char str[15];
    printf("Enter a string: ");
    scanf("%[^\n]", &str);
	int n = strlen(str); 
	permute(str, 0, n-1); 
	return 0; 
} 
