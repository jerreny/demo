'''
A--给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
B--在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
   重复的结点不保留，返回链表头指针。
'''
class Chain(object):
    def deleteDuplication(self, pHead):
        if pHead is None or pHead.next is None:
            return pHead
        head1 = pHead.next
        if head1.val != pHead.val:
            pHead.next = self.deleteDuplication(pHead.next)
        else:
            while pHead.val == head1.val and head1.next is not None:
                head1 = head1.next
            if head1.val != pHead.val:
                pHead = self.deleteDuplication(head1)
            else:
                return None
        return pHead








