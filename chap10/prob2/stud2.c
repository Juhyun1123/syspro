#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	int id;
	char name[20];
	struct student *next;
};

int main(void){
	int count = 0, id;
	char name[20];
	struct student *head = NULL;
	struct student *p;
	
	printf("please input student number and name\n");

	while(scanf("%d %s", &id, name) == 2){
		p = (struct student*)malloc(sizeof(struct student));
		if(p == NULL){
			perror("malloc");
			exit(1);
		}

		p -> id = id;
		strcpy(p -> name, name);
		p -> next = head;
		head = p;
	}

	printf("\n* student information(reverse) *\n");
	p = head;

	while(p != NULL){
		count++;
		printf("student number : %d name : %s \n", p -> id, p -> name);
		p = p -> next;
	}

	printf("number of student : %d\n", count);
	exit(0);
}

