/* 	Objectives:
*	Reverses the linked list.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node node;

//FUNCTION DECALARATION
void insert_end(node **,int);
void display(node *);
void reverse(node **);

int main()
{
	node *head=NULL;
	int ch=0,ele=0;

	while(1) {

		puts("\t\t-MENU-\n1.Insert 2.Display 3.Reverse Display 4.Exit\n");
		printf("Enter your choice :");
		scanf("%d",&ch);

		switch (ch) {

		case 1:
			printf("Enter element :");
			scanf("%d",&ele);
			insert_end(&head,ele);					//insert the element
			break;

		case 2:
			display(head);
			break;

		case 3:
			reverse(&head);
			break;

		case 4:
			printf("Exiting...\n");
			exit(-1);

		default:
			printf("Enter valid choice");
			break;
		}

	} 

	return 0;
}

// Function to insert at the end of the linked list
void insert_end(node **headptr,int ele)
{
	node *temp=NULL, *t=*headptr;

	temp=(node *)malloc(sizeof(node));
	if (temp==NULL) {							//NULL CHECK for dynamic memory allocation
		printf("Memory allocation failed\n");
		return;
	}

	temp->data=ele;							//new node creation
	temp->next=NULL;

	if (*headptr==NULL) {				//if list empty, then make new node as head
		*headptr=temp;					// Update head pointer to new node
		return;
	}

	while (t->next!=NULL)				//traverse till the end of linked list
		t=t->next;

	t->next=temp;						//add new node to last node

	return;
}


// Function to display linked list
void display(node *head)
{
	node *t=head;

	if (head==NULL) {
		printf("Linked List is Empty\n");
		return;
	}

	printf("Linked List is:\nHEAD");
	while (t!=NULL) {					//traverse till the end of LL

		printf("-->[%d]",t->data);
		t=t->next;
	}
	puts("");

	return;
}

// Function to reverse linked list
void reverse(node **headptr)
{
	node *prev=NULL,*cur=*headptr,*nextNode=NULL;

	if (*headptr==NULL) {
		printf("Linked List is Empty\n");
		return;
	}

	while (cur!=NULL) {			//travel till current node is null

		nextNode=cur->next;		//store the nextnode temporarily
		cur->next=prev;			//reverse the link-> cur points to prev

		prev=cur;				//for next iteration, prev will be current
		cur=nextNode;			//move to next node
	}

	*headptr=prev;				//prev points to last node, update it as head

	printf("Linked List is Reversed\n");
	display(*headptr);
	
	return;
}