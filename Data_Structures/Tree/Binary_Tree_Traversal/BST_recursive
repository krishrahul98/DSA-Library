class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key


def recursivePreorder(root):
    if root is not None:
        print(root.val,end=" ")
        recursivePreorder(root.left)
        recursivePreorder(root.right)

def recursiveInorder(root):
    if root is not None:
        recursiveInorder(root.left)
        print(root.val,end=" "),
        recursiveInorder(root.right)

def recursivePostorder(root):
    if root is not None:
        recursivePostorder(root.left)
        recursivePostorder(root.right)
        print(root.val,end=" "),

root = Node(10)
root.left = Node(8)
root.right = Node(2)
root.left.left = Node(3)
root.left.right = Node(5)
root.right.left = Node(2)
root.right.right = Node(4)
print ("Preorder traversal of binary tree is\n")
recursivePreorder(root)
print ("\nInorder traversal of binary tree is\n")
recursiveInorder(root)
print ("\nPostorder traversal of binary tree is\n")
recursivePostorder(root)
print ("\n")
