//Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* h1, Node* h2)  
{  
    Node* h3 = NULL;
    Node* last = NULL;
    if(h1->data < h2->data)
    {
        last = h3 = h1;
        h1 = h1->next;
        h3->next = NULL;
    }
    else{
        last = h3 = h2;
        h2 = h2->next;
        h3->next = NULL;
    }
    
    while(h1!=NULL && h2!=NULL)
    { 
        if(h1->data < h2->data)
        {
            last->next = h1;
            last = h1;
            h1 = h1->next;
            last->next = NULL;
        }
        else
        {
            last->next = h2;
            last = h2;
            h2 = h2->next;
            last->next = NULL;
        }
    }
    
    if(h1)
        last->next = h1;
    else
        last->next = h2;
    
    return h3;
}  
