#define LIBRE 0
#define OCUPADO 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "input.h"
#include "pelicula.h"
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
    }

}
void hardcodearActores(eActores actores[],int tam){
    int codigo[]={1,2,3};
    char nombre[3][51]= {"Fernando","Emanuel","Lucia"};
    char apellido[3][51]={"Sosa","Domingues","Ramires"};
    char sexo[]={'m','m','f'};
    int i;
    for(i=0; i<tam; i++)
    {
        actores[i].codigo=codigo[i];
        strcpy(actores[i].nombre,nombre[i]);
        strcpy(actores[i].apellido,apellido[i]);
        actores[i].sexo=sexo[i];
        actores[i].estado=OCUPADO;
    }
}
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
void agregarActor(eActores actores[],int ta)
{
    int i;
    i=buscarLibre(actores,ta);
    if(i!=-1)
    {
        do
        {
            actores[i].codigo=autoId(actores,ta);
            while((getStringLetras(actores[i].nombre,"Ingrese nombre del actor: ","Error, solo entre 1 y 51 caracteres",1,52))==-1);
            while((getStringLetras(actores[i].apellido,"Ingese apellido del actor: ","Error, solo entre 1 y 51 caracteres",1,51))==-1);
            while((getCharValidOpciones(&actores[i].sexo,"Ingrese sexo F o M: ","Error",'m','f'))==-1);
            actores[i].estado=OCUPADO;
        }
        while((confirm())==0);
        mostrarActor(actores[i]);

    }
    else
    {
        printf("No hay lugar disponible\n");
    }
}

