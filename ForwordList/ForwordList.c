#include<stdlib.h>
#include<string.h>
#include "../Stack/Stack.h"
#include "ForwordList.h"

static int default_comp(NodeValue first,NodeValue second,int size){ 
	return memcmp(first,second,size);

}

static int string_cmp(NodeValue first,NodeValue second,int size) { //comparision function for string
	return strcmp((*(char**)first),(*(char**)second));
}

static void default_freefn(NodeValue data) { //free function for float,int,double;
	free(data);
}

static void string_free(NodeValue data) {//free function for string
	free(*(char**)data);
}
void Llist_dispose(LinkedList *list) {
	 ListNode *temp = (list->head);
	while(temp != NULL) {
		 ListNode *del_node = temp;
		(temp) = temp->next;
		list->freefn(del_node->data);
		free(del_node);
	}
	list->head = NULL;
	list->count = 0;
	free(list);
}

int Llist_isEmpty(LinkedList *list){
	if(list->count == 0)
		return 1;
	return 0;
}


static void  swap(ListNode *prev,ListNode *after,int size) {
	NodeValue temp = malloc(size);
	if(temp == NULL) {
		exit(EXIT_FAILURE);
	}
	memcpy(temp,prev->data,size);
	memcpy(prev->data,after->data,size);
	memcpy(after->data,temp,size);
}

 int Llist_size(LinkedList *list){
	return list->count;
}

static ListNode* search(LinkedList *list,int size,NodeValue data){
	ListNode **walk = &(list->head);
	if(list->compare((*walk)->data,data,size) == 0)
		return *walk;
	while((*walk)->next != NULL) {
		if(list->compare(((*walk)->next)->data,data,size) == 0)
			return (*walk);
		walk = &((*walk)->next);
	}
	return NULL;
}

LinkedList* Llist_create(int type,int (*compare)(NodeValue first,NodeValue seconde,int size),
								void (*freefn)(NodeValue data)) {
	if(type < 0) {
		return NULL;
	}
	LinkedList *list = malloc(sizeof(LinkedList));
	if(list == NULL) {
		return NULL;
	}
	list->size = type;
	list->count = 0;
	list->head = NULL;
	if(compare == NULL)
		list->compare = default_comp;
	else
		list->compare = compare;
	if (freefn == NULL)
		list->freefn = default_freefn;
	else
		list->freefn = freefn;
}

int Llist_push(LinkedList *list,NodeValue data){
	ListNode *attach = malloc(sizeof(ListNode));
	if(attach == NULL)
		return 0;
	attach->data  = malloc(list->size);
	if(data == NULL)
		return 0;
	memcpy(attach->data,data,list->size);
	attach->next = NULL;
	if((list->head) == NULL){
		(list->head) = attach;
		list->count++;
		return 1;
	}
	else {
		ListNode *walk = list->head;
		while((walk)->next != NULL)
			walk = (walk)->next;
		(walk)->next = attach;
		list->count++;
		return 1;
	}
	return 0;

}
static void  del(LinkedList *list,ListNode **temp){
	if(*temp == list->head){
		ListNode *del_node = *temp;
		list->head = (*temp)->next;
		list->freefn(del_node->data); //Releasing the memory of the elemnt which is in the node
		free(del_node);// releading the node
		list->count--;//decrementing the count
		return ;
	}
	ListNode *del_node = (*temp)->next;
	(*temp)->next = ((*temp)->next)->next;
	list->freefn(del_node->data);
	free(del_node);
	list->count--;

}
int Llist_remove(LinkedList *list,NodeValue data) {
	if(list->count == 0){
		return 0;
	}
	ListNode *temp = search(list,list->size,data);
	if(temp == NULL) {
		return 0;
	}
	del(list,&temp);
	return 1;
}


NodeValue* Llist_pop(LinkedList *list) {
	if(list->count == 0){
		return NULL;
	}
	ListNode *head = list->head;
	NodeValue *data = head->data;
	list->head = (list->head)->next;
	free(head);
	list->count--;
	return data;

}

int Llist_push_front(LinkedList *list,NodeValue data) {
	ListNode *attach = malloc(sizeof(ListNode ));
	if(attach == NULL)
		return 0;
	attach->data = malloc(list->size);
	if(data == NULL)
		return 0;
	memcpy(attach->data,data,list->size);
	attach->next = list->head;
	list->head= attach;
	list->count++;
	return 1;

}

