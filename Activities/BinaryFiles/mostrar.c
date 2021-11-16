//Daniela Esparza Espinosa
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int num;
	setbuf(stdout,NULL);

	fp=fopen("salida.bin","rb");
	if(fp==NULL)
	{
		fprintf(stderr,"Error al leer el archivo");
		exit(1);
	}
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			fseek(fp,((i*3)+j)*sizeof(int),SEEK_SET);
			fread(&num,1,sizeof(int),fp);
			printf("%d ",num);
		}
		printf("\n");
	}
	
	fclose(fp);
}

