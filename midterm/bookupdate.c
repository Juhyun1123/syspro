#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "book.h"

int main(int argc, char *argv[]){
	int fd;
	int id, ch;
	struct Book b;

	if(argc < 2){
		fprintf(stderr, "How to use : %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1){
		perror(argv[1]);
		exit(2);
	}

	printf("input borrowCheck And bookId: ");
	scanf("%d %d", &ch, &id);

//	lseek(fd, id * sizeof(b), SEEK_SET);
	read(fd,(char*)&b,sizeof(b));
	lseek(fd, (id-1) * sizeof(b), SEEK_CUR);

	if(read(fd,(char*)&b, sizeof(b)) > 0 && b.id != 0){

		if(ch == 0 && b.borrow == 1){
			printf("borrow Fail\n");
			exit(0);
		}

		if(ch == 1){
			b.borrow = 0;
		}

		if(ch == 0){
			b.borrowCount++;
			b.borrow = 1;
		}
		
		lseek(fd,-sizeof(b), SEEK_CUR);
		write(fd, (char*)&b,sizeof(b));

		printf("%d %s %s %d %d %s\n",
				b.id, b.bookName, b.author, b.year, b.borrowCount, b.borrow == 1 ? "True" : "False");

	}
	exit(0);
}
