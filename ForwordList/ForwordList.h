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
	int (*compare)(void *,void *,int ); 	/*This function wil point to comparision funtion if
	not specified in Llist_create it will point to defaul_cmp funtion for string you have to
	make it point to strim_cmp func*/
	void (*freefn)(void *); /*This function will point to the function where it is writtern
	how dat should be freed by default it will default_cmp for datatype like float,int,double
	if you are storing strings you have to point it to string_free when witing funtion Llist_create*/
	struct node* iterator;
}LinkedList;


static int default_comp(void  *first,void *second,int size) { //comparision function for float,int,double
	return memcmp(first,second,size);

}

static int string_cmp(void *first,void *second,int size) { //comparision function for string
	return strcmp((*(char**)first),(*(char**)second));
}

static void default_freefn(void *data) { //free function for float,int,double;
	free(data);
}

static void string_free(void *data) {//free function for string
	free(*(char**)data);
}
//Funtion for free the linkedlist memeory
//Should be called after the operation on linked is finished or end of the program
void Llist_dispose(LinkedList *list) {
	struct node *temp = (list->head);
	while(temp != NULL) {
		struct node *del_node = temp;
		(temp) = temp->next;
		list->freefn(del_node->data);
		free(del_node);
	}
	list->head = NULL;
	list->count = 0;
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
//if matched is head it will return the head node
//else it will return the 1 previous node form the matched node
//if not match found it will return NULL
static struct node* search(LinkedList *list,int size,void *data){
	struct node **walk = &(list->head);
	if(list->compare((*walk)->data,data,size) == 0)
		return *walk;
	while((*walk)->next != NULL) {
		if(list->compare(((*walk)->next)->data,data,size) == 0)
			return (*walk);
		walk = &((*walk)->next);
	}
	return NULL;
}
//Creating a linked list
/*
 * Takes 4 argument
 * 1st argument is the pointer to the linked list
 * 2nd argument is the size of data type
 * 3rd argument is pointer to comparision func put NULL for default_cmp
 * 4rd argument is pointer to free func put NULL for defaut_free*/
void Llist_create(LinkedList *list,int type,int (*compare)(void *first,void *seconde,int size),
								void (*freefn)(void *data)) {
	assert(type > 0);
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
{ "_id" : { "$oid" : "52b213b38594d8a2be17c780" }, "approvalfy" : 1999, "board_approval_month" : "November", "boardapprovaldate" : "2013-11-12T00:00:00Z", "borrower" : "FEDERAL DEMOCRATIC REPUBLIC OF ETHIOPIA", "closingdate" : "2018-07-07T00:00:00Z", "country_namecode" : "Federal Democratic Republic of Ethiopia!$!ET", "countrycode" : "ET", "countryname" : "Federal Democratic Republic of Ethiopia", "countryshortname" : "Ethiopia", "docty" : "Project Information Document,Indigenous Peoples Plan,Project Information Document", "envassesmentcategorycode" : "C", "grantamt" : 0, "ibrdcommamt" : 0, "id" : "P129828", "idacommamt" : 130000000, "impagency" : "MINISTRY OF EDUCATION", "lendinginstr" : "Investment Project Financing", "lendinginstrtype" : "IN", "lendprojectcost" : 550000000, "majorsector_percent" : [ { "Name" : "Education", "Percent" : 46 }, { "Name" : "Education", "Percent" : 26 }, { "Name" : "Public Administration, Law, and Justice", "Percent" : 16 }, { "Name" : "Education", "Percent" : 12 } ], "mjsector_namecode" : [ { "name" : "Education", "code" : "EX" }, { "name" : "Education", "code" : "EX" }, { "name" : "Public Administration, Law, and Justice", "code" : "BX" }, { "name" : "Education", "code" : "EX" } ], "mjtheme" : [ "Human development" ], "mjtheme_namecode" : [ { "name" : "Human development", "code" : "8" }, { "name" : "", "code" : "11" } ], "mjthemecode" : "8,11", "prodline" : "PE", "prodlinetext" : "IBRD/IDA", "productlinetype" : "L", "project_abstract" : { "cdata" : "The development objective of the Second Phase of General Education Quality Improvement Project for Ethiopia is to improve learning conditions in primary and secondary schools and strengthen institutions at different levels of educational administration. The project has six components. The first component is curriculum, textbooks, assessment, examinations, and inspection. This component will support improvement of learning conditions in grades KG-12 by providing increased access to teaching and learning materials and through improvements to the curriculum by assessing the strengths and weaknesses of the current curriculum. This component has following four sub-components: (i) curriculum reform and implementation; (ii) teaching and learning materials; (iii) assessment and examinations; and (iv) inspection. The second component is teacher development program (TDP). This component will support improvements in learning conditions in both primary and secondary schools by advancing the quality of teaching in general education through: (a) enhancing the training of pre-service teachers in teacher education institutions; and (b) improving the quality of in-service teacher training. This component has following three sub-components: (i) pre-service teacher training; (ii) in-service teacher training; and (iii) licensing and relicensing of teachers and school leaders. The third component is school improvement plan. This component will support the strengthening of school planning in order to improve learning outcomes, and to partly fund the school improvement plans through school grants. It has following two sub-components: (i) school improvement plan; and (ii) school grants. The fourth component is management and capacity building, including education management information systems (EMIS). This component will support management and capacity building aspect of the project. This component has following three sub-components: (i) capacity building for education planning and management; (ii) capacity building for school planning and management; and (iii) EMIS. The fifth component is improving the quality of learning and teaching in secondary schools and universities through the use of information and communications technology (ICT). It has following five sub-components: (i) national policy and institution for ICT in general education; (ii) national ICT infrastructure improvement plan for general education; (iii) develop an integrated monitoring, evaluation, and learning system specifically for the ICT component; (iv) teacher professional development in the use of ICT; and (v) provision of limited number of e-Braille display readers with the possibility to scale up to all secondary education schools based on the successful implementation and usage of the readers. The sixth component is program coordination, monitoring and evaluation, and communication. It will support institutional strengthening by developing capacities in all aspects of program coordination, monitoring and evaluation; a new sub-component on communications will support information sharing for better management and accountability. It has following three sub-components: (i) program coordination; (ii) monitoring and evaluation (M and E); and (iii) communication." }, "project_name" : "Ethiopia General Education Quality Improvement Project II", "projectdocs" : [ { "DocTypeDesc" : "Project Information Document (PID),  Vol.", "DocType" : "PID", "EntityID" : "090224b081e545fb_1_0", "DocURL" : "http://www-wds.worldbank.org/servlet/WDSServlet?pcont=details&eid=090224b081e545fb_1_0", "DocDate" : "28-AUG-2013" }, { "DocTypeDesc" : "Indigenous Peoples Plan (IP),  Vol.1 of 1", "DocType" : "IP", "EntityID" : "000442464_20130920111729", "DocURL" : "http://www-wds.worldbank.org/servlet/WDSServlet?pcont=details&eid=000442464_20130920111729", "DocDate" : "01-JUL-2013" }, { "DocTypeDesc" : "Project Information Document (PID),  Vol.", "DocType" : "PID", "EntityID" : "090224b0817b19e2_1_0", "DocURL" : "http://www-wds.worldbank.org/servlet/WDSServlet?pcont=details&eid=090224b0817b19e2_1_0", "DocDate" : "22-NOV-2012" } ], "projectfinancialtype" : "IDA", "projectstatusdisplay" : "Active", "regionname" : "Africa", "sector" : [ { "Name" : "Primary education" }, { "Name" : "Secondary education" }, { "Name" : "Public administration- Other social services" }, { "Name" : "Tertiary education" } ], "sector1" : { "Name" : "Primary education", "Percent" : 46 }, "sector2" : { "Name" : "Secondary education", "Percent" : 26 }, "sector3" : { "Name" : "Public administration- Other social services", "Percent" : 16 }, "sector4" : { "Name" : "Tertiary education", "Percent" : 12 }, "sector_namecode" : [ { "name" : "Primary education", "code" : "EP" }, { "name" : "Secondary education", "code" : "ES" }, { "name" : "Public administration- Other social services", "code" : "BS" }, { "name" : "Tertiary education", "code" : "ET" } ], "sectorcode" : "ET,BS,ES,EP", "source" : "IBRD", "status" : "Active", "supplementprojectflg" : "N", "theme1" : { "Name" : "Education for all", "Percent" : 100 }, "theme_namecode" : [ { "name" : "Education for all", "code" : "65" } ], "themecode" : "65", "totalamt" : 130000000, "totalcommamt" : 130000000, "url" : "http://www.worldbank.org/projects/P129828/ethiopia-general-education-quality-improvement-project-ii?lang=en" }
	list->iterator = list->head;
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
		list->freefn(del_node->data); //Releasing the memory of the elemnt which is in the node
		free(del_node);// releading the node
		list->count--;//decrementing the count
		return ;
	}
	struct node *del_node = (*temp)->next;
	(*temp)->next = ((*temp)->next)->next;
	list->freefn(del_node->data);
	free(del_node);
	list->count--;

}
void Llist_del(LinkedList *list,void *data) {
	if(list->count == 0){
		printf("List is empty\n");
		return;
	}
	struct node *temp = search(list,list->size,data);
	if(temp == NULL) {
		printf("Element not found\n");
		return;
	}
	del(list,&temp);
}

