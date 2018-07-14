
/* A Generic header of Queue
 */

typedef struct{
	void *queues;//array of queue where elemenst will be stored
	int alloc_len;// total size size of array  array of queue
	int logical_len;//total size occupied by the array of queue
	unsigned short size;//Specifying type ex:int,float,char
	void *front;//Will point to the starting address of front element
	void *rear;//Will point to the starting address of rear element
	void (*freefn)(void *);
}Queue;

static void default_freefn(void *data) {
	free(data);
}
//Free the memory used by the queue or delete the element of the queue
void Queue_dispose(Queue *q) {
	q->logical_len = 0;
	default_freefn(q->queues);
}

/*@createQueue is just like constructor with paramenter,
 * Queue: Specifiying the queue
 * len:Total length to be allocated or size of array (a[n])
 * size:size of the type such as int or float or char
 */
void createQueue(Queue *q,const int len, int size,void (*freefn)(void *data)) {
	q->logical_len = 0;
	q->alloc_len = len;
	q->size = (unsigned short)size;
	q->queues = malloc(q->alloc_len * q->size);//creating array or allocating memory of the allocated size
	assert(q->queues != NULL);
	q->front = NULL;
	q->rear = NULL;
	if(freefn == NULL)
		freefn = default_freefn;
	else
		q->freefn = freefn;
}

static void Queue_grow(Queue *q) {
	q->alloc_len *= 2;
	q->queues = realloc(q->queues,q->alloc_len * q->size);
}
//@Queue_push push the data to the end of the queue
void Queue_push(Queue *q,const void *data) {
	if(q->logical_len > q->alloc_len ) {
		Queue_grow(q);
	}
	void *target = (char*)q->queues + q->logical_len * q->size;//creating the target array which will point to starting address of our data in the array of queue
	memcpy(target,data,q->size);//copying the data
	if(q->logical_len == 0) {
		q->front = target;
		q->rear = target;
		q->logical_len ++;
	}
	else  {
		q->rear = target;//set rear pointer to point to the next element which is inserted in the queue i.e target
		q->logical_len ++;
	}

}

//check wether queus empty or note
int Queue_isEmpty(const Queue *q) {
	if(q->logical_len == 0)
		return 1;
	return 0;
}

//@Queue_pop pop the data oldest the data from the queue which is pointed by front
//data:is the varaible type passed by the user to replicate the data is the data variable
//Note:Queue_pop does not remove the data form the memory location ,therefore you should call mannually Queue_dispose() to free the memory allocated to the queue 
void Queue_pop(Queue *q,void *data) {
	if(Queue_isEmpty(q)) {
		printf("Queue is Empty\n");
		return;
	}
	void *source = q->front;
	q->front = (char*)q->front + q->size;
	q->logical_len--;
	memcpy(data,source,q->size);
}


int Queue_max(const Queue *q) {
	return q->alloc_len;
}


//returns in specifying the total size which is occupied by the queue
int Queue_size(const Queue *q){
	return q->logical_len;
}
//Access the oldest element in the queue ,it does not delete the element in the queue
void Queue_front(const Queue *q,void *data) {
	memcpy(data,q->front,q->size);
}

//Access the last  element in the queue ,it does not delete the element in the queue
void Queue_back(const Queue *q,void *data) {
	memcpy(data,q->rear,q->size);
}
//return the return the starting address of front element of the queue
void* Queue_f(const Queue *q){
	return q->front;
}

//return the return the starting address of last element of the queue
void* Queue_r(const Queue *q) {
	return q->rear;
}
//swap the two queue
//Not prooper need improvement
void Queue_swap(Queue *first,Queue *second) {
	Queue *temp;
	temp->logical_len = first->logical_len;
	temp->alloc_len = first->alloc_len;
	temp->size = first->size;
	temp->queues = first->queues;
	temp->front = first->front;
	temp->rear = first->rear;

	first->logical_len = second->logical_len;
	first->alloc_len = second->alloc_len;
	first->size = second->size;
	first->queues = second->queues;
	first->front = second->front;
	first->rear = second->rear;

	second->logical_len = temp->logical_len;
	second->alloc_len = temp->alloc_len;
	second->size = temp->size;
	second->queues = temp->queues;
	second->front = temp->front;
	second->rear = temp->rear;

}
