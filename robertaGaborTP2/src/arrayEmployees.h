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

int menu (void);
void initEmployees(eEmployee empleados[],int tam);
int askParameters(eEmployee* empleado);
int findEmpty(eEmployee empleados[],int tam);
int addEmployees(eEmployee empleados[],int tam,int id,char name[],char lastName[],float salary,int sector);
int findEmployeeById(eEmployee empleado[], int tam,int id);
int removeEmployee(eEmployee empleados[], int tam, int id);
void printEmployee (eEmployee empleado);
void printEmployees(eEmployee empleados[],int tam);
int changeEmployeeData(eEmployee empleados[],int tam);
int menuChanges (void);
int flagFinder(eEmployee empleados[],int tam);
int menuInformes(void);
void informar(eEmployee vec[],int tam);
int sortEmployees(eEmployee empleados[],int tam,int order);
float sumaDeSalarios(eEmployee empleados[],int tam);
float promedio(eEmployee empleados[],int tam);
int cantidadDeEmpleadosSalarioMayorDelPromedio(eEmployee empleados[],int tam,float promedio);

#endif /* ARRAYEMPLOYEES_H_ */
