#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int size; 
	srand(time(NULL));
	size = rand () % 20;
	int **matriz;
	matriz = malloc(size * sizeof(int *));
	for (int i=0; i<size; i++)
	{
		matriz[i] = malloc(i * sizeof(int));
	}
	for (int i=1; i<size; i++)
	{
		printf("[");
		for (int j=0; j<i; j++)
		{
			*(*(matriz+i)+j)=i;
			printf("%d ",*(*(matriz+i)+j));
		}
		printf("]\n");
	}
	//Liberar memoria
	for(int i=0; i<size; i++)
	{
		free(matriz[i]);
	}
	free(matriz);
	return 0;
}