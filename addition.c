/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "apc.h"



int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
      Dlist *temp_tail1=*tail1;
	  Dlist *temp_tail2=*tail2;
	  Dlist *result=NULL;
	  Dlist *temp=NULL;
	  int carry=0;
	  int sum=0;
	  while(temp_tail1!=NULL && temp_tail2!=NULL )
	  {
		  sum=carry+temp_tail1->data+temp_tail2->data;
		  carry=sum/10;
		  sum=sum%10;
		  temp_tail1=temp_tail1->prev;
		  temp_tail2=temp_tail2->prev;
          create_node(headR,&result,sum);		  
	  }
      temp=(temp_tail1==NULL)?temp_tail2:temp_tail1;
	  while(temp)
	  {
		  sum=carry+temp->data;
		  carry=sum/10;
		  sum=sum%10;
		  temp=temp->prev;
		  create_node(headR,&result,sum);
	  }
	  if(carry)
	  {
		  create_node(headR,&result,carry);
	  }
	  return SUCCESS;

}
int create_node(Dlist **headR,Dlist **result,int sum)
{
	Dlist *new_node=malloc(sizeof(Dlist));
	if(new_node==NULL)
	{
	    return FAILURE;
	}
	new_node->data=sum;
	new_node->prev=NULL;
	new_node->next=NULL;
	if(*headR==NULL && *result==NULL)
	{
		*headR=*result=new_node;
	}
	else
	{
		if(*headR!=NULL)
		{
		new_node->next=*headR;
		(*headR)->prev=new_node;
		}
		(*headR)=new_node;
	}
}
