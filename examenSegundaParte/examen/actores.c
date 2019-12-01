#include "actores.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**funciones que faltan
mostrar actor por id
mostrarDatosUnActor+
que pasa si elimino a todos los actores,hacer una funcion if que no me deje entrar en eliminar actores
obtener un actor-validar un actor

*/
void hardcodearPaises(ePais paises[],int tamP)
{
    int idPais[]={1,2,3,4,5,6,7,8,9,10};
    char descripcion[][15]={"argentina","china","cuba","suecia","holanda","alemania","belgica","francia","iran","italia"};
    int i;
    for(i=0;i<tamP;i++)
    {
        strcpy(paises[i].descripcion,descripcion[i]);
        paises[i].idPais=idPais[i];
    }
}
void mostrarPaises(ePais paises[],int tamP)
{
    int i;

    for(i=0; i<tamP;i++)
    {
        mostrarUnPais(paises[i]);
    }
}

void mostrarUnPais(ePais paises){
printf("%-5d %-10s\n",paises.idPais,paises.descripcion);
}



void mostrarActorCompleto(eActores actores,ePais paises[],int tamP ){
printf("Nombre | Apellido | Sexo  |  pais  \n");
mostrarActor(actores,paises,tamP);
}
int obtenerUnActor(eActores actores[],int tam,ePais paises[],int tamP)
{
    int index;
    int idMax;
    idMax=buscarIdMayor(actores,tam);
    printf("Lista de actores: \n");
    mostrarListaActores(actores,tam,paises,tamP);
    while((getIntValid(&index,"Ingrese id de actor: \n","Error",1,idMax))==-1);
    while(findActorById(actores,tam,index)==-1)
    {
        printf("No existe ese id\n");
        while((getIntValid(&index,"Ingrese id de actor: \n","Error",1,idMax))==-1);
    }
    return index;
}

