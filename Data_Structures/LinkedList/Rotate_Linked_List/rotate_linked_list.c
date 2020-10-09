//Given a linked list, rotate the list to the right by k places, where k is non-negative.
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;


ListNode* insertNode(ListNode* head, int value) {

    // First allocate memory for the node and initialize with the value
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->val = value;

    if (head) {
        ListNode* temp = head;

        while (temp->next) {
            temp = temp->next;
        }

        temp->next = node;
    } else {
        head = node;
    }

    return head;
}


ListNode* rotateRight(ListNode* head, int k) {

    // If it's null or is a single element
    if (!head || !head->next) return head;

    int n = 1;
    ListNode* tail = head;

    // Get the last element in the list
    while (tail->next) {
        ++n;
        tail = tail->next;
    }

    k = k % n;

    // If rotation ends up in the original ordering
    if (k == 0) return head;

    ListNode* newHead = head;
    ListNode* newTail = head;

    // Rotation algorithm
    while (n > k) {
        newTail = newHead;
        newHead = newHead->next;
        --n;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;

}


void printLinkedList(ListNode* head) {

    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
}


int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    int value;
    ListNode* head = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertNode(head, value);
    }

    //Before rotation
    printf("Original List\n");
    printLinkedList(head);

    head = rotateRight(head, k);

    //After rotation
    printf("Clockwise Rotation by %d \n", k);
    printLinkedList(head);

    return 0;
}
/*
 * Input
 * 5 2
 * 1 2 3 4 5
 *
 * Output
 * Original List
 * 1 2 3 4 5
 * Clockwise Rotation by 2
 * 4 5 1 2 3
 */
