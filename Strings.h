#include <stdio.h>
#ifndef _STRING_
#define _STRING_
//-------------------------------------------------------------------------------------------------------------------------------------------------
/* gt_string() function gets the string for user and it returns the base address of input sting
 * remeber to free the pointer when job is over
 */
static char* trim(char* phrase);
char* get_string(void) {
	const size_t sizeIncrementer = 2; //alocating memory in heap
	char * buffer = (char*)malloc(sizeIncrementer); //creating a buffer for holding string
	char* current_poineter = buffer; //points to the last charater enterd
	size_t maximum_length = sizeIncrementer; //length of the string 
	size_t length = 0; //For checking the total length 
	int character;

	if(current_poineter == NULL)
		return NULL;

	while(1) {
		character = fgetc(stdin);
		if (character == '\n')
			break;
		if (++length >= maximum_length) {
			//if length is greater then max heap,realloc the size of heap
			char* newbuffer = realloc(buffer,maximum_length += sizeIncrementer);
			if (newbuffer == NULL) {
				free(buffer);
				return NULL;
			}
		current_poineter = newbuffer + (current_poineter - buffer);
		buffer = newbuffer;
		}
		*current_poineter++ = character;
	}
	return buffer = trim(buffer);
}

//trim() function trims the whitspace if provides at the begaining of the input
static char* trim(char *phrase) {
	char* new = phrase;
	char* old = phrase;
	while(*old == ' ' || *old == '\t')
		old++;

	while(*old)
		*(new++) = *(old++);
	*new = '\0';
	return (char*)realloc(phrase,strlen(phrase));
}


//-----------------------------------------------------------------------------------------------------------------------------------
/*ispresent() function for findind a subtring for a given string takes to argument
 * @s parameter is the string from which a substring is found
 * @word paramenter is the subtring to be found 
 * The way this work is it created a new string from the given string whose length is equal to @word to be searched
 * and check whether they are equal or not.
 * if not increment @s till the end of string
 */


//copy() func copies the string from the the @s whose length is equal to @word
static char* copy(const char *string,const int len) {
	char *wo = (char*)malloc(sizeof(char) + len); //creating a new string of length @word
	char *p = wo;
	for (int i = 0;i<len;i++) {
		*p = *string;
		string++;
		p++;
	}
	*p = '\0';
	return wo; //passing the address of base address of newly created string
}
static int ispresent(const char *s, const char *word) {
	int length = strlen(word);
	while(*s) {
		char *wo = copy(s,length);
		if(strcmp(wo,word) == 0){
			free(wo);//if found free the memory hold by wo and return 0
			return 0;
		}
		s++;
		free(wo);//free the memory if not found to the heap
	}
	return -1;
}
//--------------------------------------------------------------------------------------------------------------------------------------

void sort(char *arr[],const int length) {
	for (int i = 1;i<length;i++){
		char *buf = arr[i];
		int j = i;
		while(j > 0 && strcmp(arr[j-1],arr[j]) > 0) {
				char *temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;
		}
		arr[j] = buf;
	}
}

void rsort(char *arr[],const int length) {
	for (int i = 1;i<length;i++){
		char *buf = arr[i];
		int j = i;
		while(j > 0 && strcmp(arr[j-1],arr[j]) < 0) {
				char *temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;
		}
		arr[j] = buf;
	}
}
#endif
