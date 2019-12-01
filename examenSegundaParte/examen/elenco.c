#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actores.h"
#include "pelicula.h"
#include "input.h"
#include "elenco.h"



void hardcodearElenco(eElenco elencos[],int tamE)
{
    int idActor[]= {3,3,3,3};
    int idPelicula[]= {1,2,3,4};
    float valor[]= {1400,180,169,500};
    int i;
    for(i=0; i<tamE; i++)
    {
        elencos[i].codigoActor=idActor[i];
        elencos[i].codigoPelicula=idPelicula[i];
        elencos[i].valorContrato=valor[i];
        elencos[i].estado=OCUPADO;
    }
}



void menuElenco(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPE)
{
    system("cls");
    int opcion;
    int retorno;
    do
    {
        while((getIntValid(&opcion,"**Menu elencos**\n1-Dar de alta elenco\n2-Listar Elencos ordenados por pelicula y actor\n3-Salir\nElija una opcion: \n","Error",1,3))==-1){
        system("pause");
        system("cls");
        }
        switch(opcion)
        {
        case 1:
            retorno=altaElencos(elenco,tamE,generos,tamG,peliculas,tamP,actores,tamA,paises,tamPE);
            switch(retorno)
            {
            case -3:
                printf("Actor y pelicula ya existen en un elenco\n");
                break;
            case -2:
                printf("No hay peliculas y actores ingresados\n");
                break;
            case -1:
                printf("No hay mas lugar\n");
                break;
            case 0:
                printf("Accion cancelada\n");
                break;
            case 1:
                printf("Se cargo el elenco  correctamente\n");
                break;
            }
            break;
        case 2:
            retorno=listarElencosOrdenados(elenco,tamE,peliculas,tamP,actores,tamA);
            switch(retorno)
            {
            case -1:
                printf("No hay elencos\n");
                break;
            case 1:
                printf("Elencos listados correctamente\n");
                break;
            }
            break;
        case 3:
            printf("Saliendo\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=3);

}
/*
int altaElencos(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    int i;
    int retorno;
    int auxCodigo;
    eElenco auxElenco;
    idMaxPeli=buscarIdMayorPelicula(peliculas,tamP);
    idMaxActor=buscarIdMayor(actores,tamA);
    i=buscarLibreElencos(elenco,tamE);
    if(i!=-1)
    {
        system("cls");
        mostrarListaPeliculas(peliculas,tamP,generos,tamG);
        while((getIntValid(&elenco[i].codigoPelicula,"Ingrese codigo de pelicula: ","Error",1,idMaxPeli))==-1);
        mostrarListaActores(actores,tamA);
        //while((getIntValid(&elenco[i].codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMax))==-1);
        while((getIntValid(&auxCodigo,"Ingrese codigo de actor para la pelicula: ","Error",1,idMaxActor))==-1);

        if(findActorById(actores,tamA,auxCodigo)==-1)
        {
            printf("No existe ese id\n");
            while((getIntValid(&auxCodigo,"Ingrese codigo de actor para la pelicula: ","Error",1,idMaxActor))==-1);
        }
        if((existeActorYpelicula(elenco,tamE,elenco[i].codigoPelicula,auxCodigo))==0)
        {
            elenco[i].codigoActor=auxCodigo;
            while((getFloatValid(&elenco[i].valorContrato,"Ingrese valor contrato: ","Error",1,100000))==-1);
            elenco[i].estado=OCUPADO;
        }
    }
    else
    {
        retorno=-1;
    }
}
*/
int altaElencos(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPE)
{
    int i;
    int retorno=-2;
    int idMaxPeli;
    int idMaxActor;
    eElenco auxElenco;
    if(contadorActores(actores,tamA)!=0&&contadorPeliculas(peliculas,tamP)!=0)
    {
        i=buscarLibreElencos(elenco,tamE);
        if(i!=-1)
        {
            idMaxPeli=buscarIdMayorPelicula(peliculas,tamP);
            idMaxActor=buscarIdMayor(actores,tamA);
            system("cls");

            mostrarListaPeliculas(peliculas,tamP,generos,tamG);
            while((getIntValid(&auxElenco.codigoPelicula,"Ingrese codigo de pelicula: ","Error",1,idMaxPeli))==-1);
            while(findPeliculaById(peliculas,tamP,auxElenco.codigoPelicula)==-1)
            {
                printf("No existe ese id\n");
                while((getIntValid(&auxElenco.codigoPelicula,"Ingrese codigo de pelicula : ","Error",1,idMaxActor))==-1);
            }

            mostrarListaActores(actores,tamA,paises,tamPE);
            while((getIntValid(&auxElenco.codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMaxActor))==-1);
            while(findActorById(actores,tamA,auxElenco.codigoActor)==-1)
            {
                printf("No existe ese id\n");
                while((getIntValid(&auxElenco.codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMaxActor))==-1);
            }

            if(existeActorYpelicula(elenco,tamE,auxElenco.codigoPelicula,auxElenco.codigoActor)==0)
            {
                while((getFloatValid(&auxElenco.valorContrato,"Ingrese valor contrato: ","Error",1,100000))==-1);
                auxElenco.estado=OCUPADO;
                if(confirm("Desea confirmar y cargar el elenco? S/N\n")==1)
                {
                    elenco[i]=auxElenco;
                    retorno=1;
                }
                else
                {
                    retorno=0;
                }
            }
            else
            {
                retorno=-3;
            }
        }
        else
        {
            retorno=-1;
        }
    }
    return retorno;
}
/*
int altaElencos(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    int i;
    int respuesta;
    int retorno=-2;
    eElenco auxElenco;
    if(contadorActores(actores,tamA)!=0&&contadorPeliculas(peliculas,tamP)!=0)
    {
        i=buscarLibreElencos(elenco,tamE);
        if(i!=-1)
        {
            system("cls");
            respuesta=cargarElenco(peliculas,tamP,generos,tamG,actores,tamA);
            if(confirm("Desea cargar el elenco? S/N\n")==1)
            {
                elenco[i]=auxElenco;
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
*/
//-------------------------------------
/*
eElenco cargarElenco(eElenco elencos[],int tamE,ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,eActores actores[],int tamA)
{
    int idMaxPeli;
    int idMaxActor;
    eElenco auxElenco;
    idMaxPeli=buscarIdMayorPelicula(peliculas,tamP);
    idMaxActor=buscarIdMayor(actores,tamA);

    mostrarListaPeliculas(peliculas,tamP,generos,tamG);
    while((getIntValid(&auxElenco.codigoPelicula,"Ingrese codigo de pelicula: ","Error",1,idMaxPeli))==-1);
    if(findPeliculaById(peliculas,tamP,auxElenco.codigoPelicula)==-1)
    {
        printf("No existe ese id\n");
        while((getIntValid(&auxElenco.codigoPelicula,"Ingrese codigo de pelicula : ","Error",1,idMaxActor))==-1);
    }

    mostrarListaActores(actores,tamA);
    while((getIntValid(&auxElenco.codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMaxActor))==-1);

    if(findActorById(actores,tamA,auxElenco.codigoActor)==-1)
    {
        printf("No existe ese id\n");
        while((getIntValid(&auxElenco.codigoActor,"Ingrese codigo de actor para la pelicula: ","Error",1,idMaxActor))==-1);
    }

    if(existeActorYpelicula(elenco,tamE,auxElenco.codigoPelicula,auxElenco.codigoActor)!=-1)
    {
        while((getFloatValid(&auxElenco.valorContrato,"Ingrese valor contrato: ","Error",1,100000))==-1);
        auxElenco.estado=OCUPADO;
    }
    else
    {
        return -1;
    }
    return auxElenco;
}
*/
//----------------------------------------------

int existeActorYpelicula(eElenco elencos[],int tam,int idP,int idA)
{
    int i;
    int retorno=0;
    for(i=0; i<tam; i++)
    {
        if(elencos[i].estado==OCUPADO)
        {
            if(elencos[i].codigoActor==idA&&elencos[i].codigoPelicula==idP)
            {
                printf("\nYa existe una pelicula asociado con ese id de actor\n");
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
        if(elenco[i].estado==OCUPADO)
        {
            for(j=i+1; j<tamE; j++)
            {
                if(elenco[j].estado==OCUPADO)
                {
                    peli1=findPeliculaById(peliculas,tamP,elenco[i].codigoPelicula);
                    peli2=findPeliculaById(peliculas,tamP,elenco[j].codigoPelicula);

                    if(stricmp(peliculas[peli1].titulo,peliculas[peli2].titulo)>0)
                    {
                        auxElenco =elenco[i];
                        elenco[i] = elenco[j];
                        elenco[j] =auxElenco;
                    }
                    else
                    {
                        if(stricmp(peliculas[peli1].titulo,peliculas[peli2].titulo)==0)
                        {
                            actor1=findActorById(actores,tamA,elenco[i].codigoActor);
                            actor2=findActorById(actores,tamA,elenco[j].codigoActor);
                            if(stricmp(actores[actor1].nombre,actores[actor2].nombre)>0)
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
    }
}


//-------------------------------------------------
int contadorElencos(eElenco elencos[],int tam)
{
    int i;
    int contador=0;
    for(i=0;i<tam;i++)
    {
        if(elencos[i].estado==OCUPADO){
        contador++;
        }
    }
    return contador;
}

int listarElencosOrdenados(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    ordenarElencosPeliculasActor(elenco,tamE,peliculas,tamP,actores,tamA);
    int retorno;
    int i;
    if(contadorElencos(elenco,tamE)!=0)
    {
        printf("------------------------------------------------------------------------\n");
        printf("        Pelicula           |         Actor         |    valor contrato \n");
        printf("------------------------------------------------------------------------\n");
        for(i=0; i<tamE; i++)
        {
            if(elenco[i].estado==OCUPADO)
            {
                mostrarUnElenco(elenco[i],peliculas,tamP,actores,tamA);
                retorno=1;
            }
        }
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}


void mostrarUnElenco(eElenco elenco,ePeliculas peliculas[],int tamP,eActores actores[],int tamA)
{
    int idPeli;
    int idActor;
    idPeli=findPeliculaById(peliculas,tamP,elenco.codigoPelicula);
    idActor=findActorById(actores,tamA,elenco.codigoActor);
    if(idPeli!=-1&&idActor!=-1)
    {
        printf("%-25s  | ",peliculas[idPeli].titulo);
        printf("%-10s ",actores[idActor].nombre);
        printf("%-10s |",actores[idActor].apellido);
        printf("    %-5.02f\n",elenco.valorContrato);
        printf("------------------------------------------------------------------------\n");
    }
}


//--------------------------------------------------------------------
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
//fijarse bien el  prototipo cuando dice el error ->> name ommited
/*
void menuInformes(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,eFecha fechas[],int tamF,eActores actores[],int tamA,eElenco elencos[],int tamE,ePais paises[],int tamPA)
{
    int opcion;

    do
    {

        while(getIntValid(&opcion,"Informes\n1-Peliculas de terror anio despues de 2002\n2-Peliculas con actor argentino\n3-Peliculas que participo actor seleccionado\n4-Actor con recaudacion en pelis romanticas\n5-Actores sin particion en pelis\n6-salir\n","Error",1,6)==-1);

        switch(opcion)
        {

        case 1:
            mostrarPeliculasAnioTerror(peliculas,tamP,generos,tamG,fechas,tamF);
            break;
        case 2:
            listarPelisActorArgentino(elencos,tamE,peliculas,tamP,actores,tamA,paises,tamPA);
            break;
        case 3:
            listarPelisActorSeleccionado(elencos,tamE,peliculas,tamP,actores,tamA,paises,tamPA);
            break;
        case 4:
            listarPelisActorRomanticas(elencos,tamE,peliculas,tamP,actores,tamA,paises,tamPA);
            break;
        case 5:
            listarActoresSinPeli(elencos,tamE,peliculas,tamP,actores,tamA,paises,tamPA);
            break;
        case 6:
            printf("Saliendo\n");
            break;

        }
        system("pause");
        system("cls");
    }
    while(opcion!=6);

}
*/
void menuInformes(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,eActores actores[],int tamA,eElenco elencos[],int tamE,ePais paises[],int tamPA)
{
    system("cls");
    int opcion;
    do
    {
        while(getIntValid(&opcion,"Informes\n1-Peliculas de terror, anio estreno despues de 2002\n2-Peliculas con actor argentino\n3-Peliculas que participo actor seleccionado\n4-Actor con recaudacion en pelis romanticas\n5-Actores sin particion en pelis\n6-salir\n","Error",1,6)==-1);
        switch(opcion)
        {
        case 1:
            mostrarPeliculasAnioTerror(peliculas,tamP,generos,tamG);

            break;
        case 2:
            listarPelisActorArgentino(elencos,tamE,peliculas,tamP,actores,tamA,paises,tamPA);

            break;
        case 3:
            listarPelisActorSeleccionado(elencos,tamE,peliculas,tamP,actores,tamA,paises,tamPA);

            break;
        case 4:
            listarPelisActorRomanticas(elencos,tamE,peliculas,tamP,actores,tamA,paises,tamPA);

            break;
        case 5:
            listarActoresSinPeli(elencos,tamE,peliculas,tamP,actores,tamA,paises,tamPA);

            break;
        case 6:
            printf("Saliendo\n");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=6);
}

///me equivoque en la variable en el for en ves de j , puse i
void listarPelisActorArgentino(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPA)
{
    int peli;
    int i;
    int actor;
    int j;
    int flag=0;
    if(contadorElencos(elenco,tamE)!=0)
    {
        printf("-------------------------------------------------------------------------\n");
        printf("        Peliculas donde el actor es argentino                            |\n");
        printf("-------------------------------------------------------------------------\n");
        //printf("Peliculas cuyo actor sea argentina\n");
        for(i=0; i<tamE; i++)
        {
            if(elenco[i].estado==OCUPADO)
            {
                peli=findPeliculaById(peliculas,tamP,elenco[i].codigoPelicula);
                actor=findActorById(actores,tamA,elenco[i].codigoActor);

                if(actores[actor].idPais==1)
                {
                    printf("%s---",peliculas[peli].titulo);
                    printf("%s---",actores[actor].nombre);
                    for(j=0; j<tamPA; j++)
                    {
                        if(actores[actor].idPais==paises[j].idPais)
                        {
                            printf("%s\n",paises[j].descripcion);
                        }

                    }
                    flag=1;
                }
            }

        }
        if(flag==0){
        printf("No se encontraron pelis con actor argentino\n");
        }
    }
}

void listarPelisActorSeleccionado(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPA)
{
    int peli;
    int i;
    int actor;
    //int j;
    int flag=0;
    int actorSeleccionado;
    int actorIdSeleccionado=0;
    if(contadorElencos(elenco,tamE)!=0)
    {
        printf("--------------------------------------------------------------------------\n");
        printf("        Seleccione actor:        |\n");
        printf("--------------------------------------------------------------------------\n");
        mostrarListaActores(actores,tamA,paises,tamPA);
        getIntValid(&actorSeleccionado,"Ingrese id de actor: ","Error",1,tamA);
        actorIdSeleccionado=findActorById(actores,tamA,actorSeleccionado);
        printf("Listado de peliculas\n");
        for(i=0; i<tamE; i++)
        {
            if(elenco[i].estado==OCUPADO)
            {
                peli=findPeliculaById(peliculas,tamP,elenco[i].codigoPelicula);
                actor=findActorById(actores,tamA,elenco[i].codigoActor);

                if(actores[actor].codigo==actores[actorIdSeleccionado].codigo)
                {
                    printf("%-15s\t",peliculas[peli].titulo);
                    printf("%-10s\n",actores[actor].nombre);
                    flag=1;

                }

            }
        }
        if(flag==0){
        printf("El actor no esta en ninguna pelicula\n");
        }
    }
}
void listarPelisActorRomanticas(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPA)
{
    int peli;
    int i;
    int actor;
    float contador=0;
    //int j;
    int actorSeleccionado;
    int actorIdSeleccionado=0;
    if(contadorElencos(elenco,tamE)!=0)
    {
        printf("--------------------------------------------------------------------------\n");
        printf("Recaudacion de actor en peliculas romanticas\n");
        printf("Seleccione actor: \n");
        printf("--------------------------------------------------------------------------\n");
        mostrarListaActores(actores,tamA,paises,tamPA);
        getIntValid(&actorSeleccionado,"Ingrese id de actor: ","Error",1,tamA);
        actorIdSeleccionado=findActorById(actores,tamA,actorSeleccionado);
        for(i=0; i<tamE; i++)
        {
            if(elenco[i].estado==OCUPADO)
            {
                peli=findPeliculaById(peliculas,tamP,elenco[i].codigoPelicula);
                actor=findActorById(actores,tamA,elenco[i].codigoActor);

                if(actores[actor].codigo==actores[actorIdSeleccionado].codigo)
                {
                    if(peliculas[peli].idGenero==3)
                    {
                        contador=contador+elenco[i].valorContrato;

                    }

                }

            }
        }
        printf("La recaudacion del actor seleccionado es : %.02f\n",contador);

    }
}
void listarActoresSinPeli(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPA)
{
    int i;
    int j;
    int flag=0;
    if(contadorElencos(elenco,tamE)!=0)
    {
        printf("--------------------------------------------------------------------------\n");
        printf("Lista de actores sin participacion: \n");
        printf("--------------------------------------------------------------------------\n");
        for(j=0; j<tamA; j++)
        {
            if(actores[j].estado==OCUPADO)
            {
                for(i=0; i<tamE; i++)
                {
                    if(elenco[i].estado==OCUPADO)
                    {
                        /*
                        if(elenco[i].codigoActor!=actores[j].codigo)
                        {
                            flag=1;

                        }
                        */

                        if(elenco[i].codigoActor==actores[j].codigo)
                        {
                            flag=1;

                        }

                    }
                }
                /*
                if(flag==1)
                {
                    printf("%-10s\t",actores[j].nombre);
                    printf("%-10s\n",actores[j].apellido);
                    flag=0;
                }
                */
                if(flag==1)
                {
                    flag=0;
                }
                else
                {
                    printf("%-10s\t",actores[j].nombre);
                    printf("%-10s\n",actores[j].apellido);
                }
                /*
                if(flag!=1)
                {
                    printf("%-10s\t",actores[j].nombre);
                    printf("%-10s\n",actores[j].apellido);
                }
                flag=0;
                */

            }
        }

    }
}




