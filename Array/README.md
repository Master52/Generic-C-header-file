## Dynamic Array in C


## Usage
This header file is an implementation of Dynamic Array

### Data structure
Array represent following data structure:

```c
/*Array Structure*/
 struct _Array{
	void *array; //points to stating location of an Array
	size_t size;//size of data type
	int alloc_len; //Total length allocated to Array
	int logical_len; //Total length occupied in the Array
	int (*compfn)(void *,void *,size_t); //A comparion fuction for array 
	void (*freefn)(void *);//A pointer to free function
};

typedef struct _Array Array;
```
## Working with Data Structure

### Creating Array
For creating an Array use ```Array_create``` function.
For example:

```Array *foo = Array_create(sizeof(int),NULL,NULL);```
This function will return the pointer Array or NULL if failed to allocate memory
```Array_create``` takes three argument :
* First the size of the data type.
* Second is the comparision function.If your data type is float,double,int,char write NULL
or if it is of type String or any other structure provide a comparision function
* Similary the third argument is also a pointer to function which points to free funtion for
freeing the memory wirte NULL if your data type is of int,double,float,char or else provide
a free function.

### Deleting Array
For Deleting the Array object ```Array_dispose``` function
For example:
```Array_dispose(foo);```

### Adding 
For Adding an element in the Array use ```Array_add```function
For example:
```c
int data = 10;
Array_add(foo,&data);
```
This will add the element at the end of the Array

### Removing
For removing an element from the Array use ```Array_remove```funtion.
For example:
```c
int data = 10;
Array_remove(foo,&data);
```
### Retrieving Value
For getting the value from a particular index use ```Array_at``` fucntion.
```c
int data = (int)Array_at(foo,1);
```
Here the second parameter is the index.
Remember to typcast as it will return pointer to void*.

## Additional Function
```c
Array_add_at(Array *foo,int index,ArrayValue data);
/*Puts the element in particular index*/
```
```c
Array_indexOf(Array *foo,ArrayValue data);
/*returns an index of the data*/
```
```c
Array_size(Array *foo);
/*Return the size of the Array*/

```
```c
Array_isEmpty(Array *foo);
/*return 1 if empty or 0;*/
```
```c
Array_removeAt(Array *foo,int index);
/*To remove the element at particular index */
```
```c
Array_fornt(Array *foo);
Array_back(Array *foo);
/*return front or back element of the array */
```
```c
Array_sort(Array *foo);
/*It sorts the element in increasing order based on the comparision function provided */
```
```c
Array_isPresent(Array *foo,ArrayValue data);
/*it return 1 if the element is present else return 0 */
//Retrieving```
