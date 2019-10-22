
typedef struct
{
    int legajo;
    char sexo;
    float altura;
} ePersona;
ePersona* new_Persona();///Esto se llama CONSTRUCTOR por defecto por que inicialisa con 0!!
///contructor parametrisado : es el que recibe parametros,con los que quiere inicialisar la estructura,podria tener distintos tipos de constructores
ePersona* new_Persona_Parametros(int,char,float);///contructor parametrisado
void setLegajo(ePersona*,int);
int getLegajo(ePersona*);

///puedo tener un setter o un geter si tengo un geter es de lectura y si solo tengo un setter es solo de escritura
void mostrarPersona(ePersona*);
void delete_persona(ePersona* );



