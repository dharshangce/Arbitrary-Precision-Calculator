/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR)
{
  Dlist *temp_tail1=*tail1;
  Dlist *temp_tail2=*tail2;
  Dlist *result=NULL;
  Dlist *temp=NULL;
  int diff=0;
  int barrow=0;
  while(temp_tail1!=NULL || temp_tail2!=NULL)
  {
	  int val1=temp_tail1?temp_tail1->data:0;
	  int val2=temp_tail2?temp_tail2->data:0;
     diff=val1-val2-barrow;
	 if(diff<0)
	 { 
		 diff+=10;
		 barrow=1;

	 }
	 else
	 {
		 barrow=0;
	 }
	  create_node(headR,&result,diff);
	  if(temp_tail1!=NULL)
	  temp_tail1=temp_tail1->prev;
	  if(temp_tail2!=NULL)
	  temp_tail2=temp_tail2->prev;
  }
}
