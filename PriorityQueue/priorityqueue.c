/*
Priority Queue
Daniela Esparza Espinosa
 */
#include <stdio.h>
#include <stdlib.h>
#include "priorityqueue.h"


PRIORITYQUEUE priority_queue_create(int capacity,COMPAREFUNC cf)
{
	int i;
	PRIORITYQUEUE tmp = malloc(sizeof(struct PRIORITYQUEUESTR));
	tmp->array = malloc(capacity*sizeof(TYPE));
	for(i=0;i<capacity;i++)
		tmp->array[i]=NULL;
	tmp->size = 0;
	tmp->cf=cf;
	return(tmp);
}

void priority_queue_offer(PRIORITYQUEUE pq,TYPE elem)
{
	int pos=pq->size;
	int par=parent(pos);
	pq->array[pos]=elem;

	while(pos!=0 && pq->cf(pq->array[pos],pq->array[par])<0)
	{
		swap(&pq->array[pos], &pq->array[par]);
		pos=par;
		par=parent(pos);
	}

	pq->size++;
}


TYPE priority_queue_poll(PRIORITYQUEUE pq)
{
	TYPE toreturn=pq->array[0];
	pq->array[0]=pq->array[pq->size-1];
	pq->array[pq->size-1]=NULL;

	heapify(pq->array,0,pq->size,pq->cf);
	pq->size--;
	return(toreturn);
}

void heapify(TYPE *arr,int pos,int size,COMPAREFUNC cf)
{
	int left=left(pos);
	int right=right(pos);
	int below=0;

	if(right<size)
	{
		if(arr[left]!=NULL && arr[right]!=NULL) // Hay dos hijos
		{
			if(cf(arr[left],arr[right])<0)
				below=left;
			else
				below=right;
		}
		else if(arr[left]!=NULL)	// No hay dos hijos, pero si hay izquierdo
			below=left;
		else if(arr[right]!=NULL)	// Solo hay un hijo a la derecha
			below=right;

		// Hasta aqu� below debe contener el hijo m�s peque�o, sea izquierdo
		// o derecho

		if(below!=0 && cf(arr[below],arr[pos])<0)
		{
			swap(&arr[pos],&arr[below]);
			heapify(arr,below,size,cf);
		}
	}
}

void swap(TYPE *n1,TYPE *n2)
{
	TYPE tmp=*n1;
	*n1=*n2;
	*n2=tmp;
}

BOOL priority_queue_is_empty(PRIORITYQUEUE pq)
{
	return (pq->array[0]==NULL);
}

/*
void inorder(int *arr,int pos,int level)
{
	int left=left(pos);
	int right=right(pos);

	if(pos<TAM)
	{
		if(left>0 && arr[left]!=-1)
			inorder(arr,left,level+1);

		printtabs(level);
		printf("%d\n",arr[pos]);

		if(right>0 && arr[right]!=-1)
			inorder(arr,right,level+1);
	}
}

void printtabs(int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("\t");
}

*/