//List_pop will give you the front element form the linked list and 
//delete it from the linked list
//Note:In case of string or other free function other tha defaul_free
//it will just remove the elemet from the list and will give 
//you back the ownership of the data it will not free the data
//it is upto the programmer to free it
void Llist_pop(LinkedList *list,void *data) {
	if(list->count == 0){
		printf("\nList is empty\n");
		return;
	}
	memcpy(data,(list->head)->data,list->size);
	if(list->freefn == default_freefn)
		del(list,&(list->head));
	else {
		struct node *del_node = list->head;
		list->head = (list->head)->next;
		free(del_node);
		list->count--;
	}

}
//Pushes the elements to front of the linked list
void Llist_push_front(LinkedList *list,void *data) {
	struct node *attach = malloc(sizeof(struct node));
	assert(attach != NULL);
	attach->data = malloc(list->size);
	memcpy(attach->data,data,list->size);
	attach->next = list->head;
	list->head= attach;
	list->count++;

}

//insert the data at specified location
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
			if(list->compare(trav->data,((trav)->next)->data,size) > 0) {
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
	if(list->count == 0)
		return 0;
	struct node *temp = search(list,list->size,data);
	if(temp != NULL)
		return 1;
	else
		return 0;
}
/*Returns a pointer to a node containing the specified data if not present in
the linked list it returns NULL*/
void Llist_replace(LinkedList *list,void *data,void *replace_data) {
	struct node *temp = search(list,list->size,data);
	if(temp == NULL){
		printf("Element not found\n");
		return;
	}
	memcpy((temp->next)->data,replace_data,list->size);
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
		while((*walk)->next != NULL && list->compare((*walk)->data,((*walk)->next)->data,list->size) == 0)
			del(list,&(*walk));
		walk = &((*walk)->next);
	}
	
}

//returns the pointer to the head of the node so to iterate over the list
void* Llist_front(LinkedList *list) {
	return((list->head)->data);
}

//concat the two linked list
void Llist_concat(LinkedList *first,LinkedList *second) {
	if(first == NULL) 
		first = second;
	else {
		struct node *walk = first->head;
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

//Check wether the Linked list is equal or not
//if equal it return 1(true) or
//0(false)
int Llist_isEqual(LinkedList *first,LinkedList *second) {
	if(first->count != second->count)
		return 0;
	unsigned short size = first->size;
	struct node *fwalk = first->head;
	struct node *swalk = second->head;
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

//Copies the the data of first argument to second argument
void Llist_copy(LinkedList *original,LinkedList *copy) {
	if(original == NULL) {
		printf("Linked list is empty");
		printf("\n");
		return;
	}
	struct node *walk = original->head;
	while(walk != NULL) {
		Llist_push(copy,walk->data); 
		walk = walk->next;
	}
}

int hasNext(LinkedList *list,void *data) {
	if(list->iterator != NULL) {
		memcpy(data,(list->iterator)->data,list->size);
		list->iterator = ((list->iterator)->next);
		return 1;
	}
	else {
		list->iterator = list->head;
		return 0;
	}
}
