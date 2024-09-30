#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];
char longestSort[5][MAXLINE];

void swap(char *str1, char *str2){
	char temp[MAXLINE];
	copy(str1, temp);
	copy(str2, str1);
	copy(temp, str2);
}

void sort(int size){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = i; j< size; j++){
			if(strlen(longestSort[i]) < strlen(longestSort[j]))
				swap(longestSort[i], longestSort[j]);

		}
	}

}

int main(void){
	int len;
	int i;

	for(i = 0; i < 5; i++){
		gets(line);
		copy(line, longestSort[i]);
	}
	sort(5);
	for(i = 0; i < 5; i++){
		printf("%s \n",longestSort[i]);
	}



}
