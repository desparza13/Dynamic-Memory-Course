//Daniela Esparza Espinosa
//Listas doblemente encadenadas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Estructura autoreferenciada
struct NODO
{
  int value;
  struct NODO *next;
  struct NODO *prior;
};
struct LISTA
{
  struct NODO *header;
  struct NODO *last;
};
void listInsert (struct LISTA *list, int n); //Inserta elemento
void listDisplay(struct LISTA *list); //Muestra orden ascendente
void listDisplayBackwards(struct LISTA *list); //Muestra orden descendente
int isPrime(int num); //Comprueba si el numero es primo

int main(void) 
{
  struct LISTA list = {NULL, NULL};
  int limInf, limSup, n, visualizacion;
  printf("Ingrese limite inferior: ");
  scanf("%d", &limInf);
  printf("Ingrese limite superior: ");
  scanf("%d", &limSup);
  for (int i=limInf; i<limSup; i++)
  {
    if(isPrime(i)==1)
    {
      listInsert(&list,i);
    }
  }
  printf("Selecciona una opción para mostrar tu lista:\n\t1.Orden ascendente\n\t2.Orden descendente\n");
  scanf("%d",&visualizacion);
  if (visualizacion==1)
    listDisplay(&list);
  else if (visualizacion==2)
    listDisplayBackwards(&list);
  return 0;
}

void listInsert (struct LISTA *list, int n)
{
  struct NODO *new;
  struct NODO *ptr;
  new = malloc(sizeof(struct NODO));
  new->value = n;
  new->next = NULL;
  if(list->header==NULL)
  {
    new->prior=NULL;
    list->header=new;
    list->last= list->header;
  }
  else
  {
    new->prior=list->last;
    list->last->next=new;
    list->last=new;
  }
}

void listDisplay(struct LISTA *list)
{
  while(list->header!=NULL)
  {
    printf("%d, ", list->header->value);
    list->header=list->header->next;
  }
}
void listDisplayBackwards(struct LISTA *list)
{
  while(list->last!=NULL)
  {
    printf("%d, ", list->last->value);
    list->last=list->last->prior;
  }
}
int isPrime(int num)
{
  for(int i=2; i<=sqrt(num); i++)
  {
    if(num%i == 0)
    {
      return 0; //no primo
    }
  }
  if(num>=2)
  {
    return 1; //es primo
  }
  return 0;
}