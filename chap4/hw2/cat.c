#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void fileOpen(FILE **fp, char *str);
void filePrint(FILE *fp, bool ch);

int main(int argc, char *argv[]){
	FILE *fp;

	if(argc == 1 || (!strcmp(argv[1],"-n") && argc == 2)){
		fprintf(stderr, "Please input File name\n");
		return 1;
	}

	int i = strcmp(argv[1],"-n") ? 1 : 2; 
	bool ch = i == 1 ? false : true;

	for(; i < argc; i++){
		fileOpen(&fp, argv[i]);
		filePrint(fp, ch);
		fclose(fp);
	}
}

void fileOpen(FILE **fp, char *str){

	if((*fp = fopen(str, "r")) == NULL){
		fprintf(stderr, "Fail Open File\n");
		exit(1);
	}
}

void filePrint(FILE *fp, bool ch){
	static int num = 1;
	char c;
	char temp;
	if(ch) printf("\t%d ", num++);

	while((c = fgetc(fp)) != EOF){
		if(temp == '\n' && ch) printf("\t%d ", num++);
		printf("%c", c);
		if(ch) temp = c;
	}
}
