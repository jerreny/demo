# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType; 
typedef int Status;
typedef struct Node
{   ElemType data;
  struct Node *next;
}Node,* LinkList;
void CreatLinkListAll(LinkList *L,int n);           
void TravelLinkList(LinkList pHead);
Status ClearLinkList(LinkList *L);
int main()
{ Status flag;
  LinkList pHead=NULL;
  CreatLinkListAll(&pHead,4);
  TravelLinkList(pHead);
  flag=ClearLinkList(&pHead);
  printf("�Ƿ�ȫ��ɾ��%5d",flag);
  TravelLinkList(pHead);
  return 0;
}
//插队创建整个链表
void CreatLinkListAll(LinkList *L,int n){
   LinkList p;
   int i;
   *L=(LinkList)malloc(sizeof(Node));
   (*L)->next=NULL;
   for(i=0;i<n;i++){
     p=(LinkList)malloc(sizeof(Node));
     p->data=rand()%100+1;
     p->next=(*L)->next;
     (*L)->next=p;
   }
}

void TravelLinkList(LinkList pHead){
   LinkList p=pHead->next;                             //指向第一个有效结点
   while(NULL!=p)
    {  printf("%5d",p->data);
       p=p->next;
    }
}
Status ClearLinkList(LinkList *L){
  LinkList p,q;
  p=(*L)->next;
  /*
   1、将p指向第一个有效结点
   2、q指向p后面的一个结点
   3、循环，一次将头结点后面的第一个有效结点释放free
   */
  while(p){
   q=p->next;
   free(p);
   p=q;
   }
   (*L)->next=NULL;
   return OK;
}