int buscarLibre(eActores actores[],int tp)
{
    int i;

    for(i=0; i<tp; i++)
    {
        if(actores[i].estado == LIBRE)
        {
            return i;
        }
    }

    return -1;
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
void inicializarActores(eActores actores[],int ta)
{
    int i;

    for(i=0; i<ta; i++)
    {
        actores[i].estado= LIBRE;
    }

}
int autoId(eActores lista[],int tam)
{
    int retorno;
    int idMayor;
    idMayor=buscarIdMayor(lista,tam);
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

int buscarIdMayor(eActores lista[],int tam)
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
void modificarActor(eActores actores[],int tam)
{

    int flag=0;
    int opcion;
    int idA;
    int idMayor;
    idMayor=buscarIdMayor(actores,tam);
    while((getIntValid(&idA,"Ingrese id del actor a modificar","Error",1,idMayor))==-1);
    opcion=findActorById(actores,tam,idA);
    if(opcion!=-1)
    {
        //printf("%s\t\t%s\t\t%c\n",actores[opcion].nombre,actores[opcion].apellido,actores[opcion].sexo);
        flag=menuModificar(actores,tam,opcion);
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

int findActorById(eActores actores[],int tam,int id)
{
    int retorno=-1;
    int i;
    if(tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(actores[i].codigo==id && actores[i].estado==OCUPADO)
            {
                retorno=i;

                break;
            }

        }
    }
    return retorno;
}
int menuModificar(eActores actores[],int tam,int i)
{
    int flag=0;
    int opcion;
    eActores auxActor;
    printf("Se modificara el siguiente actor\n");
    printf("Codigo|   Nombre  |   Apellido |    Sexo\n");
    mostrarActor(actores[i]);
    while((getIntValid(&opcion,"Escoja el campo a modificar:\n1.Nombre\n2.Apellido\n3.Sexo\n4.Salir\n","Error",1,4))==-1);
    switch(opcion)
    {
    case 1:
        while((getStringLetras(auxActor.nombre,"Ingrese nuevo nombre","Error",1,51))==-1);
        if((confirm())==1)
        {
            strcpy(actores[i].nombre, auxActor.nombre);
            flag=1;
        }
        break;
    case 2:
        while((getStringLetras(auxActor.apellido,"Ingrese nuevo apellido","Error",1,51))==-1);
        if((confirm())==1)
        {
            strcpy(actores[i].apellido, auxActor.apellido);
            flag=1;
        }
        break;
    case 3:
        while((getCharValidOpciones(&auxActor.sexo,"Ingrese nuevo sexo F o M","Error",'F','M'))==-1);
        if((confirm())==1)
        {
            actores[i].sexo=auxActor.sexo;
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
void mostrarActor(eActores unActor)
{
    printf("%-5d | %-10s | %-10s  |  %c \n",unActor.codigo,unActor.nombre,unActor.apellido,unActor.sexo);
}
void bajarActor(eActores actores[],int tam)
{
    //int i;
    int idP;
    int flag=0;
    // char confirmacion;
    int loEncontro;
    while((getIntValid(&idP,"Ingrese id de actor a eliminar","Error",1,10000))==-1);
    loEncontro=findActorById(actores,tam,idP);
    if(loEncontro!=-1)
    {
        printf("Se dara de baja el siguiente actor:\n");
        mostrarActor(actores[loEncontro]);
        if((confirm())==1)
        {
            actores[loEncontro].estado=LIBRE;
        }
        flag=1;
    }
    if(flag==0)
    {
        printf("No ingreso un id valido\n");
    }
}

void mostrarListaActores(eActores actores[], int ta)
{
    int i;
    ordenarActoresApellidoNombre(actores,ta);
    printf("Codigo|   Nombre   |    Apellido |    Sexo\n");
    for(i=0; i<ta; i++)
    {
        if(actores[i].estado!=LIBRE)
        {
            mostrarActor(actores[i]);
        }
    }
}
void mostrarListaPeliculas(ePeliculas peliculas[], int tamP,eGeneros generos[],int tg)
{
    int i;
    //int j;
    printf("id      | pelicula    | duracion     | genero \n");
    for(i=0; i<tamP; i++)
    {
    mostrarUnaPelicula(peliculas[i],generos,tg);
    }
}

void mostrarListaPeliculaYActor(ePeliculas peliculas[], int tamP,eGeneros generos[],int tg)
{
    int i;
    //int j;
    printf("id      | pelicula    | duracion     | genero  | actor | sueldo\n");
    for(i=0; i<tamP; i++)
    {
    mostrarUnaPelicula(peliculas[i],generos,tg);
    }
}

void mostrarUnaPelicula(ePeliculas peliculas,eGeneros generos[],int tg)
{
    int j;
    printf("%-5d \t %-10s \t %-7.02f",peliculas.codigo,peliculas.titulo,peliculas.duracion);
    for(j=0; j<tg; j++)
    {
        if(generos[j].idGenero==peliculas.idGenero)
        {
            printf("%-10s\n",generos[j].genero);
        }
    }
}
void ordenarActoresApellidoNombre(eActores actores[], int tam)
{
    int i;
    int j;
    eActores auxActor;

    for(i=0; i<tam-1; i++)
    {
        if(actores[i].estado==OCUPADO)
        {
            for(j=i+1; j<tam; j++)
            {
                if(actores[j].estado==OCUPADO)
                {
                    if(strcmp(actores[i].nombre,actores[j].nombre)>0)
                    {
                        auxActor = actores[i];
                        actores[i] = actores[j];
                        actores[j] = auxActor;
                    }

                    else
                    {
                        if(strcmp(actores[i].nombre,actores[j].nombre)==0)
                        {
                            if(strcmp(actores[i].nombre,actores[j].nombre)>0)
                            {
                                auxActor = actores[i];
                                actores[i] = actores[j];
                                actores[j] = auxActor;
                            }
                        }
                    }
                }
            }
        }

    }

}

void menuActores(eActores actores[],int TA)
{
    system("cls");
    int opcion;
    do
    {
        while((getIntValid(&opcion,"1.Alta\n2-Baja\n3-Modificar\n4-listar\n5-Salir\n","Error",1,5))==-1);
        switch(opcion)
        {
        case 1:
            agregarActor(actores,TA);
            break;
        case 2:
            modificarActor(actores,TA);
            break;
        case 3:
            bajarActor(actores,TA);
            break;
        case 4:
            mostrarListaActores(actores,TA);
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
