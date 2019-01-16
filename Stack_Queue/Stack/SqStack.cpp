# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
#define ERROR 0 
#define OK 1 
#define MAXSIZE 20
typedef  int Status;
typedef int SElemType;
typedef struct{
	SElemType data[MAXSIZE];
	int top;
}SqStack;
Status Pop(SqStack *S,SElemType *e);
Status Push(SqStack *S,SElemType e);
void initSqtack(SqStack *S);
int main(){
 SElemType  push_e;
 SElemType  pop_e;
 SqStack S;
 initSqtack(&S);
 int flag1;
 int flag2;
 printf("输入压入堆栈的元素:\n");
 scanf("%d",&push_e);
 flag1=Push(&S,push_e);
 printf("入栈是否成功%d\n",flag1);
 flag2=Pop(&S,&pop_e);
 printf("弹出堆栈的元素%d\n",pop_e);
 return 0;
}
void initSqtack(SqStack *S)
{
  S->top=-1;
  }
Status Push(SqStack *S,SElemType e)
{
  if(S->top==MAXSIZE-1)
  {
  	return ERROR;
  }
  S->top++;
  S->data[S->top]=e;
  return OK;
}
Status Pop(SqStack *S,SElemType *e)
{
  if(S->top==-1)
  {
  	return ERROR;
  }
  *e=S->data[S->top];
  S->top--;
  return OK;
}
