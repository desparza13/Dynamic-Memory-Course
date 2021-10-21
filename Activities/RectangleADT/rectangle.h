//Daniela Esparza

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

/*
Este archivo solo contiene definiciones y encabezados de funciones que estarán
definidas en el archivo rectangle.c
*/
struct RECTANGLE_STR
{
	double b,h; //base y altura
};

typedef struct RECTANGLE_STR *RECTANGLE;

RECTANGLE new_rectangle(double b, double h);
void rectangle_set_base(RECTANGLE rect, double b);
void rectangle_set_height(RECTANGLE rect, double h);
double rectangle_base(RECTANGLE rect);
double rectangle_height(RECTANGLE rect);
double rectangle_area(RECTANGLE rect);
double rectangle_perimeter(RECTANGLE rect);

#endif /* RECTANGLE_H_ */
