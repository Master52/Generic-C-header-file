## Generic LinkedList in C

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
This header file is an implementation of Generic Linked List

### Data structure
LinkedList represent following data structure:
```c
 struct _LinkedList{
	size_t size; //dataype size
	int count;//counting the element in the list
	struct _ListNode *head;//head of the linked list
	int (*compare)(void *,void *,int ); 	/*This function wil point to comparision funtion if
	not specified in Llist_create it will point to defaul_cmp funtion for string you have to
	make it point to strim_cmp func*/
	void (*freefn)(void *); /*This function will point to the function where it is writtern
	how dat should be freed by default it will default_cmp for datatype like float,int,double
	if you are storing strings you have to point it to string_free when witing funtion Llist_create*/
};

typedef struct _LinkedList LinkedList;

```
Structure of node is as follow:
```c
 struct _ListNode {
	void *data;
	struct _ListNode *next;
};
typdef struct _ListNode ListNode;

```
## Working with Data Structure

### Creating LinkedList
For creating an LinkedList use ```Llist_create``` function.
For example:

```LinkedList *foo = Llist_create(sizeof(int),NULL,NULL);```
This function will return the pointer LinkedList or NULL if failed to allocate memory
```Llist_create``` takes three argument :
* First the size of the data type.
* Second is the comparision function.If your data type is float,double,int,char, write NULL
or if it is of type String or any other structure provide a comparision function.
* Similary the third argument is also a pointer to function which points to free function for
releasing the memory write NULL if your data type is of int,double,float,char, or else provide
a free function.

### Deleting LinkedList
For Deleting the Linked list object ```Llist_dispose``` function
For example:
```Llist_dispose(foo);```

### Adding 
For Adding an element in the LinkedList use ```Llist_push```function
For example:
```c
int data = 10;
Llist_push(foo,&data);
```
This will add the element at the end of the LinkedList.

### Removing
For removing an element from the LinkedList use ```Llist_remove```funtion.
For example:
```c
int data = 10;
Llist_remove(foo,&data);
```
### Retrieving Value
For getting the head of the list use ```Llist_begin``` function.
```c
ListNode data = Llist_begin(foo);
```
Here the list return a structure pointer of List node.

## Additional Function
```c
Llist_insert_after(LinkedList *foo,const int loc, NodeValue data);

/*Puts the element in particular location*/
```
```c
Llist_pop(LinkedList *foo);

/*returns the head's data of the LinkedList */
//Example:
LinkedList *l = Llist_create(sizeof(int),NULL,NULL);
int data = 10;
Llist_push(l,&data);
int *data = (int*)Llist_pop(l);
free(data);
Llist_dispose(l);
```
Remember to free the retrive data from ```Llist_pop``` fucntion.
```c
Llist_size(LinkedList *foo);

/*Return the size of the LinkedList*/

```
```c
Llist_isEmpty(LinkedList *foo);

/*return 1 if empty or 0;*/
```
```c
Llist_push_front(LinkedList *foo);

/*Push the element at the front of the linked list*/
```
```c
Llist_copy(LinkedList *foo,LinkedList *bar);

/*Copies the data of foo to bar*/
```
```c
Llist_sort(LinkedList *foo);

/*It sorts the element in increasing order based on the comparision function provided */
```
```c
Llist_isPresent(LinkedList *foo,NodeValue data);

/*it return 1 if the element is present else return 0 */
```

```c
Llist_reverse(LinkedList *foo);

/*Reverse the element in the LinkedList */
```

```c
Llist_concat(LinkedList *foo,LinkedList *bar);

/*Concat the two linked list*/
```

```c
LList_isEqual(LinkedList *foo,LinkedList *bar);

/*compare two linked List and return 1 if they are equal or 0 if not*/
```

```c
Llist_replace(LinkedList *foo,NodeValue data,NodeValue replace_data);

/*replace the data in the linked list*/

```c
Llist_unique(LinkedList *list);

/*This function sort the list and remove the duplicate data*/
```

```c
Llist_merge(LinkedList *foo,LinkedList *bar,LinkedList *foobar)

/*Merger the two linked list into the thir one */
 ```

