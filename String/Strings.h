//-------------------------------------------------------------------------------------------------------------------------------------------------
/* gt_string() function gets the string for user and it returns the base address of input sting
 * remeber to free the pointer when job is over
 */
static char* trim(char* phrase);
char charAt( char *str,int index);
char* get_string(void) {
	const size_t sizeIncrementer = 2; //alocating memory in heap
	char * buffer = (char*)malloc(sizeIncrementer); //creating a buffer for holding string
	char* current_poineter = buffer; //points to the last charater enterd
	size_t maximum_length = sizeIncrementer; //length of the string 
	size_t length = 0; //For checking the total length 
	int character;

	if(current_poineter == NULL)
		return NULL;

	while(1) {
		character = fgetc(stdin);
		if (character == '\n')
			break;
		if (++length >= maximum_length) {
			//if length is greater then max heap,realloc the size of heap
			char* newbuffer = realloc(buffer,maximum_length += sizeIncrementer);
			if (newbuffer == NULL) {
				free(buffer);
				return NULL;
			}
		current_poineter = newbuffer + (current_poineter - buffer);
		buffer = newbuffer;
		}
		*current_poineter++ = character;
	}
	return buffer = trim(buffer);
}

//trim() function trims the whitspace if provides at the begaining of the input
static char* trim(char *phrase) {
	char* new = phrase;
	char* old = phrase;
	while(*old == ' ' || *old == '\t')
		old++;

	while(*old)
		*(new++) = *(old++);
	*new = '\0';
	return (char*)realloc(phrase,strlen(phrase));
}


//-----------------------------------------------------------------------------------------------------------------------------------
/*ispresent() function for findind a subtring for a given string takes to argument
 * @s parameter is the string from which a substring is found
 * @word paramenter is the subtring to be found 
 * The way this work is it created a new string from the given string whose length is equal to @word to be searched
 * and check whether they are equal or not.
 * if not increment @s till the end of string
 */


//copy() func copies the string from the the @s whose length is equal to @word
static char* copy(const char *string,const int len) {
	char *wo = (char*)malloc(sizeof(char) + len); //creating a new string of length @word
	char *p = wo;
	for (int i = 0;i<len;i++) {
		*p = *string;
		string++;
		p++;
	}
	*p = '\0';
	return wo; //passing the address of base address of newly created string
}
static int ispresent(const char *s, const char *word) {
	int length = strlen(word);
	while(*s) {
		char *wo = copy(s,length);
		if(strcmp(wo,word) == 0){
			free(wo);//if found free the memory hold by wo and return 0
			return 0;
		}
		s++;
		free(wo);//free the memory if not found to the heap
	}
	return -1;
}
//--------------------------------------------------------------------------------------------------------------------------------------

void sort(char *arr[],const int length) {
	for (int i = 1;i<length;i++){
		char *buf = arr[i];
		int j = i;
		while(j > 0 && strcmp(arr[j-1],arr[j]) > 0) {
				char *temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;
		}
		arr[j] = buf;
	}
}

void rsort(char *arr[],const int length) {
	for (int i = 1;i<length;i++){
		char *buf = arr[i];
		int j = i;
		while(j > 0 && strcmp(arr[j-1],arr[j]) < 0) {
				char *temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				j--;
		}
		arr[j] = buf;
	}
}
char charAt( char *str,int index){
	return (*((char*)(str + index *sizeof(char))));
}

void strToLower(char *s) {
	for(int i = 0,n = strlen(s); i < n; ++i) {
		s[i] = tolower(s[i]);
	}
}

void strToUpper(char *s) {
	for(int i = 0,n = strlen(s); i < n; ++i) {
		s[i] = toupper(s[i]);
	}
}

int strcmpIgnoreCase(char *str1, char *str2) {
	strToLower(str1);
	strToLower(str2);
	return strcmp(str1,str2);
}

int startsWith(const char *str,const char *prefix,int offset) {
	for(int i = 0,n = strlen(prefix);i<n-1;++i) {
		if(str[offset] != prefix[i])
			return 0;
		offset++;
	}
	return 1;
}
int endsWith(const char *str,const char *prefix) {
	int len = strlen(prefix);
	int offset = strlen(str) - len;
	for(int i = 0;i<len;++i) {
		if(str[offset] != prefix[i])
			return 0;
		offset++;
	}
	return 1;

}

int indexOf(const char *str,char c,int offset) {
	int i = offset;
	while(str[i] != '\0') {
		if(str[i] == c)
			return i;
		i++;
	}
	return -1;
}

int lastindexOf(const char *str,char c,int offset) {
	int i = offset;
	while(str[i] != '\0' && i >= 0) {
		if(str[i] == c)
			return i;
		i--;
	}
	return -1;
}

int lastindexOfstr(const char *haystack,const char *needle) {
	int i = 0;
	int d = 0;
	int h_len = strlen(haystack);
	int n_len = strlen(needle);
	if(h_len >= n_len) {
		for(i = h_len - n_len;i>=0;i--) {
			int found = 1;
			for(d = 0;d<n_len;d++) {
				if(haystack[i+d] != needle[d]) {
					found = 0;
					break;
				}
			}
			if(found == 1) {
				return i;
			}
		}
		return -1;
	}
	printf("Haystack is smaller\n"); 
}
int indexOfstr(const char *haystack,const char *needle) {
	int i = 0;
	int d = 0;
	int h_len = strlen(haystack);
	int n_len = strlen(needle);
	if(h_len >= n_len) {
		for(i = 0;i<=h_len-n_len;i++) {
			int found = 1;
			for(d = 0;d<n_len;d++) {
				if(haystack[i+d] != needle[d]) {
					found = 0;
					break;
				}
			}
			if(found == 1) {
				return i;
			}
		}
		return -1;
	}
	printf("Haystack is smaller\n"); 
}


char* substr(const char *str,int begin,int end) {
	int len = 8;
	char *sub_string = malloc(len);
	int i = 0;
	while(begin <= end) {
		if(i > len) {
			len *= 2;;
			sub_string = realloc(sub_string,len);
		}
		sub_string[i] = str[begin];
		++i;
		++begin;
	}
	sub_string[begin] = '\0';
	return sub_string;
}

char* str_replace(char *str, char *orig, char *rep, int start)
{
  static char temp[4096];
  static char buffer[4096];
  char *p;

  strcpy(temp, str + start);

  if(!(p = strstr(temp, orig)))  // Is 'orig' even in 'temp'?
    return temp;

  strncpy(buffer, temp, p-temp); // Copy characters from 'temp' start to 'orig' str
  buffer[p-temp] = '\0';

  sprintf(buffer + (p - temp), "%s%s", rep, p + strlen(orig));
  sprintf(str + start, "%s", buffer);    

  return str;
}

void str_replaceAll(char *target, const char *needle, const char *replacement)
{
    char buffer[1024] = { 0 };
    char *insert_point = &buffer[0];
    const char *tmp = target;
    size_t needle_len = strlen(needle);
    size_t repl_len = strlen(replacement);

    while (1) {
        const char *p = strstr(tmp, needle);

        // walked past last occurrence of needle; copy remaining part
        if (p == NULL) {
            strcpy(insert_point, tmp);
            break;
        }

        // copy part before needle
        memcpy(insert_point, tmp, p - tmp);
        insert_point += p - tmp;

        // copy replacement string
        memcpy(insert_point, replacement, repl_len);
        insert_point += repl_len;

        // adjust pointers, move on
        tmp = p + needle_len;
    }

    // write altered string back to target
    strcpy(target, buffer);
}
