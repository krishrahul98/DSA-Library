#include <stdio.h>
void rev(int arr[],int rarr[],int n){
    int i;
    for(i=0;i<n;i++){
        rarr[i]=arr[n-1-i];
    }
}
int main()
{
    int i, num;
    printf("Enter the size of array : ");
    scanf("%d", &num);
    int array[num],revarr[num];
    printf("Enter the elements: ");
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]);
    printf("\nThe array before reversal: \n");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);
    printf("\nThe array of elements after reversal : \n");
    rev(array,revarr, num);
    for (i = 0; i < num; i++)
        printf("%d ", revarr[i]);
    printf("\n");
    return 0;
}
