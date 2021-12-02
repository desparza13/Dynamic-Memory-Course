/*
MAP
Daniela Esparza Espinosa
 */
#include "list.h"

#ifndef MAP_H_
#define MAP_H_

struct STRMAPNODE {
	TYPE key;
	TYPE value;
};

typedef struct STRMAPNODE * MAPNODE;

typedef unsigned long long HASH;
typedef HASH (*HASHFUNC)(TYPE);
typedef int (*COMPAREFUNC)(TYPE,TYPE);

struct STRMAP {
	int M;
	LIST *list;
	HASHFUNC hf;
	COMPAREFUNC cf;
};

typedef struct STRMAP * MAP;

MAPNODE mapnode_create(TYPE key,TYPE value);

MAP map_create(int M,HASHFUNC hf,COMPAREFUNC cf);
BOOL map_put(MAP map,TYPE key,TYPE value);
BOOL map_contains(MAP map,TYPE key);
TYPE map_get(MAP map,TYPE key);
void map_destroy(MAP map);

#endif /* MAP_H_ */
