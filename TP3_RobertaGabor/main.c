#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menuMain(void);

int main()
{
	setbuf(stdout,NULL);
    int mainOption;

    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados!=NULL)
    {
        do{
        	mainOption=menuMain();
            switch(mainOption)
            {
                case 1:
                    controller_loadFromText("data2.csv",listaEmpleados);/*listo*//*hacer que no se carguen si ya se cargaron*/
                    break;
                case 2:
                	controller_loadFromBinary("data.bin", listaEmpleados);/*listo*/
                	break;
                case 3:
                	controller_addEmployee(listaEmpleados);/*listo*/
                	break;
                case 4:
                	controller_editEmployee(listaEmpleados);/*listo*/
                	break;
                case 5:
                	controller_removeEmployee(listaEmpleados);/*listo*/
                	break;
                case 6:
                	list_Employees(listaEmpleados);/*listo*/
                	break;
                case 7:
                	controller_sortEmployee(listaEmpleados);/*listo*/
                	break;
                case 8:
                	if(controller_saveAsText("data2.csv",listaEmpleados))/*listo*/
                	{
                		printf("Cargado con exito\n");
                	}
                	else
                	{
                		printf("No se pudo cargar\n");
                	}
                	break;
                case 9:
                	if(controller_saveAsBinary("data.bin",listaEmpleados))/*listo*/
					{
                		printf("Cargado con exito\n");
					}
                	else
                	{
                		printf("No se pudo cargar\n");
                	}
                	break;
                case 10:
                	break;
                default:
                	printf("Opcion invalida\n");
                	break;
            }
            system("pause");
        }while(mainOption != 10);
    }
    else
    {
    	printf("No se pudo asignar memoria disponible\n");
    	exit(EXIT_FAILURE);
    }


    return 0;
}

int menuMain(void)
{

    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");

    printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2-Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("3-Alta de empleado\n");
    printf("4-Modificar datos de empleado\n");
    printf("5-Baja de empleado\n");
    printf("6-Listar empleados\n");
    printf("7-Ordenar empleados\n");
    printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9-Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf("10-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
