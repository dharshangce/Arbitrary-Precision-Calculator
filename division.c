#include <stdio.h>
#include "apc.h"
#include <string.h>
#include <stdlib.h>

int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR)
{
   Dlist *temp_head2=*head2;
   Dlist *temp_tail2=*tail2;
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	Dlist *tailR=NULL;
	long int count=0;
	while(1)
	{

		Dlist *t=*head1;
		long long int num=0;
		while(t!=NULL)
		{
			num=num*10+t->data;

			t=t->next;
		}
		t=*head2;
		int j=0;
		long long int num1=0;
		while(t!=NULL)
		{
			
			num1=num1*10+t->data;
			t=t->next;
		}
		*head2=temp_head2;
		*tail2=temp_tail2;
		if(num<num1)
		{
		
			while(count!=0)
			{
				create_node(headR,&tailR,count%10);
				count/=10;
			}
			return SUCCESS;
		}
	    else if(subdiv(head1,tail1,head2,tail2)==SUCCESS)
			{
				count++;
			}


         }
   return 0;
}
int subdiv(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2)
{
	Dlist *temp_tail1=*tail1;
	Dlist *temp_tail2=*tail2;
	int diff=0;
	int barrow=0;
	Dlist *resH=NULL;
	Dlist *resT=NULL;
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
		create_node(&resH,&resT,diff);
		if(temp_tail1!=NULL)
		{
			temp_tail1=temp_tail1->prev;
		}
		if(temp_tail2!=NULL)
		{
			temp_tail2=temp_tail2->prev;
		}

	}
	*head1=resH;
	*tail1=resT;
      return SUCCESS;
}

