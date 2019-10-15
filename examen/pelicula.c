#define LIBRE 0
#define OCUPADO 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "pelicula.h"
#include "actores.h"
#include "input.h"
#include "elenco.h"

void hardcodearPeliculas(ePeliculas peliculas[],int TP)
{

    int codigo[]= {1,2,3,4,5,6,7};
    char descripcion[7][31]= {"Avengers","spider man","Flash","Linterna verde","Superman","Guardanes de la galaxya","batman"};
    int idGenero[]= {1,4,2,3,4,1,2};
    float duracion[]= {1.30,1.50,2.50,3.00,2.00,3.00,1.50};
    int i;
    for(i=0; i<TP; i++)
    {
        peliculas[i].codigo =codigo[i];
        strcpy(peliculas[i].titulo,descripcion[i]);
        peliculas[i].duracion = duracion[i];
        peliculas[i].idGenero =idGenero[i];
        peliculas[i].estado=OCUPADO;
    }

}
/*
void hardcodearPeliculas(ePeliculas peliculas[],int TP)
{

    int codigo[]= {1,2,3,4,5,6,7};
    char descripcion[7][31]= {"Avengers","spider man","Flash","Linterna verde","Superman","Guardanes de la galaxya","batman"};
    int idGenero[]= {1,4,2,3,4,1,2};
    float duracion[]= {1.30,1.50,2.50,3.00,2.00,3.00,1.50};
    int i;
    for(i=0; i<TP; i++)
    {
        peliculas[i].codigo =codigo[i];
        strcpy(peliculas[i].titulo,descripcion[i]);
        peliculas[i].duracion = duracion[i];
        peliculas[i].idGenero =idGenero[i];
        peliculas[i].estado=OCUPADO;
    }

}
*/
void hardcodearGeneros(eGeneros generos[],int TG)
{
    int i;
    int codigo[]= {1,2,3,4};
    char descripcion[7][31]= {"Accion","Terror","Romance","Suspenso"};
    for(i=0; i<TG; i++)
    {
        generos[i].idGenero =codigo[i];
        strcpy(generos[i].genero,descripcion[i]);
    }
}

void mostrarListaPeliculas(ePeliculas peliculas[], int tamP,eGeneros generos[],int tg)
{
    int i;
    //int j;
    printf("id    |   pelicula  \t\t   | duracion \t   | genero \n");
    for(i=0; i<tamP; i++)
    {
    if(peliculas[i].estado==OCUPADO){
    mostrarUnaPelicula(peliculas[i],generos,tg);
    }

    }
}
/*
void mostrarListaPeliculas(ePeliculas peliculas[], int tamP,eGeneros generos[],int tg)
{
    int i;
    //int j;
    printf("id    |   pelicula  \t\t   | duracion \t   | genero \n");
    for(i=0; i<tamP; i++)
    {
    mostrarUnaPelicula(peliculas[i],generos,tg);
    }
}
*/
void mostrarListaPeliculaYActor(ePeliculas peliculas[], int tamP,eGeneros generos[],int tg)
{
    int i;
    //int j;
    printf("id       |       pelicula    |      duracion     | genero  | actor | sueldo\n");
    for(i=0; i<tamP; i++)
    {
    mostrarUnaPelicula(peliculas[i],generos,tg);
    }
}

