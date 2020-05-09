#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "arrayEmployees.h"

int flagFinder(eEmployee empleados[],int tam)
{
    int retorno=0;
    if(empleados!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(empleados[i].isEmpty==0)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}
int cantidadDeEmpleadosSalarioMayorDelPromedio(eEmployee empleados[],int tam,float promedio)
{
    int cantidadTotal=0;
    if(empleados!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(empleados[i].isEmpty==0&&empleados[i].salary>=promedio)
            {
                cantidadTotal++;
            }
        }
    }
    return cantidadTotal;
}
float promedio(eEmployee empleados[],int tam)
{
    float acumulador=0;
    int contador=0;
    float promedio;
    int flag=0;
    if(empleados!=NULL&&tam>0)
    {
       for(int i=0;i<tam;i++)
       {
    	   if(empleados[i].isEmpty==0)
    	   {
    		   acumulador+=(float)empleados[i].salary;
    		   contador++;
    		   flag=1;
    	   }
       }
       promedio=(float)acumulador/contador;
       if(flag==0)
       {
    	   promedio=0;
       }
    }

    return promedio;
}

float sumaDeSalarios(eEmployee empleados[],int tam)
{
    float acumulador=0;
    if(empleados!=NULL&&tam>0)
    {
       for(int i=0;i<tam;i++)
       {
    	   if(empleados[i].isEmpty==0)
    	   {
    		   acumulador+=empleados[i].salary;
    	   }
       }
    }

    return acumulador;
}

