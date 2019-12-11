typedef void *buffer;

buffer bufferCreate(char* name, int size);
int bufferGetChar(buffer b);
int bufferPutChar (buffer b, int ch);
int bufferDestroy(buffer b);
