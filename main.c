/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	/* Declare the pointers */
	Dlist *head1, *tail1, *head2, *tail2, *headR;
	head1=tail1=head2=tail2=headR=NULL;
	char option, operator;

   if(argc!=4)
	{
		printf("Info : Please Pass 3 Arguments\n");
		printf("Info : \n");
		printf("+ for Addition\n- for Subtraction\nx for Multiplication\n/ for Division\n");
		return FAILURE;
	}
	insert_first(&head1,&tail1,argv[1]);
	display(head1);
	insert_first(&head2,&tail2,argv[3]);
	display(head2);
	if((head1)->data==0)
	{
		printf("Result is :");
		headR=head2;
		display(headR);
	}
	else if((head2)->data==0)
	{
		printf("Result is : ");
		headR=head1;
		display(headR);
	}
	else if((head1)->data==0 && (head2)->data == 0)
	{
		printf("Result is %d\n",0);
	}
	else
	{
	   char *op=argv[2];
	
		switch(*op)
		{
			case '+':
			       if(addition(&head1,&tail1,&head2,&tail2,&headR)==SUCCESS)
				   {
					   printf("Result is : ");
				       display(headR);
				   }
				   else
				   {
					   printf("Info : Error in addition\n");
				   }
				break;
			case '-':	
				   
				if(atoi(argv[1])<atoi(argv[3]))
				{
					Dlist *temp=head1;
					head1=head2;
					head2=temp;
					temp=tail1;
					tail1=tail2;
					tail2=temp;
				}
				if(subtraction(&head1, &tail1, &head2, &tail2, &headR)==SUCCESS)
				{
					printf("Result is : ");
					if(atoi(argv[1])<atoi(argv[3]))
					{
					    headR->data*=-1;
					}
				    display(headR);
				}
				else
				{
					printf("Info : Error in Subtraction\n");
				}
				break;
			case 'x':	
				   if(multiply(&head1,&tail1,&head2,&tail2,&headR)==SUCCESS)
				   {
                    printf("Result is : ");
					display(headR);
				   }
				   else
				   {
					   printf("Info : Error in Subtraction\n");
				   }
				break;
			case '/':
			    if(division(&head1,&tail1,&head2,&tail2,&headR)==SUCCESS)
				{
					printf("Result is : ");
					display(headR);
				}
				else
				{
					printf("Info : Error in Division\n");
				}
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	}

	return 0;
}
int insert_first(Dlist **head,Dlist **tail,char *str)
{
	for(int i=strlen(str)-1;i>=0;i--)
	{
		Dlist *new_node=malloc(sizeof(Dlist));
		if(new_node==NULL)
		{
			return FAILURE;
		}
		new_node->prev=NULL;
		new_node->data=str[i]-48;
		new_node->next=NULL;
		if(*head==NULL)
		{
			*head=*tail=new_node;
			
		}
		else
		{
			new_node->next=*head;
			(*head)->prev=new_node;
			*head=new_node;
		}
	}
}
		
void display(Dlist *head)
{
	if(head==NULL)
	{
		printf("Info : List is empty\n");
	}
	else
	{
		printf("Head -> ");
		while(head)
		{
			printf("%d <-",head->data);
			head=head->next;
			if(head)
			{
				printf("> ");
			}
		}
		printf("Tail\n");
	}
}
