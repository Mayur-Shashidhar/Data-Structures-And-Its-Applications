//implementation of stack using a structure
#include<stdio.h>
#include<stdlib.h>
struct stack
{
  int *s;
  int top;
  int size;
};

typedef struct stack stack_t;
 
int push(stack_t *,int);
int pop(stack_t*);
void display(stack_t*);
int main()
{
  int top,size,ch,k,x;
  stack_t stk;
  printf("Enter the size of the stack..\n");
  scanf("%d",&stk.size);
  stk.s=(int*)malloc(sizeof(int)*stk.size);
  stk.top=-1;
  while(1)
  {
    display(&stk);
    printf("\n1..push\n");
    printf("2..pop\n");
    printf("3..display\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the data\n");
             scanf("%d",&x);
             k=push(&stk,x);
             if(k>0)
               printf("Element pushed successfully\n");
             break;
     case 2:k=pop(&stk);
            if(k>0)
               printf("Element popped=%d",k);
            break;
     case 3:display(&stk);
            break;
     case 4:exit(0);
   }
 }
}

int push(stack_t *ptr_stk , int x)
{
	//check for stack overflow
	if(ptr_stk->top==ptr_stk->size-1)
	{
		printf("stack overflow..cannot insert");
	    return 0;
	}
	ptr_stk->top++; //++ptr_stk->top
    ptr_stk->s[ptr_stk->top]=x;
	return 1;
}

	int pop(stack_t*ptr_stk)
	{
		int x;
		if(ptr_stk->top==-1)
		{
			printf("Stack underflow..cannot delete\n");
			return 0;
		}
		x=ptr_stk->s[ptr_stk->top];
		ptr_stk->top--;
		return x;
	}
		
  void display(stack_t *ptr_stk)
  {
	  int i;
	  if(ptr_stk->top==-1)
		  printf("\nStack underflow..");
	  else
	  {
		  printf("\n");
		  for(i=ptr_stk->top;i>=0;i--)
			  printf("%d ",ptr_stk->s[i]);
	  }
	  printf("\n");
  }
