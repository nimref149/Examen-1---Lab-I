

/** \brief Solicita un texto al usuario y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \param input[] char Donde se cargara el texto ingresado
 * \return void
 */
void getString(char message[],char input[]);

/** \brief Solicita al usuario un numero y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \return int Devuelve el numero entero ingresado
 */
int getInt(char message[]);

/** \brief Solicita al usuario un numero flotante y lo devuelve
 * \param message[] char Es el mensaje a ser mostrado
 * \return float Devuelve el numero flotante ingresado
 */
float getFloat(char message[]);

/** \brief Solicita al un caracter y lo devuelve
 * \param message[] char El mensaje a ser mostrado
 * \return char Devuelve el caracter ingresado
 */
char getChar(char message[]);

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y -1 si no lo es
 */
int esNumerico(char str[]);

/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 0 si es númerico y -1 si no lo es
 */
int esNumericoFlotante(char str[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo ' ' y letras y -1 si no lo es
 */
int esSoloLetras(char str[]);

/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde numero minimo
 * \param hiLimit hasta numero maximo
 * \return devuelve 0 si es numerico y -1 si el numero no es valido
 */
int getIntValid(int* input,char message[],char eMessage[],int lowLimit,int hiLimit);

/** \brief
 * \brief Solicita un numero flotante al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde numero minimo
 * \param hiLimit hasta numero maximo
 * \return devuelve 0 si es flotante y -1 si no lo es
 */
int getFloatValid(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/** \brief
 * \brief Solicita un caracter al usuario y lo valida
 * \param *input donde se cargara el caracter
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde caracter minimo
 * \param hiLimit hasta caracter maximo
 * \return devuelve 0 si es un caracter y -1 si si no lo es
 */
int getCharValid(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

/** \brief
 * \brief Solicita un texto entero al usuario y lo valida
 * \param *input donde se cargara el texto
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde texto minimo
 * \param hiLimit hasta numero texto
 * \return devuelve 0 si es un texto y -1 si no lo es
 */
int getStringLetras(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief
 * \brief Solicita un texto con espacio al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde texto minimo
 * \param hiLimit hasta texto maximo
 * \return devuelve 0 si es texto y -1 si no lo es
 */
int getStringLetrasEspacio(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief
 * \brief Solicita una cadema de numeros enteros al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde numero minimo
 * \param hiLimit hasta numero maximo
 * \return devuelve 0 si es numerico y -1 si no es valido
 */
int getStringNumeros(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief
 * \brief Solicita una cadena de numeros flotantes al usuario y lo valida
 * \param *input donde se cargara el numero
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \param lowLimit desde numero minimo
 * \param hiLimit hasta numero maximo
 * \return devuelve 0 si es numero flotante y -1 si no lo es
 */
int getStringFlotantes(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief Solicita al usuario ingresar una confirmacion S o N
 *
 * \return int devuelve 0 si es N y 1 si es S
 *
 */
int confirm();

/**
 * \brief Verifica si el valor recibido contiene solo letras con espacio
 * \param str Array con la cadena a ser analizada
 * \return 0 si contiene solo ' ' y letras y -1 si no lo es
 */
int esSoloLetrasEspacio(char str[]);

/** \brief permite ingresar numeros y letras
 *
 * \param str[] char
 * \return int
 *
 */
int esAlfaNumerico(char str[]);

/** \brief Verifica si lo ingresado se trata de letras y numeros
 *
 * \param input char*
 * \param message[] char
 * \param eMessage[] char
 * \param lowLimit int
 * \param hiLimit int
 * \return int
 *
 */
int getStringLetrasYnumeros(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/** \brief validar entre 2 opcion de caracter
 *
 * \param input char*
 * \param message[] char
 * \param eMessage[] char
 * \param char
 * \param char
 * \return int
 *
 */
int getCharValidOpciones(char* input,char message[],char eMessage[], char, char);

/** \brief pregunta al usuario si desea continuar s o n
 *
 * \return int
 *
 */
int continuar();

