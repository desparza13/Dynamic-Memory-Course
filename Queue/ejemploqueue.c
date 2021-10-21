/*
*/
#include <stdio.h>
#include "queue.h"
#include "datatypes.h"

#define N 10

int main()
{
	QUEUE q1=queue_create();
	int i;
	TYPE e;

	queue_offer(q1,string_create("Daniela"));
	queue_offer(q1,string_create("Jennifer"));
	queue_offer(q1,string_create("Ariadna"));

	while(!queue_isempty(q1))
	{
		e=queue_poll(q1);
		printf("%s\n",str_ptr(e));		
	}
	free(q1);
}

