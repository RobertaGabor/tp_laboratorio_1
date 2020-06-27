/*
 ============================================================================
 Name        : TP4_RobertaGabor_LAB1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "Controller.h"
#include "Employee.h"
#include "validaciones.h"
int menuMain(void);
int menuInformes(void);
int main(void)
{
	setbuf(stdout,NULL);
    int mainOption;
    int flag=0;
    int informesOption;
    int flagInfo=0;
    int contains;

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosBackup = ll_newLinkedList();
    LinkedList* listaEmpleadosRanked = ll_newLinkedList();
    LinkedList* listaEmpleadosMejoresSueldos = ll_newLinkedList();
    if(listaEmpleados!=NULL)
    {
        do{
        	mainOption=menuMain();
            switch(mainOption)
            {
                case 1:
                    if(flag==0)
                    {
                    	controller_loadFromText("data2.csv",listaEmpleados);
                    	flag=1;
                    }
                    else
                    {
                    	if(flag==1)
                    	{
                    		printf("Ya se cargaron los datos en texto\n");
                    	}
                    	else
                    	{
                    		printf("Los datos ya se cargaron como binario\n");
                    	}
                    }

                    break;
                case 2:
                	if(flag==0)
                	{
                		controller_loadFromBinary("data.bin", listaEmpleados);
                		flag=2;
                	}
                	else
                	{
                		if(flag==2)
                		{
                			printf("Ya se cargaron los datos en binario\n");
                		}
                		else
                		{
                			printf("Los datos ya se cargaron como texto\n");
                		}
                	}

                	break;
                case 3:
                	controller_addEmployee(listaEmpleados);
                	break;
                case 4:
                	controller_editEmployee(listaEmpleados);
                	break;
                case 5:
                	controller_removeEmployee(listaEmpleados);
                	break;
                case 6:
                	list_Employees(listaEmpleados);
                	break;
                case 7:
                	controller_sortEmployee(listaEmpleados);
                	break;
                case 8:
                	if(controller_saveAsText("data2.csv",listaEmpleados))
                	{
                		printf("Cargado con exito\n");
                	}
                	else
                	{
                		printf("No se pudo guardar\n");
                	}
                	break;
                case 9:
                	if(controller_saveAsBinary("data.bin",listaEmpleados))
					{
                		printf("Guardado con exito\n");
					}
                	else
                	{
                		printf("No se pudo guardar\n");
                	}
                	break;
                case 10:
                	/*clonar y guardar y decir que fue conexito*/
                	listaEmpleadosBackup=ll_clone(listaEmpleados);
                	if(controller_saveAsText("dataBackup.csv",listaEmpleadosBackup))
                	{
                		printf("Guardado con exito\n");
                	}
                	else
                	{
                		printf("No se pudo guardar\n");
                	}
                	break;
                case 11:
                	/*informes*/
            		if(listaEmpleadosRanked!=NULL)
            		{
                    	do
                    	{
                    		informesOption=menuInformes();
                    		switch(informesOption)
                    		{
                    		case 1:
                    			if(flagInfo==2)
                    			{
                    				ll_clear(listaEmpleadosRanked);/*si ya esta cargada la limpio y vuelvo a escribir en la lista lo ultimo  guardado en el archivo*/
                    			}
                    			if(flagInfo==3)
                    			{
                    				printf("La lista ya fue cargada desde el archivo\n");
                    				break;
                    			}

                    			controller_loadFromText("dataRanked.csv",listaEmpleadosRanked);

                    			list_Employees(listaEmpleadosRanked);
                    			flagInfo=3;
                    			break;
                    		case 2:/*todos los meses se modifica todo el ranking y se vuelve a cargar encima con modificar rank*/
                    			if(flag==1||flag==2)/*si se cargo la lista de empleados*/
                    			{
									if(flagInfo==3)
									{
										ll_clear(listaEmpleadosRanked);
									}
									if(flagInfo==2)
									{
										printf("La lista ya fue cargada desde la lista de empleados\n");
										break;
									}

									listaEmpleadosRanked=ll_filter(listaEmpleados,filtrarRank);
									if(!ll_isEmpty(listaEmpleadosRanked))
									{
										ll_sort(listaEmpleadosRanked,comparaPorRanked, 1);
										if(controller_saveAsText("dataRanked.csv",listaEmpleadosRanked))
										{
											printf("Guardado con exito\n");
											flagInfo=2;
										}
										else
										{
											printf("No se pudo guardar\n");
										}
									}
									else
									{
										printf("No hay rangos posibles del 1 al 10 en la lista\n");
									}
                    			}
                    			else
                    			{
                    				printf("Antes de sobreescribir el ranked cargar la lista de empleados\n");
                    			}

                    			break;
                    		case 3:/*si un empleado de lista esta en 10 mejores*/
                    			if(chequearRanked(listaEmpleadosRanked)&&(flagInfo==1||flagInfo==2))/*si ya cargaron lista empleados*/
                    			{
                    				printf("\nSe encuentra en los 10 mejores\n");

                    			}
                    			else
                    			{
                    				printf("\nNo se encuentra en los 10 mejores o no se ha cargado lista\n");
                    			}
                    			break;
                    		case 4:/*si los 10 mejores sueldo estan en los 10 mejores*/
                    			if(flagInfo==1||flagInfo==2)
                    			{
                    				listaEmpleadosMejoresSueldos=mejoresSueldos(listaEmpleados);
                    				list_Employees(listaEmpleadosMejoresSueldos);
                    				contains=ll_containsAll(listaEmpleadosRanked,listaEmpleadosMejoresSueldos);
                    				if(contains==-1)
                    				{
                    					printf("No se pudo corroborar\n");

                    				}
                    				else
                    				{
                    					if(!contains)
                    					{
                    						printf("No todos los empleados con mayor sueldo estan contenidos en el ranked\n");
                    					}
                    					else
                    					{
                    						printf("Todos los empleados con mayor sueldo estan contenidos en el ranked\n");
                    					}
                    				}

                    			}
                    			else
                    			{
                    				printf("Aun no se ha cargado la lista\n");
                    			}
                    			break;
                    		case 5:/*mostrar empleados sin rango rango==-1*/
                    			if(flagInfo==1||flagInfo==2)
                    			{
                    				mostrarNuevos(listaEmpleados);
                    			}
                    			else
                    			{
                    				printf("Aun no se ha cargado la lista\n");
                    			}
                    			break;
                    		case 6:
                    			if(flagInfo==1||flagInfo==2)
                    			{
                    				list_Employees(listaEmpleadosRanked);
                    			}
                    			else
                    			{
                    				printf("No hay empleados que mostrar porque no se ha cargado la lista\n");
                    			}

                    			break;
                    		case 0:
                    			break;
                            default:
                            	printf("Opcion invalida\n");
                            	break;
                    		}
                    		 system("pause");
                    	}while(informesOption!=0);
            		}
                	break;
                case 0:
                	break;
                default:
                	printf("Opcion invalida\n");
                	break;
            }
            system("pause");
        }while(mainOption != 0);
    }
    else
    {
    	printf("No se pudo asignar memoria disponible\n");
    	exit(EXIT_FAILURE);
    }

    ll_deleteLinkedList(listaEmpleadosMejoresSueldos);
    ll_deleteLinkedList(listaEmpleadosRanked);
    ll_deleteLinkedList(listaEmpleadosBackup);
    ll_deleteLinkedList(listaEmpleados);
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
    printf("10-Guardar Backup del mes\n");
    printf("11-Informes de RANKED\n");
    printf("0-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int menuInformes(void)
{

    int opcion;
    system("cls");
    printf("********Menu de informes Ranking**********\n");

    printf("1-Mostrar los ultimos 10 mejores del mes pasado\n");
    printf("2-Cargar nuevos 10 mejores del mes\n");
    printf("3-Verificar si un determinado empleado esta en los mejores\n");
    printf("4-Corroborar si todos los 10 con mejores sueldos estan en los mejores\n");
    printf("5-Mostrar nuevos empleados sin rank\n");
    printf("6-Mostrar lista ranked activa\n");
    printf("0-Salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}



