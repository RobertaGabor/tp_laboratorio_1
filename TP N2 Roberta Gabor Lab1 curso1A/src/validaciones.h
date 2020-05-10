#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * @brief Valida que en una cadena solo haya letras de a-z y A-Z
 *
 * @param vector Vector a analizar
 * @param tam Tamaño del vector
 * @return Devuelve 1 si se verifico correctamente, sino devuelve 0
 */
int validarStringLetras (char vector[],int tam);
/**
 * @brief Verifica que lo ingresado en el buffer sea de un tamaño apropiado y que sea validado como cadena de caracteres unicamente letras
 *
 * @param cadena vector que guarda la cadena
 * @param tam Tamaño de la cadena
 * @return Devuelve 1 si se respetan las dos coindiciones, sino devuelve 0
 */
int stringValidated(char cadena[],int tam);
/**
 * @brief Toma lo ingresado en el buffer
 *
 * @param ingreso cadena que guarda lo ingresado
 * @param tam Tamaño de la cadena
 * @return Devuelve 1 si se pudo guardar bien, sino devuelve 0
 */
int scanString (char ingreso[],int tam);
/**
 * @brief Pide una cadena de caracteres y lo devuelve por referencia
 *
 * @param string Guarda lo ingresado si se valido correctamente
 * @param tam Tamaño de la cadena
 * @param mensaje Mensaje que indica al usuario que ingresar
 * @param mensajeError Mensaje que indica al usuario si lo inrgesado esta mal
 * @param reintentos Cantidad de reintentos para volver a ingresar
 * @return Devuelve 1 si se ingreso todo correctamente, sino devuelve 0
 */
int getString(char string[],int tam,char* mensaje,char* mensajeError,int reintentos);
/**
 * @brief Pide un numero float y lo devuelve por referencia
 *
 * @param numero puntero que guarda el numero
 * @param tam Tamaño del vector
 * @param mensaje Mensaje que pide el float
 * @param mensajeError Mensaje que avisa si no se ingreso el numero correctamente
 * @param reintentos cantidad de reintentos posibles
 * @return devuelve 1 si se pudo tomar el numero, sino devuelve 0
 */
int getFloat(float* numero,int tam,char* mensaje,char* mensajeError,int reintentos);
/**
 * @brief Valida que una cadena este compuesta solo por numeros del 0 al 9 o sea un punto (solo valido 1 punto)
 *
 * @param vector Vector a analizar
 * @param tam Tamaño del vector
 * @return devuelve 1 si lo analizado dio todo igualado a esos valores, 0 si no se pudo validar
 */
int validarNumeroFloat (char vector[],int tam);
/**
 * @brief Valida que se haya ingresado un string de tamaño correcto, y que haya sido validado como numerico float (incluido el punto)
 *
 * @param numero puntero que guarda el string convertido en atof si se valido todo bien
 * @param tam Tamaño del vector
 * @return devueve 1 si se pudo convetir en atof, sino devuelve 0
 */
int floatValidated(float* numero,int tam);
/**
 * @brief Valida que una cadena este compuesta solo por numeros del 0 al 9
 *
 * @param vector Cadena a analizar
 * @param tam tamaño de la cadena
 * @return Devuelve 1 si se valido correctamente, devuelve 0 si algun caracter de la cadena no se valido correctamente
 */
int validarNumeroInt (char vector[],int tam);
/**
 * @brief Valida que se haya ingresado un string de tamaño correcto, y que haya sido validado como numerico
 *
 * @param numero puntero que guarda el string convertido en atoi si se valido todo bien
 * @return devueve 1 si se pudo convetir en atoi, sino devuelve 0
 */
int validatedInt(int* numero);
/**
 * @brief Pide un numero entero y lo devueve por referencia
 *
 * @param numero puntero donde guarda el entero recibido
 * @param mensaje Mensaje que pide el numero
 * @param mensajeError Mensaje que sale cuando fallas y no se respeto alguna validacion
 * @param minimo Numero minimo que se puede ingresar
 * @param maximo Numero maximo que se puede ingresar
 * @param reintentos Cantidad de reintentos posible
 * @return Devuelve 1 si se pudo tomar bien el numero, 0 si algo falló
 */
int getInt(int* numero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

#endif /* VALIDACIONES_H_ */
