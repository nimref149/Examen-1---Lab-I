#define OCUPADO 1
#define LIBRE 0
typedef struct
{
    int codigoPelicula;
    int codigoActor;
    float valorContro;
    int estado;
} eElenco;
typedef struct
{
    int idGenero;
    char genero[51];
} eGeneros;

typedef struct
{
    char titulo[31];
    int codigo;
    float duracion;
    int idGenero;
} ePeliculas;
typedef struct
{
    int codigo;
    char nombre[31];
    char apellido[21];
    char sexo;
    int estado;
} eActores;

    void hardcodearPeliculas(ePeliculas peliculas[],int TP);
    void hardcodearGeneros(eGeneros generos[],int TG);
    void agregarActor(eActores actores[],int TA);
    int buscarLibre(eActores[],int);
    void inicializarActores(eActores[],int ta);
    int autoId(eActores[],int tam);
    int buscarIdMayor(eActores[],int tam);
    void modificarActor(eActores[],int);
    int findActorById(eActores[],int,int);
    int menuModificar(eActores[],int,int);
    void mostrarActor(eActores);
    void bajarActor(eActores[], int);
    void mostrarListaActores(eActores[], int);
    void ordenarActoresApellidoNombre(eActores[], int);
    void menuActores(eActores[],int);
    int contadorActores(eActores actores[],int tam);
    void hardcodearActores(eActores[],int);

