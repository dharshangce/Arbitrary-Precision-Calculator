#include <stdio.h>
#include "apc.h"
#include <string.h>
#include <stdlib.h>

int  multiply(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR)
{
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	Dlist *tailR=NULL;
	Dlist *resultH=NULL;
	Dlist *resultT=NULL;
	int carry=0;
	int mul=0;
	int decimal=0;
	while(temp2!=NULL)
	{
		temp1=*tail1;
		resultH=NULL;
		resultT=NULL;
		carry=0;
		while(temp1!=NULL)
		{
			mul=carry+(temp2->data * temp1->data);
			carry=mul/10;
			mul=mul%10;
			create_node(&resultH,&resultT,mul);
			temp1=temp1->prev;
		}

	    if(carry)
      	{
	    	create_node(&resultH,&resultT,carry);
	    }
        for(int i=0;i<decimal;i++)
		{
			Dlist *new=malloc(sizeof(Dlist));
			new->data=0;
			new->prev=resultT;
			new->next=0;
			resultT->next=new;
			resultT=new;
		}
		Dlist *t=resultH;
		/*while(t!=NULL)
		{
			printf("%d ",t->data);
			t=t->next;
		}
		printf("\n");*/
		decimal++;
		if(*headR==NULL && tailR==NULL)
		{
			*headR=resultH;
			tailR=resultT;
		}
		else
		{
			
		   addmul(headR,&tailR,&resultH,&resultT);
		}
		Dlist *add=*headR;
		/*printf("After adding \n");
		while(add)
		{
			printf("%d ",add->data);
			add=add->next;
		}
		printf("\n");
		printf("---------------------\n");*/
		temp2=temp2->prev;
	}
	if(carry)
	{
		create_node(&resultH,&resultT,carry);
	}

	
  return 0;
}
int addmul(Dlist **headR,Dlist **tailR,Dlist **resultH,Dlist **resultT)
{
	int carry=0;
	int sum=0;
	Dlist *head=NULL;
	Dlist *tail=NULL;
	while(*tailR !=NULL && *resultT !=NULL)
	{
		sum=carry+(*tailR)->data + (*resultT)->data;
		carry=sum/10;
		sum=sum%10;
		create_node(&head,&tail,sum);
		*tailR=(*tailR)->prev;
		*resultT=(*resultT)->prev;
	}
	while(*tailR!=NULL)
	{
		sum=carry+(*tailR)->data;
		carry=sum/10;
		sum=sum%10;
		create_node(&head,&tail,sum);
		*tailR=(*tailR)->prev;

	}
	while(*resultT!=NULL)
	{
		sum=carry+(*resultT)->data;
		carry=sum/10;
		sum=sum%10;
		create_node(&head,&tail,sum);
		*resultT=(*resultT)->prev;
	}

	if(carry)
	{
		create_node(&head,&tail,carry);
	}
	/*Dlist *temp=(*resultT!=NULL)?*resultT:*tailR;
	while(temp)
	{
		sum=carry+temp->data;
		carry=sum/10;
		sum=sum%10;
		temp=temp->prev;
		create_node(&head,&tail,sum);
	}
	if(carry)
	{
		create_node(&head,&tail,carry);
	}
	Dlist *tem=head;*/
	/*printf("In function\n");
	while(tem)
	{
		printf("%d ",tem->data);
		tem=tem->next;
	}
	printf("_______---------------\n");*/
	*headR=head;
	*tailR=tail;

	return SUCCESS;
}
