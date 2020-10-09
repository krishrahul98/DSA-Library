#include <bits/stdc++.h>
using namespace std;
//import required header files
typedef struct node{   //creates a linked list
    int data;
    struct node* left;
    struct node* right;
}node;
 
node* NewNode(int data);  //prototypes a new node function
node* InsertNode(node* root, int data);   //prototypes insert function
node* SearchTree(node* root, int search);  //prototypes search function
void Inorder(node* Node);  //prototypes inorder function
 
int main(){
    node* root = NULL;   //initializes root as NULL
    int option, data, search;  //declares variables
    while(1){   //while loop if true
        cout<<"1. To insert an element into the BST."<<endl;
        cout<<"2. To search for an element in the BST."<<endl;
        cout<<"3. To print Inorder traversal of BST."<<endl;
        cout<<"4. Exit."<<endl;
        cout<<"Enter your choice: ";
        cin>>option;
        switch(option){  //swithch on choices
            case 1: cout<<"Enter an element to insert into the BST: "<<endl;
                cin>>data;
                if (root == NULL){
                    root = InsertNode(root, data);  //calls the insert function
                }
                else{
                    InsertNode(root, data);
                }
                break;
            case 2: cout<<"Enter an element to search: "<<endl;
                cin>>search;
                SearchTree(root, search);  //calls the function to search the element in tree
                break;
            case 3: cout<<"Inorder Traversal: "<<endl;
                Inorder(root);  //calls the function to print the tree
                cout<<"\n";
                break;
            case 4: exit(0);  //exit the program
            default: cout<<"\nEnter a valid option!!!";  //print a message to the screen
        }
    }
    return 0;
}
 
node* NewNode(int data){
    node* temp = new node;  //allocates memory
    temp->data = data;   //sets data
    temp->left = temp->right = NULL;  //puts left and right nodes as NULL
    return temp;  //returns temp
}
 
node* InsertNode(node* Node, int data){  //function to create a node related to the value recieved
    if (Node == NULL){
        return NewNode(data);
    }
    if (data < Node->data){
        Node->left = InsertNode(Node->left, data);
    }
    else if (data > Node->data){
        Node->right = InsertNode(Node->right, data);
    }
    return Node;
}
 
node* SearchTree(node* Node, int search){   //function to search for element in the tree
    if (Node == NULL){
        cout<<"The entered element is not found in the BTS!!!"<<endl;
        return Node;
    }
    if (Node->data == search){
        cout<<"The element "<<search<<" is found in the BTS!!!"<<endl;
        
    }
    if (search < Node->data){
        SearchTree(Node->left, search);
    }
    else if (search > Node->data){
        SearchTree(Node->right, search);
    }
}
 
void Inorder(node* Node){    //inorder traversal function
    if (Node == NULL){
        return;
    }
    Inorder(Node->left);
    cout<<"-> "<<Node->data<<" ";
    Inorder(Node->right);
}
