//循环队列
#include<stdio.h>
typedef int QElemType;
#define MAXSIZE 20
#define ERROR 0 
#define OK 1 
typedef  int Status;
typedef struct 
{
  QElemType data[MAXSIZE];
  int front;
  int rear; 
}SqQueue;
Status InitQueue(SqQueue* S);
Status EnQueue(SqQueue* S,QElemType En_e);
Status DeQueue(SqQueue* S,QElemType *De_e);
int LengthQueue(SqQueue* S);
int main(){
SqQueue S;
int i,n;
int LenQueue;
QElemType En_e;
InitQueue(&S);
printf("插入元素的个数为=\n");
scanf("%d",&n);
for (i=0;i<n;i++){
  scanf("%d",&En_e);
  EnQueue(&S,En_e);
}
LenQueue=LengthQueue(&S);
printf("队列的长度=%d",LenQueue);
return 0;
}
Status InitQueue(SqQueue* S){
   S->front=0;
   S->rear=0;
   return OK;
}
//返回队列的长度
int LengthQueue(SqQueue* S){
    return (S->rear-S->front+MAXSIZE)%MAXSIZE;
}
//若队列未满，插入操作
Status EnQueue(SqQueue* S,QElemType En_e){
   if((S->rear+1)%MAXSIZE==S->front)
   	return ERROR;
   else
     S->data[S->rear]=En_e;
   	 S->rear=(S->rear+1)%MAXSIZE;
     return OK;
}
//若队列不是空，删除操作
Status DeQueue(SqQueue* S,QElemType *De_e){
  if(S->rear==S->front)
  	return ERROR;
  else
    *De_e=S->data[S->front];
     S->front=( S->front+1)%MAXSIZE;
     return OK;
}