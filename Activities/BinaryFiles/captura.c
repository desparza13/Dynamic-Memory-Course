//Daniela Esparza Espinosa
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numero;
	int pos;
	
	FILE *fp,*fp1;
	char eleccion;

	setbuf(stdout,NULL);

	fp=fopen("entrada.bin","r+");
	if(fp==NULL)
	{
		fp=fopen("entrada.bin","wb");
		if(fp==NULL)
		{
			printf("Error al crear el archivo\n");
			exit(1);
		}
	}

	// Leer la lista de n�meros desde el teclado
	printf("Introduzca A para capturar la matriz A\nIntroduzca B para capturar la matriz B\n->");
	scanf("%c",&eleccion);
	if (eleccion=='A')
	{
		rewind(fp);
	}
	else if (eleccion=='B')
	{
		fseek(fp, (9*sizeof(int)), SEEK_SET);
	}
	for (int i=0; i<9; i++)
	{
		printf("Dame un numero:");
		scanf("%d",&numero);
		fwrite(&numero,1,sizeof(int),fp);
	}
	fclose(fp);
}

