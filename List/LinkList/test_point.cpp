# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
typedef int ElemType; 
typedef struct Node
{   ElemType data;
	struct Node *next;
}Node,* LinkList;

int main()
{  int val;
   LinkList pHead=(LinkList)malloc(sizeof(Node));
   LinkList pTail=pHead;
   printf("The %dth value =");
      scanf("%d",&val);
      LinkList pNew=(LinkList)malloc(sizeof(Node));
      if(NULL==pNew)
      {
        printf("�ڴ����ʧ��\n");
        exit(-1);
      }
      else
      { /*��ÿ�δ����Ľ��,����ָ�������*/  
        pNew->data=val;
        pTail->next=pNew;
        pNew->next=NULL;
        pTail=pNew;
      }
	  printf("%d",pHead->next->data);
	  return 0;
}