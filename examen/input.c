#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "input.h"
/**
isalpha() //Valida si es una letra
isdigit() //Valida si es un numero Verdadero (!=0) o falso (0)
isupper() //valida si es mayuscula
islower() //valida si es minuscula
toupper();para pasar el contenido de una variable tipo char ( char letra ) o array de cadena ( char cad[20] ), a mayusculas.
tolower();para pasar el contenido de una variable tipo char ( char letra ) o array de cadena ( char cad[20] ), a minusculas.
*/
void getString(char message[],char input[])
{
    printf("%s",message);
    gets(input);
}

int getInt(char message[])
{
    int numero;
    printf("%s",message);
    scanf("%d",&numero);
    return numero;
}

float getFloat(char message[])
{
    float numero;
    printf("%s",message);
    scanf("%f",&numero);
    return numero;
}

char getChar(char message[])
{
    char letra;
    printf("%s",message);
    scanf("%c",&letra);
    return letra;
}

char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return -1;
        i++;
    }
    return 0;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return -1;
        i++;
    }
    return 0;
}

int esSoloLetrasEspacio(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return -1;
        i++;
    }
    return 0;
}
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return -1;
        i++;
    }
    return 0;
}
int getIntValid(int* input,char message[],char eMessage[],int lowLimit,int hiLimit)
{
    char aux[256];
    int auxNumero;
    getString(message,aux);
    int retorno=-1;
    int esValido=esNumerico(aux);
    if(esValido==0)
    {
        auxNumero=atoi(aux);
        if(auxNumero>=lowLimit && auxNumero<=hiLimit)
        {
            *input=auxNumero;

            retorno=0;
        }
        else
        {

            printf("%s ",eMessage);
        }
    }
    else
    {
        printf("%s ",eMessage);
    }

    return retorno;
}


int getFloatValid(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int retorno=-1;
    char aux[256];
    float auxNumero;
    getString(message,aux);
    int esValido=esNumericoFlotante(aux);
    if(esValido==0)
    {
        auxNumero=atof(aux);
        if(auxNumero<lowLimit || auxNumero>hiLimit)
        {
            printf("%s ",eMessage);
        }
        else
        {
            *input=auxNumero;
            retorno=0;
        }

    }
    else
    {
        printf("%s ",eMessage);
    }
    return retorno;
}

int getCharValid(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)//mejorado con validacion de letra y rango
{
    printf("%s\n",message);
    //getChar(message);
    char auxChar=getch();
    fflush(stdin);
    int retorno=-1;
    int esValido;
    auxChar=tolower(auxChar);
    lowLimit=tolower(lowLimit);
    hiLimit=tolower(hiLimit);
    esValido=isalpha(auxChar);
    if(esValido!=0)
    {
        if(auxChar<lowLimit || auxChar>hiLimit)
        {
            printf("%s ",eMessage);
        }
        else
        {
            *input=auxChar;
            retorno=0;
        }
    }
    else
    {
        printf("%s ",eMessage);
    }
    return retorno;
}

int getStringLetras(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno=-1;
    char auxString[256];
    int esValido;
    getString(message,auxString);
    fflush(stdin);
    esValido=esSoloLetras(auxString);
    if(esValido==0)
    {
        if(strlen(auxString)<lowLimit || strlen(auxString)>hiLimit)
        {
            printf("%s ",eMessage);
        }
        else
        {
            strcpy(input,auxString);
            retorno=0;
        }
    }
    else
    {
        printf("%s ",eMessage);
    }

    return retorno;
}

int getStringNumeros(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno=-1;
    char auxNum[256];
    int esValido;
    getString(message,auxNum);
    esValido=esNumerico(auxNum);
    if(esValido==0)
    {
        if(strlen(auxNum)<lowLimit || strlen(auxNum)>hiLimit)
        {
            printf("%s ",eMessage);
        }
        else
        {
            strcpy(input,auxNum);
            retorno=0;
        }
    }
    else
    {
        printf("%s ",eMessage);
    }

    return retorno;
}
int getStringFlotantes(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno=-1;
    char auxNum[256];
    int esValido;
    getString(message,auxNum);
    esValido=esNumericoFlotante(auxNum);
    if(esValido==0)
    {
        if(strlen(auxNum)<lowLimit || strlen(auxNum)>hiLimit)
        {
            printf("%s ",eMessage);
        }
        else
        {
            strcpy(input,auxNum);
            retorno=0;
        }
    }
    else
    {
        printf("%s ",eMessage);
    }

    return retorno;
}


int confirm()
{
    int retorno=-1;
    char opcion;
    while(retorno==-1)
    {
        printf("Desea confirmar? Ingrese S para confirmar o N para cancelar\n");
        opcion=getch();
        opcion=tolower(opcion);
        if(opcion=='n')
        {
            retorno=0;
        }
        else if(opcion=='s')
        {

            retorno=1;
        }
        else
        {
            printf("Opcion no valida\n");
        }
    }
    return retorno;
}

int getStringLetrasEspacio(char* input,char message[],char eMessage[], int lowLimit, int hiLimit){

    int retorno=-1;
    char auxString[256];
    int esValido;
    getString(message,auxString);
    fflush(stdin);
    esValido=esSoloLetrasEspacio(auxString);
    if(esValido==0)
    {
        if(strlen(auxString)<lowLimit || strlen(auxString)>hiLimit)
        {
            printf("%s ",eMessage);
        }
        else
        {
            strcpy(input,auxString);
            retorno=0;
        }
    }
    else
    {
        printf("%s ",eMessage);
    }

    return retorno;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

int getStringLetrasYnumeros(char* input,char message[],char eMessage[], int lowLimit, int hiLimit){

    int retorno=-1;
    char auxString[256];
    int esValido;
    getString(message,auxString);
    fflush(stdin);
    esValido=esAlfaNumerico(auxString);
    if(esValido==0)
    {
        if(strlen(auxString)<lowLimit || strlen(auxString)>hiLimit)
        {
            printf("%s ",eMessage);
        }
        else
        {
            strcpy(input,auxString);
            retorno=0;
        }
    }
    else
    {
        printf("%s ",eMessage);
    }

    return retorno;
}

int getCharValidOpciones(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)//mejorado con validacion de letra y rango
{
    printf("%s\n",message);
    char auxChar=getch();
    fflush(stdin);
    int retorno=-1;
    int esValido;
    auxChar=tolower(auxChar);
    lowLimit=tolower(lowLimit);
    hiLimit=tolower(hiLimit);
    esValido=isalpha(auxChar);
    if(esValido!=0)
    {
        if(auxChar!=lowLimit&&auxChar!=hiLimit)
        {
            printf("%s ",eMessage);
        }
        else
        {
            *input=auxChar;
            retorno=0;
        }
    }
    else
    {
        printf("%s ",eMessage);
    }
    return retorno;
}















































































































































































































































































































































































































































































































