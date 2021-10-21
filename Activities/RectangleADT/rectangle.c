/*
 * vec3.c
 *
 *  Created on: 28 sep. 2021
 *      Author: Jos� Luis Elvira
 */
#include <stdlib.h>
#include <math.h>
#include "rectangle.h"
RECTANGLE new_rectangle(double b, double h);
void rectangle_set_base(RECTANGLE rect, double b);
void rectangle_set_height(RECTANGLE rect, double h);
double rectangle_base(RECTANGLE rect);
double rectangle_height(RECTANGLE rect);
double rectangle_area(RECTANGLE rect);
double rectangle_perimeter(RECTANGLE rect);

RECTANGLE new_rectangle(double b, double h)
{
	RECTANGLE tmp=malloc(sizeof(struct RECTANGLE_STR));
	tmp->b=b;
	tmp->h=h;

	return(tmp);
}

void rectangle_set_base(RECTANGLE rect, double b)
{
	rect->b=b;
}
void rectangle_set_height(RECTANGLE rect, double h)
{
	rect->h=h;
}

double rectangle_base(RECTANGLE rect)
{
	return (rect->b);
}
double rectangle_height(RECTANGLE rect)
{
	return (rect->h);
}

double rectangle_area(RECTANGLE rect)
{
	return(rect->b * rect->h);
}
double rectangle_perimeter(RECTANGLE rect)
{
	return ((2*rect->b)+(2*rect->h));
}


