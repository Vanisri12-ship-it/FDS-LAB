#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;    
};
struct node *top=NULL,*temp,*newNode;

void push(int data)
{
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;

	if(top == NULL)
	{
		top = newNode;
	}else{
		newNode->next = top;
		top = newNode;
	}
	printf("element pushed:%d \n",data);
}

int pop() 
{
    if (top == NULL) {
        printf("\nEMPTY STACK");
    } else {
        temp = top;
        int temp_data = top->data; //to store data of top node
        top = top->next; 
        free(temp); //deleting the node
        return temp_data;
    }
}

void display() {
    // Display the elements of the stack
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("\n The stack is: \n");
        temp = top;
        while (temp != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

int main()
{
	push(10);
	push(20);
	push(30);	
	display();
	printf("\nelement poped %d",pop());
	printf("\nelement poped %d",pop());
	display();
	return 0;
}
