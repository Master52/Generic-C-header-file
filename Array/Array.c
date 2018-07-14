/* Array.c
 *
 * Author:Hatim Master
 *
 * Modified By:Hatim Master
 * Generic implementation of Array in C
 *
 * Compiled through gcc
 */

#include <string.h>
#include <stdlib.h>
#include "Array.h"
#include <stdio.h>

static int default_compfn(ArrayValue,ArrayValue,size_t);
static void default_freefn (void *);

Array* Array_create(int size,int (*compfn)(ArrayValue ,ArrayValue ,size_t),void (*freefn)(ArrayValue )){
	Array *arr = malloc(sizeof(Array));
	arr->alloc_len = 10;
	arr->logical_len = 0;
	if(size < 0){
		printf("Error:\nSize of data type two small\n"); 
		exit(EXIT_FAILURE);
	}
	arr->size = size;
	arr->array = malloc(arr->alloc_len * arr->size);
	if(arr->array == ArrayNULL)
		return ArrayNULL;
	if(compfn == ArrayNULL)
		arr->compfn = default_compfn;
	else
		arr->compfn = compfn;
	if(freefn == ArrayNULL)
		arr->freefn = default_freefn;
	else
		arr->freefn = freefn;
	return arr;
}

static void default_freefn(ArrayValue data){
	free(data);
}

static int default_compfn (ArrayValue first,ArrayValue second,size_t size) {
	return memcmp(first,second,size);
}

static int Array_grow(Array *arr){
	arr->alloc_len *= 2;
	arr->array = realloc(arr->array,arr->alloc_len * arr->size);
	if(arr->array == NULL) {
		printf("Error\nUnable to rellocate the Array memory\n");
		return 0;

	}
	return 1;
}
int Array_add_at(Array *arr,int index,ArrayValue data){
	if(arr->logical_len == arr->alloc_len) 
		 if(Array_grow(arr) == 0)
			 return 0;
	void *target = (char*)arr->array + index * arr->size;
	memcpy(target,data,arr->size);
	arr->logical_len++;
	return 1;
}

static int swap(ArrayValue first,ArrayValue second,size_t size){
	void *temp = malloc(size);
	if(temp == ArrayNULL)
		return 0;
	memcpy(temp,first,size);
	memcpy(first,second,size);
	memcpy(second,temp,size);
	free(temp);
	return 1;
}

void Array_dispose(Array *arr){
	arr->freefn(arr->array);
	free(arr);
}
ArrayValue Array_at(Array *arr,int index){
	void *source = (char*)arr->array + index * arr->size;
	return source;
}

int Array_indexOf(Array *arr,ArrayValue data){
	for(int i = 0,n = arr->logical_len; i < n ; i++) {
		void *source = (char*)arr->array + i * arr->size;
		if(arr->compfn(source,data,arr->size) == 0)
			return i;
	}
	return -1;
}

int Array_add(Array *arr,ArrayValue data){
	if(arr->logical_len == arr->alloc_len) {
		int status = Array_grow(arr);
		if(status == 0)
			return 0;
	}
	void *target = (char*)arr->array + arr->logical_len * arr->size;
	memcpy(target,data,arr->size); arr->logical_len++;
	return 1;
}
ArrayValue Array_begin(Array *arr){
	if(arr->logical_len == 0)
		return ArrayNULL;
	return arr->array;
}

ArrayValue Array_end(Array *arr) {
	if(arr->logical_len == 0)
		return ArrayNULL;
	return ((char*)arr->array + (arr->logical_len ) * arr->size) ;
}
int Array_size(Array *arr){
	return arr->logical_len;
}
int Array_maxSize(Array *arr){
	return arr->alloc_len;
}
int Array_isEmpty(Array *arr){
	if(arr->logical_len > 0)
		return 0;
	return 1;
}
int Array_remove(Array *arr,ArrayValue data){
	for ( int i = 0; i < arr->logical_len ; i++) {
		void *target = (char*)arr->array + i * arr->size;
		if(arr->compfn(target,data,arr->size) == 0 ) {
			memmove(target,(char*)target + arr->size,(arr->logical_len - i) * arr->size);
			arr->logical_len--;
			return 1;
		}
		else 
			return 0;
	}
}
int Array_removeAt(Array *arr,int index){
	if(index > arr->logical_len)
		return 0;
	void *target = (char*)arr->array + index * arr->size;
	memmove(target,(char*)target + arr->size,(arr->logical_len - index) * arr->size);
	arr->logical_len--;
	return 1;

}
ArrayValue Array_front(Array *arr){
	if(arr->logical_len == 0)
		return ArrayNULL;
	return( Array_begin(arr));
}
ArrayValue Array_back(Array *arr){
	if(arr->logical_len == 0)
		return ArrayNULL;
	void *source = (char*)Array_end(arr) - arr->size;;
	return source;
}
void Array_sort(Array *arr){
	for(int i = 0; i< arr->logical_len;i++)
		for(int j = 0; j < arr->logical_len -1 ;j++)
			if(arr->compfn(((char*)arr->array + j * arr->size),((char*)arr->array + (j+1) * arr->size),arr->size) > 0)
				swap(((char*)arr->array + j * arr->size),((char*)arr->array + (j+1) * arr->size),arr->size);
}

int Array_BisPresent(Array *arr,ArrayValue data) {
	int low = 0;
	int heigh = arr->logical_len;
	int middle = (low + heigh )/2;
	while(low <= heigh) {
		int comp = arr->compfn(((char*)arr->array + middle * arr->size),data,arr->size); 
		if(comp == 0)
			return 1;
		else if(comp > 0)
			heigh = middle -1;
		else
			low = middle + 1;
		middle = (low + heigh)/2;
	}
	return 0;

}
int Array_isPresent(Array *arr,ArrayValue data){
	for(int i = 0; i < arr->logical_len - 1; i++)
		if(arr->compfn(((char*)arr->array + i * arr->size),data,arr->size) == 0)
			return 1;
	return 0;
}

