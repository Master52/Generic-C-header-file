#include <stdio.h>
#include "Hash.c"
int main(int argc,char* argv[]) {
	HashMap *foo = Hash_create(sizeof(int),NULL,NULL);
	int a = 10;
	Hash_add(foo,"Haitm",&a);
	return 0;
} 
