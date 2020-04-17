#include <stdio.h>
#include <stdlib.h>


int menuDesplegado(int flagFuncion,int x,int y)
{
    int validacion;
    if(flagFuncion==2||flagFuncion==3)
    {
        printf("______________________________________________\n");
        printf("|        BIENVENIDO A LA CALCULADORA         |\n");
        printf("______________________________________________\n");
        system("pause");
        printf("\n***************Menu de opciones***************\n");
        printf("1 - Ingresar 1er Operando\n");
        printf("2 - Ingresar 2do Operando\n");
        printf("3 - Calcular todas las operaciones siguiente: \n");
        printf("A)Calcular la suma (%d+%d)\n",x,y);
        printf("B)Calcular la resta (%d-%d)\n",x,y);
        printf("C)Calcular la division (%d-%d)\n",x,y);
        printf("D)Calcular la multiplicacion (%d*%d)\n",x,y);
        printf("E)Calcular el factorial de %d\n",x);
        printf("F)Calcular el factorial de %d\n",y);
        printf("4 - Informar los resultados de las operaciones\n");
        printf("5 - Salir\n");
    }
    else
    {
           if(flagFuncion==1)
           {
                printf("______________________________________________\n");
                printf("|        BIENVENIDO A LA CALCULADORA         |\n");
                printf("______________________________________________\n");
                system("pause");
                printf("\n***************Menu de opciones***************\n");
                printf("1 - Ingresar 1er Operando\n");
                printf("2 - Ingresar 2do Operando\n");
                printf("3 - Calcular todas las operaciones siguiente: \n");
                printf("A)Calcular la suma (%d+B)\n",x);
                printf("B)Calcular la resta (%d-B)\n",x);
                printf("C)Calcular la division (%d-B)\n",x);
                printf("D)Calcular la multiplicacion (%d*B)\n",x);
                printf("E)Calcular el factorial de %d\n",x);
                printf("F)Calcular el factorial de B\n");
                printf("4 - Informar los resultados de las operaciones\n");
                printf("5 - Salir\n");
           }
           else
           {
                printf("______________________________________________\n");
                printf("|        BIENVENIDO A LA CALCULADORA         |\n");
                printf("______________________________________________\n");
                system("pause");
                printf("\n***************Menu de opciones***************\n");
                printf("1 - Ingresar 1er Operando\n");
                printf("2 - Ingresar 2do Operando\n");
                printf("3 - Calcular todas las operaciones siguiente: \n");
                printf("A)Calcular la suma (A+B)\n");
                printf("B)Calcular la resta (A-B)\n");
                printf("C)Calcular la division (A/B)\n");
                printf("D)Calcular la multiplicacion (A*B)\n");
                printf("E)Calcular el factorial de A\n");
                printf("F)Calcular el factorial de B\n");
                printf("4 - Informar los resultados de las operaciones\n");
                printf("5 - Salir\n");
           }
    }

    printf("Que desea hacer?: ");
    fflush(stdin);
    scanf("%d",&validacion);
    printf("\n\n");

    return validacion;
}

void pedirPrimerNumero(int* x)
{
    printf("\nIngrese el primer operando: ");
    scanf("%d",x);
}

void pedirSegundoNumero(int* y)
{
    printf("\nIngrese el segundo operando: ");
    scanf("%d",y);
}

int suma(int x,int y)
{
    int sumaResultado;
    sumaResultado=x+y;

    return sumaResultado;
}

int resta(int x,int y)
{
    int restaResultado;
    restaResultado=x-y;

    return restaResultado;
}

float division(int x,int y)
{
    float validacionDivision=0;

    if(y!=0)
    {
        validacionDivision=(float)x/y;
    }
    return validacionDivision;
}

int multiplicacion(int x, int y)
{
    int productoResultado;
    productoResultado=x*y;

    return productoResultado;
}

long long int factorial(int x)
{
    long long int factorialResultado=-1;
    if(x>20)
    {
        factorialResultado=0;
    }
    else
    {
        if(x>=0)
        {
            if (x==1||x==0)
            {
                factorialResultado=1;
            }
            else
            {
                factorialResultado=x*factorial(x-1);
            }
        }
    }

    return factorialResultado;
}

void resetFlag (int* x)
{
    *x=0;
}

