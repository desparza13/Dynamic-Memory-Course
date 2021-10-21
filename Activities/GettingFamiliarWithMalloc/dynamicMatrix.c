#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int col; 
	int ren;
	srand(time(NULL));
	printf("Ingrese la cant. de renglones: ");
	scanf("%d",&ren);
	printf("Ingrese la cant. de columnas: ");
	scanf("%d",&col);
	int **matriz;
	matriz = malloc(col * sizeof(int *));
	for (int i=0; i<ren; i++)
	{
		matriz[i] = malloc(col * sizeof(int));
	}
	for (int i=0; i<ren; i++)
	{
		for (int j=0; j<col; j++)
		{
			*(*(matriz+j)+i)=rand();
		}
	}
	for (int i=0; i<ren; i++)
	{
		printf("[");
		for (int j=0; j<col; j++)
		{
			printf("%d, ",*(*(matriz+j)+i));
		}
		printf("]\n");
	}
	free(matriz);
	return 0;
}