/* C program to merge two sorted linked lists (using recursion)*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Link list node */
struct Node
{
    int data;
    struct Node *next;
};

/* pull off the front node of the source and put it in dest */
void MoveNode(struct Node **destRef, struct Node **sourceRef);

/* Takes two lists sorted in increasing order, and splices
their nodes together to make one big sorted list which
is returned. */
struct Node *SortedMerge(struct Node *a, struct Node *b)
{
    struct Node *result = NULL;

    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    /* Pick either a or b, and recur */
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

/* UTILITY FUNCTIONS */
/* MoveNode() function takes the node from the front of the
source, and move it to the front of the dest.
It is an error to call this with the source list empty.

Before calling MoveNode():
source == {1, 2, 3}
dest == {1, 2, 3}

Affter calling MoveNode():
source == {2, 3}
dest == {1, 1, 2, 3} */
void MoveNode(struct Node **destRef, struct Node **sourceRef)
{
    /* the front source node */
    struct Node *newNode = *sourceRef;
    assert(newNode != NULL);

    /* Advance the source pointer */
    *sourceRef = newNode->next;

    /* Link the old dest off the new node */
    newNode->next = *destRef;

    /* Move dest to point to the new node */
    *destRef = newNode;
}

/* Function to insert a node at the beginging of the
linked list */
void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node *res = NULL;
    struct Node *a = NULL;
    struct Node *b = NULL;

    /* Getting user input for first linkedlist */
    printf("Enter the size of fisrt linked list: ");

    int sizeof_linkedlist1;
    scanf("%d", &sizeof_linkedlist1);

    printf("Enter space separated inputs for the first linked list: ");
    int input1;
    for (int i = 0; i < sizeof_linkedlist1; i++)
    {
        scanf("%d", &input1);
        push(&a, input1);
    }

    /* Getting user input for second linkedlist */
    printf("Enter the size of second linked list: ");

    int sizeof_linkedlist2;
    scanf("%d", &sizeof_linkedlist2);

    printf("Enter space separated inputs for the linked list: ");
    int input2;
    for (int i = 0; i < sizeof_linkedlist2; i++)
    {
        scanf("%d", &input2);
        push(&b, input2);
    }

    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);

    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
}
