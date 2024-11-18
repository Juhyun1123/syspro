#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node *top, int data);
int pop(struct node *top);

int main(void){
	int num;
	struct node *top = (struct node*)malloc(sizeof(struct node));
	top -> next = NULL;

	while(scanf("%d", &num) == 1){
		push(top, num);	
	}
	
	printf("Print stack\n");

	while(top -> next != NULL){
		printf("%d\n", pop(top));
	}
	
	exit(0);
}

void push(struct node *top, int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode -> data = data;
	newNode -> next = top -> next;
	top -> next = newNode;
}

int pop(struct node *top){
	int data = top -> next -> data;
	top -> next = top -> next -> next;

	return data;
}
