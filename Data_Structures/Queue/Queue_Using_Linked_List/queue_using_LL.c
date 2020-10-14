//Using Dynamic Allocation
//node *Add_left(node*);
// node*left=NULL;
//node* add-left(node *L)
//int x=0; scanf("%d",&x);
//p=(node *)malloc(sizeof(node));
////p->info=x;
//p->next=L;
//L=p;
//return L;
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
node* push()
{
    node*temp=(node*)malloc(sizeof(node));
    if(temp==NULL)printf("Not enough memory\n");
    else{
    scanf("%d",&(temp->info));
    temp->next=NULL;
    return(temp);}
}
void display(node *f,node *r)
{
    while
        (f!=r)
    {
        printf("%d",f->info);
        f=f->next;
    }printf("%d",f->info);
}
node* pop(node*tp)
{
    node *temp=tp;
    tp=tp->next;
    free(temp);
    return(tp);
}

int main()
{
    node *f=NULL,*r=NULL;
        char ch;int n;
    do
    {
        printf("Enter 1: to insert\n2: to serve\n3: to display\n");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            if(f==NULL){r=push();f=r;}
            else{ r->next=push();r=r->next;}
            break;
        case 2:
            if(f==-1)
                {printf("Underflow\n");
                }
           /* else
                f=serve(queue,f,r);
                if(f==-1)r=-1;
                break;*/
        case 3:
            if(f==NULL)
            {
                printf("No element to display\n");
            }
            else
            {
                display(f,r);
            }
        }printf("\nDo you wish to continue: Y/N");
        fflush(stdin);
            scanf("%c",&ch);

    }while(ch=='Y'||ch=='y');
}
