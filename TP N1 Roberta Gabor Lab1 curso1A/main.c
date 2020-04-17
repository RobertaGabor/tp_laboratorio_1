#include <stdio.h>
#include <stdlib.h>
#include "lab1_tp1.h"

int main()
{
    int numero1;
    int numero2;
    int seguir=0;
    int opcionEjecutar;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int flag=0;
    int resultadoMultiplicacion;
    long long int resultadoFactorialNum1;
    long long int resultadoFactorialNum2;
    do
    {
        opcionEjecutar=menuDesplegado(flag,numero1,numero2);
        switch(opcionEjecutar)
        {
        case 1:
            pedirPrimerNumero(&numero1);
            flag=1;
            break;
        case 2:
            if(flag==1)
            {
                pedirSegundoNumero(&numero2);
                flag=2;
            }
            else
            {
                printf("\nDebe ingresar antes el primer operando\n\n\n");
                system("pause");
            }
            break;
        case 3:
            if(flag==2)
            {
                resultadoSuma=suma(numero1,numero2);
                resultadoResta=resta(numero1,numero2);
                resultadoDivision=division(numero1,numero2);
                resultadoMultiplicacion=multiplicacion(numero1,numero2);
                resultadoFactorialNum1=factorial(numero1);
                resultadoFactorialNum2=factorial(numero2);
                printf("\n:::calculando:::\n");
                system("pause");
                flag=3;
            }
            else
            {
                printf("\nDebe ingresar primero los dos operandos\n\n\n");
                system("pause");
            }
            break;
        case 4:
            if(flag==3)
            {
                system("cls");
                printf("\n::::Resultados::::\n\n");
                printf("El resultado de %d+%d es: %d\n",numero1,numero2,resultadoSuma);
                printf("El resultado de %d-%d es: %d\n",numero1,numero2,resultadoResta);
                if(resultadoDivision==0)
                {
                    if(numero2==0)
                    {
                        printf("No se puede realizar la division de %d por %d, el segundo numero no puede ser 0. Ingrese otro\n",numero1,numero2);
                    }
                    else

                    {
                        printf("El resultado de s de poner 0 dividido cualquier numero da 0\n");
                    }
                }
                else
                {
                    printf("El resultado de %d/%d es %.2f\n",numero1,numero2,resultadoDivision);
                }

                printf("El resultado de %d*%d es %d\n",numero1,numero2,resultadoMultiplicacion);

                if(resultadoFactorialNum1==-1)
                {
                    printf("No se puede hacer el factorial de %d porque es un numero negativo\n",numero1);
                }
                else
                {
                    printf("El factorial de %d es: %lld\n",numero1,resultadoFactorialNum1);
                }
                if(resultadoFactorialNum2==-1)
                {
                    printf("No se puede hacer el factorial de %d porque es un numero negativo\n",numero2);
                }
                else
                {
                    printf("El factorial de %d es: %lld\n",numero2,resultadoFactorialNum2);
                }
                resetFlag(&flag);
                system("pause");
            }
            else
            {
                printf("\nPrimero debe calcular las operaciones\n\n\n");
                system("pause");
            }
            break;
        case 5:
            seguir=-1;
            break;
        default:
            printf("\nError, debe ingresar una opcion valida. Vuelva a intentar o presione 5 para salir\n\n\n");
            resetFlag(&flag);
            system("pause");
            break;
        }

        system("cls");
    }
    while(seguir==0);

    return 0;
}
