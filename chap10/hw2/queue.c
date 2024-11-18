#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

void addq(struct node *head, struct node *tail, int data);
int delete(struct node *head, struct node *tail);

int main(void){
	int num;
	struct node *head = (struct node*)malloc(sizeof(struct node));
	struct node *tail = (struct node*)malloc(sizeof(struct node));

	head -> next = NULL;
	tail -> next = NULL;

	while(scanf("%d", &num) == 1){
		addq(head, tail, num);	
	}
	
	printf("Print queue\n");

	while(head -> next != NULL){
		printf("%d\n", delete(head, tail));
	}
	
	exit(0);
}

void addq(struct node *head, struct node *tail, int data){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode -> data = data;
	newNode -> next = NULL;

	if(tail -> next != NULL)
		tail -> next -> next = newNode;
	

	tail -> next = newNode;
	
	if(head -> next == NULL)
		head -> next = newNode;
	
}

int delete(struct node *head, struct node *tail){
	int data = head -> next -> data;
	head -> next = head -> next -> next;
	return data;
}
