#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int menu(){
    int opcion;
    system("cls");
    printf("  *** Menu de Opciones ***\n\n");
    printf("1- Ingresar Kilometros:\n");
    printf("2- Ingresar Precio de Vuelos:\n");
    printf("3- Calcular todos los costos:\n");
    printf("4- Informar Resultados\n");
    printf("5- Carga forzada de datos\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

float dividirEnteros(int primerValor, int segundoValor){
    float resultado;

    resultado = primerValor / segundoValor;

    return resultado;
}

float descuento(int primerValor){
    float resultado;
    float resultadoDescuento;

    resultado = (primerValor * 10) / 100;
    resultadoDescuento = primerValor - resultado;

    return resultadoDescuento;
}

float aumento(int primerValor){
    float resultado;
    float resultadoAumento;

    resultado = (primerValor * 25) / 100;
    resultadoAumento = primerValor + resultado;

    return resultadoAumento;
}

float convertir(int primerValor){
    float resultado;

    resultado = (primerValor * 1) / 4606954.55;

    return resultado;
}

float diferencia(int primerValor, int segundoValor){
    float resultado;

    if (primerValor > segundoValor){
        resultado = primerValor - segundoValor;
    }else{
        resultado = segundoValor - primerValor;
    }

    return resultado;
}



