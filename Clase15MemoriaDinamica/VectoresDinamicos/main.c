#include <stdio.h>
#include <stdlib.h>
/**
Vectores dinamicos:
punteros se guardan en el projecto de la clase de ahora

realloc: reubica el puntero,cuando lo uso hay esenarios distintos,
muda los datos del vector chico, al vector grande pero sige apuntando al mismo
 vector,osea lo tengo que liberar para que el s.o lo pueda reutilizar.puede devolver null si no puede encontrar mas espacio.
recibe un puntero a void,primero tiene que haber un malloc

calloc:inicialisa todo el vector en 0


*/
int main()
{
    //int miVector[10]; no me sirve, lo unico que voy a cargar en una pila son punteros 1 puntero = 4 bytes seguimos con algo parecido a esto
    int* pVec;
    int* aux;
    int i;
    //int vector[5];//lo hace en la pila, es estatico,no puedo hacer que la variable cresca en memoria si es 5 siempre sera 5
    pVec=(int*)calloc(sizeof(int),5);///inicialiso en 0
    ///pVec=(int*)malloc(sizeof(int)*5);//lo guarda en,hace en el heap/monton, es dinamico,esto apunta a un segmento de memoria en el monton,siempre tiene un tamanio inicial pero luego si nesesito mas le pido
    //pVec=miVector;
/*
    for(i=0; i<5; i++)
    {
        //*(pVec+i)=i+1;
        //pido datos y avanso por cada lugar en el lugar
        printf("Ingrese un numero: ");
        scanf("%d",pVec+i);
    }
*/
    //tenemos que limpiar el stack
    for(i=0; i<5; i++)
    {
        // hacer un malloc aca no me sirve
        printf("%d\n",*(pVec+i));
    }
    aux=(int*)realloc(pVec,sizeof(int)*10);
    if(aux!=NULL)
    {
        printf("Agrego 5 mas\n");
        pVec=aux;
        for(i=5; i<10; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d",pVec+i);
        }
        for(i=0; i<10; i++)
        {
            printf("%d\n",*(pVec+i));
        }
        printf("Lo achico\n");
        pVec=(int*)realloc(pVec,sizeof(int)*4);
        for(i=0; i<4; i++)
        {
            printf("%d\n",*(pVec+i));
        }



    }
    return 0;
}

