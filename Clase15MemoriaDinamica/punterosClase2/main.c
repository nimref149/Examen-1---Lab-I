#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
/**
tema de hoy memoria dinamica:
anda al head y resevame espacio para una persona y me devuelve la direccion de memoria del primer bit
si le pido a malloc mas memoria de la que puedo reservar me devuelve null
en el heap es, encontro espacio y ahi lo guardo
el otro en la pila se va acumulando

funcion free libera el espacio que no se usa
EN EL CAMPUS EN CLASE MEMORIA DINAMICA HAY UN ARCHIVO LLAMADO PEOPLE .C
en el campo dice THIS que es la persona actual, el puntero que recibo, se le puede poner de nombre  una persona
HAY FUNCIONES PARECIDAS A LA CLASE
NUEVAS FUNCIONES:
SET AGE NO PIDE LOS DATOS SINO QUE LE PASA LOS DATOS
GET AGE OBTIENE LOS DATOS devuelde valor dato de una estructura
getter return estructura
getter
setter
sigiente clase archivo ir armando el tp 3

*/

int main()
{
    ePersona* puntero=new_Persona_Parametros(1000,'M',1.98);
    setLegajo(puntero,1001);///suponiendo que el constructo no construye con legajo

    ///ePersona* puntero=new_Persona_Parametros(1000,'M');

    ///setter///puntero->altura=1.70;///ESTO ESTA MAL NO SE USA EN EL MAIN NI TAMPOCO CALLOC NI MALLOC USAR FUNCIONES, SETTER GETTER
    int x;

    if(puntero!=NULL){

        printf("la persona es: \n");
        ///if(puntero!=NULL)///MAL
        if(getLegajo(puntero)>1000)///dame el legajo de esa persona y si es mayor a 1000 mustro
        mostrarPersona(puntero);

    }

    delete_persona(puntero);///trabaje con el espacio en la memoria y luego cuando ya no lo nesesito lo libero

/**
    ePersona* puntero = new_Persona();
    printf("%d--%d---%d\n\n",&puntero,puntero,&x);//memoria en la pila, el otro en el heap
*/

    //------------------------------------------------------------------------

    //free(puntero);
    //puntero=NULL;
/**
    if(puntero!=NULL)
    {
        printf("La persona es: \n"); // <<<--- antes me salia cualquier cosa,ahora se llego a pisar ese espacio, ahora trabajo en un espacio de memoria distinto con la reserva y anda bien
        printf("%d--%c--%f", puntero->legajo,
                             puntero->sexo,
                             puntero->altura);
    }

*/

    return 0;
}






