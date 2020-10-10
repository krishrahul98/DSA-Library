#include<stdio.h>
#include<stdlib.h>
struct node
{
int num;
struct node *left,*right;
}*start;
struct Stack
{
struct node *ptr;
struct Stack *next;
}*stackStart;
struct Queue
{
struct node*ptr;
struct Queue *next;
}*queueStart,*queueEnd;

void pushOnStack(struct node *ptr)
{
struct Stack *t;
t=(struct Stack*)malloc(sizeof(struct Stack));
t->ptr=ptr;
t->next=stackStart;
stackStart=t;
}

struct node *popFromStack()
{
struct Stack*t;
struct node*elem;
t=stackStart;
stackStart=stackStart->next;
elem=t->ptr;
free(t);
return elem;
}

struct node* elementAtTop()
{
return stackStart->ptr;
}

int isStackEmpty()
{
return stackStart==NULL;
}

void addToQueue(struct node*ptr)
{
struct Queue*t;
t=(struct Queue*)malloc(sizeof(struct Queue));
t->ptr=ptr;
t->next=NULL;
if(queueStart==NULL)
{
queueStart=t;
queueEnd=t;
}
else
{
queueEnd->next=t;
queueEnd=t;
}
}

struct node*removeFromQueue() 
{
struct node*elem;
struct Queue*t;
t=queueStart;
queueStart=queueStart->next;
if(queueStart==NULL)queueEnd=NULL;
elem=t->ptr;
free(t);
return elem;
}

int isQueueEmpty()
{
return queueStart==NULL;
}

int InsertInBSTTree(int num)
{
struct node*t,*j;
t=(struct node*)malloc(sizeof(struct node));
t->num=num;
t->left=NULL;
t->right=NULL;
if(start==NULL)
{
start=t;
return 1;
}
j=start;
while(1)
{
if(j->num==num)
{
while(!isStackEmpty())
{
popFromStack();
}
free(t);
return 0;
}
if(num<j->num)
{
if(j->left==NULL)
{
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
return 1;
}

int RemoveFromBSTTree(int num)
{
struct node*j,*t,*e,*f;
t=start;
while(t!=NULL)
{
if(t->num==num)break;
j=t;
if(num<t->num)t=t->left;
else t=t->right;
}
if(t==NULL)
{
return 0;
}
if(t->left==NULL&&t->right==NULL)
{
if(start==t) start=NULL;
else if(j->left==t) j->left=NULL;
else j->right=NULL;
}
else
{
if(t->right!=NULL)
{
for(e=t->right;e->left!=NULL;e=e->left)
{
f=e;
}
if(e==t->right)e->left=t->left;
else
{
f->left=e->right;
e->left=t->left;
e->right=t->right;
}
if(start==t)start=e;
else if(j->left==t)j->left=e;
else j->right=e;
}
else
{
for(e=t->left;e->right!=NULL;e=e->right)
{
f=e;
}
if(e!=t->left)
{
f->right=e->left;
e->left=t->left;
e->right=t->right;
}
if(start==t)start=e;
else if(j->left==t)j->left=e;
else j->right=e;
}
}
free(t);
return 1;
}

int SearchInBSTTree(int num)
{
struct node*t;
t=start;
while(t!=NULL)
{
if(t->num==num)return 1;
if(num<t->num)t=t->left;
else t=t->right;
}
return 0;
}
void TreverseInorderWithoutRecursive()
{
struct node*t,*j;
if(start==NULL)
{
printf("No element in BST Tree\n");
return;
}
for(t=start;t!=NULL;t=t->left)pushOnStack(t);
while(!isStackEmpty())
{
t=popFromStack();
printf("%d\n",t->num);
if(t->right!=NULL)
{
for(j=t->right;j!=NULL;j=j->left)pushOnStack(j);
}
}
return;
}
void TreversePostorderWithoutRecursive()
{
struct node*t;
if(start==NULL)
{
printf("No element in BST Tree\n");
return ;
}
t=start;
while(1)
{
while(t!=NULL)
{
if(t->right!=NULL)pushOnStack(t->right);
pushOnStack(t);
t=t->left;
}
t=popFromStack();
if(!isStackEmpty()&&t->right!=NULL&&t->right==elementAtTop())
{
popFromStack();
pushOnStack(t);
t=t->right;
}
else
{
printf("%d\n",t->num);
t=NULL;
}
if(isStackEmpty())break;
}
}
void TreversePreorderWithoutRecursive()
{
struct node*t;
if(start==NULL)
{
printf("No elemnet in BST Tree\n");
return;
}
t=start;
pushOnStack(t);
while(!isStackEmpty())
{
t=popFromStack();
printf("%d\n",t->num);
if(t->right!=NULL)pushOnStack(t->right);
if(t->left!=NULL)pushOnStack(t->left);
}
}
void TreverseInorderUsingRecursive(struct node*root)
{
if(root==NULL)return;
if(root->left!=NULL)TreverseInorderUsingRecursive(root->left);
printf("%d\n",root->num);
if(root->right!=NULL)TreverseInorderUsingRecursive(root->right);
}
void TreversePostorderUsingRecursive(struct node*root)
{
if(root==NULL)return ;
if(root->left)TreversePostorderUsingRecursive(root->left);
if(root->right)TreversePostorderUsingRecursive(root->right);
printf("%d\n",root->num);
}
void TreversePreorderUsingRecursive(struct node*root)
{
if(root==NULL)return;
printf("%d\n",root->num);
if(root->left)TreversePreorderUsingRecursive(root->left);
if(root->right)TreversePreorderUsingRecursive(root->right);
}
int main()
{
int ch,num;
queueStart=NULL;
queueEnd=NULL;
start=NULL;
stackStart=NULL;
while(1)
{
printf("1.Insert in BST Tree\n");
printf("2.Remove From BST Tree\n");
printf("3.Search In BST Tree\n");
printf("4.Treverse(Inorder Without Recursive)\n");
printf("5.Treverse(Postorder Without Recursive)\n");
printf("6.Treverse(Preorder Without Recursive)\n");
printf("7.Treverse(Inorder Using Recursive)\n");
printf("8.Treverse(Postorder Using Recursive)\n");
printf("9.Treverse(Preorder Using Recursive)\n");
printf("10.Exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
fflush(stdin);
if(ch==1)
{
printf("Enter the number to be insert in BST Tree:");
scanf("%d",&num);
fflush(stdin);
if(InsertInBSTTree(num))printf("%d is inserted in BST Tree\n",num);
else printf("%d is already inserted in BST Tree hence, its is not inserted in BST Tree\n",num);
}
if(ch==2)
{
printf("Enter the number to be Remove from BST Tree :");
scanf("%d",&num);
fflush(stdin);
if(RemoveFromBSTTree(num))printf("%d is remove from BST Tree\n",num);
else printf("%d is not inserted in BST,henec can't remove from BST Tree\n",num);
}
if(ch==3)
{
printf("Enter the number to be search in BST Tree:");
scanf("%d",&num);
fflush(stdin);
if(SearchInBSTTree(num))printf("%d is Present in BST Tree\n",num);
else printf("%d is not present in BST Tree\n",num);
}
if(ch==4)
{
TreverseInorderWithoutRecursive();
}
if(ch==5)
{
TreversePostorderWithoutRecursive();
}
if(ch==6)
{
TreversePreorderWithoutRecursive();
}
if(ch==7)
{
TreverseInorderUsingRecursive(start);
}
if(ch==8)
{
TreversePostorderUsingRecursive(start);
}
if(ch==9)
{
TreversePreorderUsingRecursive(start);
}
if(ch==10)break;
}
return 0;
}