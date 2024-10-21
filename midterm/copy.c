#include <stdio.h>


int main(int argc, char *argv[]){
	char op = '0', c;
	FILE *fp1, *fp2;
	int fpp1 = 1;
	int fpp2 = 2;
	
	if(argc != 3 && argc != 4){
		fprintf(stderr, "How to Use: %s File1 File2\n", argv[0]);
		return 1;
	}

	if(argc == 4){
		switch(argv[1][0]){
			case '0':
				op = '0';
				break;
			case '1':
				op = '1';
				break;
			case '2':
				op = '2';
				break;
			default:
				fprintf(stderr, "command Fail\n");
				return 2;
		}
		fpp1 = 2;
		fpp2 = 3;
	}

	fp1 = fopen(argv[fpp1], "r");

	if(fp1 == NULL){
		fprintf(stderr, "File %s Open Error\n", argv[fpp1]);
		return 3;
	}

	fp2 = fopen(argv[fpp2], "w");

	while((c = fgetc(fp1)) != EOF){
		if(op == '1'){
			if('A' <= c && c <= 'Z') c = c + 32;
		}
		if(op == '2'){
			if('a' <= c && c <= 'z') c = c - 32;
		}
		printf("%c", c);
		fputc(c, fp2);
	}

	fclose(fp1);
	fclose(fp2);


	return 0;
}
