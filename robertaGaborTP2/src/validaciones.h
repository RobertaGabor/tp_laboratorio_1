#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int validarStringLetras (char vector[],int tam);
int stringValidated(char cadena[],int tam);
int scanString (char ingreso[],int tam);
int getString(char string[],int tam,char* mensaje,char* mensajeError,int reintentos);
int getFloat(float* numero,int tam,char* mensaje,char* mensajeError,int reintentos);
int validarNumeroFloat (char vector[],int tam);
int floatValidated(float* numero,int tam);
int validarNumeroInt (char vector[],int tam);
int validatedInt(int* numero);
int getInt(int* numero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#endif /* VALIDACIONES_H_ */
