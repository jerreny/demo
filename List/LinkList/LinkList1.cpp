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
LinkList CreatLinkList();           //��������ĵ�ַ,��������
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
  printf("�ڵڼ�������Ԫ��Ϊ");
  scanf("%d %d",&insert_i,&insert_e);
  InsertLinkList(pHead,insert_i,insert_e);
  TravelLinkList(pHead);
  printf("�ڵڼ���ɾ��Ԫ��");
  scanf("%d",&delet_i);
  DeletLinkList(pHead,delet_i,&delet_e);
  printf("ɾ����Ԫ��Ϊ%d\n",delet_e);
  TravelLinkList(pHead);
  printf("����������\n");
  SortlLinkList(pHead);
  TravelLinkList(pHead);
  return 0;
}
//��Ӵ�����������
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
  /*��󷵻�ͷָ��
    1���ȴ���ͷָ��pHead,��һ�ν�㴴����ֵ
    2������βָ��pTail���������½��pNew�Ĵ���(����forѭ��)
       ÿ�δ�����������β�������ڸýڵ㣬ÿ�����ڵ㽫��ź�������
  */
  int len;
  int i,val;
  printf("������Ҫ��������ĳ���=");
  scanf("%d",&len);
  LinkList pHead=(LinkList)malloc(sizeof(Node));    //������ͷ���ĵ�ַ,Ϊͷ�������ڴ�ռ�
  LinkList pTail=pHead;
  pTail->next=NULL;
  for (i = 0; i < len; ++i)
   {  /*����һ�����(�½��)֮���丳ֵ*/
      printf("The %dth value =",i+1);
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
    }
  return pHead;
}
void TravelLinkList(LinkList pHead){
   LinkList p=pHead->next;                             //ָ���һ����Ч���
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
   printf("�������\n");
   exit(-1);
  }
    LinkList pNew1=(LinkList)malloc(sizeof(Node)); 
    if (NULL==pNew1)
    {
      printf("��̬�ڴ�������\n");
      exit(-1);
    }
	  LinkList q=p->next;
	  pNew1->data=e;
    pNew1->next=q;
    p->next=pNew1;  
  }

//����ǰ����
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
   printf("�������\n");
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
  printf("������=%d\n",len);
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