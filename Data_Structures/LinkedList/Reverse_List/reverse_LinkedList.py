# Python program to reverse a linked list
# Time Complexity : O(n)
# Space Complexity : O(1)

# Node Class
class Node:
    # Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None  # In python, None == null


class LinkedList:
    # Constructor to initialize the linked list
    def __init__(self):
        self.head = None

    # Function to insert a new node at the beginning
    def push(self, data):
        node = Node(data)  # This is how you create an object in python
        node.next = self.head
        self.head = node

    # Function to insert a new node at the end
    def append(self, data):
        node = Node(data)
        currentNode = self.head
        while currentNode.next is not None:
            currentNode = currentNode.next
        currentNode.next = node

    # Function to remove a node
    def remove(self, data):
        currentNode = self.head

        if currentNode.data == data:
            self.head = self.head.next
            return

        while currentNode.next is not None:
            if currentNode.next.data == data:
                currentNode.next = currentNode.next.next
                return

            currentNode = currentNode.next

    # Function to search for a node
    def search(self, data):
        currentNode = self.head
        if currentNode.data == data:
            return currentNode

        while currentNode.next is not Node:
            if currentNode.next.data == data:
                return currentNode.next
            currentNode = currentNode.next

        return None

    # Function to reverse the linked list
    def reverse(self):
        temp = self.head  # save the head to a temp linked list
        self.head = None  # reset to None

        while temp is not None:
            self.push(temp.data)  # push to the head of the empty linked list
            temp = temp.next

    # Function to reverse the every k nodes in the linked list
    def reverseWithK(self, head, k):
        current = head
        next = None
        temp = None
        count = 0

        # Reverse first k nodes of the linked list
        while(current is not None and count < k):
            next = current.next
            current.next = temp
            temp = current
            current = next
            count += 1

        # next is now a pointer to (k+1)th node
        # recursively call for the list starting
        # from current . And make rest of the list as
        # next of first node (head)
        if next is not None:
            head.next = self.reverseWithK(next, k)

        # temp is new head of the reversed list
        return temp

    # Utility function to print the linked list

    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data),
            temp = temp.next


linkedlist = LinkedList()
linkedlist.push('Siddhant')
linkedlist.push('Rahul')
linkedlist.push('DSA-Library')
linkedlist.append('XYZ')
linkedlist.remove('XYZ')
linkedlist.reverse()
linkedlist.printList()


# Driver program
llist = LinkedList()
llist.push(9)
llist.push(8)
llist.push(7)
llist.push(6)
llist.push(5)
llist.push(4)
llist.push(3)
llist.push(2)
llist.push(1)

print("\nGiven linked list")
llist.printList()
llist.head = llist.reverseWithK(llist.head, 3)

print("\nReversed Linked list with k node")
llist.printList()

""" 
Output =>

Siddhant
Rahul
DSA-Library      

Given linked list
1
2
3
4
5
6
7
8
9

Reversed Linked list with k node
3
2
1
6
5
4
9
8
7

"""
