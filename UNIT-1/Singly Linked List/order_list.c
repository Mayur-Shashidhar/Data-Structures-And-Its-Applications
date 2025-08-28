//program to create an ordered list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;

struct list
{
	node_t *head;
};
typedef struct list list_t;

void init_list(list_t*);
void display(list_t *);
void insert_order(list_t *, int);

int main()
{
   list_t l;
   init_list(&l);
   int n;
   while(1)
  {
	   printf("\nEnter the element<0 to end>");
	   scanf("%d",&n);
	   if(n==0)
		   break;
	   insert_order(&l,n);
	   display(&l);
   }
}
  
  void init_list(list_t *ptr_list)
  {
	  ptr_list->head=NULL;
  }
  
  void insert_order(list_t *ptr_list, int x)
  {
	    node_t *temp, *pres, *prev;
	   //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
	  
	      //if list empty
		  //first node gets inserted
		  if(ptr_list->head==NULL)
			 ptr_list->head=temp;
         else
		 {
			 pres=ptr_list->head;
			 prev=NULL;
			 //find position for x;
			 //move forward in the list until the position is found
			 while((pres!=NULL) &&( x >pres->key))
			 {
				 prev=pres;
				 pres=pres->link;
			 }
			 if(pres==NULL)
			 //insert at the end; because x is greater than all the nodes
                  prev->link=temp;
            else  // list exists
			{
				if(prev==NULL) //insert before the first node ; x is smaller than the first node
				{
					temp->link=pres;
					ptr_list->head=temp;
				}
				else
				{				
               //insert between positions 2 and the last
                 temp->link=pres;
				 prev->link=temp;
			}
		 }
    }
  }
