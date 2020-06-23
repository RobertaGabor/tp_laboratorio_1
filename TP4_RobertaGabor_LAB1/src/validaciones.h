/*
 * validaciones.h
 *
 *  Created on: 11 jun. 2020
 *      Author: TCL
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_


int scanString (char ingreso[],int tam);
int stringValidated(char cadena[],int tam);
int validarStringLetras (char vector[],int tam);
int validarNumeroInt (char vector[],int tam);
int validatedInt(int* numero);
int getString(char string[],int tam,char* mensaje,char* mensajeError,int reintentos);
int getInt(int* numero,char* mensaje,char* mensajeError,int minimo,int reintentos);
int getIntConMax(int* numero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#endif /* VALIDACIONES_H_ */
