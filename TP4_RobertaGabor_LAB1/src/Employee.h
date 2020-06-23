#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
int employee_delete(Employee* empleado);
int list_oneEmployee(LinkedList* pArrayListEmployee,int index);
int list_Employees(LinkedList* pArrayListEmployee);
int employee_FindId (LinkedList* pArrayListEmployee, int id);
int employee_addEmployee(LinkedList* pArrayListEmployee);
int employee_editEmployee(LinkedList* pArrayListEmployee);
int subMenuEditEmployee(void);
int employee_editNombre(LinkedList* pArrayListEmployee,int index);
int employee_editHoras(LinkedList* pArrayListEmployee,int index);
int employee_editSueldo(LinkedList* pArrayListEmployee,int index);
int employee_removeEmployee(LinkedList* pArrayListEmployee);
int subMenuSortEmployee(void);
int comparaPorID(void* pPersonA,void* pPersonB);
int comparaPorHoras(void* pPersonA,void* pPersonB);
int comparaPorSueldo(void* pPersonA,void* pPersonB);
int comparaPorNombre(void* pPersonA,void* pPersonB);
int employee_sortEmployee(LinkedList* pArrayListEmployee);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
