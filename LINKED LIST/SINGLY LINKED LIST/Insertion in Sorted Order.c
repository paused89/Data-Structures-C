/* 	Objectives:
*	Inserts a new node with the given element in SORTED ORDER (ascending) in the linked list.
*   If no valid position is found (i.e., the new element is the largest), it inserts the element at the end of the list.
*	Only insert unique elements. If duplicate element entered, then do not insert.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

//FUNCTION DECALARATIONS
int dup(int *,node *);				//1=duplicates found, 0=no duplicates
void insert(int *, node **);		//insert data, pass head pointer 
void display(node *);				//display using head


int main()
{
	int ch, ele;
	node *head= NULL;

	while(1)
	{
		puts("---MENU---");
		puts("1.Insert\t2.Display\n3.EXIT");
		printf("Enter a choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
			printf("Enter an Element: ");
			scanf("%d",&ele);

			if(dup(&ele,head)){			//if duplicate found, don't insert
				puts("Duplicate Found!!!This element already exists. Enter unique element.");
				break;
			}
			insert(&ele, &head);
			break;

			case 2:
				display(head);
				break;

			case 3:
				puts("Exiting....");
				return -1;

			default:
				puts("INVALID CHOICE !!!!");

		}
	}

	return 0;
}

// Function to insert a new node with the given element in sorted order
void insert(int *ele, node **headptr)
{
	node *temp,*t=*headptr,*t2=NULL;
	temp=(node *)malloc(sizeof(node));
	temp->data=(*ele);
	temp->next=NULL;

	if(*headptr==NULL){						//first node creation
		*headptr=temp;
	}
	
	else if((*headptr)->data>(*ele)){		//if smallest element entered, insert in beginning
		temp->next=*headptr;
		*headptr=temp;						//change head to NEW element
	}

	else{
		
		while(t->next!=NULL){
			t2=t->next;
			if(t->data<(*ele) && (*ele)<(t2->data)){	//if element found in between 2 adjacent nodes of LL then insert in between
				temp->next=t2;
				t->next=temp;
				return;
			}
			t=t->next;						//traverse through linked list
		}

		t->next=temp;			//if no valid position found, i.e largest element entered then insert at end
	}
}

// Function to display the linked list
void display(node *head)
{
	node *t=head;

	if(head==NULL){
		puts("List is empty!!!");
		return;
	}

	printf("HEAD");
	while(t!=NULL){			//traverse through LL

		printf("---> [%d]",t->data);
		t=t->next;
	}
	puts("");
}

// Function to check for duplicate
int dup(int *ele, node *head)
{
	node *t=head;
	while(t!=NULL){
		if((*ele)==t->data)		//if duplicate found then return 1
			return 1;
		t=t->next;
	}

	return 0;
}