#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
	int fd1, fd2;

	if((fd1 = creat("myFile", 0600)) == -1) perror("myFile");

	write(fd1, "Hello! Linux", 12);
	fd2 = dup(fd1);
	write(fd2, "Bye! Linux", 10);

	close(fd1);
	close(fd2);
	exit(0);
}
