#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>
#include <string.h>
#include "buffer.h"

typedef struct safebuf {
	char *name;
	char buffer[80];
	sem_t *empty;
	sem_t *full;
	int *nextOut;
	int nextIn;
} safebuf_t, *safebufp_t;


buffer bufferCreate(char* name, int size) {
	safebufp_t bp;
	bp = (safebufp_t) malloc (sizeof (safebuf_t));
	
	if(name != NULL){
		bp->name = (char*) malloc(sizeof(strlen(name));
		strcpy (bp-name, name);
	} else {
		bp -> name = NULL;
		bp->empty = (sem_t*) malloc(sizeof(sem_t));
		sem_init (bp->empty, 0, 1);
		bp->full = (sem_t*) malloc(sizeof(sem_t));
		sem_init(bp->full, 0, 0);
		bp->nextIn = (int*) malloc(sizeof(int));
		bp->nextOut = (int*) malloc(sizeof(int));
		*bp->nextOut, *bp->nextIn = 0;
		return (buffer) bp;
	}
}

int bufferGetChar(buffer b) {
	int rc = 0;
	safebufp_t bp;
	bp = (safebufp_t)b;
	sem_wait(bp->full);
	rc = bp->buffer[*bp->nextOut%79];
	*bp->nextOut = *bp->nextOut + 1;
	sem_post(bp->empty);
	return rc;
}

int bufferPutChar(buffer b) {
	int rc = 0;
	safebufp_t bp;
	bp = (safebufp_t)b;
	sem_wait(bp->empty);
	rc = bp->buffer[*bp->nextIn%79];
	*bp->nextIn = *bp->nextIn + 1;
	sem_post(bp->full);
	return rc;
}

int bufferDestroy(buffer b) {
	safebufp_t bp;
	bp = (safebufp_t)b;
	sem_destroy(bp->full);
	sem_destroy(bp->empty);

	free(bp->name);
	free(bp->empty);
	free(bp->full);
	free(bp->nextOut);
	free(bp->nextIn);
	free(bp);
	return 0;
}

	



	
