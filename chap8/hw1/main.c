#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

void environF();
void myenv(char *str);
void printUserID();
void printGroupID();

int main(int argc, char* argv[]){
	if(argc < 2 || argv[1][0] != '-'){
		fprintf(stderr, "select option -e, -u, -g, -i, -p\n");
		exit(1);
	}

	switch(argv[1][1]){
		case 'e':
			if(argc > 2)
				myenv(argv[2]);
			else 
				environF();
			break;
		case 'u':
			printUserID();
			break;
		case 'g':
			printGroupID();
			break;
		case 'i':
			printf("my process number : [%d]\n", getpid());
			break;
		case 'p':
			printf("my parent's process number : [%d]\n", getppid());
			break;
		default:
			fprintf(stderr,"-%c is not option\n",argv[1][1]);
			exit(3);
	}
	exit(0);
}

void environF(){
	char **ptr;
	extern char **environ;

	for(ptr = environ; *ptr != 0; ptr++)
		printf("%s \n", *ptr);
}

void myenv(char *str){
	printf("%s = %s \n", str, getenv(str));
}

void printUserID(){
	printf("My Realistic User ID : %d(%s)\n", getuid(), getpwuid(getuid()) -> pw_name);
	printf("My Valid User ID : %d(%s)\n", geteuid(), getpwuid(geteuid()) -> pw_name);
}

void printGroupID(){
	printf("My Realistic Group ID : %d(%s)\n", getgid(), getgrgid(getgid()) -> gr_name);
	printf("My Valid Group ID : %d(%s)\n", getegid(), getgrgid(getegid()) -> gr_name);
}
