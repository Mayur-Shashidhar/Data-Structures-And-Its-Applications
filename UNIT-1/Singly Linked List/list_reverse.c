	 
//reversing a list
        void reverse_list(list_t *ptr_list)
		{
			node_t *pres,*prev,*temp;
			prev=NULL;
			pres=ptr_list->head;
			
			while(pres!=NULL)
			{
				temp=pres->link;
				pres->link=prev;
				prev=pres;
				pres=temp;
			}
			ptr_list->head=prev;
		}
				

//another approach of reversing

	 void reverse_list(node_t **ptr)
		{
			node_t *pres,*prev,*temp;
			prev=NULL;
			pres=*ptr
			
			while(pres!=NULL)
			{
				temp=pres->link;
				pres->link=prev;
				prev=pres;
				pres=temp;
			}
			*ptr=prev;
		}		
				
			
	//another approach of reversing

	node_t* reverse_list(node_t *ptr)
		{
			node_t *pres,*prev,*temp;
			prev=NULL;
			pres=ptr
			
			while(pres!=NULL)
			{
				temp=pres->link;
				pres->link=prev;
				prev=pres;
				pres=temp;
			}
			return prev;
		}		
			   
		
               //counting the nodes in the list  recursively

                               int count_nodes_recur(node_t *pres)
		 {
			 if(pres->link==NULL)//one node
			    return 1;
			return(1+count_nodes_recur(pres->link));
		 }
