#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Arr{
   int *pBase;  //�����ŵ�һ��Ԫ�صĵ�ַ
   int len;     //�������󳤶�
   int cnt;
};
void init_arr(struct Arr *pArr,int length);
void show_arr(struct Arr *pArr);
bool isempty(struct Arr *pArr);
int main(){
 struct Arr arr; 
 init_arr(&arr,6);
 int num;
 printf("input numbers");
 scanf("%d",&num);
 for(int i=0;i<num;i++)
 { scanf("%d",&(arr.pBase[i]));
   arr.cnt++;
 }
 show_arr(&arr);
 return 0;
}   
void init_arr(struct Arr *pArr,int length){
  pArr->pBase=(int *)malloc(sizeof(int)*length); //int * pArr=(int *)malloc(sizeof(int)*length)
  if(NULL==pArr->pBase)
  {
   printf("����ʧ��");
   exit(-1);
  }
  else
  {
   printf("����ɹ�");
   pArr->len=length;
   pArr->cnt=0;
   return;
  }  
}
void show_arr(struct Arr *pArr)
{
if(isempty(pArr))
  {
   printf("empty");
   exit(-1);
  }
 else
  {
   for(int i=0;i<pArr->cnt;i++) 
     printf("%3d",pArr->pBase[i]);
  }  
}
bool isempty(struct Arr *pArr)
{
  if(pArr->cnt==0)
    return true;
  else
    return false;
}