//PROGRAM TO EVALUATE A GIVEN PREFIX  EXPRESSION
//INPUT IS OF THE FORM (eg. +A *BC )
#include<stdio.h>
#include<string.h>
void push(int *, int *,int);
int pop(int*,int*);
int isoper(char);
int prefix_eval(char*);
int main()
{
 char prefix[100];
 printf("\nenter the postfix expression\n");
 scanf("%s",prefix);
 int result=prefix_eval(prefix);
 printf("\nthe result=%d\n",result);
 
}


  void push(int *s,int *t,int x)
  {
   ++*t;//increment top
   s[*t]=x;
  }

  int pop(int *s, int *t)
  {
   int x;
    x=s[*t];
    --*t;//decrement top
    return x;
  }

  int isoper(char ch)
  {
    if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/'))
      return 1;
    return 0;
   }

 int prefix_eval(char* prefix)
 {
   int i,top,r,a;
   int s[10];//stack
   top=-1;
  
   i=strlen(prefix)-1; // find the length of the string
   
   //scan from right to left
   while(i>=0)
   {
     char ch=prefix[i];
     if(isoper(ch)) // if operator
     {
       int op1=pop(s,&top);
       int op2=pop(s,&top);
        switch(ch)
        {
           case '+':r=op1+op2;
                    push(s,&top,r);
                    break;
           case '-':r=op1-op2;
                     push(s,&top,r);
                     break;
            case '*':r=op1*op2;
                    push(s,&top,r);
                     break;
           case '/':r=op1/op2;
                     push(s,&top,r);
                    break;
        }//end switch   
     }//end if
     else // if operand
     {
      printf("%c =",ch);
      scanf("%d",&a);
      push(s,&top,a);
     }
     i--;
    }  //end while
  return(pop(s,&top));
 }
