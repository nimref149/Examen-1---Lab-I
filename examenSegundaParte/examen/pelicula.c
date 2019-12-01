#include <stdlib.h>
#include <stdio.h>
#include "pelicula.h"
#include "input.h"
#include <string.h>
/*
void hardcodearFechas(eFecha fechas[],int tamF)
{
    int dia[]={11,5,4,3,8,4,6,9,8,5};
    int mes[]={12,11,13,14,15,16,18,17,19,14};
    int anio[]={1995,2001,2004,1999,2006,2003,2008,2004,2007,2010};
    int idFecha[]={1,2,3,4,5,6,7,8,9,10};
    int i;
    for(i=0; i<tamF; i++)
    {
        fechas[i].dia=dia[i];
        fechas[i].mes=mes[i];
        fechas[i].anio=anio[i];
        fechas[i].idFecha=idFecha[i];
    }

}
*/

//void menuPeliculas(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,eFecha fecha[],int tamF)
void menuPeliculas(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG)
{
    system("cls");
    int retorno;
    int opcion;
    do
    {
    while((getIntValid(&opcion,"****Peliculas****\n1.Alta de pelicula\n2-Modificar pelicula\n3-Baja de pelicula\n4-listar peliculas\n5-Salir\n","Error",1,5))==-1);
    switch(opcion){
    case 1:
        retorno=agregarPelicula(peliculas,tamP,generos,tamG);
        switch(retorno)
        {
        case -1:
            printf("No hay lugar libre\n");
            break;
        case 0:
            printf("Carga cancela por el usuario\n");
            break;
        case 1:
            printf("Se cargo la pelicula con exito\n");
            break;
        }
        break;
    case 2:
        retorno=modificarPelicula(peliculas,tamP,generos,tamG);
        switch(retorno)
        {
        case -1:
            printf("No se encuentra el id ingresado\n");
            break;
        case 0:
            printf("Modificacion cancelada\n");
            break;
        case 1:
            printf("Se ha modificado correctamente\n");
            break;
        }
        break;
    case 3:
        retorno=bajarPelicula(peliculas,tamP,generos,tamG);
        switch(retorno)
        {
        case -2:
            printf("No hay peliculas cargadas\n");
            break;
        case -1:
            printf("No se encontro la pelicula\n");
            break;
        case 0:
            printf("Accion cancelada\n");
            break;
        case 1:
            printf("Se dio de baja la pelicula correctamente\n");
            break;
        }
        break;
    case 4:
        mostrarListaPeliculas(peliculas,tamP,generos,tamG);
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

void hardcodearPeliculas(ePeliculas peliculas[],int TP)
{
    int codigo[]= {1,2,3,4,5,6,7,8,9,10};
    char descripcion[][31]= {"Avengers","Duro de matar","Chuky","Titanic","Saw","Watchmen","Matrix","Jumper","Ella y yo","Primera cita"};
    int idGenero[]= {1,1,2,3,2,1,4,4,3,3};
    float duracion[]= {1.30,1.50,2.50,3.00,2.00,3.00,1.50,1.50,1.35,1.25};
    int i;
    //int idFecha[]={1,2,3,4,5,6,7,8,9,10};
    int dia[]={2,8,15,12,14,17,18,19,15,20};
    int mes[]={1,5,3,11,12,8,9,7,5,6};
    int anio[]={1995,2001,2004,1999,2006,2003,2008,2004,2007,2010};
    for(i=0; i<TP; i++)
    {
        peliculas[i].codigo =codigo[i];
        strcpy(peliculas[i].titulo,descripcion[i]);
        peliculas[i].duracion = duracion[i];
        peliculas[i].idGenero =idGenero[i];
        peliculas[i].estado=OCUPADO;
        //peliculas[i].idFecha=idFecha[i];
        peliculas[i].fechas.dia=dia[i];
        peliculas[i].fechas.mes=mes[i];
        peliculas[i].fechas.anio=anio[i];
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

void mostrarListaPeliculas(ePeliculas peliculas[], int tamP,eGeneros generos[],int tg)
{
    int i;
    printf("Listado de peliculas\n");
    printf("id    |   pelicula  \t\t   | duracion \t   | genero \n");
    for(i=0; i<tamP; i++)
    {
        if(peliculas[i].estado==OCUPADO)
        {
            mostrarUnaPelicula(peliculas[i],generos,tg);
        }

    }
}

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

void mostrarUnaPeliculaConFecha(ePeliculas peliculas,eGeneros generos[],int tg)
{
    int j;
    printf("%-5d |\t %-25s |\t %-10.02f |\t %d/%d/%d ",peliculas.codigo,peliculas.titulo,peliculas.duracion,peliculas.fechas.dia,peliculas.fechas.mes,peliculas.fechas.anio);
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
    int retorno=0;
    int opcion;
    ePeliculas auxPelicula;
    printf("Se modificara la siguiente pelicula\n");
    printf("Codigo|   titulo  | duracion |  genero \n");
    mostrarUnaPelicula(peliculas[i],generos,tamG);
    while((getIntValid(&opcion,"Escoja el campo a modificar: \n1.Tituto\n2.Duracion\n3.Genero\n4.Salir\n","Error",1,4))==-1);
    switch(opcion)
    {
    case 1:
        while((getStringLetras(auxPelicula.titulo,"Ingrese nuevo titulo de pelicula: ","Error",1,31))==-1);
        if((confirm("Desea confirmar? S o N"))==1)
        {
            strcpy(peliculas[i].titulo, auxPelicula.titulo);
            retorno=1;
        }
        break;
    case 2:
        while((getFloatValid(&auxPelicula.duracion,"Ingrese nueva duracion: ","Error",1,5))==-1);
        if((confirm("Desea confirmar? S o N"))==1)
        {
            peliculas[i].duracion=auxPelicula.duracion;
            retorno=1;
        }
        break;
    case 3:
        mostrarListaGeneros(generos,tamG);
        while((getIntValid(&auxPelicula.idGenero,"Ingrese nuevo genero: ","Error",1,tamG))==-1);
        if((confirm("Desea confirmar? S o N"))==1)
        {
            peliculas[i].idGenero=auxPelicula.idGenero;
            retorno=1;
        }
        break;
    case 4:
        printf("Saliendo\n");
        retorno=0;
        break;
    }
    return retorno;
}

void mostrarListaGeneros(eGeneros generos[],int tam)
{
    int i;
    printf("Lista de generos\n");
    printf("ID     GENERO  \n");
    for(i=0;i<tam;i++)
    {
        printf("%-5d      %-10s\n",generos[i].idGenero,generos[i].genero);
    }
}

int agregarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG)
{
    int retorno;
    int i;
    ePeliculas auxPelicula;
    i=buscarLibrePelicula(peliculas,tamP);
    if(i!=-1)
    {
        auxPelicula=cargarPelicula(peliculas,tamP,generos,tamG);
        mostrarUnaPelicula(auxPelicula,generos,tamG);
        if(confirm("Desea cargar la pelicula? S/N\n")==1)
        {
            retorno=1;
            peliculas[i]=auxPelicula;
        }
        else
        {
            retorno=0;
        }
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}
ePeliculas cargarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG)
{
    ePeliculas auxPelicula;
    auxPelicula.codigo=autoIdPeliculas(peliculas,tamP,1);
    while((getStringLetras(auxPelicula.titulo,"Ingrese nombre de la pelicula: ","Error, solo entre 1 y 31 caracteres",1,52))==-1);
    mostrarListaGeneros(generos,tamG);
    while((getIntValid(&auxPelicula.idGenero,"Ingrese genero de la pelicula","Error",1,tamG))==-1);
    while((getFloatValid(&auxPelicula.duracion,"Ingrese duracion de la pelicula ","Error",1,5))==-1);
    auxPelicula.estado=OCUPADO;
    return auxPelicula;
}



int modificarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG){

    int retorno;
    int opcion;
    int idA;
    int idMayor;
    idMayor=buscarIdMayorPelicula(peliculas,tamP);
    mostrarListaPeliculas(peliculas,tamP,generos,tamG);
    while((getIntValid(&idA,"Ingrese id de la pelicula a modificar: ","Error",1,idMayor))==-1);
    opcion=findPeliculaById(peliculas,tamP,idA);
    if(opcion!=-1)
    {
        retorno=menuModificarPeli(peliculas,tamP,generos,tamG,opcion);
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}
int bajarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG)
{
    int idP;
    int retorno=-2;
    int idMayor;
    int loEncontro;
    idMayor=buscarIdMayorPelicula(peliculas,tamP);
    if(idMayor!=-1)
    {
        mostrarListaPeliculas(peliculas,tamP,generos,tamG);
        while((getIntValid(&idP,"Ingrese id de pelicula a eliminar: ","Error",1,idMayor))==-1);
        loEncontro=findPeliculaById(peliculas,tamP,idP);
        if(loEncontro!=-1)
        {
            printf("Se dara de baja la siguiente pelicula:\n");
            mostrarUnaPelicula(peliculas[loEncontro],generos,tamG);
            if((confirm("Desea confirmar? S o N\n"))==1)
            {
                peliculas[loEncontro].estado=LIBRE;
                retorno=1;
            }
            else
            {
                retorno=0;
            }
        }
        else
        {
            retorno=-1;
        }
    }
    return retorno;
}
void inicializarCodigoPeliculas(ePeliculas peliculas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        peliculas[i].codigo= LIBRE;
    }
}
void inicializarPeliculas(ePeliculas peliculas[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        peliculas[i].estado= LIBRE;
    }
}

int buscarLibrePelicula(ePeliculas peliculas[],int tam){
    int i;
    for(i=0; i<tam; i++)
    {
        if(peliculas[i].estado == LIBRE)
        {
            return i;
        }
    }
    return -1;
}
int autoIdPeliculas(ePeliculas peliculas[],int tam,int index)
{
    int retorno;
    int idMayor;
    idMayor=buscarIdMayorPelicula(peliculas,tam);
    if(idMayor!=-1)
    {
        retorno=idMayor+1;
    }
    else
    {
        retorno=index;
    }
    return retorno;
}

int buscarIdMayorPelicula(ePeliculas lista[],int tam)
{
    int retorno=-1;
    int i;
    int flag=0;
    int mayor1=0;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(lista[i].codigo>mayor1 || flag==0)
            {
                mayor1=lista[i].codigo;
                flag=1;
            }
        }
    }
    if(flag!=0)
    {
        retorno=mayor1;
    }
    return retorno;
}
int contadorPeliculas(ePeliculas peliculas[],int tam)
{
    int i;
    int contador=0;
    for(i=0; i<tam; i++)
    {
    if(peliculas[i].estado==OCUPADO)
    {
        contador++;
    }
    }
return contador;
}
int mostrarPeliculaPorId(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,int id)
{
    int retorno=-1;
    int respuesta;
    respuesta=findPeliculaById(peliculas,tamP,id);
    if(respuesta!=-1)
    {
        mostrarUnaPelicula(peliculas[respuesta],generos,tamG);
        retorno=0;
    }
    return retorno;
}


void mostrarPeliculasAnioTerror(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG)
{
    //int idFecha;
    int i;
    int flag=0;
    for(i=0; i<tamP; i++)
    {
        if(peliculas[i].estado==OCUPADO&&peliculas[i].idGenero==2)
        {
            //idFecha=buscarPorIdFecha(fechas,tamF,peliculas[i].idFecha);

            //if(fechas[idFecha].anio>2002)
            if(peliculas[i].fechas.anio<2002)
            {
                //mostrarUnaPelicula(peliculas[i],generos,tamG);
                mostrarUnaPeliculaConFecha(peliculas[i],generos,tamG);
                //printf("El anio de estreno es %d\n",fechas[idFecha].anio);
                printf("------------------------------------------------------------\n");
                flag=1;
            }
        }
    }
    if(flag==0){
    printf("No se encontraron peliculas con el anio despues a 2002\n");

    }
}
/*
    int buscarPorIdFecha(eFecha fechas[],int tamF,int id)
    {
        int retornoo=0;
        int i;
        for(i=0; i<tamF; i++)
        {
            if(fechas[i].idFecha==id)
            {
                retornoo=i;
            }
        }
    return retornoo;

    }
*/
