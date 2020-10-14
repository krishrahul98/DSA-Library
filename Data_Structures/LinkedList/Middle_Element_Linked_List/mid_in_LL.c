#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void insert(node**l,int num)
{
    node *p=(node*)malloc(sizeof(node));
    if(p!=NULL){
    p->info=num;
    p->next=NULL;
    if((*l)==NULL)*l=p;
    else{(*l)->next=p;*l=p;}
    }
    else
        printf("MEMORY ERROR!");
}
void display(node *f)
{
    while(f!=NULL)
    {
        printf("%d ",f->info);
        f=f->next;
    }
}
void mid(node *f)
{
    node *fast=f,*slow=f;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("MID ELEMENT : %d ",slow->info);
    if(fast->next!=NULL)
    printf("%d",slow->next->info);
}
int main()
{
    node *first=NULL,*last=NULL;
    char ch;int n;
    do
    {
        printf("Enter the element you want to enter :");
        scanf("%d",&n);
        insert(&last,n);
        if(first==NULL)first=last;
        printf("Do you want to continue..Y/N");
        fflush(stdin);
        scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    display(first);
    mid(first);
}
