#Python program to detect loop in linked list using the Floyd's Algorithm

#node class
class linkedListNode:
    
    #Initializing the node
    def __init__(self,data):
        self.data=data
        self.next= None

#Linked list class
class linkedList:

    #initialize the linked list
    def __init__(self):
        self.head = None

    #function to push data into the linked list
    def push(self, data):
        node = linkedListNode(data)
        node.next = self.head
        self.head = node

    #function to print the linked list
    def printLinkedList(self):
        temp= self.head
        while(temp):
            print(temp.data)
            temp = temp.next

    def loopDetectFloyd(self):
        slow = self.head
        fast = self.head
        while(slow and fast and fast.next):
            slow= slow.next
            fast= fast.next.next
            if slow == fast:
                return True