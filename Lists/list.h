/*
 * list.h
 * Daniela Esparza Espiinosa
 */

#include "datatypes.h"

#ifndef LIST_H_
#define LIST_H_

struct STRLISTNODE {
	TYPE data;	// Apuntador a cualquier tipo de elemento.
	int position;
	struct STRLISTNODE *prior,*next;
};

typedef struct STRLISTNODE * LISTNODE;
typedef struct STRLISTNODE * ITERATOR;

struct STRLIST {
	LISTNODE prefirst,first,last,postlast;
	int size;
	void (*destructor)(void *);
};

typedef struct STRLIST * LIST;

LIST list_create(void (*destructor)(void *));
void list_destroy(LIST list);
int list_size(LIST list);
void list_add(LIST list,TYPE elem);
TYPE list_get(ITERATOR iterator,int pos);
void list_set(ITERATOR iterator,TYPE elem,int pos);
TYPE list_remove(LIST list,int pos);
void list_insertAfter(ITERATOR iterator,int pos, TYPE elem);
void list_deleteNode(ITERATOR iterator,int pos);

#define list_begin(l) (l->prefirst)
#define list_end(l) (l->postlast)
#define list_has_next(l) (l->next!=NULL)
#define list_has_prior(l) (l->prior!=NULL)


#endif /* LIST_H_ */
