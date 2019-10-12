
void inicializarElencos(eElenco elencos[],int);
void menuElenco(eElenco elenco[],int,eGeneros generos[],int,ePeliculas peliculas[],int,eActores actores[],int);
void altaElencos(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA);
void mostrarListaPeliculas(ePeliculas peliculas[], int tamP,eGeneros generos[],int tg);
void mostrarUnaPelicula(ePeliculas peliculas,eGeneros generos[],int tg);
int buscarLibreElencos(eElenco elencos[],int tp);
void listarElencosOrdenados(eElenco elenco[],int,eGeneros generos[],int,ePeliculas peliculas[],int,eActores actores[],int);
int findPeliculaById(ePeliculas peliculas[],int tam,int id);
void ordenarElencosPeliculasActor(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA);
int existeActorYpelicula(eElenco elencos[],int tam,int idP,int idA);
