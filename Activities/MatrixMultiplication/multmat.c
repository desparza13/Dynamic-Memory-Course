//Daniela Esparza
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main()
{
	//Archivos
	FILE *a;
    FILE *b;
    FILE *c;
	//Matrices
	int matA[3][3];
	int matB[3][3];
	int matC[3][3];


	setbuf(stdout,NULL);

    //Crear matriz a y b
	a=fopen("a.txt","w");
    b=fopen("b.txt","w");
	if(a==NULL)
	{
		fprintf(stderr,"Error al crear el archivo a");
		exit(1);
	}
    if(b==NULL)
    {
        fprintf(stderr,"Error al crear el archivo b");
        exit(1);
    }
    for (int i=1; i<10; i++)
    {
		fprintf(a,"%d\n",i);
        fprintf(b,"%d\n", 10-i);
    }
	fclose(a);
    fclose(b);

	//Lectura y llenado de matriz a y b
	a=fopen("a.txt","r");
	b=fopen("b.txt", "r");
	if(a==NULL)
	{
		fprintf(stderr,"Error al abrir el archivo a");
		exit(1);
	}
	if(b==NULL)
	{
		fprintf(stderr,"Error al crear el archivo b");
		exit(1);
	}
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			int *auxA;
			int *auxB;
			fscanf(a, "%d", auxA);
			//fscanf(b, "%d", auxB);
			matA[i][j]=*auxA;
			//matB[i][j]=*auxB;
		}
	}
	fclose(a);
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			int *auxB;
			fscanf(b, "%d", auxB);
			matB[i][j]=*auxB;
		}
	}
	fclose(b);

	//Calcular y llenar C
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


	//Escribir C
	c=fopen("c.txt","w");
	if(c==NULL)
	{
		fprintf(stderr,"Error al crear el archivo c");
		exit(1);
	}
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			if (j==2)
				fprintf(c,"%d\n",matC[i][j]);
			else
				fprintf(c,"%d, ",matC[i][j]);
		}
	}
	fclose(c);		

}




