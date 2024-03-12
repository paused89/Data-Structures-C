/* 	Objectives:
*	Inserts a new node with the given element at the beginning of the linked list.
*	Deletes the node at the specified position from the linked list
*/	

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structure for a node in the linked list
struct node {
	int data;
	struct node *next;
};

typedef struct node node;

//FUNCTION DECLARATIONSS
void insert(int,node**);
void display(node *);
void delete(int,node **);

int main(){

	node *head=NULL;		// Initialize head of the linked list to NULL

	int ch,ele,pos;

	while(1){

		puts("\n---MENU---");
		puts("1.INSERT\t2.DISPLAY\t3.DELETE\t4.EXIT");
		printf("\nEnter your choice :");
		scanf("%d",&ch);

		switch(ch){

			case 1:
				printf("Enter Element :");
				scanf("%d",&ele);
				insert(ele,&head);
				break;
			case 2: 
				display(head);
				break;
			case 3:
				printf("Enter Position :");
				scanf("%d",&pos);
				delete(pos,&head);
				break;
			case 4:
				puts("EXITING...");
				exit(1);
			default:
				puts("INVALID CHOICE!!!");
				break;
		}
	}
}

// Function to insert a node at the beginning of the linked list
void insert(int ele,node **headPtr){
	node *temp=(node *)malloc(sizeof(node));		//dynamically creating new node

	if(temp==NULL){
		puts("Memory Allocation");
		return;
	}

	temp->data=ele;
	temp->next=*headPtr;				//insert in beg, new node will point to head

	*headPtr=temp;						//new node will be now head
}

// Function to display the linked list
void display(node *head){
	node *t=head;

	if(head==NULL){
		puts("Linked list is Empty.");
		return;
	}

	puts("\nLINKED LIST IS :");
	printf("HEAD");
	while(t!=NULL){					//traverse till end of linked list and print
		printf("-->[%d]",t->data);
		t=t->next;
	}
	printf("\n");
}

// Function to delete a node at a given position in the linked list
void delete(int pos,node **headPtr){
	node *t=*headPtr,*delNode=NULL;
	int i=1;

	if(*headPtr==NULL){
		puts("Linked list is Empty.");
		return;
	}

	while(t!=NULL){
		i=1;
		while(i<pos-1){					//"t node" traverse till last (pos -1) of linked list
			if(t->next==NULL)
				return;
			t=t->next;
			i++;
		}
		delNode=t->next;				//delnode is the node which has to be deleted (t+1)
		t->next=delNode->next;    		//connect (pos -1) with (pos +1)
		free(delNode);					//delete node

		t=t->next;
	}
	
}
