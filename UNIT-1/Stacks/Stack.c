//implementation of stack uisng an array
#include<stdio.h>
#include<stdlib.h>
int push(int*,int*,int,int);
int pop(int*,int*);
void display(int*,int);
int main()
{
  int top,size,ch,k,x;
  int *s;
  printf("Enter the size of the stack..\n");
  scanf("%d",&size);
  s=malloc(sizeof(int)*size);
  top=-1;
  while(1)
  {
    display(s,top);
    printf("\n1..push\n");
    printf("2..pop\n");
    printf("3..display\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the data\n");
             scanf("%d",&x);
             k=push(s,&top,size,x);
             if(k>0)
               printf("Element pushed successfully\n");
             break;
     case 2:k=pop(s,&top);
            if(k>0)
               printf("\nElement popped=%d\n",k);
            break;
     case 3:display(s,top);
            break;
     case 4:exit(0);
   }
 }
}

  int push(int *s, int *t, int size, int x)
  {
	  if(*t==size-1)
	  {
		  printf("\nstack overflow..cannot insert");
		  return 0;
	  }
	  (*t)++;//or ++*t;
	  s[*t]=x;
	  return 1;
  }
	  
	 int pop(int *s, int *t)
	 {
		 int x;
         if(*t==-1)
		 {
			 printf("Stack underflow..\n");
			 return 0;
		 }
		 else
		 {
			 x=s[*t];
		     (*t)--;  // or --*t
			 return x;
		 }
	 }
	 
	 void display(int *s, int t)
	 {
		 int i;
		 if(t==-1)
			 printf("Stack underflow..\n");
		 else
		 {
			 for(i=t;i>=0;i--)
			      printf("%d ",s[i]);
			 printf("\n");
		 }
	 }
