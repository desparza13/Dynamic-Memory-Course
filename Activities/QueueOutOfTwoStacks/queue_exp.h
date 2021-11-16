//Daniela Esparza
//Queue experimental hecha a partir de dos stacks

#ifndef QUEUE_EXP_H_
#define QUEUE_EXP_H_

#include "stack.h"

struct QUEUE_EXPSTR {
	STACK in;
	STACK out;
	int size;
};

typedef struct QUEUE_EXPSTR * QUEUE_EXP;

QUEUE_EXP queue_exp_create();
void queue_exp_offer(QUEUE_EXP queue_exp,TYPE data);
TYPE queue_exp_poll(QUEUE_EXP queue_exp);
BOOL queue_exp_isempty(QUEUE_EXP queue_exp);
int queue_exp_size(QUEUE_EXP queue_exp);

#endif /* QUEUE_EXP_H_ */
