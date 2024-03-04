#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int insert_first(Dlist **head,Dlist **tail,char *str);
void display(Dlist *);
int addition(Dlist **,Dlist **,Dlist **,Dlist **,Dlist **);
int subtraction(Dlist **,Dlist **,Dlist **,Dlist **,Dlist **);
int create_node(Dlist **,Dlist ** ,int);
int multiply(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
int addmul(Dlist **headR,Dlist **tailR,Dlist **resultH,Dlist **resultT);
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR);
int subdiv(Dlist **,Dlist **,Dlist **,Dlist **);
#endif
