#define OCUPADO 1
#define LIBRE 0
///ESTRUCTURA A ANIDAR
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

/*
typedef struct
{
    int dia;
    int mes;
    int anio;
    int idFecha;
}eFecha;
*/
typedef struct
{
    int idGenero;
    char genero[51];
} eGeneros;
/*
typedef struct
{
   ///eFecha fechas;<----ASI SE ANIDA UNA ESTRUCTURA ePeliculas[].fechas.dia

    char titulo[31];
    int codigo;
    float duracion;
    int idGenero;
    int estado;
    int idFecha;
    eFecha fechas;
} ePeliculas;
*/
typedef struct
{
   ///eFecha fechas;<----ASI SE ANIDA UNA ESTRUCTURA ePeliculas[].fechas.dia
    char titulo[31];
    int codigo;
    float duracion;
    int idGenero;
    int estado;
    eFecha fechas;
} ePeliculas;

//void hardcodearFechas(eFecha[],int);
//int buscarPorIdFecha(eFecha[],int,int);
//void menuPeliculas(ePeliculas [],int,eGeneros [],int,eFecha[],int);
void menuPeliculas(ePeliculas [],int,eGeneros [],int);
void mostrarPeliculasAnioTerror(ePeliculas[],int,eGeneros[],int);
//void mostrarPeliculasAnioTerror(ePeliculas[],int,eGeneros[],int,eFecha[],int);

void hardcodearPeliculas(ePeliculas[],int);



void hardcodearGeneros(eGeneros[],int);

int findPeliculaById(ePeliculas[],int,int);

void mostrarUnaPelicula(ePeliculas peliculas,eGeneros[],int );

void mostrarListaPeliculas(ePeliculas [], int ,eGeneros [],int );

int menuModificarPeli(ePeliculas [],int ,eGeneros [],int ,int );

void mostrarListaGeneros(eGeneros [],int );

int agregarPelicula(ePeliculas[],int,eGeneros[],int);

int modificarPelicula(ePeliculas [],int,eGeneros [],int );

int bajarPelicula(ePeliculas [],int,eGeneros [],int );

void inicializarPeliculas(ePeliculas [], int );

void inicializarCodigoPeliculas(ePeliculas [], int );

int buscarLibrePelicula(ePeliculas [],int );

int autoIdPeliculas(ePeliculas [],int,int);

int buscarIdMayorPelicula(ePeliculas [],int );

ePeliculas cargarPelicula(ePeliculas[],int ,eGeneros[],int );

int contadorPeliculas(ePeliculas[],int);

int mostrarPeliculaPorId(ePeliculas[],int,eGeneros[],int,int);

void mostrarUnaPeliculaConFecha(ePeliculas peliculas,eGeneros generos[],int tg);



