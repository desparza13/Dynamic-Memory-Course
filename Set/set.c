/*
 * set.c
 *
 *  Created on: 11 nov. 2021
 *      Author: Jos� Luis Elvira
 */
#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "datatypes.h"


BOOL tree_insert(TREENODE *tnode,TYPE data,COMPAREFUNC cf)
{
	BOOL success =0;
	if(*tnode==NULL)
	{
		*tnode = malloc(sizeof(struct STRTREENODE));
		(*tnode)->data=data;
		(*tnode)->left=NULL;
		(*tnode)->right=NULL;
		success=1;
	}
	else if(cf(data,(*tnode)->data)<0)
		tree_insert(&(*tnode)->left,data,cf);
	else if(cf(data,(*tnode)->data)>0)
		tree_insert(&(*tnode)->right,data,cf);
	return(success);
}

void tree_inorder(TREENODE tnode,PRINTFUNC pf,int level)
{
	if(tnode->left!=NULL)
		tree_inorder(tnode->left,pf,level+1);

	printtabs(level);
	pf(tnode->data);

	if(tnode->right!=NULL)
		tree_inorder(tnode->right,pf,level+1);
}

void tree_preorder(TREENODE tnode,PRINTFUNC pf,int level)
{
	printtabs(level);
	pf(tnode->data);

	if(tnode->left!=NULL)
		tree_inorder(tnode->left,pf,level+1);

	if(tnode->right!=NULL)
		tree_inorder(tnode->right,pf,level+1);
}

void tree_postorder(TREENODE tnode,PRINTFUNC pf,int level)
{
	if(tnode->left!=NULL)
		tree_inorder(tnode->left,pf,level+1);

	if(tnode->right!=NULL)
		tree_inorder(tnode->right,pf,level+1);

	printtabs(level);
	pf(tnode->data);
}



BOOL tree_contains(TREENODE tnode,TYPE data,COMPAREFUNC cf)
{
	BOOL result=0;

	if(tnode!=NULL)
	{
		if(cf(data,tnode->data)==0)	// Si lo encontr�
			result=1;
		else if(cf(data,tnode->data)<0)
			result=tree_contains(tnode->left,data,cf);
		else if(cf(data,tnode->data)>0)
			result=tree_contains(tnode->right,data,cf);

	}
	return(result);
}

void printtabs(int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("\t");
}

SET set_create(COMPAREFUNC cf,PRINTFUNC pf)
{
	SET tmp=malloc(sizeof(struct STRSET));
	tmp->root=NULL;
	tmp->cf=cf;
	tmp->pf=pf;
	tmp->size=0;
	return tmp;
}

void set_add(SET set,TYPE data)
{
	if(tree_insert(&set->root,data,set->cf))
		set->size++;
}

void set_print(SET set)
{
	tree_preorder(set->root,set->pf,0);
}

BOOL set_contains(SET set,TYPE data)
{
	BOOL result=tree_contains(set->root,data,set->cf);
	return(result);
}


