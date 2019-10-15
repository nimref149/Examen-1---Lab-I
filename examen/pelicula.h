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
    int estado;
} ePeliculas;
typedef struct
{
    int codigo;
    char nombre[31];
    char apellido[21];
    char sexo;
    int estado;
} eActores;

    /** \brief Agregar datos a estructura peliculas
     *
     * \param peliculas[] ePeliculas
     * \param TP int
     * \return void
     *
     */
    void hardcodearPeliculas(ePeliculas peliculas[],int TP);

    /** \brief Agregar datos a estructura generos
     *
     * \param generos[] eGeneros
     * \param TG int
     * \return void
     *
     */
    void hardcodearGeneros(eGeneros generos[],int TG);

    /** \brief buscar pelicula por id
     *
     * \param peliculas[] ePeliculas
     * \param tam int
     * \param id int
     * \return int
     *
     */
    int findPeliculaById(ePeliculas peliculas[],int tam,int id);

    /** \brief muestra una pelicula con datos
     *
     * \param peliculas ePeliculas
     * \param generos[] eGeneros
     * \param tg int
     * \return void
     *
     */
    void mostrarUnaPelicula(ePeliculas peliculas,eGeneros generos[],int tg);

    /** \brief muestra todas las peliculas de la estructura
     * \param peliculas[] ePeliculas
     * \param tamP int
     * \param generos[] eGeneros
     * \param tg int
     * \return void
     *
     */
    void mostrarListaPeliculas(ePeliculas peliculas[], int tamP,eGeneros generos[],int tg);

    /** \brief
     *
     * \param peliculas[] ePeliculas
     * \param tamP int
     * \param generos[] eGeneros
     * \param tamG int
     * \param i int
     * \return int
     *
     */
    int menuModificarPeli(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG,int i);

    /** \brief muestra una lista de generos
     *
     * \param generos[] eGeneros
     * \param tam int
     * \return void
     *
     */
    void mostrarListaGeneros(eGeneros generos[],int tam);

    /** \brief permite ingresar datos para una pelicula y agregarla a la estructura
     *
     * \param peliculas[] ePeliculas
     * \param tamP int
     * \param generos[] eGeneros
     * \param tamG int
     * \return void
     *
     */
    void agregarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG);

    void modificarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG);
    void bajarPelicula(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG);
    void initPeliculas(ePeliculas peliculas[], int tam);
    int buscarLibrePelicula(ePeliculas peliculas[],int tamP);
    int autoIdPeliculas(ePeliculas peliculas[],int tamP);
    int buscarIdMayorPelicula(ePeliculas lista[],int tam);
    void menuPeliculas(ePeliculas peliculas[],int tamP,eGeneros generos[],int tamG);



