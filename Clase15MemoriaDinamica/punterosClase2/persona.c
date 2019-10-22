//lo que hace es reservar memoria con malloc,y poner dentro el tamaño en bites a reservar
//uso siseof por q pueden haber diferentes s.o y ni poner directamente el tamaño (4)
#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
ePersona* new_Persona()
{
    //ePersona unaPersona= {1000,'M',1.78}; se borra
    ePersona* puntero;
    //printf("la persona es ");
    //puntero=&unaPersona; se borra

    /**
    puntero=(ePersona*)malloc(sizeof(ePersona));//devuelve un puntero a void por que permite reservar memoria para cualquier variable,luego convierto lo generico que devuelve malloc a algo espefico,por ej: si uso un entero poner (int*)

    //puntero=NULL;se rompe el programa
    if(puntero!=NULL)
    {
        puntero->legajo=1000;
        puntero->sexo='M';
        puntero->altura=1.79;
    }
    */
    puntero=(ePersona*)calloc(sizeof(ePersona),1);

    return puntero;
}
void mostrarPersona(ePersona* persona){

if(persona!=NULL)
{
        printf("La persona es: \n"); // <<<--- antes me salia cualquier cosa,ahora se llego a pisar ese espacio, ahora trabajo en un espacio de memoria distinto con la reserva y anda bien
        printf("%d--%c--%f", persona->legajo,
                             persona->sexo,
                             persona->altura);
}

}

void delete_persona(ePersona* unaPersona)
{
free(unaPersona);
}
///contruir espacio para una persona,contruye espacio en memoria crea el espacio y pone con los valores
ePersona* new_Persona_Parametros(int legajo,char sexo,float altura)
{
    //ePersona* p = (ePersona*)malloc(sizeof(ePersona));// ya tengo algo que hace lo mismo que es new persona
    ePersona* p=new_Persona();
    if(p!=NULL)
    {
        p->legajo = legajo;
        p->sexo = sexo;
        p->altura = altura;
    }
    return p;
}
void setLegajo(ePersona* unaPersona,int legajo){
    if(legajo>0){
unaPersona->legajo=legajo;
    }
}
int getLegajo(ePersona* unaPersona){

return unaPersona->legajo;
}
