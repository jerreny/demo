#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct Arr{
   int *pBase;  //数组存放第一个元素的地址
   int len;     //数组的最大长度
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
   printf("分配失败");
   exit(-1);
  }
  else
  {
   printf("分配成功");
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