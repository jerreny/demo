# -*- coding: utf-8 -*-
"""
Created on Sat Dec  8 16:07:55 2018

@author: Administrator
"""
import chaintable
def FindKthToTail(self, head, k):
        # write code here
        l=[]
        while head!=None:
            l.append(head)
            head=head.next
        if k>len(l) or k<1:
            return
        return l[-k]#从零索引的节点输出的链表
def __repr__(self):
        return str(self.data)
def main(argv=None):
    chain1=chaintable.ChainTable()
    for i in range(7):
       chain1.append(i)
    L=FindKthToTail(chain1,2)
    data=L._repr_()
    print(data)
