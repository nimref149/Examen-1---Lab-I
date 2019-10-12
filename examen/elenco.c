#include "pelicula.h"
#include "input.h"
#include "elenco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//TALVES HAY Q EL TAMAÑO DEL ELENCO EN BASE A LOS ACTORES OSEA SI SON 5 ACTORES Y 5 PELIS PONER 5 POR CADA PELI OSEA EN TOTAL 25



void menuElenco(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    int opcion;

    do
    {
        while((getIntValid(&opcion,"Menu elencos\n1-Dar de alta elenco\n2-Listar Elencos ordenados","Error",1,3))==-1);
        switch(opcion)
        {
        case 1:
            altaElencos(elenco,tamE,generos,tamG,peliculas,tamP,actores,tamA);
            break;
        case 2:
            listarElencosOrdenados(elenco,tamE,generos,tamG,peliculas,tamP,actores,tamA);
            break;
        }
        system("pause");
        system("cls");
        }
        while(opcion!=3);

}

void altaElencos(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    int i;
    //int respuesta;
    i=buscarLibreElencos(elenco,tamE);
    int idMax;
    idMax=buscarIdMayor(actores,tamA);
    if(i!=-1)
    {
        do
        {
            mostrarListaPeliculas(peliculas,tamP,generos,tamG);
            while((getIntValid(&elenco[i].codigoPelicula,"Ingrese codigo de pelicula: ","Error",1,tamP))==-1);
            mostrarListaActores(actores,tamA);
            while((getIntValid(&elenco[i].codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMax))==-1);
            while((findActorById(actores,tamA,elenco[i].codigoActor))==-1||(existeActorYpelicula(elenco,tamE,elenco[i].codigoPelicula,elenco[i].codigoActor))==-1){
            //printf("No existe ese id o ya existe id con la pelicula");
            while((getIntValid(&elenco[i].codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMax))==-1);
            }
            while((getFloatValid(&elenco[i].valorContro,"Ingrese valor contrato: ","Error",1,100000))==-1);
            elenco[i].estado=OCUPADO;
        }
        while((confirm())==0);
        //printf("%d------%s\t\t%s\t\t%c\n",actores[i].codigo,actores[i].nombre,actores[i].apellido,actores[i].sexo);
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
}
int existeActorYpelicula(eElenco elencos[],int tam,int idP,int idA)
{
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(elencos[i].estado==OCUPADO){
        if(elencos[i].codigoActor==idA&&elencos[i].codigoPelicula==idP)
        {
            printf("Ya existe una pelicula con ese id");
            retorno=-1;
            break;
        }
        }
    }
return retorno;
}

int contadorActores(eActores actores[],int tam)
{
        int contador=0;
        int i;
        for(i=0; i<tam; i++)
        {
            if(actores[i].estado==OCUPADO)
            {
                contador++;
            }
        }

        return contador;
}

void inicializarElencos(eElenco elencos[],int ta)
{
    int i;

    for(i=0; i<ta; i++)
    {
        elencos[i].estado= LIBRE;
    }

}

void ordenarElencosPeliculasActor(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    int i;
    int j;
    eElenco auxElenco;
    int peli1;
    int peli2;
    int actor1;
    int actor2;

    for(i=0; i<tamE-1; i++)
    {
        for(j=i+1; j<tamE; j++)
        {
            peli1=findPeliculaById(peliculas,tamP,elenco[i].codigoPelicula);
            peli2=findPeliculaById(peliculas,tamP,elenco[j].codigoPelicula);

            if(strcmp(peliculas[peli1].titulo,peliculas[peli2].titulo)>0)
            {
                auxElenco =elenco[i];
                elenco[i] = elenco[j];
                elenco[j] =auxElenco;
            }

            else
            {

                if(strcmp(peliculas[peli1].titulo,peliculas[peli2].titulo)==0)
                {
                actor1=findActorById(actores,tamA,elenco[i].codigoActor);
                actor2=findActorById(actores,tamA,elenco[j].codigoActor);
                    if(actores[actor1].nombre>actores[actor2].nombre)
                    {
                        auxElenco = elenco[i];
                        elenco[i] = elenco[j];
                        elenco[j] = auxElenco;
                    }
                }
            }
        }
    }
}


int findPeliculaById(ePeliculas peliculas[],int tam,int id){
    int retorno=-1;
    int i;
    if(tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(peliculas[i].codigo==id)
            {
                retorno=i;

                break;
            }

        }
    }
    return retorno;
}
void listarElencosOrdenados(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    ordenarElencosPeliculasActor(elenco,tamE,peliculas,tamP,actores,tamA);
    int i;
    int j;
    int k;
    printf("    Pelicula     |      Actor        |         valor \n");
    for(i=0; i<tamE; i++)
    {
        for(k=0;k<tamP; k++)
        {
            if(elenco[i].codigoPelicula==peliculas[k].codigo&&elenco[i].estado==OCUPADO)
            {

                for(j=0; j<tamA; j++)
                {
                    if(elenco[i].codigoActor==actores[j].codigo&&actores[j].estado==OCUPADO)
                    {
                        printf("%-15s  | ",peliculas[k].titulo);
                        printf("%-8s ",actores[j].nombre);
                        printf("%-8s |",actores[j].apellido);
                        printf("%-5.02f\n",elenco[i].valorContro);
                        //mostrarActor(actores[j]);
                        //mostrarUnaPelicula(peliculas[k],generos,tamG);
                        //printf(" Actor %-10s\n",actores[j].nombre);
                    }
                }

            }
        }
    }
}
