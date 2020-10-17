class Node:
    def __init__(self,data):
        self.left = None
        self.right = None
        self.val = data


def iterativePreorder(root):
    if root is None:
        return
    nodeStack = []
    nodeStack.append(root)
    while(len(nodeStack) > 0):
        node = nodeStack.pop()
        print(node.val,end=" ")
        if node.right is not None:
            nodeStack.append(node.right)
        if node.left is not None:
            nodeStack.append(node.left)

def iterativeInorder(root):
    current = root
    nodeStack = []
    while True:
        if current is not None:
            nodeStack.append(current)
            current = current.left
        elif(nodeStack):
            current = nodeStack.pop()
            print(current.val, end=" ")
            current = current.right
        else:
            break

def iterativePostorder(root):
	if root is None:
		return
	s1 = []
	s2 = []
	s1.append(root)
	while (len(s1)):
		node = s1.pop()
		s2.append(node)
		if node.left:
			s1.append(node.left)
		if node.right:
			s1.append(node.right)
	while s2:
		node = s2.pop()
		print(node.val,end=" ")

root = Node(10)
root.left = Node(8)
root.right = Node(2)
root.left.left = Node(3)
root.left.right = Node(5)
root.right.left = Node(2)
root.right.right = Node(4)
print ("Preorder traversal of binary tree is\n")
iterativePreorder(root)
print ("\nInorder traversal of binary tree is\n")
iterativeInorder(root)
print ("\nPostorder traversal of binary tree is\n")
iterativePostorder(root)
print ("\n")
