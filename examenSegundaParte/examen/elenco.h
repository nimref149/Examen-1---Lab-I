typedef struct
{
    int codigoPelicula;
    int codigoActor;
    float valorContrato;
    int estado;
} eElenco;

void inicializarElencos(eElenco[],int);
void hardcodearElenco(eElenco[],int);
void menuElenco(eElenco[],int,eGeneros[],int,ePeliculas[],int,eActores[],int,ePais[],int);
int altaElencos(eElenco[],int,eGeneros[],int,ePeliculas[],int,eActores[],int,ePais[],int);
int buscarLibreElencos(eElenco elencos[],int tp);
//void listarElencosOrdenados(eElenco[],int,eGeneros[],int,ePeliculas[],int,eActores[],int);
void ordenarElencosPeliculasActor(eElenco[],int,ePeliculas[],int tamP,eActores[],int);
int existeActorYpelicula(eElenco elencos[],int,int,int);
void mostrarUnElenco(eElenco elenco,ePeliculas[],int,eActores[],int);
int listarElencosOrdenados(eElenco[],int,ePeliculas[],int tamP,eActores[],int);
int contadorElencos(eElenco[],int);
//void menuInformes(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,eActores[],int,eElenco elencos[],int TE,ePais[],int);
void menuInformes(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,eActores[],int,eElenco elencos[],int TE,ePais[],int);
void listarPelisActorArgentino(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPA);
void listarPelisActorSeleccionado(eElenco[],int,ePeliculas[],int,eActores[],int,ePais[],int);
void listarPelisActorRomanticas(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPA);
void listarActoresSinPeli(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA,ePais paises[],int tamPA);
