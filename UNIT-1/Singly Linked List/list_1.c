//Another approach of implementing Linked List
//program to implement singly linked list
//head (independent variable) will point to the first node 

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;



void insert_end(node_t**, int);
void insert_head(node_t**, int);
void delete_last(node_t**);
void delete_first(node_t**);
void display(node_t*);
void delete_node(node_t **,int);
void delete_pos(node_t ** , int);
void insert_pos(node_t ** , int,int);
int main()
{
    int ch,n,pos;
	node_t *head;
   head=NULL;
   while(1)
   {
	   display(head);
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
						insert_end(&head,n);
						break;  
						
		  case 2:display(head);
		               break;
		
	      case 3: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_head(&head,n);
						break;  
		case 4:delete_last(&head);
						break;  			
		case 5:delete_first(&head);
						break;
		case 6:printf("\nEnter the element to be deleted..");
		                 scanf("%d",&n);
						 delete_node(&head,n);
						 break;
			case 7:printf("\nEnter the position..");
		                 scanf("%d",&n);
						 delete_pos(&head,n);
						 break;
			case 8:printf("\nEnter the value and position..");
		                 scanf("%d %d",&n,&pos);
						 insert_pos(&head,n,pos); 
						 break; 
			case 9:exit(0);
	    }
    }				  
}		
  
   void insert_head(node_t**ptr, int x)
   {
	    node_t *temp;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  
		  temp->link=*ptr;
		  *ptr=temp;
   }

          /*or use this function to insert at head of the list */
	/*void insert_head(node_t**ptr, int x)
	   {
		  node_t *temp;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		
		   //check if the list is empty ?
		   if(*ptr==NULL)
			   *ptr=temp;
		   else
		   {
			   //insert temp before the first node
		 	 temp->link=*ptr;
			  *ptr=temp;
		   }
		 
	}  */ 
			   
	
	void insert_end( node_t**ptr, int x)
	{
		  node_t *temp,*pres;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		  
		  //is the list empty ?
		  if(*ptr==NULL)
			  *ptr=temp;
		  else
		  {
			  pres=*ptr;//copy the address of the first node;
			  //go to the last node
			  while(pres->link!=NULL)
				      pres=pres->link;
			  pres->link=temp;
		  }  
	}
			  
			  
	void display(node_t *ptr)
    {
      node_t *pres;
	  //if list empty ?
	  if(ptr==NULL)
	     printf("\nEmpty list");
      else
	  {
		   //move along the list and the print the key value
		  //till the end of the list
		  while(ptr!=NULL)
		  {
			  printf("%d-->",ptr->key);
			  ptr=ptr->link;
		  }
	  }
	}
			  
	void delete_last(node_t** ptr)
        {		
		  node_t *pres,*prev;
		  //check if the list empty ?
		  
		  if(*ptr==NULL)
		   printf("Empty list..cannot delete");
	   else
	   {
		  
		   pres=*ptr; //copy the address of the first Node
		   prev=NULL;
		    //move to the last node
		  while(pres->link!=NULL)
		  {
			  prev=pres;
			  pres=pres->link;
		  }
		  if(prev==NULL) //only one node in the list
		    *ptr=NULL;
		else
		    prev->link=NULL;
		  free(pres);
	     }
		}	  
		  
        void delete_first(node_t** ptr)
		{
			node_t *pres;
			pres=*ptr;
			if(pres==NULL)
				printf("Empty list..cannot delete");
			else
			{
			  *ptr=pres->link; //copy the address of the second node
              free(pres);
			}
		}
				
       void delete_node(node_t** ptr, int x)
		{
			node_t *pres,*prev;
			//is list empty
			if(*ptr==NULL)
				printf("Empty list..cannot delete..");
			else
			{
				pres=*ptr; //get the address of the first node
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
                     *ptr=pres->link;//make head point to second node
				 else
				    prev->link=pres->link;
				 free(pres);
				}
			}
		}
			
			
		 void delete_pos(node_t** ptr, int pos)
		{
			node_t *pres,*prev;
			int count;
			//is list empty
			if(*ptr==NULL)
				printf("Empty list..cannot delete..");
			else
			{
				pres=*ptr; //get the address of the first node
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
                     *ptr=pres->link;//make head point to second node
				 else
				    prev->link=pres->link;
				 free(pres);
				}
			}
		}
		
		void insert_pos(node_t** ptr, int x, int pos)		
		{
			node_t *temp,*pres,*prev;
			int count;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		  
		  count=1;
		  prev=NULL;
		  pres=*ptr;
		  
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
				  *ptr=temp;
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