void informar(eEmployee vec[],int tam)
{

    int opcionInformes;
    int ordenamiento;
    float promedioSalarios;
    float acumuladorSalarios;
    int cantidadEmpleadosSuperanPromedio;


    do
    {
        opcionInformes=menuInformes();
        switch(opcionInformes)
        {
        case 1:

            if(getInt(&ordenamiento,"\nIngrese un numero de ordenamiento: 1-ascendente    0-descendente: ","\nError. Debe ingresar 0 o 1\n",0,1,0))
            {
                sortEmployees(vec,tam,ordenamiento);
                system("cls");
                printEmployees(vec,tam);
            }
            else
            {
                printf("\n*****No se pudo realizar el ordenamiento*****\n");
            }
            break;
        case 2:
            acumuladorSalarios=sumaDeSalarios(vec,tam);
            promedioSalarios=promedio(vec,tam);
            cantidadEmpleadosSuperanPromedio=cantidadDeEmpleadosSalarioMayorDelPromedio(vec,tam,promedioSalarios);
            system("cls");
            printf("\n*******Finanzas de la empresa*****\n\n");
            printf("Sueldo totales a pagar: $%.2f\nSalario promedio de los empleados: $%.2f\nCantidad de empleados que cobrar mayor o igual al promedio: %d\n",acumuladorSalarios,promedioSalarios,cantidadEmpleadosSuperanPromedio);
            break;
        case 3:
            break;
        default:
            printf("Ingrese un informe valido\n");
            break;
        }
        system("pause");
    }
    while(opcionInformes!=3);
}
int menuInformes(void)
{
    int opcion;
    system("cls");

    printf("*********Menu de Informes*********\n");
    printf("1-Ordenar lista de empleados\n");
    printf("2-Informar total y promedio de salarios\n");
    printf("3-Salir\n");

    printf("\n\nIngrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}
int menu (void)
{
    int opcion;
    system("cls");

    printf("*********Menu ABM e informes para empleados*********\n");
    printf("1-Alta de un empleado\n");
    printf("2-Modificar datos de un empleado\n");
    printf("3-Baja de un empleado\n");
    printf("4-Informar\n");
    printf("5-Salir\n");

    printf("\n\nIngrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void initEmployees(eEmployee empleados[],int tam)
{
      if(empleados!=NULL && tam>0)
      {
         for(int i=0;i<tam;i++)
        {
            empleados[i].isEmpty=1;
        }
      }
}
int askParameters(eEmployee* ingreso)
{
    int retorno=0;
    eEmployee empleado;
    system("cls");
    printf("*********Ingrese plantilla de datos*********\n");
    if(!getString(empleado.name,sizeof(empleado.name),"Ingrese el nombre del empleado: ","Error. Debe ser una cadena alfabetica",1))
    {
        printf("\nNo se pudo registrar ese nombre.\n");
    }
    else
    {
        if(!getString(empleado.lastName,sizeof(empleado.lastName),"Ingrese el apellido del empleado: ","Error. Debe ser una cadena alfabetica",1))
        {
            printf("\nNo se pudo registrar ese apellido.\n");
        }
        else
        {
            if(!getFloat(&empleado.salary,50,"Ingrese el sueldo del empleado: ","Error. Debe ser un salario numerico",1))
            {
                printf("\nNo se pudo registrar ese salario.\n");
            }
            else
            {
                if(!getInt(&empleado.sector,"Ingrese sector del empleado: ","Error. Debe ser un sector numerico entero entre 0 y 30",0,30,1))
                {
                    printf("\nNo se pudo registrar ese sector.\n");
                }
                else
                {
                    empleado.isEmpty=0;
                    *ingreso=empleado;
                    retorno=1;
                }
            }
        }
    }
    return retorno;
}

int findEmpty(eEmployee empleados[],int tam)
{
    int retorno=-1;
    if(empleados!=NULL&&tam>0)
    {
    	for(int i=0;i<tam;i++)
    	{
    	   if(empleados[i].isEmpty==1)
    	   {
    		   retorno=i;
    	   }
    	}
    }


    return retorno;
}


int addEmployees(eEmployee empleados[],int tam,int id,char name[],char lastName[],float salary,int sector)
{
   int retorno=0;
   int indice;
   if(empleados!=NULL&&name!=NULL&&lastName!=NULL)
   {
        indice=findEmpty(empleados,tam);
        if(indice==-1)
        {
            printf("\n\n*****No hay lugar disponible*****\n\n");
        }
        else
        {
            empleados[indice].id=id;
            strcpy(empleados[indice].name,name);
            strcpy(empleados[indice].lastName,lastName);
            empleados[indice].salary=salary;
            empleados[indice].sector=sector;
            empleados[indice].isEmpty=0;
            retorno=1;
        }
   }

   return retorno;
}

int findEmployeeById(eEmployee empleados[], int tam,int id)
{
    int retorno=-1;

    if(empleados!=NULL&&tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(empleados[i].id==id)
            {
                retorno=i;
            }
        }
    }

    return retorno;
}

int removeEmployee(eEmployee empleados[], int tam, int id)
{
    int retorno=0;
    int indice;
    char seguir='s';
    if(empleados!=NULL&&tam>0)
    {
        indice=findEmployeeById(empleados,tam,id);

        if(indice==-1||empleados[indice].isEmpty==1)
        {
            printf("\n*****No se encontro ese ID en la base de datos*****\n");
            retorno=2;
        }
        else

        {
            printEmployee(empleados[indice]);
            printf("\nSeguro desea eliminar a este empleado de la base de datos?\n");
            printf("s- para aceptar, oprima otra letra para cancelar: ");
            scanf("%c",&seguir);
            if(seguir=='s')
            {
                empleados[indice].isEmpty=1;
                retorno=1;
            }
        }
    }

    return retorno;
}

void printEmployee (eEmployee empleado)
{
    printf("\n%d  %10s    %10s    %11.2f      %d   ", empleado.id,empleado.name,empleado.lastName,empleado.salary,empleado.sector);

}

void printEmployees(eEmployee empleados[],int tam)
{
    int flag=0;

    printf("\n******Lista de empleados activos*******\n");
    printf("ID          NOMBRE     APELLIDO     SALARIO     SECTOR\n");

    for(int i=0;i<tam;i++)
    {
       if(empleados[i].isEmpty==0)
       {
          printEmployee(empleados[i]);
          flag=1;
       }
    }
    printf("\n\n");
    if(flag==0)
    {
        printf("\n*****No hay empleados cargados para mostrar*****\n\n");
    }
}

int sortEmployees(eEmployee empleados[],int tam,int order)
{
    eEmployee auxiliar;
    int retorno;
    if(empleados!=NULL&&tam>0&&(order==1||order==0))
    {
        if(order==1)
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(empleados[i].sector>empleados[j].sector)
                    {
                        auxiliar=empleados[i];
                        empleados[i]=empleados[j];
                        empleados[j]=auxiliar;
                        retorno=1;
                    }
                    else
                    {
                        if(empleados[i].sector==empleados[j].sector&&strcmp(empleados[i].lastName,empleados[j].lastName)>0)
                        {
                            auxiliar=empleados[i];
                            empleados[i]=empleados[j];
                            empleados[j]=auxiliar;
                            retorno=1;
                        }
                    }
                }
            }
        }
        else
        {
            for(int i=0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(empleados[i].sector<empleados[j].sector)
                    {
                        auxiliar=empleados[i];
                        empleados[i]=empleados[j];
                        empleados[j]=auxiliar;
                        retorno=1;
                    }
                    else
                    {

                        if(empleados[i].sector==empleados[j].sector&&strcmp(empleados[i].lastName,empleados[j].lastName)<0)
                        {
                            auxiliar=empleados[i];
                            empleados[i]=empleados[j];
                            empleados[j]=auxiliar;
                            retorno=1;
                        }
                    }
                }
            }
        }

    }

    return retorno;
}

