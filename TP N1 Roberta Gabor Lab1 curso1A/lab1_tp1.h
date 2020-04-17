#ifndef LAB1_TP1_H_INCLUDED
#define LAB1_TP1_H_INCLUDED

/** \brief Funcion que muestra un menu, el usuario elije una opcion y la devuelve al main para que ejecute una accion. Si la bandera en main es 3, reemplaza las variables por los numeros ingresados.
 *
 * \param flagFuncion int Pregunta en que estado está la bandera en main.
 * \param x int Primer numero ingresado para reemplazar en el menu.
 * \param y int Segundo numero ingresado para reemplazar en el menu.
 * \return int Devuelve el numero del menu elegido.
 *
 */
int menuDesplegado(int flagFuncion,int x,int y);

/** \brief Funcion que pide un numero entero y lo devuelve.
 *
 * \param x int* 1er numero entero ingresado.
 * \return void Reescribe en la direccion de memoria del primer entero en main.
 *
 */
void pedirPrimerNumero(int* x);

/** \brief Funcion que pide un segundo numero entero y lo devuelve.
 *
 * \param y int* 2do numero entero ingresado.
 * \return void Reescribe en la direccion de memoria del segundo entero en main.
 *
 */
void pedirSegundoNumero(int* y);

/** \brief Funcion que suma dos enteros ingresados.
 *
 * \param x int Primer entero.
 * \param y int Segundo entero.
 * \return Devuelve la suma de ambos enteros.
 *
 */
int suma(int x,int y);


/** \brief Funcion que resta el primer numero ingresado por el segundo.
 *
 * \param x int Primer entero ingresado.
 * \param y int Segundo entero ingresado.
 * \return int Devuelve la resta del primer entero por el segundo.
 *
 */
int resta(int x,int y);

/** \brief Funcion divide el primer numero entero por el segundo.
 *
 * \param x int Primer entero.
 * \param y int Segundo entero.
 * \return float Devuelve 0 si el segundo entero ingresado es 0, o si el primer numero ingresado es 0. Sino retorna la division.
 *
 */
float division(int x,int y);

/** \brief Funcion que multiplica el primer entero por el segundo.
 *
 * \param x int Primer entero ingresado.
 * \param y int Segundo entero ingresado.
 * \return int Devuelve el producto de la ecuacion.
 *
 */
int multiplicacion(int x, int y);

/** \brief Funcion que multiplica todos los numeros enteros anteriores al entero ingresado.
 *
 * \param x int Numero entero ingresado.
 * \return long long int Devuelve el factorial del entero ingresado hasta el numero 20. Si es mayor retorna 0.
 *
 */
long long int factorial(int x);

/** \brief Funcion que resetea una bandera.
 *
 * \param puntero de la bandera en Main ya inicializada.
 * \return void Reescribe direccion de memoria de la bandera en 0.
 *
 */
void resetFlag (int* x);


#endif // LAB1_TP1_H_INCLUDED
