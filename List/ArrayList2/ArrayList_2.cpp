#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef int ElemType;
typedef struct Arr{
   ElemType data[MAXSIZE];            //����������:����data/��󳤶�Max/���Ա�ĵ�ǰ����length
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
 printf("������Ч����=%d\n",arr.length);
 Listshow(&arr,arr.length);
 printf("ɾ��Ԫ�ص�i��=");
 scanf("%d",&dele_i);
 Listdele(&arr,dele_i,&dele_e);      //������ֵͨ�����ظ�Ԫ��e
 printf("delet element is %d",dele_e);
return 0;
}  
void List_init(SqList *L){
   int num;
   printf("����Ԫ�ص�����num=");
   scanf("%d",&num);
   for(int n=0;n<num;n++)
   {scanf("%d",&(L->data[n]));        //���Ա�L��"��i����λ��ʵ�ֲ����ɾ��ֵe
    
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
  printf("���ڲ��뷶Χ\n");
  }
  if(i<L->length)
     for (int k=L->length-1;k>=i-1;k--)  //�õ��ѵ�i��λ��Ԫ������ƶ�һλ
       {L->data[k+1]=L->data[k];
       }
  L->data[i-1]=e;
  L->length=L->length+1;
}
void Listdele(SqList *L,int i,ElemType *e)          //���Ա�L��"��i����λ��ʵ��ɾ��ֵe
{ 
  if(i<1||i>L->length){
  printf("����ɾ����Χ\n");
  }
  if(i<L->length)
	 *e =L->data[i-1];
     for (int k=i-1;k<=L->length-1;k++)  //�õ��ѵ�i��λ��Ԫ������ƶ�һλ
       {
		 L->data[k]=L->data[k+1];
       }
   L->length--; 
}