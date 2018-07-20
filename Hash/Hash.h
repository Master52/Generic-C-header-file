
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* HashTable;


typedef void* HashValue;

struct _HashMap {
	size_t size;
	void* table;
	unsigned int primeIndex;
	void (*freefn)(HashValue );
	unsigned long (*hashFun)(char *);
};

typedef struct _HashMap HashMap;

HashMap* Hash_create(size_t,void (*freefn)(HashValue ),unsigned long (*hashFun)(char*));

/*TODO*/
/*
 * @Hash_dispose
 * @Hash_add
 * @Hash_getValue
 * @Hash_removeValue
 * @Hash_replace
 * @Hash_getIndex
 * @Hash_isEmpty
 * @Hash_max
 */
