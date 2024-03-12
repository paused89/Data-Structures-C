#include<stdio.h>
#include<stdlib.h>

#define SIZE 10				//macro to define the maximum array length

//FUNCTION PROTOTYPES
void display(int []);
void selection(int []);

int main() 
{
	int arr[SIZE];

	printf("Enter array elements\n");

	for (char ind=0; ind<SIZE; ind++) 
		scanf("%d",&arr[ind]);
	
	printf("Array from user :\n");
	display(arr);

	selection(arr);
	printf("Sorted Array :\n");
	display(arr);

	return 0;
}

/*
*Function to sort the given array using selection sort
*Selection sort : Start from index 0 and find if any minimum element found in the remaining array
*if found store the index and then swap with index 0 element. Continue till SIZE-1. 
*For iteration, skip index 0
*/
void selection(int arr[SIZE])
{
	int min_ind=0, temp;

	for (char iter=0; iter<SIZE-1; iter++) {		//iterate SIZE-1 times to get sorted array
		
		min_ind=iter;								//keep index of minimum number as fixed position itself
		
		for (char ind= iter+1; ind<SIZE; ind++) {	//traverse from fixed index till end of array

			if (arr[min_ind] > arr[ind]) 
				min_ind=ind;						//if smaller element found,store the index
			
		}

		if (min_ind != iter) {						//swap if smaller element found i.e, min_ind is changed
			temp=arr[min_ind];
			arr[min_ind]=arr[iter];
			arr[iter]=temp;
		}
	}

}

//Function to display array
void display(int arr[SIZE]) 
{
	for (char ind=0; ind<SIZE; ind++) 
		printf("%d\t",arr[ind]);
	printf("\n");
}