void mostrarUnaPelicula(ePeliculas peliculas,eGeneros generos[],int tg)
{
    int j;
    printf("%-5d |\t %-25s |\t %-10.02f",peliculas.codigo,peliculas.titulo,peliculas.duracion);
    for(j=0; j<tg; j++)
    {
        if(generos[j].idGenero==peliculas.idGenero)
        {
            printf("|%-10s\n",generos[j].genero);
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
            if(peliculas[i].codigo==id&&peliculas[i].estado==OCUPADO)
            {
                retorno=i;

                break;
            }

        }
    }
    return retorno;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
int menuModificarPeli(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,int i)
{
    int flag=0;
    int opcion;
    ePeliculas auxPelicula;
    printf("Se modificara la siguiente pelicula\n");
    printf("Codigo|   titulo  | duracion |  genero \n");
    mostrarUnaPelicula(peliculas[i],generos,tamG);
    while((getIntValid(&opcion,"Escoja el campo a modificar:\n1.Tituto\n2.Duracion\n3.Genero\n4.Salir\n","Error",1,4))==-1);
    switch(opcion)
    {
    case 1:
        while((getStringLetras(auxPelicula.titulo,"Ingrese nuevo titulo de pelicula: ","Error",1,31))==-1);
        if((confirm())==1)
        {
            strcpy(peliculas[i].titulo, auxPelicula.titulo);
            flag=1;
        }
        break;
    case 2:
        while((getFloatValid(&auxPelicula.duracion,"Ingrese nueva duracion: ","Error",1,5))==-1);
        if((confirm())==1)
        {
            peliculas[i].duracion=auxPelicula.duracion;
            flag=1;
        }
        break;
    case 3:
        mostrarListaGeneros(generos,tamG);
        while((getIntValid(&auxPelicula.idGenero,"Ingrese nuevo genero: ","Error",1,tamG))==-1);
        if((confirm())==1)
        {
            peliculas[i].idGenero=auxPelicula.idGenero;
            flag=1;
        }
        break;
    case 4:
        printf("Saliendo\n");
        flag=0;
        break;
    }
    return flag;
}

void mostrarListaGeneros(eGeneros generos[],int tam)
{
    int i;
    printf("ID     GENERO  \n");
    for(i=0;i<tam;i++)
    {
        printf("%-5d      %-10s\n",generos[i].idGenero,generos[i].genero);
    }
}

void agregarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG)
{
    int i;
    i=buscarLibrePelicula(peliculas,tamP);
    if(i!=-1)
    {
        peliculas[i].codigo=autoIdPeliculas(peliculas,tamP);
        do
        {
            while((getStringLetras(peliculas[i].titulo,"Ingrese nombre de la pelicula: ","Error, solo entre 1 y 31 caracteres",1,52))==-1);
            mostrarListaGeneros(generos,tamG);
            while((getIntValid(&peliculas[i].idGenero,"Ingrese genero de la pelicula","Error",1,tamG))==-1);
            while((getFloatValid(&peliculas[i].duracion,"Ingrese duracion de la pelicula ","Error",1,5))==-1);
            peliculas[i].estado=OCUPADO;
            mostrarUnaPelicula(peliculas[i],generos,tamG);
        }
        while((confirm())==0);
    }
    else
    {
        printf("No hay lugar disponible\n");
    }

}
void modificarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG){

    int flag=0;
    int opcion;
    int idA;
    int idMayor;
    idMayor=buscarIdMayorPelicula(peliculas,tamP);
    mostrarListaPeliculas(peliculas,tamP,generos,tamG);
    while((getIntValid(&idA,"Ingrese id de la pelicula a modificar","Error",1,idMayor))==-1);
    opcion=findPeliculaById(peliculas,tamP,idA);
    if(opcion!=-1)
    {
        flag=menuModificarPeli(peliculas,tamP,generos,tamG,opcion);
    }
    else
    {
        printf("No se encontro el id\n");
    }
    if(flag==0)
    {
        printf("No se ha modificado\n");
    }

}
void bajarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG)
{
    int idP;
    int flag=0;
    int idMayor;
    idMayor=buscarIdMayorPelicula(peliculas,tamP);
    int loEncontro;
    mostrarListaPeliculas(peliculas,tamP,generos,tamG);
    while((getIntValid(&idP,"Ingrese id de pelicula a eliminar","Error",1,idMayor))==-1);
    loEncontro=findPeliculaById(peliculas,tamP,idP);
    if(loEncontro!=-1)
    {
        printf("Se dara de baja la siguiente pelicula:\n");
        mostrarUnaPelicula(peliculas[loEncontro],generos,tamG);
        if((confirm())==1)
        {
            peliculas[loEncontro].estado=LIBRE;
        }
        flag=1;
    }
    if(flag==0)
    {
        printf("No ingreso un id valido\n");
    }

}
void initPeliculas(ePeliculas peliculas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        peliculas[i].estado= LIBRE;
    }
}


int buscarLibrePelicula(ePeliculas peliculas[],int tamP){
    int i;
    for(i=0; i<tamP; i++)
    {
        if(peliculas[i].estado == LIBRE)
        {
            return i;
        }
    }
    return -1;
}
int autoIdPeliculas(ePeliculas peliculas[],int tamP)
{
    int retorno;
    int idMayor;
    idMayor=buscarIdMayorPelicula(peliculas,tamP);
    if(idMayor!=-1)
    {
        retorno=idMayor+1;
    }
    else
    {
        retorno=1;
    }

    return retorno;
}

int buscarIdMayorPelicula(ePeliculas lista[],int tam)
{
    int retorno=-1;
    int i;
    int flag=0;
    int mayor;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(lista[i].codigo>mayor || flag==0)
            {
                mayor=lista[i].codigo;
                flag=1;
            }
        }
    }
    if(flag!=0)
    {
        retorno=mayor;
    }
    return retorno;
}
void menuPeliculas(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG)
{
    system("cls");
    int opcion;
    do
    {
        while((getIntValid(&opcion,"****Peliculas****\n1.Alta de pelicula\n2-Modificar pelicula\n3-Baja de pelicula\n4-listar peliculas\n5-Salir\n","Error",1,5))==-1);
        switch(opcion)
        {
        case 1:
            agregarPelicula(peliculas,tamP,generos,tamG);
            break;
        case 2:
            modificarPelicula(peliculas,tamP,generos,tamG);
            break;
        case 3:
            bajarPelicula(peliculas,tamP,generos,tamG);
            break;
        case 4:
            //mostrarListaPeliculas(peliculas,tamP);
            break;
        case 5:
            printf("Saliendo\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=5);
}