void menuActores(eActores actores[],int TA,ePais paises[],int TPI)
{
    system("cls");
    int opcion;
    int retorno;
    do
    {
        while(getIntValid(&opcion,"****MENU GESTION ACTORES****\n1.Alta\n2-Modificar\n3-Baja\n4-listar\n5-Salir\n","Error",1,5)==-1){
        system("pause");
        system("cls");
        }
        switch(opcion)
        {
        case 1:
            retorno=agregarActor(actores,TA,paises,TPI);
            switch(retorno)
            {
            case -1:
                printf("No hay mas espacio\n");
                break;
            case 1:
                printf("Actores agregados con exito\n");
                break;
            }
            break;
        case 2:
            retorno=modificarActor(actores,TA,paises,TPI);
            switch(retorno)
            {
            case -1:
                printf("No se a encontrado el id a modificar\n");
                break;
            case 0:
                printf("Modificacion cancelada\n");
                break;
            case 1:
                printf("Se ha modificado con exito!\n");
                break;
            case 2:
                printf("No hay actores ingresados\n");
                break;
            }
            break;
        case 3:
            retorno=bajaActor(actores,TA,paises,TPI);
            switch(retorno)
            {
            case -2:
                printf("No hay actores ingresados\n");
                break;
            case -1:
                printf("No se encontro el actor\n");
                break;
            case 0:
                printf("Baja de actor cancelada\n");
                break;
            case 1:
                printf("Se elimino el actor correctamente\n");
                break;
            }
            break;
        case 4:
            retorno=mostrarListaActoresOrdenados(actores,TA,paises,TPI);
            switch(retorno){
            case -1:
                printf("No hay actores para ordenar\n");
                break;
            case 1:
                printf("Listado ordenado correctamente\n");
                break;
            }
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
/*
int agregarActor(eActores actores[],int ta)
{
    int i;
    int retorno;
    i=buscarLibre(actores,ta);
    if(i!=-1)
    {
        actores[i].codigo=autoId(actores,ta);
        do
        {
            while((getStringLetras(actores[i].nombre,"Ingrese nombre del actor: ","Error, solo entre 1 y 51 caracteres",1,52))==-1);
            while((getStringLetras(actores[i].apellido,"Ingese apellido del actor: ","Error, solo entre 1 y 51 caracteres",1,51))==-1);
            while((getCharValidOpciones(&actores[i].sexo,"Ingrese sexo F o M: ","Error",'m','f'))==-1);
            actores[i].estado=OCUPADO;
            mostrarActor(actores[i]);
        }
        while((confirm())==0);
        retorno=1;
    }
    else
    {
        retorno=-1;
        //printf("No hay lugar disponible\n");
    }
    return retorno;
}
*/
//--------------------------------

int agregarActor(eActores actores[],int ta,ePais paises[],int tp)
{
    int i;
    int retorno;
    int continuar;
    eActores auxActor;
    do
    {
        if(buscarLibreActor(actores,ta)!=-1)
        {
            i=buscarLibreActor(actores,ta);
            /*
            auxActor.codigo=autoId(actores,ta);
            while((getStringLetras(auxActor.nombre,"Ingrese nombre del actor: ","Error, solo entre 1 y 51 caracteres",1,52))==-1);
            while((getStringLetras(auxActor.apellido,"Ingese apellido del actor: ","Error, solo entre 1 y 51 caracteres",1,51))==-1);
            while((getCharValidOpciones(&auxActor.sexo,"Ingrese sexo F o M: ","Error",'m','f'))==-1);
            auxActor.estado=OCUPADO;
            */
            auxActor=cargarActor(actores,ta,paises,tp);
            //mostrarActor(auxActor);
            mostrarActorCompleto(auxActor,paises,tp);
            if(confirm("Desea confirmar ? S/N\n")==1)
            {
                actores[i]=auxActor;
                printf("Actor agregado correctamente\n");
                retorno=1;
            }
            else
            {
                retorno=0;
            }
            continuar=confirm("Desea ingresar otro actor ? s=SI n=NO\n");
            system("cls");
        }
        else
        {
            continuar=-1;
            retorno=-1;
        }
    }
    while(continuar==1);

    return retorno;
}

eActores cargarActor(eActores actores[],int ta,ePais paises[],int tp)
{
    eActores auxActor;
    auxActor.codigo=autoId(actores,ta,1);
    while((getStringLetras(auxActor.nombre,"Ingrese nombre del actor: ","Error, solo letras entre 1 y 51 caracteres.",1,52))==-1);
    while((getStringLetras(auxActor.apellido,"Ingese apellido del actor: ","Error, solo letras entre 1 y 51 caracteres.",1,51))==-1);
    while((getCharValidOpciones(&auxActor.sexo,"Ingrese sexo F o M: ","Error.",'m','f'))==-1);
    mostrarPaises(paises,tp);
    while(getIntValid(&auxActor.idPais,"Ingrese id de pais al actor: ","Error.",1,10)==-1);
    auxActor.estado=OCUPADO;
    return auxActor;
}



//--------------------------------
int buscarLibreActor(eActores actores[],int tp)
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
void inicializarCodigoActores(eActores actores[],int ta)
{
    int i;
    for(i=0; i<ta; i++)
    {
        actores[i].codigo=LIBRE;
    }
}
void inicializarActores(eActores actores[],int ta)
{
    int i;
    for(i=0; i<ta; i++)
    {
        actores[i].estado= LIBRE;
    }
}
/*
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
*/
int autoId(eActores lista[],int tam,int inicio)
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
        retorno=inicio;
    }

    return retorno;
}
int buscarIdMayor(eActores lista[],int tam)
{
    int retorno=-1;
    int i;
    int flag=0;
    int mayor=0;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(lista[i].codigo>mayor)
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
int menuModificar(eActores actores[],int tam,int i,ePais paises[],int tamP)
{
    int retorno=0;
    int opcion;
    eActores auxActor;
    printf("Se modificara el siguiente actor\n");
    printf("Codigo|   Nombre  |   Apellido | Sexo |    pais \n");
    mostrarActor(actores[i],paises,tamP);
    while((getIntValid(&opcion,"Escoja el campo a modificar:\n1.Nombre\n2.Apellido\n3.Sexo\n4.Salir\n","Error",1,4))==-1);
    switch(opcion)
    {
    case 1:
        while((getStringLetras(auxActor.nombre,"Ingrese nuevo nombre: ","Error",1,51))==-1);
        if((confirm("Desea confirmar?"))==1)
        {
            strcpy(actores[i].nombre, auxActor.nombre);
            retorno=1;
        }
        break;
    case 2:
        while((getStringLetras(auxActor.apellido,"Ingrese nuevo apellido: ","Error",1,51))==-1);
        if((confirm("Desea confirmar?"))==1)
        {
            strcpy(actores[i].apellido, auxActor.apellido);
            retorno=1;
        }
        break;
    case 3:
        while((getCharValidOpciones(&auxActor.sexo,"Ingrese nuevo sexo F o M: ","Error",'F','M'))==-1);
        if((confirm("Desea confirmar?"))==1)
        {
            actores[i].sexo=auxActor.sexo;
            retorno=1;
        }
        break;
    case 4:
        mostrarPaises(paises,tamP);
        while(getIntValid(&auxActor.idPais,"Ingrese nuevo pais: ","Error",1,10)==-1);
        if((confirm("Desea confirmar?"))==1)
        {
            actores[i].idPais=auxActor.idPais;
            retorno=1;
        }
        break;
    case 5:
        printf("Saliendo\n");
        retorno=0;
        break;
    }
    return retorno;
}
void mostrarActor(eActores unActor,ePais paises[],int tamP)
{
    printf("%-5d | %-10s | %-10s  |  %c  |",unActor.codigo,unActor.nombre,unActor.apellido,unActor.sexo);
    int i;
    for(i=0; i<tamP; i++)
    {
        if(unActor.idPais==paises[i].idPais)
        {
            printf("%s\n",paises[i].descripcion);
        }
    }
}

int bajaActor(eActores actores[],int tam,ePais paises[],int tamP)
{
    int retorno=-2;
    int idP;
    int loEncontro;
    if(contadorActores(actores,tam)!=0)
    {
        printf("Lista de actores\n");
        mostrarListaActores(actores,tam,paises,tamP);
        int idMax=buscarIdMayor(actores,tam);
        while((getIntValid(&idP,"Ingrese id de actor a dar de baja","Error",1,idMax))==-1);
        loEncontro=findActorById(actores,tam,idP);
        if(loEncontro!=-1)
        {
            printf("Se dara de baja el siguiente actor:\n");
            mostrarActor(actores[loEncontro],paises,tamP);
            if((confirm("Esta seguro? S/N\n"))==1)
            {
                actores[loEncontro].estado=LIBRE;
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

int mostrarListaActoresOrdenados(eActores actores[], int ta,ePais paises[],int tamP)
{
    int retorno;
    retorno=ordenarActoresApellidoNombre(actores,ta);
    if(retorno!=-1)
    {
        mostrarListaActores(actores,ta,paises,tamP);
    }

    return retorno;
}
void mostrarListaActores(eActores actores[], int ta,ePais paises[],int tamP)
{
    int i;
    printf("Listado de actores\n");
    printf("Codigo|   Nombre   |    Apellido | Sexo|  pais  \n");
    for(i=0; i<ta; i++)
    {
        if(actores[i].estado!=LIBRE)
        {
            mostrarActor(actores[i],paises,tamP);
        }
    }
}
int ordenarActoresApellidoNombre(eActores actores[], int tam)
{
    int retorno=-1;
    int i;
    int j;
    eActores auxActor;
    if(contadorActores(actores,tam)!=0)
    {
        for(i=0; i<tam-1; i++)
        {
            //if(actores[i].estado==OCUPADO)
            //{
            for(j=i+1; j<tam; j++)
            {
                if(actores[j].estado==OCUPADO&&actores[i].estado==OCUPADO)
                {
                    if(stricmp(actores[i].nombre,actores[j].nombre)>0)
                    {
                        auxActor = actores[i];
                        actores[i] = actores[j];
                        actores[j] = auxActor;
                    }

                    else
                    {
                        if(strcmp(actores[i].nombre,actores[j].nombre)==0)
                        {
                            if(stricmp(actores[i].apellido,actores[j].apellido)>0)
                            {
                                auxActor = actores[i];
                                actores[i] = actores[j];
                                actores[j] = auxActor;
                            }
                        }
                    }

                }
            }
            //}
        }
        retorno=1;
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
void hardcodearActores(eActores actores[],int tam){
    int codigo[]={1,2,3,4,5,6,7,8};
    char nombre[][51]= {"Ben","Michael","Jamie","Natalie","Eric","Joseph","Reme","Matt"};
    char apellido[][51]={"Damon","Cloney","Gere","Afren","Caine","Portman","Ster","Banli"};
    char sexo[]={'m','m','m','f','m','m','f','m'};
    int idPais[]={1,2,4,4,5,6,7,8};
    int i;
    for(i=0; i<tam; i++)
    {
        actores[i].codigo=codigo[i];
        strcpy(actores[i].nombre,nombre[i]);
        strcpy(actores[i].apellido,apellido[i]);
        actores[i].sexo=sexo[i];
        actores[i].estado=OCUPADO;
        actores[i].idPais=idPais[i];
    }
}
int modificarActor(eActores actores[],int tam,ePais paises[],int tamP)
{
    int retorno=-2;
    int opcion;
    int idA;
    int idMayor;
    if(contadorActores(actores,tam)!=0)
    {
        idMayor=buscarIdMayor(actores,tam);
        printf("lista de actores\n");
        mostrarListaActores(actores,tam,paises,tamP);
        while((getIntValid(&idA,"Ingrese id del actor a modificar","Error",1,idMayor))==-1);
        opcion=findActorById(actores,tam,idA);
        if(opcion!=-1)
        {
            //printf("%s\t\t%s\t\t%c\n",actores[opcion].nombre,actores[opcion].apellido,actores[opcion].sexo);
            retorno=menuModificar(actores,tam,opcion,paises,tamP);
        }
        else
        {
            retorno=-1;
        }
    }

    return retorno;
}
