#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*, char op);

int main(int argc, char **argv){
	DIR *dp;
	char *dir;
	struct stat st;
	struct dirent *d;
	char path[BUFSIZ + 1];
	char op = '\0';

	if(argc == 1)
		dir = ".";
	else if(argc == 2){
		if(argv[1][0] == '-'){
			dir = ".";
			op = argv[1][1];
		}
		else{
			dir = argv[1];
		}	
	}else if(argc == 3){
		dir = argv[1];
		op = argv[2][1];
	}else{
		perror("Command format error");
		exit(1);
	}

	if((dp = opendir(dir)) == NULL)
		perror(dir);

	while((d = readdir(dp)) != NULL){
		sprintf(path, "%s/%s", dir, d -> d_name);
		if(lstat(path, &st) < 0)
			perror(path);
		else
			printStat(path, d -> d_name, &st, op);
	}

	closedir(dp);
	exit(0);
}

char type(mode_t mode){
	if(S_ISREG(mode))
		return('-');
	if(S_ISDIR(mode))
		return('d');
	if(S_ISCHR(mode))
		return('c');
	if(S_ISBLK(mode))
		return('b');
	if(S_ISLNK(mode))
		return('l');
	if(S_ISFIFO(mode))
		return('p');
	if(S_ISSOCK(mode))
		return('s');
}

char* perm(mode_t mode){
	static char perms[10];
	strcpy(perms, "---------");

	for(int i = 0; i < 3; i++){
		if(mode & (S_IRUSR >> i*3))
			perms[i*3] = 'r';
		if(mode & (S_IWUSR >> i*3))
			perms[i*3+1] = 'w';
		if(mode & (S_IXUSR >> i*3))
			perms[i*3+2] = 'x';
	}

	return(perms);
}

void printStat(char *pathname, char *file, struct stat *st, char op){
	printf("%5ld ", st -> st_blocks);
	if(op == 'i') printf("%ld ", st -> st_ino);
	printf("%c%s ", type(st -> st_mode), perm(st -> st_mode));
	printf("%3ld ", st -> st_nlink);
	printf("%s %s ", getpwuid(st -> st_uid) -> pw_name, getgrgid(st -> st_gid) -> gr_name);
	printf("%9ld ", st -> st_size);
	printf("%.12s ", ctime(&st -> st_mtime) + 4);
	if(op == 'Q') printf("\"");
	printf("%s", file);
	if(op == 'Q') printf("\"\n");
	else if(op == 'p' && type(st -> st_mode) == 'd') printf("/\n");
	else printf("\n");
}
















