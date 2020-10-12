# Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1
'''
	Function to merge two sorted lists in one
	
	Function Arguments: head_a and head_b (head reference of both the sorted lists)
	Return Type: head of the obtained list after merger.

	{
		# Node Class
		class Node:
		    def __init__(self, data):   # data -> value stored in node
		        self.data = data
		        self.next = None
	}

'''
def sortedMerge(head_A, head_B):

    head_res = None
    res = None

    while head_A is not None and head_B is not None:

        if head_A.data < head_B.data:
            if res:
                res.next = Node(head_A.data)
                res = res.next
            else:
                res = Node(head_A.data)
                head_res = res
            head_A = head_A.next

        else:
            if res:
                res.next = Node(head_B.data)
                res = res.next
            else:
                res = Node(head_B.data)
                head_res = res
            head_B = head_B.next
        
    if head_A is None:
        if res:
            res.next = head_B
        else:
            res = head_B
            head_res = res
    
    if head_B is None:
        if res:
            res.next = head_A
        else:
            res = head_A
            head_res = res

    return head_res