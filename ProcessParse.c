#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include "buffer.h"
#include <fcnt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define GET 	0;
#define PROCESS 1;
#define PRINT   2;

buffer b[3];
char line[80];
bool wasAst = false;
int lineCount = 0;
int cd, cd, cp;
int q = 0;
char temp;
int parseCount = 0;
char compare[2];
int childPID1;
int childPID2;

void main() {
	b[GET] = bufferCreate(80);
	b[PROCESS] = bufferCreate(80);
	b[PRINT] = bufferCreate(80);

	childPID1 = fork();

	if(childPID1 == -1) {
		fprintf(stderr, "First fork failed");
		exit(1);
	}  

	if(childPID1 == 0) {
		childPID2 = fork();
		
		if(childPID2 == 0) {
			while ((ch = getchar()) != EOF) {
				bufferPutChar(b[GET], ch);
			}
			bufferPutChar(b[GET], EOF);
			exit(0);
		} else {
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
		}
		exit(0);

		} else {
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
	
			
			bufferDestroy(b[GET]);
			bufferDestroy(b[PROCESS]);
			bufferDestroy(b[PRINT]);
			exit(0);
		}
return (void) NULL;
}
			

			

	