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
#pragma once
#ifdef __cplusplus
extern 'C' {
#endif

 struct _ListNode {
	void *data;
	struct _ListNode *next;
};
//Construct for the linked list
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

typedef struct _ListNode ListNode;

typedef void* NodeValue;

	
//Funtion for free the linkedlist memeory
//Should be called after the operation on linked is finished or end of the program
void Llist_dispose(LinkedList *list);

int Llist_isEmpty(LinkedList *list);



 int Llist_size(LinkedList *list);



//Creating a linked list
/*
 * Takes 4 argument
 * 1st argument is the pointer to the linked list
 * 2nd argument is the size of data type
 * 3rd argument is pointer to comparision func put NULL for default_cmp
 * 4rd argument is pointer to free func put NULL for defaut_free*/
LinkedList* Llist_create(int type,int (*compare)(NodeValue first,NodeValue seconde,int size),
								void (*freefn)(void *data));
//add the elment to the specified linked list
int Llist_push(LinkedList *list,NodeValue data);


int Llist_remove(LinkedList *list,NodeValue data);

//List_pop will give you the front element form the linked list and 
//delete it from the linked list
//Note:In case of string or other free function other tha defaul_free
//it will just remove the elemet from the list and will give 
//you back the ownership of the data it will not free the data
//it is upto the programmer to free it
NodeValue* Llist_pop(LinkedList *list);

//Pushes the elements to front of the linked list
int Llist_push_front(LinkedList *list,NodeValue data);

//insert the data at specified location
int Llist_insert_after(LinkedList *list,const int loc,NodeValue data);
	//return if the element count of the linked list is smaller then the specified location

//Sorts the linked list in ascending order
void Llist_sort(LinkedList *list);

//Reverse the content of stirng using stack.h header
void Llist_reverse(LinkedList *list);

/*Return 1(i.e ture) if data is present or 0(false) is not*/
int Llist_isPresent(LinkedList *list,NodeValue data);

/*Returns a pointer to a node containing the specified data if not present in
the linked list it returns NULL*/
int Llist_replace(LinkedList *list,NodeValue data,NodeValue replace_data);

/*Merges the first two list into the third one
 * the data in the third list are such that there are no duplicate data
 * form both list */
void Llist_merge(LinkedList *first,LinkedList *second,LinkedList *third);

/*This method sort the elemet of the list and removes all duplicated elements from the list */
void Llist_unique( LinkedList *list);

//returns the pointer to the head of the node so to iterate over the list
NodeValue Llist_front(LinkedList *list);

//concat the two linked list
void Llist_concat(LinkedList *first,LinkedList *second);

//Check wether the Linked list is equal or not
//if equal it return 1(true) or
//0(false)
int Llist_isEqual(LinkedList *first,LinkedList *second);

//Copies the the data of first argument to second argument
int Llist_copy(LinkedList *original,LinkedList *copy);

ListNode* Llist_begin(LinkedList *);

#ifdef __cplusplus
}
#endif
