#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<sys/wait.h>


int childPID;
char *line;
char *args[1024];
char **input = args;
char *ptr;
char *p;


int main() {
	line = (char*)malloc(1024);
	printf("%% ");
	
	while(fgets(line, 1024, stdin) != NULL) {
		if(p == strchr(line, '\n') {
			fprintf(stderr, "Command too big. Please limit to 1024 bytes");
			scanf("%*[^\n]");
			scanf("%*c");
			main();
	}


	ptr = line;
	
	childPID = fork();

	if(childPID == -1){
		frpintf("stderr, "Fork Failed");
		free(line);
	}else if (childPID == 0) {
		
		while(*line != '\0') {
			if(*line == '\t' || *line == ''\n') {
				*line = ' ';
			}
			line++;
		}

		ptr = strtok(ptr, " ");
		
		while(ptr != NULL) {
			*input++ = ptr;
			ptr = strtok(NULL, " ");
		}

		*input = NULL;

		if((execvp(args[0]. args) == -1)) {
			fprintf(stderr, "Exec Failed: File '%s' not found \n", args[0]);
			exit(1);
		} else {

			exit(0);
		}
	} else {
		wait(NULL);
		printf("%% );
	}
	exit(0);
}
		