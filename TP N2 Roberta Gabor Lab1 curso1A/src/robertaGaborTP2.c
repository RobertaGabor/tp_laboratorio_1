#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "arrayEmployees.h"
#define TAM 1000

int main()
{
	setbuf(stdout,NULL);
    int opcionMenuMain;
    int idBuscado;
    eEmployee empleadosArray[TAM];
    eEmployee empleadosauxiliar;
    initEmployees(empleadosArray,TAM);
    int idSecuencial=1000;
    int retorno;



    do
    {
        opcionMenuMain=menu();
        switch(opcionMenuMain)
        {
        case 1:
                if(askParameters(&empleadosauxiliar))
                {
                   if(addEmployees(empleadosArray,TAM,idSecuencial,empleadosauxiliar.name,empleadosauxiliar.lastName,empleadosauxiliar.salary,empleadosauxiliar.sector))
                   {
                        idSecuencial++;
                        printf("\n*****Empleado dado de alta exitosamente*****\n");
                   }

                }
                else
                {
                    printf("\n*****No se pudo dar de alta ese empleado*****\n");
                }
            break;
        case 2:
            if(flagFinder(empleadosArray,TAM))
            {
                if(!changeEmployeeData(empleadosArray,TAM))
                {
                    printf("\nHa ocurrido un error\n");
                }
            }
            else
            {
                printf("\nPrimero debe ingresar al menos los datos de un empleado\n\n");
            }
            break;
        case 3:
            if(flagFinder(empleadosArray,TAM))
            {
                if(getInt(&idBuscado,"\nIngrese ID del empleado a dar de baja: ","\nError. Ingrese un valor entero numerico valido mayor a 1000\n",1000,10000,0))
                {
                	retorno=removeEmployee(empleadosArray,TAM,idBuscado);
                    if(retorno)
                    {
                        printf("\n*****Empleado dado de baja exitosamente*****\n");
                    }
                    else
                    {
                    	if(!retorno)
                    	{
                    		printf("\n*****Operacion cancelada*****\n");
                    	}

                    }
                }
                else
                {
                    printf("\n*****No se pudo dar de baja ese empleado*****\n");
                }
            }
            else
            {
                printf("\nPrimero debe ingresar al menos los datos de un empleado\n\n");
            }
            break;
        case 4:
            if(flagFinder(empleadosArray,TAM))
            {
               informar(empleadosArray,TAM);
            }
            else
            {
                printf("\nPrimero debe ingresar al menos los datos de un empleado\n\n");
            }
            break;
        case 5:
            break;
        default:
            printf("Error. Ingrese una opcion valida\n");
            break;
        }

    system("pause");
    }while(opcionMenuMain!=5);

    return EXIT_SUCCESS;
}
