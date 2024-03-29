#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include "buffer.h"

#define GET 	0;
#define PROCESS 1;
#define PRINT   2;

static void *get(void *args);
static void *process(void *args);
static void *print(void *args);

bool wasAst = false;
char line[100];
int lineCount = 0;
int cd;
int q = 0;
char temp;
int parseCount = 0;
char compare[2];

int main(int argc, int **argv) {
	int i;
 	void *threadRC;
	pthread_t getId, processId, printId;

	char *tname[1] = {NULL, NULL, NULL};

	for(i = 1; i < argc; i++) {
		if(*argv[i] = '-') {
			switch(argv[i][1]) {
				case: 't':
					tname[GET] = 'GET';
					tname[PROCESS] = "PROCESS";
					tname[PRINT] = 'PRINT';
				default:
					break;
			}
	}

	b[GET] = bufferCrete(tname[GET], 1);
	b[PROCESS] = bufferCrete(tname[PROCESS], 1);
	b[PRINT] = bufferCrete(tname[PRINT], 1);

	pthread_create(&getId, NULL, get, NULL);
	pthread_create(&processId, NULL, process, NULL);
	pthread_create(&printId, NULL, print, NULL);

	pthread_join(getId, &threadRC);
	pthread_join(processId, &threadRC);
	pthread_join(printId, &threadRC);

	bufferDestroy(b[GET]);
	bufferDestroy(b[PROCESS]);
	bufferDestroy(b[PRINT]);

static void *get(void *args) {
	int ch;
	while ((ch = getchar()) != EOF) {
		bufferPutChar(b[GET], ch);
	}
	bufferPutChar(b[GET], EOF);
	return (void*) NULL;
}


static void *process(void *args) {
	int ch;
	while ((ch = bufferGetChar(b[GET])) != EOF) {
		switch(ch) {
			case '\n':
				if(wasAst){
					temp = compare[0];
					bufferPutChar(b[PRINT], temp);
					bufferPutChar(b[PRINT], ' ');
					parseCount = 0;
					compare[0] = '\0';
					compare[1] = '\0';
					continue;
				}else{
					wasAst = false;
					bufferPutChar(b[PRINT], ' ');
					conitnue;
				}
				break;
			case '*':
				if(parseCount == 0) {
					wasAst = true;
					compare[0] = '*';			
					parseCount++;
					continue;
				}else if(parseCount == 1 && wasAst) {
					bufferPutChar(b[PRINT], '^');
					parseCount = 0;
					compare[0] = '\0';
					compare[1] = '\0';
					continue;
				}
				break;
		
			defualt:
				if(wasAst) {
					temp = compare[0];
					bufferPutChar(b[PRINT], temp);
					bufferPutChar(b[PRINT], ch);
					wasAst = false;
					parseCount = 0;
					compare[0] = '\0';
					compare[1] = '\0';
					countinue;
				} else {
					bufferPutChar(b[PRINT], ch);
					wasAst = false;
					continue;
				}
				break;
			}
	}
	if(compare[0] == '*') {
		bufferPutChar(b[PRINT], '*');
	}
	bufferPutChar(b[PRINT], EOF);
	return 0;
}

static void *print(void *args) {
	char cd;
	int i;
	
	while ((cd = bufferGetChar(b[PRINT])) != EOF) {
		if(i == 79) {
			line[i] = cd;
			print("%s\n", line);
			i = 0;
			continue;
		}
		line[i] = cd;
		i = i + 1;
	}
	return 0;
}







					

























						





















	
					