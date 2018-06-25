/* A Generic representation of Linked List */
 struct node {
	void *data;
	struct node *next;
};
//Construct for the linked list
typedef struct{
	unsigned short size; //dataype size
	int count;//counting the element in the list
	struct node *head;//head of the linked list
}LinkedList;


static int compare(void  *first,void *second,int size) {
	return memcmp(first,second,size);

}

void Llist_dispose(LinkedList *list) {
	struct node *temp = (list->head);
	while(temp != NULL) {
		struct node *del_node = temp;
		(temp) = temp->next;
		free(del_node->data);
		free(del_node);
	}
	list->head = NULL;
}

int Llist_isEmpty(LinkedList *list){
	if(list->count == 0)
		return 1;
	return 0;
}


//A Generic swap function
void static swap(struct node *prev,struct node *after,int size) {
	void *temp = malloc(size);
	assert(temp != NULL);
	memcpy(temp,prev->data,size);
	memcpy(prev->data,after->data,size);
	memcpy(after->data,temp,size);
}

 int Llist_length(LinkedList *list){
	return list->count;
}

//search the data in the list using memcmp function it compare each byte of the two data
//if match it return the node which contains the particular data
static struct node* search(struct node **walk,int size,void *data){
	if(memcmp((*walk)->data,data,size) == 0)
		return *walk;
	while((*walk)->next != NULL) {
		if(memcmp(((*walk)->next)->data,data,size) == 0)
			return (*walk);
		walk = &((*walk)->next);
	}
	return NULL;
}
//Creating a linked list
void Llist_create(LinkedList *list,int type) {
	assert(type > 0);
	list->size = type;
	list->count = 0;
	list->head = NULL;
}
//add the elment to the specified linked list
void Llist_push(LinkedList *list,void *data){
	struct node *attach = malloc(sizeof(struct node));
	attach->data  = malloc(list->size);
	memcpy(attach->data,data,list->size);
	attach->next = NULL;
	if((list->head) == NULL){
		(list->head) = attach;
		list->count++;
		return;
	}
	struct node *walk = list->head;
	while((walk)->next != NULL)
		walk = (walk)->next;
	(walk)->next = attach;
	list->count++;
	return;

}
void static del(LinkedList *list,struct node **temp){
	if(*temp == list->head){
		struct node *del_node = *temp;
		list->head = (*temp)->next;
		free(del_node->data); //Releasing the memory of the elemnt which is in the node
		free(del_node);// releading the node
		list->count--;//decrementing the count
		return ;
	}
	struct node *del_node = (*temp)->next;
	(*temp)->next = ((*temp)->next)->next;
	free(del_node->data);
	free(del_node);
	list->count--;

}
void Llist_del(LinkedList *list,void *data) {
	if(list->count == 0){
		printf("List is empty\n");
		return;
	}
	struct node *temp = search(&(list->head),list->size,data);
	if(temp == NULL) {
		printf("Element not found\n");
		return;
	}
	del(list,&temp);
}

void Llist_pop(LinkedList *list,void *data) {
	if(list->count == 0){
		printf("\nList is empty\n");
		return;

	}
	memcpy(data,(list->head)->data,list->size);
	del(list,&(list->head));

}

void* Llist_head(LinkedList *list) {
	return list->head;
}

void Llist_push_front(LinkedList *list,void *data) {
	struct node *attach = malloc(sizeof(struct node));
	assert(attach != NULL);
	attach->data = malloc(list->size);
	memcpy(attach->data,data,list->size);
	attach->next = list->head;
	list->head= attach;
	list->count++;

}

void Llist_insert_after(LinkedList *list,const int loc,void *data) {
	//return if the element count of the linked list is smaller then the specified location
	if(list->count < loc) {
		printf("List element are less than the specifed location");
		return;
	}
	struct node* walk = list->head;
	for(int i=0 ; i<loc ;i++)
		walk = (walk->next);
	struct node *attach = malloc(sizeof(struct node));
	assert(attach != NULL);
	attach->data = malloc(sizeof(list->size));
	memcpy(attach->data,data,list->size);
	attach->next = (walk)->next;
	(walk)->next = attach;
	list->count++; //incrementing list count after every addition of linked list
}

//Sorts the linked list in ascending order
void Llist_sort(LinkedList *list) {
	int len = Llist_length(list);
	const int size = list->size;
	for(int i = 0; i<len-1 ;i++) {
	struct node *trav = list->head;
		for(int j = 0; j < len -1 ; j++) {
			if(compare(trav->data,((trav)->next)->data,size) > 0) {
				swap(trav,trav->next,size);
			}
		trav = trav->next;
		}
	}
}
	
//Reverse the content of stirng using stack.h header
void Llist_reverse(LinkedList *list) {
	Stack st;
	StackNew(&st,list->size,NULL);
	struct node *trav = list->head;
	while(trav != NULL) {
		StackPush(&st,&(trav->data));
		trav = trav->next;
	}
	trav = list->head;
	while(trav != NULL) {
		StackPop(&st,&(trav->data));
		trav = trav->next;
	}
}

/*Return 1(i.e ture) if data is present or 0(false) is not*/
int Llist_isPresent(LinkedList *list,void *data) {
	struct node *temp = search(&(list->head),list->size,data);
	if(temp != NULL)
		return 1;
	else
		return 0;
}
/*Returns a pointer to a node containing the specified data if not present in
the linked list it returns NULL*/
void* Llist_find(LinkedList *list,void *data) {
	struct node *temp = search(&(list->head),list->size,data);
	if(temp == NULL){
		printf("Element not present\n");
		return NULL;
	}
	return temp->data;
}

/*Merges the first two list into the third one
 * the data in the third list are such that there are no duplicate data
 * form both list */
void Llist_merge(LinkedList *first,LinkedList *second,LinkedList *third) {
	struct node *fpt = first->head;
	struct node *spt = second->head;
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

/*This method sort the elemet of the list and removes all duplicated elements from the list */
void Llist_unique( LinkedList *list) {
	Llist_sort(list);
	struct node **walk = &(list->head);
	while((*walk)!= NULL) {
		while((*walk)->next != NULL && compare((*walk)->data,((*walk)->next)->data,list->size) == 0)
			del(list,&(*walk));
		walk = &((*walk)->next);
	}
	
}

//returns the pointer to the head of the node so to iterate over the list
void* Llist_front(LinkedList *list) {
	return((list->head)->data);
}
