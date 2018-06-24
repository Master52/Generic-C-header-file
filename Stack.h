

typedef struct{
	void *ele_size; //pointing to array of stack
	int size; //size of datatype
	int logical_length; //Simlar to top
	int allocate_length; //Total size of length
	void (*freefn)(void *);
}Stack;

void StackNew(Stack *s,int size,void (*freefn)(void *));
void StackDispose(Stack *s);
void StackPush(Stack *s,void *value);
void StackPop(Stack *s,void *value);
static void StringFree(void *elem);

//static because can't be used in multiple file
static void StackGrow(Stack *s) {
	s->allocate_length *= 2;
	s->ele_size = realloc(s->ele_size,s->allocate_length * s->size);
}


//Initialization of Stack
void StackNew(Stack *s,int size,void (*freefn)(void *)) {
	assert(size > 0); //It's a macro for giving us line number where there is a null pointer problem
	s->logical_length = 0;
	s->allocate_length = 4;
	s->size = size;
	s->ele_size = malloc(s->allocate_length * s->size);
	assert(s->ele_size != NULL);
	s->freefn = freefn;

}

void StackDispose(Stack *s) {
	if(s->freefn != NULL)
		for(int i = 0; i<s->logical_length; i++)
			s->freefn((char*)s->ele_size + i * s->size);
	free(s->ele_size); //Freeing the array of stack
}

static void StringFree(void *elem) {
	free(*(char **)elem);
}


void StackPush(Stack *s,void *value) {
	//Checking wether the top is at max location of array of stack
	if(s->logical_length == s->allocate_length)
		StackGrow(s);
	void *target = (char*)s->ele_size + s->logical_length * s -> size;
	//Copies the bit of block of the memory
	memcpy(target,value,s->size);
	s->logical_length ++;
}

void StackPop(Stack *s,void *value) {
	//The reson for (char*) typcasting is void pointer cannot do arthimatic operation
	//Giving the starting address of last emelent if ele_size
	void *source = (char*)s->ele_size + (s->logical_length-1) * s->size;
	memcpy(value,source,s->size);
	s->logical_length --;
}


