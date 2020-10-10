"""
Question:
Given a linked list, rotate the list to the right by k places, where k is non-negative.
Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
"""


class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def __repr__(self):
        if self:
            return "{} -> {}".format(self.val, self.next)


class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head or not head.next:
            return head

        current = head
        n = 1
        while current.next:
            current = current.next
            n += 1

        current.next = head
        current = head
        tail = current
        k = n - k % n  # find the shift position

        for _ in range(k):
            tail = current
            current = current.next
        tail.next = None

        return current


if __name__ == "__main__":
    n5 = ListNode(5)
    n4 = ListNode(4)
    n3 = ListNode(3)
    n2 = ListNode(2)
    n1 = ListNode(1)
    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5
    test = Solution().rotateRight(n1, 2)
    print(test)
