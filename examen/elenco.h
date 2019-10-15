void inicializarElencos(eElenco elencos[],int);
void menuElenco(eElenco elenco[],int,eGeneros generos[],int,ePeliculas peliculas[],int,eActores actores[],int);
void altaElencos(eElenco elenco[],int tamE,eGeneros generos[],int tamG,ePeliculas peliculas[],int tamP,eActores actores[],int tamA);
int buscarLibreElencos(eElenco elencos[],int tp);
void listarElencosOrdenados(eElenco elenco[],int,eGeneros generos[],int,ePeliculas peliculas[],int,eActores actores[],int);
void ordenarElencosPeliculasActor(eElenco elenco[],int tamE,ePeliculas peliculas[],int tamP,eActores actores[],int tamA);
int existeActorYpelicula(eElenco elencos[],int tam,int idP,int idA);