int Llist_insert_after(LinkedList *list,const int loc,NodeValue data) {
	if(list->count < loc) {
		return 0;
	}
	ListNode  *walk = list->head;
	for(int i=0 ; i<loc ;i++)
		walk = (walk->next);
	ListNode *attach = malloc(sizeof(ListNode ));
	if(attach == NULL)
		return 0;
	attach->data = malloc(sizeof(list->size));
	if(data == NULL)
		return 0;
	memcpy(attach->data,data,list->size);
	attach->next = (walk)->next;
	(walk)->next = attach;
	list->count++; //incrementing list count after every addition of linked list
	return 1;
}

void Llist_sort(LinkedList *list) {
	int len = Llist_size(list);
	const int size = list->size;
	for(int i = 0; i<len-1 ;i++) {
	ListNode *trav = list->head;
		for(int j = 0; j < len -1 ; j++) {
			if(list->compare(trav->data,((trav)->next)->data,size) > 0) {
				swap(trav,trav->next,size);
			}
		trav = trav->next;
		}
	}
}
	
void Llist_reverse(LinkedList *list) {
	Stack st;
	StackNew(&st,list->size,NULL);
	ListNode *trav = list->head;
	while(trav != NULL) {
		StackPush(&st,&(trav->data));
		trav = trav->next;
	}
	trav = list->head;
	while(trav != NULL) {
		StackPop(&st,&(trav->data));
		trav = trav->next;
	}
	StackDispose(&st);
}

int Llist_isPresent(LinkedList *list,NodeValue data) {
	if(list->count == 0)
		return 0;
	ListNode *temp = search(list,list->size,data);
	if(temp != NULL)
		return 1;
	else
		return 0;
}

int Llist_replace(LinkedList *list,NodeValue data,NodeValue replace_data) {
	ListNode *temp = search(list,list->size,data);
	if(temp == NULL){
		return 0;
	}
	memcpy((temp->next)->data,replace_data,list->size);
	return 1;
}

void Llist_merge(LinkedList *first,LinkedList *second,LinkedList *third) {
	ListNode *fpt = first->head;
	ListNode *spt = second->head;
	int size = first->size;
	if(first->count > second->count) {
		while(fpt != NULL) {
				Llist_push(third,fpt->data);
				fpt = fpt->next;
		}
		while(spt != NULL) {
			if(Llist_isPresent(third,spt->data)) //if data is present it skip the node 
				spt = spt->next;
			else {
				Llist_push(third,spt->data);//else if push the node
				spt = spt->next;
			}
		}
	}
	else {
		while(spt != NULL) {
				Llist_push(third,spt->data);
				spt = spt->next;
		}
		while(fpt != NULL) {
			if(Llist_isPresent(third,fpt->data))
				fpt = fpt->next;
			else {
				Llist_push(third,fpt->data);
				fpt = fpt->next;
			}
		}
	}

}

void Llist_unique( LinkedList *list) {
	Llist_sort(list);
	ListNode **walk = &(list->head);
	while((*walk)!= NULL) {
		while((*walk)->next != NULL && list->compare((*walk)->data,((*walk)->next)->data,list->size) == 0)
			del(list,&(*walk));
		walk = &((*walk)->next);
	}
	
}

void Llist_concat(LinkedList *first,LinkedList *second) {
	if(first == NULL) 
		first = second;
	else {
		ListNode *walk = first->head;
		while(walk->next != NULL)
			walk = walk->next;
		walk->next = second->head;
	}
	first->count += second->count;
	second->head = NULL;
	second->count  = 0;
	second->freefn = NULL;
	second->compare = NULL;
}

int Llist_isEqual(LinkedList *first,LinkedList *second) {
	if(first->count != second->count)
		return 0;
	unsigned short size = first->size;
	ListNode *fwalk = first->head;
	ListNode *swalk = second->head;
	while(fwalk != NULL ) {
		if(first->compare(fwalk->data,swalk->data,size) == 0) {
			fwalk = fwalk->next;
			swalk = swalk->next;
		}
		else
			return 0;
	}
	return 1;
}

int Llist_copy(LinkedList *original,LinkedList *copy) {
	if(original == NULL) {
		return 0;
	}
	ListNode *walk = original->head;
	while(walk != NULL) {
		Llist_push(copy,walk->data); 
		walk = walk->next;
	}
	return 1;
}
ListNode* Llist_begin(LinkedList *list) {
	return (list->head);
}

