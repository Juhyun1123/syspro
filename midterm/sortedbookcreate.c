#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "book.h"

int main(int argc, char *argv[]){
	int fd, id;
	char c[10];
	int ch;

	struct Book b[100];
	int count = 0;

	if(argc < 2){
		fprintf(stderr, "How to use: %s file\n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1){
		perror(argv[1]);
		exit(2);
	}

	while((read(fd, (char*)&b[count], sizeof(b[count])) > 0)){
		if(b[count].id == 0){
			//count--;
			continue;
		}
		
		count++;
	}
	

	int i, j;
	for(i = 0; i < count; i++){
		for(j = i; j < count; j++){
			if(b[i].year < b[j].year){
				struct Book temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	
	lseek(fd, 0, SEEK_SET);

	for(i = 0; i < count; i++){
		write(fd, (char*)&b[i], sizeof(b[i]));
	}
	
	exit(0);
}
