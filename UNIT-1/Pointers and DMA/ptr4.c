#include<stdio.h>
#include<stdlib.h>
//program to create an array dynamically
int main()
{
	int *p;
	int i;
	//p=(int*)malloc(sizeof(int)*4);
	p=(int*)calloc(4,sizeof(int));
	
	for(i=0;i<4;i++)
      printf("%d ",*(p+i));
  
    for(i=0;i<4;i++)	
      *(p+i)=i;
	
	for(i=0;i<4;i++)
      printf("%d ",*(p+i));
	
}
