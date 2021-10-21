#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printMatrix(int **matriz, int n);
void liberarMatriz( int **matriz, int n);
int main()
{
	int n; 
	srand(time(NULL));
	printf("Ingrese n: ");
	scanf("%d",&n);
	int **matriz1;
	int **matriz2;
	int **res;
	matriz1 = malloc(n * sizeof(int *));
	matriz2 = malloc(n * sizeof(int *));
	res = malloc(n * sizeof(int *)); 
	for (int i=0; i<n; i++)
	{
		matriz1[i] = malloc(n * sizeof(int));
		matriz2[i] = malloc(n * sizeof(int));
		res[i] = malloc(n * sizeof(int));
	}
	//Inicializar las originales con valores aleatorios del 1 al 10
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			*(*(matriz1+i)+j)=rand()%10;
			*(*(matriz2+i)+j)=rand()%10;
			*(*(res+i)+j)=0;
		}
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			for (int k=0; k<n; k++)
			{
				*(*(res+i)+j) += *(*(matriz1+i)+k) * *(*(matriz2+k)+j);
			}
		}
	}
	printf("A:\n");
	printMatrix(matriz1, n);
	printf("B:\n");
	printMatrix(matriz2,n);
	printf("A*B:\n");
	printMatrix(res, n);
	liberarMatriz(matriz1,n);
	liberarMatriz(matriz2,n);
	liberarMatriz(res, n);
	return 0;
}
void printMatrix(int **matriz, int n)
{
	for (int i=0; i<n; i++)
	{
		printf("[");
		for (int j=0; j<n; j++)
		{
			printf("%d ",*(*(matriz+i)+j));
		}
		printf("]\n");
	}
}
void liberarMatriz( int **matriz, int n)
{
	for(int i=0; i<n; i++)
	{
		free(matriz[i]);
	}
	free(matriz);
}
