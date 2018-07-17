
/* A Generic header of Queue
 */

 struct _Queue{
	void *queues;//array of queue where elemenst will be stored
	int alloc_len;// total size size of array  array of queue
	int logical_len;//total size occupied by the array of queue
	size_t size;//Specifying type ex:int,float,char
	void *front;//Will point to the starting address of front element
	void *rear;//Will point to the starting address of rear element
	void (*freefn)(void *);
};

typedef struct _Queue Queue;

typedef void* QueueValue;

static void default_freefn(QueueValue data) {
	free(data);
}
//Free the memory used by the queue or delete the element of the queue
void Queue_dispose(Queue *q) {
	q->logical_len = 0;
	default_freefn(q->queues);
	free(q);
}

/*@createQueue is just like constructor with paramenter,
 * Queue: Specifiying the queue
 * len:Total length to be allocated or size of array (a[n])
 * size:size of the type such as int or float or char
 */
Queue* Queue_create(const int len, int size,void (*freefn)(QueueValue data)) {
	Queue *q = malloc(sizeof(Queue));
	if(q == NULL)
		return NULL;
	q->logical_len = 0;
	q->alloc_len = len;
	q->size = size;
	q->queues = malloc(q->alloc_len * q->size);//creating array or allocating memory of the allocated size
	if(q->queues == NULL)
		return NULL;
	q->front = NULL;
	q->rear = NULL;
	if(freefn == NULL)
		freefn = default_freefn;
	else
		q->freefn = freefn;
	return q;
}

static int Queue_grow(Queue *q) {
	q->alloc_len *= 2;
	q->queues = realloc(q->queues,q->alloc_len * q->size);
	if(q->queues == NULL)
		return 0;
	return 1;
}
//@Queue_push push the data to the end of the queue
int Queue_push(Queue *q,const void *data) {
	if(q->logical_len > q->alloc_len ) {
		if(!Queue_grow(q))
			return 0;
	}
	QueueValue target = (char*)q->queues + q->logical_len * q->size;//creating the target array which will point to starting address of our data in the array of queue
	memcpy(target,data,q->size);//copying the data
	if(q->logical_len == 0) {
		q->front = target;
		q->rear = target;
		q->logical_len ++;
		return 1;
	}
	else  {
		q->rear = target;//set rear pointer to point to the next element which is inserted in the queue i.e target
		q->logical_len ++;
		return 1;
	}
	return 0;

}

//check wether queus empty or note
int Queue_isEmpty(const Queue *q) {
	if(q->logical_len == 0)
		return 1;
	return 0;
}

//@Queue_pop pop the data oldest the data from the queue which is pointed by front
//Note:Queue_pop does not remove the data form the memory location ,therefore you should call mannually Queue_dispose() to free the memory allocated to the queue 
QueueValue Queue_pop(Queue *q) {
	if(Queue_isEmpty(q)) {
		return NULL;
	}
	QueueValue source = q->front;
	q->front = (char*)q->front + q->size;
	q->logical_len--;
	return source;
}


int Queue_max(const Queue *q) {
	return q->alloc_len;
}


//returns in specifying the total size which is occupied by the queue
int Queue_size(const Queue *q){
	return q->logical_len;
}
//Access the oldest element in the queue ,it does not delete the element in the queue
QueueValue Queue_front(const Queue *q) {
	return q->front;;
}

//Access the last  element in the queue ,it does not delete the element in the queue
QueueValue Queue_back(const Queue *q) {
	return q->rear;
}

//swap the two queue
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
