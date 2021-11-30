/*
Priority Queue
Daniela Esparza Espinosa
 */
#include "datatypes.h"

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

typedef int (*COMPAREFUNC)(TYPE,TYPE);

struct PRIORITYQUEUESTR {
	TYPE *array;
	int size;
	COMPAREFUNC cf;
};

typedef struct PRIORITYQUEUESTR * PRIORITYQUEUE;


PRIORITYQUEUE priority_queue_create(int capacity,COMPAREFUNC cf);
void priority_queue_offer(PRIORITYQUEUE pq,TYPE elem);
TYPE priority_queue_poll(PRIORITYQUEUE pq);
BOOL priority_queue_is_empty(PRIORITYQUEUE pq);

void inorder(int *arr,int pos,int level);
void swap(TYPE *n1,TYPE *n2);
void printtabs(int n);
void heapify(TYPE *arr,int pos,int size,COMPAREFUNC cf);

#define parent(n) 	((n-1)/2)
#define left(n)		(n*2 + 1)
#define right(n)	(n*2 + 2)


#endif /* PRIORITYQUEUE_H_ */
