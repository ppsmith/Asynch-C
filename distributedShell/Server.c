#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#define INPUT_SIZE = 1024;
#include "Socket.h"
#include <string.h>


void main(int args, char *argv[]) {
	ServerSocket welcome;
	ServerSocket complete;
	FILE *fPtr;
	char *ptr;
	char ch1;
	char ch2;
	char *line;
	char *arguments[1024];
	char **input = arguments;
	char *p;
	int *status_ptr;
	int port;
	int charNumber = 0;

	port = atoi(argv[1]);
	
	welcome = ServerSocket_new(port);
	complete = ServerSocket_accept(welcome);


	while(1) {
		line = (char*)malloc(INPUT_SIZE);
		status_ptr = (int*)malloc(sizeof(int));
		
		memset(line, '\0', INPUT_SIZE);
		memset(status_ptr, 0, sizeof(int));
		
		p = line;
		ptr = p;

		int pid;

		pid = getpid();

		sprintf(name, "tmp%i", pid);
		
		while((ch1 = Socket_getc(complete)) != EOF){
			*p = ch1;
			p++;
		}

		fPtr = freopen(name, "w", stdout);
		int childPID = fork();

		if(childPID == -1) {
			printf("Fork Failed");
			free(line);
			free(status_ptr);
		}

		if(childPID == 0) {
			while(*p != '\0') {
				if(*p == '\t' || *p == '\n') {
					*p = ' ';
				}
				p++;
		}

		otr = strtok(NULL, " ");

		while(ptr != NULL) {
			*input++ = ptr;
			ptr = strtok(NULL, " ");		
		}

		*input = NULL;
		
		if((execvp







