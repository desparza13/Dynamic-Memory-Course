/*
MAP
Daniela Esparza Espinosa
 */
#include <stdio.h>
#include "datatypes.h"
#include "map.h"

MAPNODE mapnode_create(TYPE key,TYPE value)
{
	MAPNODE tmp=malloc(sizeof(struct STRMAPNODE));
	tmp->key=key;
	tmp->value=value;
	return(tmp);
}

MAP map_create(int M,HASHFUNC hf,COMPAREFUNC cf)
{
	MAP tmp = malloc(sizeof(struct STRMAP));
	int i;
	tmp->M = M;
	tmp->list = malloc(M*sizeof(LIST));
	for(i=0;i<M;i++)
	{
		tmp->list[i]=list_create(NULL);
	}
	tmp->hf = hf;
	tmp->cf = cf;
	return(tmp);
}

BOOL map_put(MAP map,TYPE key,TYPE value)
{
	HASH hashcode = map->hf(key);
	int pos = (unsigned int) hashcode % map->M;
	BOOL found = 0;
	ITERATOR iterator;
	MAPNODE data;

	// Buscar el elemento key en la lista
	iterator=list_begin(map->list[pos]);
	while(list_has_next(iterator) && !found)
	{
		iterator=list_next(iterator);
		data=iterator->data;
		found = map->cf(data->key,key)==0;
		if(found)
			data->value = value;
	}


	if(!found)
		list_add(map->list[pos],mapnode_create(key,value));

	return(!found);
}

BOOL map_contains(MAP map,TYPE key)
{
	HASH hashcode = map->hf(key);
	int pos = (unsigned int) hashcode % map->M;
	BOOL found = 0;
	ITERATOR iterator;
	MAPNODE data;

	// Buscar el elemento key en la lista
	iterator=list_begin(map->list[pos]);
	while(list_has_next(iterator) && !found)
	{
		iterator=list_next(iterator);
		data=iterator->data;
		found = map->cf(data->key,key)==0;
	}

	return(found);
}

TYPE map_get(MAP map,TYPE key)
{
	HASH hashcode = map->hf(key);
	int pos = (unsigned int) hashcode % map->M;
	BOOL found = 0;
	ITERATOR iterator;
	MAPNODE data;

	// Buscar el elemento key en la lista
	iterator=list_begin(map->list[pos]);
	while(list_has_next(iterator) && !found)
	{
		iterator=list_next(iterator);
		data=iterator->data;
		if (map->cf(data->key,key)==0)
			return data->value;
	}
	return NULL;
}

void map_destroy(MAP map)
{
	for(int i=0;i<map->M;i++)
	{
		ITERATOR it=list_begin(map->list[i]);
		while(list_has_next(it))
		{
			it=list_next(it);
			MAPNODE e=it->data;
			free(map->list[i]);
		}
		printf("\n");
	}
	free(map);	
}