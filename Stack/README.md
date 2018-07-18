# Generic Stack in C

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
This header file is an implementation of Generic Stack

### Data structure
Stack represent following data structure:
```c
 struct Stack{
	void *ele_size; //pointing to array of stack
	size_t size; //size of datatype
	unsigned int logical_length; //Simlar to top
	unsigned int allocate_length; //Total size of length
	void (*freefn)(void *);
};


typedef void* StackValue;
```
## Working with Data Structure

### Creating Stack
For creating an Stack use ```Stack_create``` function.
For example:

```Stack *foo = Stack_create(sizeof(int),NULL);```
This function will return the pointer Stack or NULL if failed to allocate memory
```Stack_create``` takes two argument :
* First size of data type.
* The Second argument is  a pointer to function which points to free function for
releasing the memory write NULL if your data type is of int,double,float,char, or else provide
a free function.

### Deleting Stack
For Deleting the Stack object ```Stack_dispose``` function
For example:
```Stack_dispose(foo);```

### Adding 
For Adding an element in the Stack use ```Stack_push```function
For example:
```c
Stack *foo = Stack_create(sizeof(int),NULL);
int data = 10;
Stack_push(foo,&data);
```
This will add the element at the end of the Stack.

### Popping the element form the Stack
For getting the front Value use ```Stack_pop``` function.
```c
int data = *(int*)Stack_pop(foo);
```
Here it will return the front element of the Stack.

## Additional Function
```c
Llist_insert_after(LinkedList *foo,const int loc, NodeValue data);

/*Puts the element in particular location*/
```
```c
Stack_top(Stack *foo);

/*Access the top element form the Stack,it does not delete it form the Stack*/

```
```c
Stack_isEmpty(Stack *foo);

/*return 1 if empty or 0;*/
```
