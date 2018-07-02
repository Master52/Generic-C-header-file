/* Generic representation of Array */

typedef struct {
	void *array;
	unsigned short size;
	int alloc_len;
	int logical_len;
	int (*compfn)(void *,void *,int);
	void (*freefn)(void *);
}Array;

void Array_create(Array *,int ,int (*comfn)(void *,void *,int),void (*freefn)(void *));
static void default_freefn (void *);
static int default_compfn(void *,void *,int);
static void Array_grow(Array *arr);
static void swap(void *first,void *second,int size);
void Array_add_at(Array *arr,int index,void *data);
void Array_dispose(Array *arr);
void Array_at(Array *arr,int index,void *data);
int Array_indexOf(Array *arr,void *data);
void Array_add(Array *arr,void *data);
void* Array_begin(Array *arr);
void* Array_end(Array *arr);
int Array_size(Array *arr);
int Array_maxSize(Array *arr);
int Array_isEmpty(Array *arr);
void Array_remove(Array *arr,void *data);
void Array_removeAt(Array *arr,int index);
void Array_front(Array *arr,void *data);
void Array_back(Array *arr,void *data);
void Array_sort(Array *arr);
int Array_isPresent(Array *arr,void *data);
int Array_BisPresent(Array *arr,void *data);
void swap(Array *first,Array *second);

void Array_create(Array *arr,int size,int (*compfn)(void *,void *,int),void (*freefn)(void *)){
	arr->alloc_len = 10;
	arr->logical_len = 0;
	arr->size = size;
	arr->array = malloc(arr->alloc_len * arr->size);
	assert(arr->array != NULL);
	if(compfn == NULL)
		arr->compfn = default_compfn;
	else
		arr->compfn = compfn;
	if(freefn == NULL)
		arr->freefn = default_freefn;
	else
		arr->freefn = freefn;
}

static void default_freefn(void *data){
	free(data);
}

static int default_compfn (void *first,void *second,int size) {
	return memcmp(first,second,size);
}
void Array_add_at(Array *arr,int index,void *data){
	if(arr->logical_len == arr->alloc_len)
		Array_grow(arr);
	void *target = (char*)arr->array + index * arr->size;
	memcpy(target,data,arr->size);
	arr->logical_len++;
}
static void Array_grow(Array *arr){
	arr->alloc_len *= 2;
	arr->array = realloc(arr->array,arr->alloc_len * arr->size);
}

static void swap(void *first,void *second,int size){
	void *temp = malloc(size);
	memcpy(temp,first,size);
	memcpy(first,second,size);
	memcpy(second,temp,size);
	free(temp);
}

void Array_dispose(Array *arr){
	arr->freefn(arr->array);
	arr->logical_len = 0;
}
void Array_at(Array *arr,int index,void *data){
	void *source = (char*)arr->array + index * arr->size;
	memcpy(data,source,arr->size);
}
int Array_indexOf(Array *arr,void *data){
	for(int i = 0,n = arr->logical_len; i < n ; i++) {
		void *source = (char*)arr->array + i * arr->size;
		if(arr->compfn(source,data,arr->size) == 0)
			return i;
	}
	return -1;
}

void Array_add(Array *arr,void *data){
	if(arr->logical_len == arr->alloc_len)
		Array_grow(arr);
	void *target = (char*)arr->array + arr->logical_len * arr->size;
	memcpy(target,data,arr->size);
	arr->logical_len++;
}
void* Array_begin(Array *arr){
	return arr->array;
}

void* Array_end(Array *arr) {
	return ((char*)arr->array + (arr->logical_len ) * arr->size) ;
}
int Array_size(Array *arr){
	return arr->logical_len;
}
int Array_maxSize(Array *arr){
	return arr->alloc_len;
}
int Array_isEmpty(Array *arr){
	if(arr->logical_len > 0)
		return 0;
	return 1;
}
void Array_remove(Array *arr,void *data){
	for ( int i = 0; i < arr->logical_len ; i++) {
		void *target = (char*)arr->array + i * arr->size;
		if(arr->compfn(target,data,arr->size) == 0 ) {
			memmove(target,(char*)target + arr->size,(arr->logical_len - i) * arr->size);
			arr->logical_len--;
			return;
		}
	}
}
void Array_removeAt(Array *arr,int index){
	void *target = (char*)arr->array + index * arr->size;
	memmove(target,(char*)target + arr->size,(arr->logical_len - index) * arr->size);
	arr->logical_len--;

}
void Array_front(Array *arr,void *data){
	void *source = Array_begin(arr);
	memcpy(data,source,arr->size);
}
void Array_back(Array *arr,void *data){
	void *source = (char*)Array_end(arr) - arr->size;;
	memcpy(data,source,arr->size);
}
void Array_sort(Array *arr){
	for(int i = 0; i< arr->logical_len;i++)
		for(int j = 0; j < arr->logical_len -1 ;j++)
			if(arr->compfn(((char*)arr->array + j * arr->size),((char*)arr->array + (j+1) * arr->size),arr->size) > 0)
				swap(((char*)arr->array + j * arr->size),((char*)arr->array + (j+1) * arr->size),arr->size);
}

int Array_BisPresent(Array *arr,void *data) {
	int low = 0;
	int heigh = arr->logical_len;
	int middle = (low + heigh )/2;
	while(low <= heigh) {
		int comp = arr->compfn(((char*)arr->array + middle * arr->size),data,arr->size); 
		if(comp == 0)
			return 1;
		else if(comp > 0)
			heigh = middle -1;
		else
			low = middle + 1;
		middle = (low + heigh)/2;
	}
	return 0;

}
int Array_isPresent(Array *arr,void *data){
	for(int i = 0; i < arr->logical_len - 1; i++)
		if(arr->compfn(((char*)arr->array + i * arr->size),data,arr->size) == 0)
			return 1;
	return 0;
}
