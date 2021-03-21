# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        t = node
        while t.next != None:
            t.val = t.next.val
            t = t.next
        tail = t
        t = node
        while t.next != tail:
            t = t.next

        t.next = None
