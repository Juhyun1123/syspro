#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *masterFile;
	FILE *appendFile;
	char c;

	if(argc != 3){
		fprintf(stderr, "How to use: %s FileName\n", argv[0]);
		return 1;
	}

	if((masterFile = fopen(argv[2], "r + w")) == NULL){
		fprintf(stderr, "Fail Open %s\n", argv[2]);
		return 1;
	}

	if((appendFile = fopen(argv[1], "r")) == NULL){
		fprintf(stderr, "Faile Open %s\n", argv[1]);
		return 1;
	}

	
	while((c = fgetc(masterFile)) != EOF){}
	fseek(masterFile, -1, SEEK_CUR);

	while((c = fgetc(appendFile)) != EOF){
		fputc(c, masterFile);
	}
	
	fclose(masterFile);
	fclose(appendFile);
	return 0;
}
