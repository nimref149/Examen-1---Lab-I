#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "input.h"
#include "pelicula.h"
#include "elenco.h"
#define TP 7
#define TA 5
#define TG 4
#define TE 35

/**
Desarrollar en ANSI C:
Se necesita administrar los alquileres de juegos infantiles, y para ello se deberá realizar un programa de acuerdo a lo
siguiente:

Película:
● Código
● Descripción
● Duración
● idGenero

Género:
● id
● Descripción (máximo 51 caracteres) (Accion, Terror, Romance, Suspenso)

Actor:
● Código (autoincremental)
● Nombre (máximo 51 caracteres) Validar
● Apellido(máximo 51 caracteres)Validar
● Sexo Validar

Elenco:
● Código de reparto(autoincremental)
● Código de película Validar
● Código de actor Validar
● Valor contrato
Realizar un menú con las siguientes opciones:
//------------------------------------------------------------------
1) Gestión de Actores:
A) Altas: No es necesario el ingreso de todos los actores.
B) Modificar: Se ingresará el Código del actor, permitiendo en un submenú modificar:
● Nombre
● Apellido
● Sexo
C) Baja: Se ingresará el Código de Actor y se realizará una baja lógica.
D) Listar: Hacer un único listado de todos los Actores ordenados por apellido y nombre.
//-------------------------------------------------------------------
2) Gestión de Elencos:
A) Generar elenco: Se dará de alta cada ocurrencia de Elenco (puede ser uno o varios actores
para una película), relacionando Película – Actor, Valor de contrato. Verificar que no se repita
el par película-actor.
B) Listar Elencos (Con sus datos relacionados). Ordenados por Película y ante igualdad de
criterio, por actor.
/.....................................................................
NOTAS:
I. Se deberá desarrollar bibliotecas por cada entidad, las cuales contendrán las funciones Alta, Baja, Modificar
y Listar.
II. Las validaciones deberán estar en una biblioteca aparte.
III. El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas
de estilo de la cátedra.
*/

int main()
{

    int opcion;
    ePeliculas peliculas[TP];
    eElenco elencos[TE];
    eGeneros generos[TG];
    eActores actores[TA];

    inicializarActores(actores,TA);
    inicializarElencos(elencos,TE);
    hardcodearActores(actores,3);
    hardcodearPeliculas(peliculas,TP);
    hardcodearGeneros(generos,TG);
    //int i;
    /*
        for(i=0;i<7;i++){
        printf("%s----%d\n",generos[i].genero,generos[i].idGenero);
        }
        */
    do
    {
        getIntValid(&opcion,"Menu abm\n1-Gestion de actores\n2-Gestion de elencos\n","Error",1,3);
        switch(opcion)
        {
        case 1:
            menuActores(actores,TA);
            break;
        case 2:
            menuElenco(elencos,TE,generos,TG,peliculas,TP,actores,TA);
            break;
        case 3:
            printf("Saliendo del programa");
            break;
        }
        system("cls");
        system("pause");
    }
    while(opcion!=3);

            return 0;

}
