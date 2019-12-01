#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "pelicula.h"
#include "actores.h"
#include "elenco.h"
#define TP 10
#define TA 10
#define TG 4
#define TE 100
//#define TF 10
#define TPI 10
/**
Parte 1:
Atender a las siguientes modificaciones:
Al programa solicitado en la instancia de examen anterior
1. Agregar las siguientes estructuras:

● Fecha (dia, mes, anio)
● Pais (id, descripcionPais)

2. Agregar:

a. A la estructura Pelicula la fecha de estreno.
b. Al actor la nacionalidad.

3. Refactorizar el programa de forma tal que atienda a todos los requisitos
solicitados con anterioridad.

Parte 2.
Una vez concluida la parte 1:

Agregar la opcion 3 (Informes) al menú principal y visualizar en
distintas opciones:
1. Mostrar las películas de terror cuyo año de estreno sea después del 2002.
2. Películas en donde haya participado un actor argentino.
3. Mostrar las películas en las que participó un actor seleccionado.
4. Seleccionar un actor y determinar cuánto ha recaudado en todas las
películas románticas en las que participó.
5. Listar los actores que no participaron en ninguna película.
NOTAS:
I. Se deberá desarrollar bibliotecas por cada entidad, las cuales contendrán las funciones Alta, Baja, Modificar
y Listar.
II. Las validaciones deberán estar en una biblioteca aparte.
III. El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las reglas
de estilo de la cátedra
datos harcodeados
dar alta
informes
el pais SU TAMANIO ES TPI <<<<-----------------------
el pais SU TAMANIO ES TPI <<<<-----------------------
el pais SU TAMANIO ES TPI <<<<-----------------------

*/

int main()
{
    int opcion;
    ePais paises[TPI];
    //eFecha fechas[TF];
    ePeliculas peliculas[TP];
    eGeneros generos[TG];
    eActores actores[TA];
    eElenco elencos[TE];

    inicializarPeliculas(peliculas,TP);
    inicializarCodigoPeliculas(peliculas,TP);
    inicializarActores(actores,TA);
    inicializarCodigoActores(actores,TA);
    inicializarElencos(elencos,TE);


    //hardcodearFechas(fechas,10);
    hardcodearPaises(paises,TPI);
    hardcodearActores(actores,8);
    hardcodearPeliculas(peliculas,TP);
    hardcodearGeneros(generos,TG);
    hardcodearElenco(elencos,4);

    do
    {
        getIntValid(&opcion,"**Menu de abm**\n1-Gestion de actores\n2-Gestion de elencos\n3-Listar\n4-Salir\nElija una opcion\n","Error",1,4);

        switch(opcion)
        {
        case 1:
            menuActores(actores,TA,paises,TPI);
            break;
        case 2:
            menuElenco(elencos,TE,generos,TG,peliculas,TP,actores,TA,paises,TPI);
            break;
        case 3:
            //menuInformes(peliculas,TP,generos,TG,fechas,TF,actores,TA,elencos,TE,paises,TPI);
            menuInformes(peliculas,TP,generos,TG,actores,TA,elencos,TE,paises,TPI);
            break;
        case 4:
            printf("Saliendo del programa");
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=4);

    return 0;
}
