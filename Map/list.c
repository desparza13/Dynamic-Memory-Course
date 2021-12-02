/*
Daniela Esparza
listita
 */
#include "list.h"

LIST list_create(void (*destructor)(struct STRLIST *))
{
	LIST tmp=malloc(sizeof(struct STRLIST));
	tmp->first=NULL;
	tmp->last=NULL;
	tmp->size=0;
	tmp->prefirst=malloc(sizeof(struct STRLISTNODE));
	tmp->prefirst->position=-1;
	tmp->postlast=malloc(sizeof(struct STRLISTNODE));
	tmp->postlast->position=0xFFFFFFF;
	tmp->prefirst->prior=NULL;
	tmp->prefirst->data=NULL;
	tmp->postlast->next=NULL;
	tmp->postlast->data=NULL;

	tmp->destructor=destructor;
	return(tmp);
}

void list_destroy(LIST list)
{
	list->destructor(list);
	free(list);
}

int list_size(LIST list)
{
	return(list->size);
}

void list_add(LIST list,TYPE elem)
{
	LISTNODE new = malloc(sizeof(struct STRLISTNODE));
	new->data=elem;
	new->next=NULL;
	new->prior=NULL;

	// Checar si la lista est� vac�a
	if(list->first==NULL)
	{
		list->first=new;
		list->prefirst->next=list->first;
		new->position=0;
	}
	else
	{
		list->last->next = new;
		new->prior = list->last;
		new->position = new->prior->position + 1 ;
	}
	list->size++;
	list->last = new;
	list->postlast->prior = list->last;
}

TYPE list_get(ITERATOR iterator,int pos)
{
	TYPE retval=NULL;

	if(pos > iterator->position)	// Hay que avanzar hacia adelante
		while(list_has_next(iterator) && iterator->position < pos)
			iterator=iterator->next;

	else if(pos < iterator->position)							// Hay que avanzar hacia atr�s
		while(list_has_prior(iterator) && iterator->position > pos)
			iterator=iterator->prior;

	if(pos == iterator->position) // Est� en la posici�n
		retval=iterator->data;

	return(iterator->data);
}

BOOL list_isempty(LIST list)
{
	return(list->first==NULL);
}

TYPE list_remove_element(LIST list)
{
	LISTNODE toremove = list->first;
	TYPE data = toremove->data;
	list->prefirst = list->first->next;
	list->first->next->prior=NULL;
	free(toremove);
	return(data);
}
