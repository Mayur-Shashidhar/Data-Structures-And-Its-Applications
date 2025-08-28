//creating a 2D array dynamically
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j;
	int **p;
	printf("Enter the number of rows..");
	scanf("%d",&m);
	printf("Enter the number of columns");
	scanf("%d",&n);
	
	//create an array for row
	 p=(int**)malloc(sizeof(int*)*m);
	 
	 for(i=0;i<m;i++)
		 p[i]=(int*)malloc(sizeof(int)*n);
   
                 for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&p[i][j]);
	}
	//print the 2d array
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
			printf("  %d",p[i][j]);
		prinf("\n");
	}
   
	
}
