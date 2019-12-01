#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idPais;
    char descripcion[15];

} ePais;
typedef struct
{
    int codigo;
    char nombre[31];
    char apellido[21];
    char sexo;
    int estado;
    int idPais;

} eActores;


void mostrarPaises(ePais[],int);

void mostrarUnPais(ePais);

void hardcodearPaises(ePais[],int);

int agregarActor(eActores[],int,ePais[],int i);

int buscarLibreActor(eActores[],int);

void inicializarActores(eActores[],int ta);

int autoId(eActores[],int,int);

int buscarIdMayor(eActores[],int);

int modificarActor(eActores[],int,ePais[],int);

int findActorById(eActores[],int,int);

int menuModificar(eActores[],int,int,ePais[],int);

void mostrarActor(eActores,ePais[],int);

int bajaActor(eActores[], int,ePais[],int);
void mostrarListaActores(eActores[], int,ePais[],int);
int ordenarActoresApellidoNombre(eActores[], int);
void menuActores(eActores[],int,ePais[],int);
int contadorActores(eActores actores[],int);
void hardcodearActores(eActores[],int);
eActores cargarActor(eActores[],int,ePais[],int);
void inicializarCodigoActores(eActores[],int);
void mostrarActorCompleto(eActores actores,ePais[],int);
int obtenerUnActor(eActores[],int,ePais[],int);
int mostrarListaActoresOrdenados(eActores[], int,ePais[],int );
