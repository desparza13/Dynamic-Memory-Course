
#include <stdio.h>
#include <string.h>
#include "map.h"

unsigned long long hash(TYPE p);
int compare(TYPE d1,TYPE d2);

int main()
{
	MAP map=map_create(10,hash,compare);
	ITERATOR it;
	int i;
	char key[30];
	char value[30];
	MAPNODE e;

	setbuf(stdout,NULL);

	do {
		printf("Dame la llave, FIN para terminar :");
		scanf("%s",key);
		if(strcmp(key,"FIN")!=0)
		{
			printf("Dame el valor :");
			scanf("%s",value);

			if(map_put(map,string_create(key),string_create(value)))
				printf("Elemento a�adido\n");
			else
				printf("Elemento encontrado en el mapa, el valor fue reemplazado\n");
		}
	} while(strcmp(key,"FIN")!=0);

	do {
		printf("Dame la llave a buscar, FIN para dejar de buscar :");
		scanf("%s",key);
		if(strcmp(key,"FIN")!=0)
		{
			printf("Valor: %s\n",str_ptr(map_get(map,string_create(key))));
		}
	} while(strcmp(key,"FIN")!=0);

	// Mostrar las listas
	for(i=0;i<map->M;i++)
	{
		printf("Lista %d:  ",i);

		it=list_begin(map->list[i]);
		while(list_has_next(it))
		{
			it=list_next(it);
			e=it->data;
			printf("{\"key\": %s,\"value\":\"%s\"}\t",(char *)e->key,(char *)e->value);
		}

		printf("\n");
	}
}

HASH hash(TYPE p)
{
	unsigned long long tot=0;
	unsigned char *s=p;
	int iter=0;

	while(*s && iter<12)
	{
		tot = tot << 5;
		tot = tot + (*s & 0x1F);
		s++;
		iter++;
	}
	return(tot);
}

int compare(TYPE d1,TYPE d2)
{
	char *s1=d1;
	char *s2=d2;
	return(strcmp(s1,s2));
}
