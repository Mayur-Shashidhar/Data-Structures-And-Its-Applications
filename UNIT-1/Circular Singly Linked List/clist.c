//program to implement circular singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	 struct node *link;
};

typedef struct node node_t;

//last : pointer to last node
struct list
{
	node_t *last;
};

typedef struct list clist_t;

void init_list(clist_t *);
void insert_head(clist_t *, int);
void insert_tail(clist_t*,int);
void delete_node(clist_t*, int);
void display(clist_t*);

int main()
{
	int ch,key,pos;
	clist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.Delete a node");
		printf("\n5..Exit");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
			            insert_head(&l,key);
			            break;
			case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
			             insert_tail(&l,key);
			            break;			 
			case 3:display(&l);
			             break;
			 
			case 4:printf("\nEnter the key...");
			             scanf("%d",&key);
			            delete_node(&l,key);	
                       		           break;	
					   
			case 5:exit(0);
		}
	}
}

void init_list(clist_t * ptr_list)
{
	ptr_list->last=NULL;
}

 void insert_head(clist_t *ptr_list , int x)
 {
	 node_t *temp,*end;
	 
	 //create a node
	 temp=(node_t*)malloc(sizeof(node_t));
	 temp->key=x;
	 temp->link=temp;
	 
	 //is the list empty ?
	 if(ptr_list->last==NULL)
		 ptr_list->last=temp;
	 
	 else //list not empty
	 {
		 
		 end=ptr_list->last;
		 temp->link=end->link;
		 end->link=temp;
	 }
 }
		 
	void insert_tail(clist_t *ptr_list , int x)
 {
	 node_t *temp,*end;
	 
	 //create a node
	 temp=(node_t*)malloc(sizeof(node_t));
	 temp->key=x;
	 temp->link=temp;
	 
	 //is the list empty ?
	 if(ptr_list->last==NULL)
		 ptr_list->last=temp;
	 
	 else //list not empty
	 {
		 
		 end=ptr_list->last;
		 temp->link=end->link;
		 end->link=temp;
		 ptr_list->last=temp;
	 }
 }			 
				 
	void display(clist_t* ptr_list)
	  {
		  node_t *pres, *end,*prev;
		  if(ptr_list->last==NULL)
			  printf("Empty List\n");
		  else
		  {
			  end=ptr_list->last; //copy last node's address
			  pres=end->link; // point to the first node
			  
			  while(pres!=end)
			  {
				  printf("%d ->",pres->key);
			     pres=pres->link;
			  }
			   printf("%d ",pres->key); // print the last node
		  }
	  }			 
		
  void delete_node(clist_t *ptr_list , int x)
  {
	  node_t *pres, *prev,*end;
	  
	  end =ptr_list->last;
	  pres=end->link;
	  prev=end;
	  
	  //search for the node to be deleted
	  
	  while((pres->key!=x)&&(pres!=end))
	  {
		  prev=pres;
		  pres=pres->link;
	  }
	  if(pres->key==x)//node is found
	  {
		  //if only one node
		  if(pres->link==pres)
			  ptr_list->last=NULL;
		  else
		  {
                                     prev->link=pres->link;
		      if(pres==end) //is it the last node
		          ptr_list->last=prev;
	     }
		 free(pres);
	  }
	  else
		  printf("\nNode not present\n");
  }
