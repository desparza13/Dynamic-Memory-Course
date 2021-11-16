//Daniela Esparza Espinosa
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	FILE *salida;
	int matA[3][3];
	int matB[3][3];
	int matC[3][3];

	setbuf(stdout,NULL);

	fp=fopen("entrada.bin","rb");
	if(fp==NULL)
	{
		fprintf(stderr,"Error al leer el archivo");
		exit(1);
	}
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			fread(&matA[i][j],1,sizeof(int),fp);		}
	}
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			fread(&matB[i][j],1,sizeof(int),fp);
		}
	}
	fclose(fp);
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			matC[i][j]=0;
			for (int k=0; k<3; k++)
			{
				matC[i][j] += matA[i][k] * matB[k][j];
			}
		}
	}
	salida=fopen("salida.bin","wb");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			fwrite(&matC[i][j],1,sizeof(int),salida);
		}
	}

	fclose(salida);

	
}

