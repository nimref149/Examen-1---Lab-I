#include "pelicula.h"
#include "actores.h"
#include "input.h"
#include "elenco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void menuElenco(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    system("cls");
    int opcion;

    do
    {
        while((getIntValid(&opcion,"**Menu elencos**\n1-Dar de alta elenco\n2-Listar Elencos ordenados por pelicula y actor\nElija una opcion:\n","Error",1,3))==-1);
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
    int auxCodigo;
    idMax=buscarIdMayor(actores,tamA);
    if(i!=-1)
    {
        //do
        //{
            system("cls");
            mostrarListaPeliculas(peliculas,tamP,generos,tamG);
            while((getIntValid(&elenco[i].codigoPelicula,"Ingrese codigo de pelicula: ","Error",1,tamP))==-1);
            mostrarListaActores(actores,tamA);
            //while((getIntValid(&elenco[i].codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMax))==-1);
            while((getIntValid(&auxCodigo,"Ingrese codigo de actor para la pelicula: ","Error",1,idMax))==-1);

            if(findActorById(actores,tamA,auxCodigo)==-1){
            printf("No existe ese id\n");
            while((getIntValid(&auxCodigo,"Ingrese codigo de actor para la pelicula: ","Error",1,idMax))==-1);
            }
            if((existeActorYpelicula(elenco,tamE,elenco[i].codigoPelicula,auxCodigo))==0)
            {
                elenco[i].codigoActor=auxCodigo;
                while((getFloatValid(&elenco[i].valorContro,"Ingrese valor contrato: ","Error",1,100000))==-1);
                elenco[i].estado=OCUPADO;
            }
            //printf("No existe ese id o ya existe id con la pelicula");
            //while((getIntValid(&elenco[i].codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMax))==-1);
        //}
        //while(continuar()==0);
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
            printf("\nYa existe una pelicula con ese id de actor\n");
            retorno=-1;
            break;
        }
        }
    }
return retorno;
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



void listarElencosOrdenados(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    ordenarElencosPeliculasActor(elenco,tamE,peliculas,tamP,actores,tamA);
    int i;
    int j;
    int k;
    printf("        Pelicula           |         Actor          |    valor contrato \n");
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
                        printf("%-25s  | ",peliculas[k].titulo);
                        printf("%-10s ",actores[j].nombre);
                        printf("%-10s |",actores[j].apellido);
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
int buscarLibreElencos(eElenco elencos[],int tp)
{
    int i;

    for(i=0; i<tp; i++)
    {
        if(elencos[i].estado== LIBRE)
        {
            return i;
        }
    }

    return -1;
}

//crear funcion que muestre peli por id
//crer funcion que muestre actort por id
//crear funcion que reciba un elenco y lo muestre
//crear funciones que falten en peliculas
//crear biblio de actores


/*
void listarElencosOrdenados(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    ordenarElencosPeliculasActor(elenco,tamE,peliculas,tamP,actores,tamA);
    int i;
    int j;
    //int k;
    int index;
    for(i=0; i<tamE; i++)
    {
        if(elenco[i].estado==OCUPADO)
        {
            index=findPeliculaById(peliculas,tamP,elenco[i].codigoPelicula);
            printf("id  |  Pelicula  |  duracion  |  genero  \n");
            mostrarUnaPelicula(peliculas[index],generos,tamG);
            printf("Actores\n");
            printf("Nombre  |  apellido  |  sexo | valor contrato\n");
            for(j=0; j<tamA; j++)
            {
                if(elenco[i].codigoActor==actores[j].codigo&&actores[j].estado==OCUPADO)
                {
                    printf("%-10s  %-10s   %c     ",actores[j].nombre,actores[j].apellido,actores[j].sexo);
                    printf("%f\n",elenco[i].valorContro);
                }
            }
            printf("-------------------------------------------------\n");
        }
    }
}
*/
