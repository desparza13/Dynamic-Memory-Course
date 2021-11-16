//Daniela Esparza Espinosa
//Listas circulares
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
void listDisplayFor(struct LISTA *list, int n); //Muestra orden ascendente
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
  printf("Ingrese la cantidad de elementos a mostrar: ");
  scanf("%d",&visualizacion);
  listDisplayFor(&list,visualizacion);
  return 0;
}

void listInsert (struct LISTA *list, int n)
{
  struct NODO *new;
  struct NODO *ptr;
  new = malloc(sizeof(struct NODO));
  new->value = n;
  new->next = list->header;
  if(list->header==NULL)
  {
    list->header=new;
    list->last= list->header;
  }
  else
  {
    list->last->next=new;
    list->last=new;
  }
}

void listDisplayFor(struct LISTA *list, int n)
{
  for(int i=0; i<n; i++)
  {
    printf("%d, ", list->header->value);
    list->header=list->header->next;
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