//program to implement singly linked list
//head will point to the first node and is a field of structure List

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
void insert_end(list_t*, int);
void insert_head(list_t*, int);
void delete_last(list_t*);
void delete_first(list_t*);
void display(list_t*);
void delete_node(list_t *,int);
void delete_pos(list_t * , int);
void insert_pos(list_t * , int,int);
int main()
{
   list_t l;
   int ch,n,pos;
  init_list(&l);
  //l.head=NULL;
   while(1)
   {
	   display(&l);
	   printf("\n1..Insert at end");
	   printf("\n2..display");
	   printf("\n3..Insert at head");
	   printf("\n4..delete_last");
	   printf("\n5.delete first");
	   printf("\n6..delete node");
	   printf("\n7 delete position");
	   printf("\n8.insert at a position");
	   printf("\n9. Exit");
	   scanf("%d",&ch);
	   switch(ch)
	   {
		case 1: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_end(&l,n);
						break;  
						
		  case 2:display(&l);
		               break;
		
	      case 3: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_head(&l,n);
						break;  
		  case 4:delete_last(&l);
						break;  			
		case 5:delete_first(&l);
						break;
		case 6:printf("\nEnter the element to be deleted..");
		                 scanf("%d",&n);
						 delete_node(&l,n);
						 break;
			case 7:printf("\nEnter the position..");
		                 scanf("%d",&n);
						 delete_pos(&l,n);
						 break;
			case 8:printf("\nEnter the value and position..");
		                 scanf("%d %d",&n,&pos);
						 insert_pos(&l,n,pos); 
						 break;
			case 9:exit(0);
	    }
    }				  
}		


void init_list(list_t *ptr_list)
{
	ptr_list->head=NULL;
}

  
			
		void insert_head(list_t *ptr_list, int x)
	   {
		  node_t *temp,*pres;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		
		   //check if the list is empty ?
		   if(ptr_list->head==NULL)
			   ptr_list->head=temp;
		   else
		   {
			   //insert temp before the first node
		 	 temp->link=ptr_list->head;
			  ptr_list->head=temp;
		   }
		 
	} 
			   
	
	void insert_end( list_t *ptr_list, int x)
	{
		  node_t *temp,*pres;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		  
		  //is the list empty ?
		  if(ptr_list->head==NULL)
			  ptr_list->head=temp;
		  else
		  {
			  pres=ptr_list->head;//copy the address of the first node;
			  //go to the last node
			  while(pres->link!=NULL)
				      pres=pres->link;
			  pres->link=temp;
		  }  
	}
			  
			  
	void display(list_t *ptr_list)
    {
      node_t *pres;
	  //if list empty ?
	  if(ptr_list->head==NULL)
	     printf("\nEmpty list");
      else
	  {
		  pres=ptr_list->head;
		  //move along the list and the print the key value
		  //till the end of the list
		  while(pres!=NULL)
		  {
			  printf("%d-->",pres->key);
			  pres=pres->link;
		  }
	  }
	}
			  
	void delete_last(list_t * ptr_list)
        {		
		  node_t *pres,*prev;
		  //check if the list empty ?
		  
		  if(ptr_list->head==NULL)
		   printf("Empty list..cannot delete");
	   else
	   {
		  
		   pres=ptr_list->head; //copy the address of the first Node
		   prev=NULL;
		    //move to the last node
		  while(pres->link!=NULL)
		  {
			  prev=pres;
			  pres=pres->link;
		  }
		  if(prev==NULL) //only one node in the list
		    ptr_list->head=NULL;
		else
		    prev->link=NULL;
		  free(pres);
	     }
		}	  
		  
        void delete_first(list_t *ptr_list)
		{
			node_t *pres;
			pres=ptr_list->head;
			if(pres==NULL)
				printf("Empty list..cannot delete");
			else
			{
			  ptr_list->head=pres->link; //copy the address of the second node
              free(pres);
			}
		}
				
        void delete_node(list_t * ptr_list, int x)
		{
			node_t *pres,*prev;
			//is list empty
			if(ptr_list->head==NULL)
				printf("Empty list..cannot delete..");
			else
			{
				pres=ptr_list->head; //get the address of the first node
				prev=NULL;
			    //move forward until the node is found
				//or go beyond the last node
			    while((pres!=NULL)&&(pres->key!=x))
				{
					prev=pres;
					pres=pres->link;		
				}
				if(pres==NULL)
					printf("Node not found.");
				else//node found
				{
				  if(prev==NULL)//check whether it is first node
                     ptr_list->head=pres->link;//make head point to second node
				 else
				    prev->link=pres->link;
				 free(pres);
				}
			}
		}
			
			
		 void delete_pos(list_t * ptr_list, int pos)
		{
			node_t *pres,*prev;
			int count;
			//is list empty
			if(ptr_list->head==NULL)
				printf("Empty list..cannot delete..");
			else
			{
				pres=ptr_list->head; //get the address of the first node
				prev=NULL;
			    //move forward until the node is found
				//or go beyond the last node
				count=1;
			    while((pres!=NULL)&&(count<pos))
				{
					prev=pres;
					pres=pres->link;	
					count++;
				}
				if(pres==NULL)
					printf("Invalid position");
				else//node found
				{
				  if(prev==NULL)//check whether it is first node
                     ptr_list->head=pres->link;//make head point to second node
				 else
				    prev->link=pres->link;
				 free(pres);
				}
			}
		}
		
		void insert_pos(list_t * ptr_list, int x, int pos)		
		{
			node_t *temp,*pres,*prev;
			int count;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		  
		  count=1;
		  prev=NULL;
		  pres=ptr_list->head;
		  
		  //search for the position
		  while((pres!=NULL)&&(count<pos))
		  {
			  prev=pres;
			  pres=pres->link;
			  count++;
		  }
		  if(pres!=NULL)//poistion found somewhere between 1 and last node
		  {
			  //check if it is the first position
			  if(prev==NULL)
			  {
				  temp->link=pres;
				  ptr_list->head=temp;
			  }
				else //insert node at poistions 2,3,4..
				{
					temp->link=pres;
					prev->link=temp;
				}
		  }
			else//if pres =NULL
			{
				if(count==pos) //insert after the last node
				    prev->link=temp;
				else
					printf("Invalid position");
			}
		} 
