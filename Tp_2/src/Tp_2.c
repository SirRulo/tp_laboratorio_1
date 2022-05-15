#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayPassenger.h"

#define TAM 2000

int menu();

int main()
{
    char salir = 'n';
    int nextId = 10000;
    int inform;
    Passenger lista[TAM];

    initPassengers(lista, TAM);

    do{
            switch (menu()){

                case 1:
                    //printf("Alta pasajero\n");
                    if (addPassenger(lista, TAM, &nextId)){
                        printf("Pasajero agregado con exito!!!\n");
                    }else{
                        printf("Problema al hacer el alta del pasajero");
                    }
                    break;
                case 2:
                    //printf("Modificar pasajero\n");
                    if (modifyPassenger(lista, TAM) == 0){
                        printf("Problema al hacer la modificacion de pasajero");
                    }
                    break;
                case 3:
                    //printf("Baja pasajero\n");
                    if (removePassenger(lista, TAM) == 0){
                        printf("Problema al hacer la baja del pasajero");
                    }
                    break;
                case 4:
                    system("cls");
                    printf("***Informe de Pasajeros***\n\n");
                    printf("Que desea listar?\n");
                    printf("1-Listar por Apellido y Tipo de Pasajero\n");
                    printf("2-Listar por Codigo de Vuelo y Estado de Vuelos 'ACTIVO'\n\n");
                    printf("Ingrese una opcion: ");
                    scanf("%d", &inform);

                    while(inform <= 0 || inform >= 3){
                        printf("La opcion que ingresaste no existe. Reingrese opcion:");
                        scanf("%d", &inform);
                    }

                    if(inform == 1){
                        sortPassengers(lista, TAM);
                    }else{
                       sortPassengersByCode(lista, TAM);
                    }

                    //printf("Informar pasajero\n");
                    printPassengers(lista, TAM);
                    break;
                case 5:
                    salir = 's';
                    break;
            }
        system("pause");

    }while(salir != 's');

    return 0;
}

int menu(){

    int opcion;
    system("cls");
    printf("  *** Menu de Opciones ***\n\n");
    printf("1- ALTAS:\n");
    printf("2- MODIFICAR:\n");
    printf("3- BAJA:\n");
    printf("4- INFORMAR:\n");
    printf("5- SALIR:\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
