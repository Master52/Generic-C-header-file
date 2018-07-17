## Generic Queue in C

## License

Copyright (c) 2018,Hatim Master
Permission to use, copy, modify, and/or distribute this software
for any purpose with or without fee is hereby granted, provided
that the above copyright notice and this permission notice appear
in all copies.

THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.


## Usage
This header file is an implementation of Generic Queue

### Data structure
Queue represent following data structure:
```c
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
```

```
## Working with Data Structure

### Creating Queue
For creating an Queue use ```Queue_create``` function.
For example:

```Queue *foo = Queue_create(int length,sizeof(int),NULL);```
This function will return the pointer Queue or NULL if failed to allocate memory
```Queue_create``` takes three argument :
* First the length of the Queue.
*Second size of data type.
* The third argument is also a pointer to function which points to free function for
releasing the memory write NULL if your data type is of int,double,float,char, or else provide
a free function.

### Deleting Queue
For Deleting the Queue object ```Queue_dispose``` function
For example:
```Queue_dispose(foo);```

### Adding 
For Adding an element in the Queue use ```Queue_push```function
For example:
```c
Queue *foo = Queue_create(10,sizeof(int),NULL);
int data = 10;
Queue_push(foo,&data);
```
This will add the element at the end of the Queue.

### Retrieving the front Value
For getting the front Value use ```Queue_pop``` function.
```c
int data = *(int*)Queue_pop(foo);
```
Here it will return the front element of the Queue and also delete it form the list.

## Additional Function
```c
Llist_insert_after(LinkedList *foo,const int loc, NodeValue data);

/*Puts the element in particular location*/
```
```c
Queue_max(Queue *foo);

/*Return the Maximum size of the Queue*/

```
```c
Queue_isEmpty(Queue *foo);

/*return 1 if empty or 0;*/
```
```c
Queue_front(Queue *foo);

/*Accessing the front element from the Queue.It does not delet the front element from the Queue*/
```
```c
Queue_back(Queue *foo);

/*Accessing the rear element form the queue*/
```
