//dynamic allocation of 1 d array
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *p;
	int i;
//	 p=(int*) malloc(sizeof(int)*4);
                 p=(int*)calloc(sizeof(int), 4);

	 for(i=0;i<4;i++)
		 *(p+i)=i;//p[i];
	  for(i=0;i<4;i++)
		printf("  %d", *(p+i));//p[i]
	
	
}
