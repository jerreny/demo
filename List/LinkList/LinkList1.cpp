# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALse 0
typedef int ElemType; 
typedef struct Node
{   ElemType data;
  struct Node *next;
}Node,* LinkList;
LinkList CreatLinkList();           //传送链表的地址,单独创建
void TravelLinkList(LinkList pHead);
void SortlLinkList(LinkList pHead);
bool EmptyLinkList(LinkList pHead);
void InsertLinkList(LinkList pHead,int i,ElemType e);
void DeletLinkList(LinkList pHead,int i,ElemType *e);
int main()
{ int insert_i;
  ElemType insert_e;
  int delet_i;
  ElemType delet_e;
  LinkList pHead=NULL;
  pHead=CreatLinkList();
  TravelLinkList(pHead);
  printf("在第几处插入元素为");
  scanf("%d %d",&insert_i,&insert_e);
  InsertLinkList(pHead,insert_i,insert_e);
  TravelLinkList(pHead);
  printf("在第几处删除元素");
  scanf("%d",&delet_i);
  DeletLinkList(pHead,delet_i,&delet_e);
  printf("删除的元素为%d\n",delet_e);
  TravelLinkList(pHead);
  printf("排序后的序列\n");
  SortlLinkList(pHead);
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
LinkList CreatLinkList(){
  /*最后返回头指针
    1、先创建头指针pHead,第一次结点创建赋值
    2、创建尾指针pTail，用于在新结点pNew的创建(利用for循环)
       每次创建结束都将尾部结点等于该节点，每次来节点将其放后面连接
  */
  int len;
  int i,val;
  printf("输入需要创建链表的长度=");
  scanf("%d",&len);
  LinkList pHead=(LinkList)malloc(sizeof(Node));    //创建的头结点的地址,为头结点分配内存空间
  LinkList pTail=pHead;
  pTail->next=NULL;
  for (i = 0; i < len; ++i)
   {  /*创建一个结点(新结点)之后将其赋值*/
      printf("The %dth value =",i+1);
      scanf("%d",&val);
      LinkList pNew=(LinkList)malloc(sizeof(Node));
      if(NULL==pNew)
      {
        printf("内存分配失败\n");
        exit(-1);
      }
      else
      { /*将每次创建的结点,对其指向的问题*/  
        pNew->data=val;
        pTail->next=pNew;
        pNew->next=NULL;
        pTail=pNew;
      }
    }
  return pHead;
}
void TravelLinkList(LinkList pHead){
   LinkList p=pHead->next;                             //指向第一个有效结点
   while(NULL!=p)
    {  printf("%5d",p->data);
       p=p->next;
    }
   printf("\n");
}

bool EmptyLinkList(LinkList pHead){
   if(NULL==pHead->next)
      return true;
   else
      return false;
}
void InsertLinkList(LinkList pHead,int pose,ElemType e)
{ LinkList p=pHead;
  int i=0;
  while(NULL!=p && i<pose-1)
  {
   p=p->next;
   ++i;
  }
  if(i>pose-1||p==NULL)
  {
   printf("插入出错\n");
   exit(-1);
  }
    LinkList pNew1=(LinkList)malloc(sizeof(Node)); 
    if (NULL==pNew1)
    {
      printf("动态内存分配出错\n");
      exit(-1);
    }
	  LinkList q=p->next;
	  pNew1->data=e;
    pNew1->next=q;
    p->next=pNew1;  
  }

//在其前插入
void DeletLinkList(LinkList pHead,int pose,ElemType *e){
   LinkList p=pHead;
  int i=0;
  while(NULL!=p->next && i<pose-1)
  {
   p=p->next;
   ++i;
  }
  if(i>pose-1||p->next==NULL)
  {
   printf("插入出错\n");
   exit(-1);
  }
    LinkList q=p->next;
    *e=q->data;
    p->next=q->next;
    free(q);
    q=NULL; 
}

void SortlLinkList(LinkList pHead){
  LinkList p=pHead->next;
  int len=0;
  while(NULL!=p){
    len++;
    p=p->next;
  }
  printf("链表长度=%d\n",len);
  p=pHead->next;
  LinkList q;
  int j,i;
  int t;
  for (i = 0; i < len-1; ++i,p=p->next)
       for (j=i+1,q=p->next; j<len; q=q->next,j++)
       { 
           if (p->data>q->data)
		   {  
                t=p->data;
                p->data=q->data;
                q->data=t;                
             }  
	   }      
}