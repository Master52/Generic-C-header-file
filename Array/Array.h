/*Copyright (c) 2018,Hatim Master

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
 */

/*
 *
 *
 * @file Array.h
 *
 * An implementation of Dynamic Array
 *
 * To create an use @Array_create and to destory use
 * @Array_dispose
 *
 * To add the element in the array use @Array_add or @Array_add_att
 * To retrive the first element from the array use @Array_front and
 * to retrueve the last element fromt the array use @Array_end
 *
 * From removing the Array use @Array_remove or @Array_remove_at
 *
 * To retrieve the element from a particular index use @Array_at
 * To know the value to a particular index use @Array_indexOf
 */

#pragma once
#ifdef __cplusplus
extern 'C' {
#endif

//Structure of Array
 struct _Array{
	void *array; //points to stating location of an Array
	size_t size;//size of data type
	int alloc_len; //Total length allocated to Array
	int logical_len; //Total length occupied in the Array
	int (*compfn)(void *,void *,size_t); //A comparion fuction for array 
	void (*freefn)(void *);//A pointer to free function
};


typedef struct _Array Array;

typedef void* ArrayValue;//pointing to data of the array

#define ArrayNULL ((void *)0) //NULL value
/*
 * @Array_create take 3 argument
 * 1)size of datatype
 * 2)Pointer to comparision funtion if the ArrayValue is only numbers or char use NULL
 * 3)Pointer to free funtion if the ArrayValue is only numbers or char use NULL
 * if Succes return pointer to Array else ArrayNULL
 */
Array* Array_create(int ,int (*comfn)(ArrayValue,ArrayValue,size_t),void (*freefn)(ArrayValue ));

/*
 * @Array_add_at put the element to the index specified
 * Taker 3 argument
 * 1)Pointer of Array
 * 2)index
 * 3)pointer of adderss of data
 * if Succes returen 1 else return 0
 */
int Array_add_at(Array *arr,int index,ArrayValue data);



//@Array_dispose frees the memory from the heap
//Note:Should always be called after work on Array is done
void Array_dispose(Array *arr);


/*
 * Return a ArrayValue at particular index
 * Note:Remember to typcast the return ArrayValue while using it
 */
ArrayValue Array_at(Array *arr,int index);



//@Array_indexOf:returns the index of ArrayValue esle return -1
int Array_indexOf(Array *arr,ArrayValue data);



//Adds the data to the Array
//Return 1 on success esle 0
int Array_add(Array *arr,ArrayValue data);



/*
 * @Array_begin:It return the base adderess of whole Array 
 */
ArrayValue Array_begin(Array *arr);



//@Array_end:returns the base address of the last index of the entire Array
ArrayValue Array_end(Array *arr);



//@Array_size:Return the size of the Array occupied 
int Array_size(Array *arr);



//@Array_maxSize:return the max Size of the Array
int Array_maxSize(Array *arr);



/*
 * @ Array_isEmpty return 0 if empty else
 * return 1
 */
int Array_isEmpty(Array *arr);



//@Array_remove:
//Removes the data from the array
//On success return 1 else 0
int Array_remove(Array *arr,ArrayValue data);



//@Array_removeAt:
//Remove the data from the particular index
//On Success return 1 else 0
int Array_removeAt(Array *arr,int index);


//@Array_front: gives the first element in the Array
ArrayValue Array_front(Array *arr);


//@Array_end:returns the last elment from the Array
ArrayValue Array_back(Array *arr);


//@Array_sort:Sorts the Array using bubble sort
void Array_sort(Array *arr);


//@Array_isPresent:
//return 1 if the data is present else 0

int Array_isPresent(Array *arr,ArrayValue data);
//@Array_BisPresent:same as Array_isPresent but uses binary search if the element is sorted
int Array_BisPresent(Array *arr,ArrayValue data);


#ifdef __cplusplus
}
#endif
