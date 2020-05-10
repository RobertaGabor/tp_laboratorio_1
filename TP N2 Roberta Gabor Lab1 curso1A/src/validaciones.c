#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int getString(char string[],int tam,char* mensaje,char* mensajeError,int reintentos)
{
    char auxiliarResultado[tam];
    int validacion=0;

    if(string!=NULL && mensaje!= NULL && mensajeError!= NULL &&reintentos>=0&&tam>0)
    {
        for(int i=0;i<=reintentos;reintentos--)
        {
            printf("\n%s",mensaje);
            if(stringValidated(auxiliarResultado,tam))
            {
                strcpy(string,auxiliarResultado);
                validacion=1;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
            }
        }
    }

    return validacion;
}
int scanString (char ingreso[],int tam)
{
    int retorno=-1;
    char auxiliar[4500];

    if(ingreso!=NULL&&tam>0)
    {
        fflush(stdin);

        if((fgets(auxiliar,sizeof(auxiliar),stdin)!=NULL))
        {
            if(auxiliar[strlen(auxiliar)-1]=='\n')
            {
                 auxiliar[strlen(auxiliar)-1]='\0';
            }
            if(strlen(auxiliar)<=tam)
            {
                strncpy(ingreso,auxiliar,tam);
                retorno=1;
            }
        }

    }
   return retorno;
}

int stringValidated(char cadena[],int tam)
{
    int retorno=0;
    char bufferString[tam];
    if(cadena!=NULL&&tam>0)
    {
        if(scanString(bufferString,tam)&&validarStringLetras(bufferString,tam)&&strlen(bufferString)>0)
        {
            retorno=1;
            strncpy(cadena,bufferString,tam);
        }
    }
    return retorno;
}

int validarStringLetras (char vector[],int tam)
{
    int retorno=1;

    if(vector!=NULL&&tam>0)
    {
         for(int i=0;vector[i]!='\0'&&i<tam;i++)
        {
            if(vector[i]!=' '&&(vector[i]<'a'||vector[i]>'z')&&(vector[i]<'A'||vector[i]>'Z'))
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}
int getFloat(float* numero,int tam,char* mensaje,char* mensajeError,int reintentos)
{
    float auxiliarResultado;
    int validacion=0;

    if(numero!=NULL && mensaje!= NULL && mensajeError!= NULL &&reintentos>=0&&tam>0)
    {
        for(int i=0;i<=reintentos;reintentos--)
        {
            printf("\n%s",mensaje);
            if(floatValidated(&auxiliarResultado,tam))
            {
                *numero=auxiliarResultado;
                validacion=1;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
            }
        }
    }

    return validacion;
}

int validarNumeroFloat (char vector[],int tam)
{
    int retorno=0;
    int contadorPunto=0;
    int retornoAuxiliar=1;

    if(vector!=NULL&&tam>0)
    {
         for(int i=0;vector[i]!='\0'&&i<tam;i++)
        {
            if((vector[i]<'0'||vector[i]>'9')&&vector[i]!='.')
            {
                retornoAuxiliar=0;
                break;
            }
            else
            {
                if(vector[i]=='.')
                {
                    contadorPunto++;
                }
            }
        }

        if((contadorPunto==1||contadorPunto==0)&&retornoAuxiliar==1)
        {
            retorno=1;
        }
    }

    return retorno;
}

int floatValidated(float* numero,int tam)
{
    int retorno=0;
    char bufferString[tam];
    if(numero!=NULL&&tam>0)
    {
        if(scanString(bufferString,tam)&&validarNumeroFloat(bufferString,tam)&&strlen(bufferString)>0)
        {
            retorno=1;
            *numero=atof(bufferString);
        }
    }
    return retorno;
}

int getInt(int* numero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int auxiliarResultado;
    int validacion;
    validacion=0;

    if(numero!=NULL && mensaje!= NULL && mensajeError!= NULL && minimo<=maximo&&reintentos>=0)
    {
        for(int i=0;i<=reintentos;reintentos--)
        {
            printf("\n%s",mensaje);
            if(validatedInt(&auxiliarResultado)&&(auxiliarResultado<=maximo)&&(auxiliarResultado>=minimo))
            {
                *numero=auxiliarResultado;
                validacion=1;
                break;
            }
            else
            {
                printf("\n%s\n",mensajeError);
            }
        }

    }
    return validacion;
}
int validatedInt(int* numero)
{
    int retorno=0;
    char bufferString[20];
    if(numero!=NULL)
    {
        if(scanString(bufferString,sizeof(bufferString))&&validarNumeroInt(bufferString,sizeof(bufferString))&&strlen(bufferString)>0)
        {
            retorno=1;
            *numero=atoi(bufferString);
        }
    }

    return retorno;
}

int validarNumeroInt (char vector[],int tam)
{
    int retorno=1;
    if(vector!=NULL)
    {
        for(int i=0;vector[i]!='\0'&&i<tam;i++)
        {
            if(vector[i]<'0'||vector[i]>'9')
            {
                retorno=0;
                break;
            }
        }
    }

    return retorno;
}


