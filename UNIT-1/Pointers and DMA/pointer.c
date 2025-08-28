//program to demonstrate dynamic memory allocation
#include<stdio.h>
#include<stdlib.h>
int main()
{

                int *p;
	p = (int*)malloc(sizeof(int));
	*p = 20;
	int *q = p;
	free(q); 
	
	//printf("first= %d",*p); //dangling pointer
	p=NULL;
	printf(" third=%d",*p); 
	
}
