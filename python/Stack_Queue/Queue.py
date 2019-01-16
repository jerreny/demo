'''
A用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
1、栈一个口，先进后出；
2、队列，两个口，先进先出
'''
'''
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
    def __init__(self):
        self.stack=[]
    def push(self, node):
        self.stack.append(node)
    def pop(self):
        self.stack.pop()
    def top(self):
        len(self.stack)
    def min(self):
        min(self.stack)
'''
'''
输入两个整数序列，第一个序列表示栈的压入顺序，
请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）

'''
import sys
# -*- coding:utf-8 -*-
class Stack_Order(object):
    def IsPopOrder(self, pushV, popV):
        stack=[]
        j=0
        if len(pushV)==0:
            return False
        for i in range(len(pushV)):
            stack.append(pushV[i])
            while j<len(popV) and stack[-1]==popV[j] :
                  stack.pop()
                  j+=1
        if len(stack)==0:
            return True
        else:
            return False







def main():
    SS=Stack_Order()
    p_push = sys.stdin.readline().strip()
    p_stack = sys.stdin.readline().strip()
    print (SS.IsPopOrder(p_push,p_stack ))


if __name__ == '__main__':
    main()


class Stack_min(object):
    def __init__(self):
            self.stack = []
            self.min_stack = []

    def push(self, node):
            # write code here
            self.stack.append(node)
            if not self.min_stack or node <= self.min_stack[-1]:
                self.min_stack.append(node)

    def pop(self):
            # write code here
            if self.stack[-1] == self.min_stack[-1]:
                self.min_stack.pop()
            self.stack.pop()

    def top(self):
            # write code here
            return self.stack[-1]

    def min(self):
            # write code here
            return self.min_stack[-1]


class QueueWithTwoStacks(object):
    def __init__(self):
        self.stack1=[]
        self.stack2=[]

    def push(self, node):
        self.stack1.append(node)
    def pop(self):
        if self.stack2==[]:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return  self.stack2.pop()
    def getQueue(self):
        return self.stack1
'''
if __name__ == '__main__':
    C= QueueWithTwoStacks()
    C.push(1)
    C.push(2)
    C.push(3)
    print(C.getQueue())
    print(C.pop())
    print(C.pop())
    print(C.pop())

'''

