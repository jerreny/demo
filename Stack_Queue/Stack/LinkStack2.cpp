# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>
#define ERROR 0 
#define OK 1 
typedef  int Status;
typedef  int SElemType;
typedef struct StackNode{
  SElemType data;
  struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack{
  LinkStackPtr top;
  int count;
}LinkStack;
Status StackEmpty(LinkStack *S);
Status Push(LinkStack *S,SElemType e);  //½øÕ»²Ù×÷£¬ÆäÖÐSqStack *S£ºSÖ¸Ïò½á¹¹Ìå±äÁ¿S->³ÉÔ±£¬SqStack S£ºS.³ÉÔ±
Status Pop(LinkStack *S,SElemType *e);
int main(){
 SElemType  push_e; 
 SElemType  pop_e; 
 LinkStack S;
 int flag1,flag2;
 S.count=0;
 S.top=NULL;
 printf("ѹ���ջ��Ԫ��Ϊ\n");
 scanf("%d",&push_e);
 flag1=Push(&S,push_e);
 flag2=Pop(&S,&pop_e);
 printf("������ջ��Ԫ��Ϊ%d",pop_e);
 return 0;
}
Status Push(LinkStack *S,SElemType e){  //Ã»ÓÐ¿ÕºÍÂúµÄÎÊÌâ£¬Ñ¹ÈëÔªËØ¾ÍÐèÒªÏÈ½¨Á¢ÄÚ´æ¿Õ¼ä£¬¸³ÖµºótopÖ¸Ïò¸ü¸Ä¡£
  LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode));
  s->data=e;
  s->next=S->top;
  S->top=s;
  S->count++;
  return OK;
}
Status Pop(LinkStack *S,SElemType *e){   //ÏÈÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ£¬
   LinkStackPtr p;
   if(StackEmpty(S))
    return ERROR;
   (*e)=S->top->data;
   p=S->top;
   S->top=S->top->next;
   free(p);
   S->count--;
   return OK;
}
Status StackEmpty(LinkStack *S){
   if (NULL==S->top)
     return true;
   else 
     return false;
}