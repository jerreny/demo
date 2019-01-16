//循环队列
# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
#include<io.h>
#include<math.h>
#include<time.h>

typedef int QElemType;
#define MAXSIZE 20
#define ERROR 0 
#define OK 1 
typedef  int Status;
typedef struct QNode
{
  QElemType data;
  QNode *next;
}QNode,*QueuePtr;
typedef struct 
{
  QueuePtr front,rear;
}linkQueue;
Status InitQueue(linkQueue* Q){
   Q->front=Q->rear=(QueuePtr)malloc(sizeof(QNode));
   if(!Q->front)
    exit(OVERFLOW);
   Q->front->next=NULL;
   return OK;
}
//队列是否为空
Status QueueEmpty(linkQueue Q){
 if(Q.front==Q.rear)
  return OK;
 else
  return ERROR;
}
int QueueLength(linkQueue *Q){
  int k=0;
  QueuePtr p;
  p=Q->front;//将p作为变量向后移；
  while(Q->rear!=p)
  {
    p=p->next;
    k++;

  }
  return k;
}
//插入操作
Status EnQueue(linkQueue* Q,QElemType En_e){
   QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
   if(!s)
    exit(OVERFLOW);
   s->data=En_e;
   s->next=NULL;
   Q->rear->next=s;
   Q->rear=s;
   return OK;
}
//若队列不是空，删除操作,对S->front进行操作
Status DeQueue(linkQueue* Q,QElemType *De_e){
  if(Q->rear==Q->front)
    return ERROR;
  QueuePtr p;
  p=Q->front->next;
  *De_e=p->data;
  Q->front->next=p->next;
  if(Q->rear==p)
       Q->rear=Q->front;
  free(p);
  return OK;
}
Status TravelQueue(linkQueue* Q){
  QueuePtr p;
  p=Q->front->next;
  while(p){
     printf("%5d\n",p->data);
     p=p->next;
  }
  return OK;
}
Status DestroyQueue(LinkQueue *Q)
{
  while(Q->front)
  {
     Q->rear=Q->front->next;
     free(Q->front);
     Q->front=Q->rear;
  }
  return OK;
}
Status ClearQueue(LinkQueue *Q)
{
  QueuePtr p,q;
  Q->rear=Q->front;
  p=Q->front->next;
  Q->front->next=NULL;
  while(p)
  {
     q=p;
     p=p->next;
     free(q);
  }
  return OK;
}
int main(){
linkQueue Q;
int i;
int j,n;
int lenQue;
QElemType En_e;
i=InitQueue(&Q);
if(i)
  printf("成功初始化空队列\n");
printf("插入元素的个数为=\n");
scanf("%d",&n);
for (j=0;j<n;j++){
  scanf("%d",&En_e);
  EnQueue(&Q,En_e);
}
lenQue=QueueLength(&Q);
printf("队列的长度为=%d\n",lenQue);
TravelQueue(&Q);
return 0;
}