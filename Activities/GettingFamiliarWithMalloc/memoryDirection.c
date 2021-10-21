#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr=NULL;
	for(int i=0; i<64; i++)
	{
		ptr = malloc(64*sizeof(int));
		ptr[10]=5000;
		printf("Direcccion incial %d: %p\n",i,ptr);
		free(ptr);
	}
	//free(ptr);
	/*
	La dirección de memoria cambia porque no estoy liberando la memoria tras cada
	iteración del for, por lo que esa memoria está ocupada y se tiene que recorrer a apartar
	el siguiente bloque disponible
	Si activo el free del comentario en la linea 12 y comento la linea 14 todas las impresiones de la direcciond 
	de memoria son iguales por eso mismo, porque estoy liberando la memoria que aparte y cuando
	vuelvo a apartar la vuelvo a tomar
	*/
	
}

