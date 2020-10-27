#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 

/*
	FLOYD'S TORTOISE AND HARE CYCLE DETECTION ALGORITHM

	1. LOOP DETECTION

    -	Traverse linked list using two pointers.
    -	Move one pointer(slow pointer) by one and another pointer(fast pointer) by two.
    -	If these pointers meet at the same node then there is a loop. If pointers do not
    	meet then linked list doesn't have a loop.

    2. FINDING THE FIRST NODE WHERE THE CYCLE BEGINS


    -	If a loop is found, initialize a slow pointer to head, let fast pointer be at its position.
    -	Move both slow and fast pointers one node at a time.
    -	The point at which they meet is the start of the loop


*/
struct ListNode { 

	int data; 
	struct ListNode* next; 
}; 

void push(struct ListNode** head_ref, int new_data) 
{ 
	struct ListNode* newNode = new ListNode; 
	newNode->data = new_data; 

	newNode->next = (*head_ref); 

	(*head_ref) = newNode; 
} 


ListNode *detectCycle(ListNode *head) 
{
    ListNode *h, *t;
    int flag = 0;
    //find if there is a cycle or not
    h = head;
    t = head;
    while(h && h->next && !flag)
    {
        t = t->next;            //move tortoise by one step
        h = (h->next)->next;    //move hare by two steps.. if they meet, then cycle is there.. otherwise, cycle is not there
        
        if(t == h)
            flag = 1;
    }
    if(flag == 0)
        return NULL;

    //finding the node where the cycle begins
    t = head;
    while(t != h)
    {
        t = t->next;
        h = h->next;
    }
    
    return t;
        
}

int main() 
{ 
	struct ListNode* head = NULL; 

	push(&head, 20); 
	push(&head, 4); 
	push(&head, 15); 
	push(&head, 10); 

	/* Creating a loop for testing */
	head->next->next->next->next = head; 

	if (detectCycle(head)) 
		cout << "Loop found" << endl; 
	else
		cout << "No Loop" << endl; 

	return 0; 
} 


