#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct Arr{
   ElemType data[MAXSIZE];            //包含三部分:数组data/最大长度Max/线性表的当前长度length
   int length;  
}SqList;
void List_init(SqList *L);
void ListInsert(SqList *L,int i,ElemType e);
void Listdele(SqList *L,int i,ElemType* e);
void Listshow(SqList *L,int len);
int main(){
 int dele_i;
 ElemType dele_e;
 SqList arr; 
 printf("show array\n");
 List_init(&arr);
 printf("数组有效长度=%d\n",arr.length);
 Listshow(&arr,arr.length);
 printf("删除元素第i个=");
 scanf("%d",&dele_i);
 Listdele(&arr,dele_i,&dele_e);      //将返回值通过返回给元素e
 printf("delet element is %d",dele_e);
return 0;
}  
void List_init(SqList *L){
   int num;
   printf("插入元素的数量num=");
   scanf("%d",&num);
   for(int n=0;n<num;n++)
   {scanf("%d",&(L->data[n]));        //线性表L的"第i个“位置实现插入和删除值e
    
   }
   L->length=num;
}
void Listshow(SqList *L,int len) 
{
  for(int j=0;j<len;j++){
    printf("%4d\n",L->data[j]);
  }
}
void ListInsert(SqList *L,int i,int e)
{ 
  if(L->length==MAXSIZE){
    printf("full\n");
  }
  if(i<1||i>L->length){
  printf("不在插入范围\n");
  }
  if(i<L->length)
     for (int k=L->length-1;k>=i-1;k--)  //得到把第i个位置元素向后移动一位
       {L->data[k+1]=L->data[k];
       }
  L->data[i-1]=e;
  L->length=L->length+1;
}
void Listdele(SqList *L,int i,ElemType *e)          //线性表L的"第i个“位置实现删除值e
{ 
  if(i<1||i>L->length){
  printf("不在删除范围\n");
  }
  if(i<L->length)
	 *e =L->data[i-1];
     for (int k=i-1;k<=L->length-1;k++)  //得到把第i个位置元素向后移动一位
       {
		 L->data[k]=L->data[k+1];
       }
   L->length--; 
}