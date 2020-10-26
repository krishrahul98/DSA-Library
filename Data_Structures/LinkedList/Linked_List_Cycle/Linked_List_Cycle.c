/*Using the Floyd's Cycle finding algorithm to detect a loop/ cycle in a linked list*/
#include <stdio.h> 
#include <stdlib.h> 
  
/* Link list node */
struct Node { 
    int data; 
    struct Node* next; 
}; 


 /* Floyd’s Cycle-Finding Algorithm*/
int detectCycle(struct Node* list) 
{ 
    struct Node *slow = list, *fast = list; 
  
    while (slow && fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
        if (slow == fast) { 
            return 1; 
        } 
    } 
    return 0; 
} 
/* push function to add new node*/  
void push(struct Node** head_ref, int data) 
{ 
    
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
   
    new_node->data = data; 
  
    
    new_node->next = (*head_ref); 
  
    (*head_ref) = new_node; 
} 

int main() 
{ 
    /* empty list */
    struct Node* head = NULL; 
   
   /*Creating list*/
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
  
    /* Creating a loop*/
    head->next->next->next->next = head; 
  
    if (detectCycle(head)) 
        printf("Cycle is present"); 
    else
        printf("No Cycle"); 
    return 0; 
} 