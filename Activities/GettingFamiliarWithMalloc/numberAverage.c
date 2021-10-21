#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	int sum=0;
	printf("Ingrese la cantidad de números a usar: ");
	scanf("%d",&n);
	int *numbers = malloc(n *sizeof(int));

	for(int i=0; i<n; i++)
	{
		printf("Ingrese el valor del dato %d: ",i);
		scanf("%d",&numbers[i]);
		sum+=numbers[i];
	}
	printf("Promedio: %.2f\n",(float)sum/n);
	printf("Cantidad de memoria: %d\n",(int)(sizeof(int)*n));
	free(numbers);
	
}

