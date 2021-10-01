#include<bits/stdc++.h>
#define SIZE 10

class Node {
    public:
        int number;
        Node *next;

        void print_chain(){
            printf("( %d )",this->number);
            Node *temp = next;
            while(temp!=NULL){
                printf("( %d )",temp->number);
                temp = temp->next;
            }
        }
};

void insert_node_to_chain(int value, Node **head){
    Node *ptr = (*head);
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->number = value;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }
    else{
        while(ptr->next !=NULL){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

int main(){
    Node *hash_table[SIZE];
    for(int i=0; i<SIZE; i++){
        hash_table[i]=NULL;
    }
    while(1){
        system("clear");
        for(int i=0; i<SIZE; i++){
            Node *ptr = hash_table[i];
            printf("[%d]--> ",i);
            if(ptr!=NULL) ptr->print_chain();
            printf("\n");
        }
        std::cout << "Enter new node: ";
        int input;
        scanf("%d",&input);
        insert_node_to_chain(input, &hash_table[input%10]);
    }
    return 0;
}
