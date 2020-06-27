#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int rank;
}Employee;
/*
* \brief
 * \param
 * \param
 * \return
 */

/*
* \brief crea espacio de memoria para un elemento de tipo Employee*
 * \param void
 * \return puntero al elemento si se consiguio, sino NULL
 */
Employee* employee_new();
/*
* \brief genera espacio de memoria para un elemento de tipo Employee y corrobora que sus campos sean validos
 * \param char* string de id
 * \param char*string de nombre
 * \param char* string de horas
 * \param char* string sueldo
 * \param char* string rank
 * \return puntero al elemento si se consiguio, sino NULL
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr,char* rankStr);
/*
* \brief libera el espacio de memoria de un elemento
 * \param
 * \param puntero al elemento
 * \return devuelve 1 si se pudo liberar sino 0
 */
int employee_delete(Employee* empleado);
/*
* \brief lista un empleado con todos sus campos
 * \param LinkedList* lista para buscar el empleado
 * \param indice donde se encuentra el empleado
 * \return
 */
int list_oneEmployee(LinkedList* pArrayListEmployee,int index);
/*
* \brief lista todo el linkedlist
 * \param LinkedList* puntero a linkedlist
 * \param
 * \return
 */
int list_Employees(LinkedList* pArrayListEmployee);
/*
* \brief encuentra el indice de un elemento por el ID
 * \param LinkedList* puntero a linkedlist
 * \param Id a buscar
 * \return devuelve el indice si se encuentra sino -1
 */
int employee_FindId (LinkedList* pArrayListEmployee, int id);
/*
* \brief agrega un elemento al linkedlist, al final o reemplazando a un empleado existente
 * \param LinkedList* puntero a linkedlist
 * \param
 * \return devuelve 1 si se pudo agregar sino 0
 */
int employee_addEmployee(LinkedList* pArrayListEmployee);
/*
* \brief costructora para editar el campo de un empleado
 * \param LinkedList* puntero a linkedlist
 * \param
 * \return  devuelve 1 si se pudo cambiar sino 0
 */
int employee_editEmployee(LinkedList* pArrayListEmployee);
int subMenuEditEmployee(void);
int employee_editNombre(LinkedList* pArrayListEmployee,int index);
/*
* \brief edita el campo nombre de un elemento
 * \param LinkedList* puntero a linkedlist
 * \param indice del elemento en el linkedlist
 * \return devuelve 1 si se pudo setear sino 0
 */
int employee_editHoras(LinkedList* pArrayListEmployee,int index);
/*
* \brief edita el campo horas trabajadas de un elemento
 * \param LinkedList* puntero a linkedlist
 * \param indice del elemento en el linkedlist
 * \return devuelve 1 si se pudo setear sino 0
 */
int employee_editSueldo(LinkedList* pArrayListEmployee,int index);
/*
* \brief edita el campo sueldos de un elemento
 * \param LinkedList* puntero a linkedlist
 * \param indice del elemento en el linkedlist
 * \return devuelve 1 si se pudo setear sino 0
 */
int employee_removeEmployee(LinkedList* pArrayListEmployee);
/*
* \brief da de baja un empleado en el linkedlist
 * \param LinkedList* puntero a linkedlist
 * \param
 * \return devuelve 1 si se pudo setear sino 0
 */
int subMenuSortEmployee(void);
int comparaPorID(void* pPersonA,void* pPersonB);
/*
* \brief ordena una lista segun su id de manea ascendente o descendente
 * \param elemento del linkedlist
 * \param elemento consecutivo del linkedlist al anterior
 * \return si pPersonA> pPersonB es 1 si pPersonA< pPersonB es -1 si son iguales 0
 */
int comparaPorHoras(void* pPersonA,void* pPersonB);
/*
* \brief ordena una lista segun su horas trabajadas de manea ascendente o descendente
 * \param elemento del linkedlist
 * \param elemento consecutivo del linkedlist al anterior
 * \return si pPersonA> pPersonB es 1 si pPersonA< pPersonB es -1 si son iguales 0
 */
int comparaPorSueldo(void* pPersonA,void* pPersonB);
/*
* \brief ordena una lista segun su sueldo de manea ascendente o descendente
 * \param elemento del linkedlist
 * \param elemento consecutivo del linkedlist al anterior
 * \return si pPersonA> pPersonB es 1 si pPersonA< pPersonB es -1 si son iguales 0
 */
int comparaPorNombre(void* pPersonA,void* pPersonB);
/*
* \brief ordena una lista segun su nombre de manea ascendente o descendente
 * \param elemento del linkedlist
 * \param elemento consecutivo del linkedlist al anterior
 * \return si pPersonA> pPersonB es 1 si pPersonA< pPersonB es -1 si son iguales 0
 */
int employee_sortEmployee(LinkedList* pArrayListEmployee);
/*
* \brief ordena una lista
 * \param puntero al linkedlist
 * \param
 * \return  devuelve 1 si se pudo setear sino 0
 */
int employee_editRank(LinkedList* pArrayListEmployee,int index);
/*
* \brief edita el campo rank de un elemento
 * \param LinkedList* puntero a linkedlist
 * \param indice del elemento en el linkedlist
 * \return devuelve 1 si se pudo setear sino 0
 */
int comparaPorRanked(void* pPersonA,void* pPersonB);
/*
* \brief ordena una lista segun su rank de manea ascendente o descendente
 * \param elemento del linkedlist
 * \param elemento consecutivo del linkedlist al anterior
 * \return si pPersonA> pPersonB es 1 si pPersonA< pPersonB es -1 si son iguales 0
 */

int chequearRanked(LinkedList* this);
/*
* \brief chequea si un empleado pertenece a los 10 mejores
 * \param puntero al linkedlist
 * \param
 * \return devuelve 1 si pertenece sino 0
 */
LinkedList* mejoresSueldos(LinkedList* this);
/*
* \brief Genera una nueva lista con los 10 mejroes sueldos
 * \param puntero al linkedlist
 * \param
 * \return devuelve puntero al linkedlist de la nueva lista creada
 */
void mostrarNuevos(LinkedList* this);
/*
* \brief Muestra los empleados que no tiene rango porque entraron hace poco
 * \param puntero al linkedlist
 * \param
 * \return
 */



/*Setters:
* \brief Si el segundo parametro pasa las validaciones se seta en el campo correspondiente al nombre en el puntero al elemento del primer parametro
 * \param this Employee* Puntero al elemento
 * \param variable que será seteada en el campo del elemento
 * \return int Retorna  1 si fue seteado con exito y el puntero al elemento !=NULL sino 0
 */

/*Getters:
* \brief Si el puntero al elemento y el puntero a la variable pasada por parametro se copia el campo del elemento correspondiente en en puntero
 * \param this Employee* Puntero al elemento
 * \param puntero  que será seteado
 * \return int Retorna  1 si fue seteado con exito y los dos punteros!= NULL sino 0
 */
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setRank(Employee* this,int rank);
int employee_getRank(Employee* this,int* rank);

#endif // employee_H_INCLUDED
