/* author: Christian Bender
    This is the implementation unit of the hash-functions.

    Overview about hash-functions:

    - sdbm
    - djb2
    - xor8 (8 bits)
    - adler_32 (32 bits)
*/

#include "Hash.h"

static long long sdbm(char s[])
{
    long long hash = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        hash = s[i] + (hash << 6) + (hash << 16) - hash;
        i++;
    }
    return hash;
}

static unsigned  long djb2(char s[])
{
    long long hash = 5381; /* init value */
    int i = 0;
    while (s[i] != '\0')
    {
        hash = ((hash << 5) + hash) + s[i];
        i++;
    }
    return hash;
}

static char xor8(char s[])
{
    int hash = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        hash = (hash + s[i]) & 0xff;
        i++;
    }
    return (((hash ^ 0xff) + 1) & 0xff);
}

static int adler_32(char s[])
{
    int a = 1;
    int b = 0;
    const int MODADLER = 65521;

    int i = 0;
    while (s[i] != '\0')
    {
        a = (a + s[i]) % MODADLER;
        b = (b + a) % MODADLER;
        i++;
    }
    return (b << 16) | a;
}

static const unsigned int hash_table_primes[] = {
	193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317,
	196613, 393241, 786433, 1572869, 3145739, 6291469,
	12582917, 25165843, 50331653, 100663319, 201326611,
	402653189, 805306457, 1610612741,
};

static void default_freefn(HashValue data) {
	free(data);
}

HashMap* Hash_create(size_t size,void (*freefn)(HashValue ),unsigned long (*hashFun)(char*)) {
	HashMap *map = malloc(sizeof(HashMap));
	if(map == NULL)
		return NULL;
	map->size = size;
	if((map->freefn = freefn) == NULL)
		map->freefn = default_freefn;
	if((map->hashFun = hashFun) == NULL)
		map->hashFun = djb2;
	map->primeIndex = 0;
	map->table = calloc(hash_table_primes[map->primeIndex],map->size);
	if(map->table == NULL)
		return NULL;
	return map;

}



