class RandomListNode:
     def __init__(self, x):
         self.label = x
         self.next = None
         self.random = None
class Solution:
        # 返回 RandomListNode
        def Clone(self, pHead):
            # write code here
            if not pHead:
                return
            pFirst = pHead
            #先遍历，将赋值结点放置第一个节点之后
            while(pFirst):
                temp=pFirst.next
                pFirst_copy=RandomListNode(pFirst.label)
                pFirst.next=pFirst_copy
                pFirst_copy.next= temp
                pFirst=temp
            pFirst=pHead
            while(pFirst):
                if pFirst.random:
                     pFirst.next.random=pFirst.random.next
                pFirst=pFirst.next.next
            pFirst=pHead
            pScend=pHead.next
            while(pFirst.next):
                temp=pFirst.next
                pFirst.next=temp.next
                pFirst=temp
            return pScend


        def FindFirstCommonNode(self, pHead1, pHead2):
           # write code here,利用栈的思想，从尾部同时遍历两个链表
           node1=pHead1
           node2=pHead2
           list=[]
           while(node1):
               list.append(node1.val)
               node1=node1.next
           while(node2):
               if(node2.val in list):
                   return  node2
               else:
                   node2=node2.next







