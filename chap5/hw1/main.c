#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void readLine(char **buffer, int line);
void readAllLine(char **buffer, int size);
char** readFile(int fd, int *c); 

int main(int argc, char *argv[]){
	int fd;
	int col = 1;
	int i, j;

	if(argc != 2){
		fprintf(stderr, "How to use : %s \n", argv[0]);
		exit(1);
	}

	if((fd = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(2);
	}

	char **buffer = readFile(dup(fd), &col);
	char *wantLine = (char*)malloc(sizeof(char) * col * 2 + 1);

	printf("File read success");
	printf("Total Line : %d\n", col);
	printf("You can choose 1 ~ %d Line\n", col);
	printf("Pls 'Enter' the line to select : ");
	scanf("%s", wantLine);

	if(wantLine[0] == '*'){
		readAllLine(buffer, col);
	}else if(wantLine[1] == '\0'){
		readLine(buffer, wantLine[0] - '0' - 1);
	}else if(wantLine[1] == '-'){
		for(i = wantLine[0] - '0' + - 1; i < wantLine[2] - '0'; i++)
			readLine(buffer, i);
	}else if(wantLine[1] == ','){
		for(i = 0; i < strlen(wantLine); i++){
			if(wantLine[i] == ',') continue;
			readLine(buffer, wantLine[i] - '0' - 1);
		}
	}else{
		printf("error\n");
	}

	exit(0);
}

void readLine(char **buffer, int line){
	printf("%s", buffer[line]);
}

void readAllLine(char **buffer, int size){
	int i = 0;
	for(i = 0; i < size; i++) readLine(buffer, i);	
}

char** readFile(int fd, int *c){
	char **buffer = (char**)malloc(sizeof(char*) * (*c));
	buffer[0] = (char*)malloc(sizeof(char) * 10);

	char buf;
	int n;
	int col_size = *c, cp = 0;
	int row_size = 10, rp = 0;

	buffer[0] = (char*)malloc(sizeof(char) * 10);
	

	while((n = read(fd, &buf, 1)) > 0){
		if(cp >= col_size){
			buffer = (char**)realloc(buffer , sizeof(char*) * (++col_size));
			buffer[col_size - 1] = malloc(sizeof(char*) * 10);
		}
		if(rp >= row_size){
			buffer[cp] = (char*)realloc(buffer[cp], sizeof(char*) * (row_size + 2));
			row_size += 2;
		}

		buffer[cp][rp] = buf;
		rp++;

		if(buf == '\n'){
			buffer[cp][rp] = '\0';
			
			row_size = 10;
			rp = 0;
			cp++;
		}
	}

	*c = col_size;
	return buffer;
}










