/* 	Objectives:
*	Inserts a new node with the given element at the end and at the beginning of the linked list.
*	Deletes node at the end and at the beginning of the linked list.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

//FUNCTION DECLARATIONS
void insert(node**,int);
void insert_end(node **,int);
void delete(node **);
void delete_end(node **);
void display(node *);

int main()
{
	node *head = NULL;   // Initialize head of the linked list to NULL

	int ele, ch;  

	while (1) {  
		// Display menu options
		printf("\n1.Insert 2.Insert at End 3.Delete 4. Delete from end 5.Display 6.EXIT\n");
		printf("Enter a choice :");
		scanf("%d", &ch);  // Read user choice

		switch (ch) {  

		case 1:  // Insert at the beginning
			printf("Enter Element :");
			scanf("%d", &ele);  // Read element to be inserted
			insert(&head, ele);  
			break;

		case 2:  // Insert at the end
			printf("Enter Element :");
			scanf("%d", &ele);  // Read element to be inserted
			insert_end(&head, ele);  
			break;

		case 3:  // Delete from the beginning
			delete(&head);  
			break;
		case 4:  // Delete from the end
			delete_end(&head);  
			break;

		case 5:  // Display the linked list
			display(head);  
			break;

		case 6:  // Exit the program
			return 0;
		}
	}

	return 0;
}

// Function to insert at the end of the linked list
void insert_end(node **headptr,int ele)
{
	node *temp=NULL, *t=*headptr;
	
	//NEW NODE CREATION
	temp=(node *)malloc(sizeof(temp));
	if (temp==NULL) {									//NULL CHECK for dynamic memory allocation
		printf("Memory allocation failed\n");
		return;
	}
	temp->data=ele;
	temp->next=NULL;

	if (*headptr==NULL) {			//if list empty, then make new node as head
		*headptr=temp;				// Update head pointer to new node
		return;
	}

	//traverse till last node of LL, insert the new node at the end of linked list

	while (t->next!=NULL)	{
		t=t->next;
	}
	t->next=temp;						//connect last node with new node
}

// Function to insert at the beginning of the linked list
void insert(node **headptr,int ele)
{
	node *temp=NULL;

	temp=(node *)malloc(sizeof(node *));
	if (temp==NULL) {								//NULL CHECK for dynamic memory allocation
		printf("Memory allocation failed\n");
		return;
	}

	temp->data=ele;				// Assign data to the new node
	temp->next=*headptr;		// Set next pointer of new node to head
	*headptr=temp;				// Update head pointer to new node

	return;
}


// Function to delete from the end of the linked list
void delete_end(node **headptr)
{
	node *t=*headptr;

	if (*headptr==NULL) {				//empty list
		printf("List is empty\n");
		return;
	}

	else if (t->next==NULL) {			//only one node in LL
		free(t);
		*headptr=NULL;
		return;
	}
	else{

		while (t->next->next!=NULL) {		//traverse till second last node
			t=t->next;
		}

		free(t->next);						//delete last node
		t->next=NULL;						//Set next pointer of second last node as NULL  
	}

	return;
}

// Function to delete from the beginning of the linked list
void delete(node **headptr)
{
	node *t=*headptr;

	if (*headptr==NULL) {				//empty list
		printf("List is empty\n");
		return;
	}

	*headptr=t->next;		// Update head pointer to SECOND node (t-> next); if only one node exists, head will be null  
	free(t);				// Free memory of the FIRST node

	return;
}

void display(node *head)
{
	node *t=head;

	if (head==NULL) {							//empty condition
		printf("Linked List is empty\n");
		return;
	}

	while (t!=NULL)	{							//traverse till the end of LL
		printf("-->[%d]",t->data);
		t=t->next;
	}
	puts("");

	return;
}