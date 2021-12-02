/*
Daniela Esparza 
listita
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
	void (*destructor)(struct STRLIST *);
};

typedef struct STRLIST * LIST;

LIST list_create(void (*destructor)(struct STRLIST *));
void list_destroy(LIST list);
int list_size(LIST list);
void list_add(LIST list,TYPE elem);
TYPE list_get(ITERATOR iterator,int pos);
void list_set(LIST list,TYPE elem,int pos);
TYPE list_remove(LIST list,int pos);
BOOL list_isempty(LIST list);
TYPE list_remove_element(LIST list);

#define list_begin(l) (l->prefirst)
#define list_end(l) (l->postlast)
#define list_has_next(l) (l->next!=NULL)
#define list_has_prior(l) (l->prior!=NULL)
#define list_next(i) (i->next)
#define list_prior(i) (i->prior)


#endif /* LIST_H_ */
