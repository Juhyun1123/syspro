#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	char name[20];
};

int main(void){
	struct student *ptr;
	int i, n;

	printf("Please enter the number of students : ");
	scanf("%d", &n);

	if(n <= 0){
		fprintf(stderr, "error: fail input\n");
		fprintf(stderr, "program exit\n");
		exit(1);
	}

	ptr = (struct student*)malloc(n * sizeof(struct student));
	if(ptr == NULL){
		perror("malloc");
		exit(2);
	}

	printf("please input student number and name of %d students\n", n);
	for(i = 0; i < n; i++)
		scanf("%d %s", &ptr[i].id, ptr[i].name);

	printf("\n* student information(reverse) *\n");
	for(i = n - 1; i >= 0; i--)
		printf("%d %s\n", ptr[i].id, ptr[i].name);

	printf("\n");
	exit(0);
}
