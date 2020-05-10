#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;
/**
 * @brief Muestra el menu de opciones principal con sus respectivos case
 *
 * @return Devuelve el entero de la opcion indicada
 */
int menu (void);
/**
 * @brief Inicializa un array en la celda isEmpty en 1
 *
 * @param empleados Array de empleados a analizar
 * @param tam Tamaño del array
 */
void initEmployees(eEmployee empleados[],int tam);
/**
 * @brief Pide los datos a ingresas en AddEmployee, con sus respectivas validaciones: nombre,apellido,sector,salario
 *
 * @param empleado vector que guardar auxiliarmente los datos
 * @return Devuelve 1 si se pudo cargar correctamente, sino 0
 */
int askParameters(eEmployee* empleado);
/**
 * @brief Analiza un array de empleados en la celda isEmpty y se fija si hay algun valor que sea 1
 *
 * @param empleados Array de empleados
 * @param tam Tamaño del array de empleados
 * @return Si encontró isEmpty==1 (espacio libre) devuelve el indice, si no encontró espacio devuelve -1
 */
int findEmpty(eEmployee empleados[],int tam);
/**
 * @brief Analiza un array de empleados y si encuentra espacio libre inserta los datos pasados por parametros en las celdas correspondientes
 *
 * @param empleados Array de empleados a cargar
 * @param tam Tamaño del array de empleados
 * @param id Id secuancial automatico
 * @param name celda nombre a cargar
 * @param lastName celda apellido a cargar
 * @param salary celda salario a cargar
 * @param sector celda sector a cargar
 * @return Devuelve 1 si se pudieron cargar los datos, sino devuelve 0
 */
int addEmployees(eEmployee empleados[],int tam,int id,char name[],char lastName[],float salary,int sector);
/**
 * @brief Analiza un array de empleados en la celda ID y si lo encuentra te devuelve el indice en donde esta
 *
 * @param empleado Array de empleados
 * @param tam Tamaño de array de empleados
 * @param id Id del empleado
 * @return devuelve -1 si no lo encontró, sino devuelve el indice
 */
int findEmployeeById(eEmployee empleado[], int tam,int id);
/**
 * @brief Pide Id y si lo encuentra y está ocupado permite eliminarlo
 *
 * @param empleados Array de empleados
 * @param tam Tamaño del array de empleados
 * @param id Id del empleado a borrar
 * @return Devuelve 1 si se pudo borra, sino devuelve 0
 */
int removeEmployee(eEmployee empleados[], int tam, int id);
/**
 * @brief Imprime solo los datos de 1 empleados
 *
 * @param empleado tipo eEmployee
 */
void printEmployee (eEmployee empleado);
/**
 * @brief Imprime la lista de empleados que se desea ver con nomenclaturas de tipo de dato
 *
 * @param empleados Array de empleados
 * @param tam Tamaño de array de empleados
 */
void printEmployees(eEmployee empleados[],int tam);
/**
 * @brief Pide un ID y si lo encuentra y está ocupado, te permite modificar alguna de las celdas de empleados, nombre, apellido, sector, o salario
 *
 * @param empleados Array de empleados
 * @param tam Tamaño del array de empleados
 * @return
 */
int changeEmployeeData(eEmployee empleados[],int tam);
/**
 * @brief Menu que muestra los valores que puede tomar el case segun la opcion elegida, segun la celda de Empleados que se desea cambiar
 *
 * @return devuelve el numero entero del case que se desea cambiar
 */
int menuChanges (void);
/**
 * @brief Analiza un array en isEmpty y averigua si está cargado un empleado o no
 *
 * @param empleados Array de empleados
 * @param tam tamaño del array de empleados
 * @return Devuelve 1 si hay cargado al menos un empleado, sino devuelve 0
 */
int flagFinder(eEmployee empleados[],int tam);
/**
 * @brief Muestra las opciones que puede tomar informes en cada case y pide un entero
 *
 * @return Devuelve el numero entero del case elegido
 */
int menuInformes(void);
/**
 * @brief Ejecuta el ordenamiento o el informes de finanzas segun el case.
 *
 * @param vec array de empleados
 * @param tam tamaño del array de empleados
 */
void informar(eEmployee vec[],int tam);
/**
 * @brief  Ordena el array empleados por sector y luego por cada sector por apellido. Se pued eelegir descendente (0) o ascendente(1)
 *
 * @param empleados array de empleados
 * @param tam tamaño de array de empleados
 * @param order toma un valor 1 o 0 segun lo pasado por parametro
 * @return devuelve el array ordenado de manera ascendente en sector y ascendente en apellido (1) o descendente en sector y en apellido (0)
 */
int sortEmployees(eEmployee empleados[],int tam,int order);
/**
 * @brief Analiza el array empleados en la celda Salary y acumula todos los salarios
 *
 * @param empleados Array de empleados
 * @param tam	 Tamaño de array de empleados
 * @return Devuelve el float d ela suma de todos los salarios
 */
float sumaDeSalarios(eEmployee empleados[],int tam);
/**
 * @brief Amaliza un array eEmployee en la celda Salary y realiza el promedio de todos los salarios
 *
 * @param empleados Array de empleados
 * @param tam Tamaño del array
 * @return Devuelve un float del promedio
 */
float promedio(eEmployee empleados[],int tam);
/**
 * @brief Analiza un array en la ccelda salario, y busca cuantos superan el promedio de todos los salarios
 *
 * @param empleados Array de empleados
 * @param tam Tamaño del array de empleados
 * @param promedio Promedio pasado por parametro
 * @return Devuelve la cantidad que superan el promedio
 */
int cantidadDeEmpleadosSalarioMayorDelPromedio(eEmployee empleados[],int tam,float promedio);

#endif /* ARRAYEMPLOYEES_H_ */
