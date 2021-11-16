//Daniela Esparza Espinosa
//Crear una cola a partir de dos pilas

#include <stdio.h>
#include "queue_exp.h"

int main()
{
	QUEUE_EXP q1=queue_exp_create();
	TYPE e;
	for(int i=0;i<10;i++)
	{
		queue_exp_offer(q1,int_create(i));
	}

	while(!queue_exp_isempty(q1))
	{
		e=queue_exp_poll(q1);
		printf("%d\n",int_val(e));
	}
}

