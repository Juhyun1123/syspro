#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "book.h"

int main(int argc, char *argv[]){
	int fd;
	char strbool[10];
	struct Book book;

	if(argc < 2){
		fprintf(stderr, "How to Use: %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_WRONLY| O_CREAT | O_EXCL, 0640)) == -1){
		perror(argv[1]);
		exit(2);
	}

	printf("%4s %10s %10s %4s %10s %7s\n", "id", "bookname", "author", "year", "numofborrow", "borrow");
	

	while(scanf("%d %s %s %d %d %s",
				&book.id, book.bookName, book.author, &book.year, &book.borrowCount,strbool) == 6){
		book.borrow = strbool[0] == 'T' ? 1 : 0;
		lseek(fd, book.id * sizeof(book), SEEK_SET);
		write(fd, (char*) &book, sizeof(book));
	}
	close(fd);
	exit(0);
}