int changeEmployeeData(eEmployee empleados[],int tam)
{
    int id;
    int retorno=0;
    int indice;
    int opcion;
    eEmployee auxiliar;
    int flag;
    system("cls");
    if(empleados!=NULL&&tam>0)
    {
        retorno=1;
        printf("\n*****Modificar datos de un empleado*****\n");
        if(getInt(&id,"\nIngrese ID de empleado: ","\nError. Debe ingresar un numero entero numerico mayor a 1000\n",1000,10000,0))
        {
        	system("cls");
            indice=findEmployeeById(empleados,tam,id);
            if(indice==-1||empleados[indice].isEmpty==1)
            {
                printf("\n*****No se encontro este ID en la base de datos*****\n\n");
            }
            else
            {


                do
                {

                    printf("*****Empleado seleccionado*****\n");
                    printEmployee(empleados[indice]);
                    printf("\n\n");
                    system("pause");
                    opcion=menuChanges();
                    flag=0;
                    switch(opcion)
                    {
                    case 1:
                        if(getString(auxiliar.name,sizeof(auxiliar.name),"\nIngrese nuevo nombre: ","Error debe ser una cadena alfabetica",0))
                        {
                            strcpy(empleados[indice].name,auxiliar.name);
                            flag=1;
                        }
                        break;
                    case 2:
                        if(getString(auxiliar.lastName,sizeof(auxiliar.lastName),"\nIngrese nuevo apellido: ","Error debe ser una cadena alfabetica",0))
                        {
                            strcpy(empleados[indice].lastName,auxiliar.lastName);
                            flag=1;
                        }
                        break;
                    case 3:
                        if(getFloat(&auxiliar.salary,50,"\nIngrese nuevo sueldo: ","Error debe ser un valor de caracter numerico",0))
                        {
                            empleados[indice].salary=auxiliar.salary;
                            flag=1;
                        }
                        break;
                    case 4:
                        if(getInt(&auxiliar.sector,"\nIngrese nuevo sector: ","Error. Debe ser un valor numerico entero de 0 a 30",0,30,0))
                        {
                            empleados[indice].sector=auxiliar.sector;
                            flag=1;
                        }
                        break;
                    case 5:
                        break;
                    default:
                        printf("\n*****Error. Ingrese una opcion valida*****\n\n");
                        system("pause");
                        break;
                    }

                    system("cls");
                }while(opcion!=5);

                if(flag==1)
                {
                    printf("\n******Los cambios se han cargado con exito!!!****\n");
                }
            }
        }
    }
    return retorno;
}

int menuChanges (void)
{
    system("cls");
    int opcion;
    printf("******Eleccion de dato a modificar********\n");
    printf("1-Nombre\n");
    printf("2-Apellido\n");
    printf("3-Sueldo\n");
    printf("4-Sector\n");
    printf("5-Salir");

    printf("\nQue dato desea cambiar?: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}


