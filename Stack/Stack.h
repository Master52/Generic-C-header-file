

typedef struct{
	void *ele_size; //pointing to array of stack
	size_t size; //size of datatype
	unsigned int logical_length; //Simlar to top
	unsigned int allocate_length; //Total size of length
	void (*freefn)(void *);
}Stack;

typedef void* StackValue;

void StackNew(Stack *s,int size,void (*freefn)(StackValue));
void Stack_dispose(Stack *s);
int Stack_push(Stack *s,const StackValue data);
StackValue StackPop(Stack *s);
static void StringFree(void *elem);

//static because can't be used in multiple file
static int StackGrow(Stack *s) {
	s->allocate_length *= 2;
	s->ele_size = realloc(s->ele_size,s->allocate_length * s->size);
	if(s->ele_size == NULL)
		return 0;
	return 1;
}


//Initialization of Stack
Stack* Stack_create(int size,void (*freefn)(StackValue)) {
	if(size < 0 )
		return NULL;
	Stack *s = malloc(sizeof(Stack));
	s->logical_length = 0;
	s->allocate_length = 4;
	s->size = size;
	s->ele_size = malloc(s->allocate_length * s->size);
	if(s->ele_size == NULL)
		return NULL;
	s->freefn = freefn;

}

void Stack_dispose(Stack *s) {
	if(s->freefn != NULL)
		for(int i = 0; i<s->logical_length; i++)
			s->freefn((char*)s->ele_size + i * s->size);
	free(s->ele_size); //Freeing the array of stack
	free(s);
}

static void StringFree(StackValue elem) {
	free(*(char **)elem);
}


int Stack_push(Stack *s,const StackValue data) {
	//Checking wether the top is at max location of array of stack
	if(s->logical_length == s->allocate_length)
		if(!StackGrow(s))
			return 0;
	void *target = (char*)s->ele_size + s->logical_length * s -> size;
	//Copies the bit of block of the memory
	memcpy(target,data,s->size);
	s->logical_length ++;
	return 1;
}

StackValue StackPop(Stack *s) {
	//The reson for (char*) typcasting is void pointer cannot do arthimatic operation
	//Giving the starting address of last emelent if ele_size
	void *source = (char*)s->ele_size + (s->logical_length-1) * s->size;
	s->logical_length --;
	return source;
}

//Return a pointer which points to starting address of the top element
StackValue Stack_top(Stack *s) {
	void *source = (char*)s->ele_size + (s->logical_length-1) * s->size;
	return source;
}

//Return 1(true) if the stack is empty
int  Stack_isEmpty(Stack *s) {
	if(s->logical_length == 0)
		return 1;
	return 0;
}

//Returns the size of the Stack
int Stack_size(Stack *s) {
	return (s->logical_length);

}

