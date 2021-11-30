/*
Daniela Esparza Espinosa

 */
#include "list.h"

LIST list_create(void (*destructor)(void *))
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

	// Checar si la lista está vacía
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

	else if(pos < iterator->position)							// Hay que avanzar hacia atrás
		while(list_has_prior(iterator) && iterator->position > pos)
			iterator=iterator->prior;

	if(pos == iterator->position) // Está en la posici�n
		retval=iterator->data;

	return(retval);
}

//Modificar valor
void list_set(ITERATOR iterator,TYPE elem,int pos)
{
	if(pos > iterator->position)	// Hay que avanzar hacia adelante
		while(list_has_next(iterator) && iterator->position < pos)
			iterator=iterator->next;

	else if(pos < iterator->position)							// Hay que avanzar hacia atrás
		while(list_has_prior(iterator) && iterator->position > pos)
			iterator=iterator->prior;

	if(pos == iterator->position) // Está en la posici�n
		iterator->data=elem;
}

//Insertar nodo
void list_insertAfter(ITERATOR iterator,int pos, TYPE elem)
{
	if(pos > iterator->position)	// Hay que avanzar hacia adelante
		while(list_has_next(iterator) && iterator->position < pos)
			iterator=iterator->next;

	else if(pos < iterator->position)							// Hay que avanzar hacia atrás
		while(list_has_prior(iterator) && iterator->position > pos)
			iterator=iterator->prior;

	if(pos == iterator->position) // Está en la posici�n
	{
		LISTNODE new = malloc(sizeof(struct STRLISTNODE));
		new->data=elem;
		new->next=iterator->next;
		new->prior=iterator;
		iterator->next->prior=new;
		iterator->next=new;
	}	
}

//Delete node
void list_deleteNode(ITERATOR iterator,int pos)
{
	if(pos > iterator->position)	// Hay que avanzar hacia adelante
		while(list_has_next(iterator) && iterator->position < pos)
			iterator=iterator->next;

	else if(pos < iterator->position)							// Hay que avanzar hacia atrás
		while(list_has_prior(iterator) && iterator->position > pos)
			iterator=iterator->prior;

	if(pos == iterator->position) // Está en la posici�n
	{
		iterator->prior->next=iterator->next;
		iterator->next->prior=iterator->prior;
	}	
}
