//Daniela Esparza
//Queue experimental hecha a partir de dos stacks
#include "queue_exp.h"

QUEUE_EXP queue_exp_create()
{
	QUEUE_EXP queue_exp = malloc(sizeof(struct QUEUE_EXPSTR));
	queue_exp->in = stack_create();
	queue_exp->out = stack_create();
	queue_exp->size = 0;

	return(queue_exp);
}

void queue_exp_offer(QUEUE_EXP queue_exp,TYPE data)
{
	TYPE elem;
	while(!stack_isempty(queue_exp->out))
	{
		elem=stack_pop(queue_exp->out);
		stack_push(queue_exp->in,elem);
	}
	stack_push(queue_exp->in,data);
	queue_exp->size++;
}

TYPE queue_exp_poll(QUEUE_EXP queue_exp)
{
	TYPE elem;
	while(!stack_isempty(queue_exp->in))
	{
		elem=stack_pop(queue_exp->in);
		stack_push(queue_exp->out,elem);
	}
	elem = stack_pop(queue_exp->out);
	queue_exp->size--;
	return(elem);
}

BOOL queue_exp_isempty(QUEUE_EXP queue_exp)
{
	return stack_isempty(queue_exp->in) && stack_isempty(queue_exp->out);
}

int queue_exp_size(QUEUE_EXP queue_exp)
{
	return queue_exp->size;
}
