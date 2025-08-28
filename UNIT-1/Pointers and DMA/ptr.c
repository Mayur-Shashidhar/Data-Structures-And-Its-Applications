//dynamic memory allocation
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p, *q;
	  p=(int*) malloc(sizeof(int));
	  *p=20;
	  printf("*p=%d\n",*p);
	  q=p;
	  printf("*q=%d\n", *q);
	 // free(q);
	  printf("%d",*p);//p is a dangling pointer
	  p=NULL;
	  printf("%d",*p); //segmentation fault
	  
}
