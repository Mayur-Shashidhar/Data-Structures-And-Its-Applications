//program to demonstrate the use of realloc
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,n1;
	int *p;
	printf("Enter the number of elements...");
	scanf("%d",&n);
	
	//allocate memory dynamcally to store n elements
	
	p=(int*)malloc(n*sizeof(int));
	printf("\nEnter the values ..");
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);
	
	printf("\nThe values entered..\n");
	for(i=0;i<n;i++)
		printf("%d  ",p[i]);
	
	printf("Enter the new value for n");
	scanf("%d",&n1);
	
	printf("\nRellocating memory...");

               p=(int*)realloc(p,n1*sizeof(int));
	
	printf("\nPrinting old values  ...");
	for(i=0;i<n;i++)
		printf("%d  ",p[i]);


	printf("\nEnter the new set of values ..");
	
	for(i=n;i<n1;i++)
		scanf("%d", &p[i]);
	
	printf("\nPrinting all the values...");
		for(i=0;i<n1;i++)
		printf("%d  ", p[i]);
}
