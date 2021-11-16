/*
 * set.h
 *
 *  Created on: 11 nov. 2021
 *      Author: Jos� Luis Elvira
 */
#include "datatypes.h"

#ifndef SET_H_
#define SET_H_

struct STRTREENODE
{
	TYPE data;
	struct STRTREENODE *left,*right;
};

typedef struct STRTREENODE * TREENODE;

typedef int (*COMPAREFUNC)(TYPE,TYPE);
typedef void (*PRINTFUNC)(TYPE);

struct STRSET
{
	TREENODE root;
	int size;
	COMPAREFUNC cf;
	PRINTFUNC pf;
};

typedef struct STRSET * SET;

BOOL tree_insert(TREENODE *tnode,TYPE data,COMPAREFUNC cf);
void tree_inorder(TREENODE tnode,PRINTFUNC pf,int level);
void tree_preorder(TREENODE tnode,PRINTFUNC pf,int level);
void tree_postorder(TREENODE tnode,PRINTFUNC pf,int level);
void printtabs(int n);

SET set_create(COMPAREFUNC cf,PRINTFUNC pf);
void set_add(SET set,TYPE data);
void set_print(SET set);
BOOL set_contains(SET set,TYPE data);



#endif /* SET_H_ */
