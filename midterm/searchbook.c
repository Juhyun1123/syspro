#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "book.h"

int main(int argc, char *argv[]){
	int fd, id;
	char c[10];
	char name[NAME_MAX];
	int ch;

	struct Book b;

	if(argc < 2){
		fprintf(stderr, "How to use: %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}
	
	printf("input name of book: ");
	scanf("%s", name);

	printf("%s %s %s %s %s %s \n","id","bookname","author","year","namofborrow","borrow");

	while((read(fd, (char*)&b, sizeof(b)) > 0)){
		if(b.id == 0) continue;
		if(ch == 1 && b.borrow == 0) continue;
		if(strcmp(b.bookName, name) != 0) continue;
		printf("%d\t%s\t%s\t%d\t%d\t\%s\n",
				b.id,b.bookName,b.author,b.year,b.borrowCount,b.borrow == 1 ? "True" : "False");
		exit(0);
	}	

	printf("not found book name : %s", name);
	exit(0);
}