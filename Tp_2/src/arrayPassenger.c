#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayPassenger.h"

#define TAM 5

void printPassenger(Passenger p){

    printf("  %4d    %10s    %10s    %2d    %10s    %9.2f\n", p.id, p.name, p.lastName, p.typePassenger, p.flycode, p.price);

}

int initPassengers(Passenger vec[], int tam){

    int itsOk = 0;

    if (vec != NULL && tam > 0){
        for (int i=0; i<tam; i++){
            vec[i].isEmpty = 1;
        }

        itsOk = 1;
    }

    return itsOk;
}

int printPassengers(Passenger vec[], int tam){

    int itsOk = 0;
    int flag = 0;

    if (vec != NULL && tam > 0){
        system("cls");
        printf("                   *** Listado de Pasajeros ***\n\n");
        printf("   ID      NOMBRE        APELLIDO       TIPO       CODIGO        PRECIO\n");
        printf("-----------------------------------------------------------------------------\n");
        for (int i=0; i<tam; i++){
            if (vec[i].isEmpty == 0){
                printPassenger(vec[i]);
                flag++;
            }
        }
        if (flag == 0){
            system("cls");
            printf("                    No hay pasajeros en el sistema");
        }

        printf("\n\n");
        itsOk = 1;
    }

    return itsOk;
}

int findFreePassenger(Passenger vec[], int tam, int* pIndex){

    int itsOk = 0;

    if (vec != NULL && tam > 0 && pIndex != NULL){
        *pIndex = -1;
        for (int i=0; i<tam; i++){
            if (vec[i].isEmpty == 1){
                *pIndex = i;
                break;
            }
        }

        itsOk = 1;
    }

    return itsOk;
}


int addPassenger(Passenger vec[], int tam, int* pId){

    int itsOk = 0;
    int indice;
    char auxCad[100];
    Passenger newPassenger;

    if (vec != NULL && tam > 0 && pId != NULL){
        if (findFreePassenger(vec, tam, &indice)){
            system("cls");
            if (indice == -1){
                printf("No hay lugar en el sistema\n");
            }else{
                //aca hay lugar
                printf("Ingrese el nombre del pasajero: ");
                fflush(stdin);
                gets(auxCad);
                strcpy(newPassenger.name, auxCad);
                system("cls");
                printf("Ingrese el apellido del pasajero: ");
                fflush(stdin);
                gets(auxCad);
                strcpy(newPassenger.lastName, auxCad);

                while (strlen(auxCad) >= 51){
                    system("cls");
                    printf("Nombre demasiado largo. Reingrese nombre: ");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(newPassenger.name, auxCad);
                    system("cls");
                    printf("Apellido demasiado largo. Reingrese apellido: ");
                    fflush(stdin);
                    gets(auxCad);
                    strcpy(newPassenger.lastName, auxCad);
                }
                system("cls");
                printf("Tipo de Pasajero?\n");
                printf("1- Infante (menor de 2)\n");
                printf("2- Menor (2 a 12)\n");
                printf("3- Adulto (12 a 59)\n");
                printf("4- Senector (+60)\n\n");
                printf("Ingrese el Tipo de Pasajero: ");
                scanf("%d", &newPassenger.typePassenger);

                while(newPassenger.typePassenger >= 5 || newPassenger.typePassenger <= 0){
                    printf("Esta opcion no existe. Reingrese Tipo de Pasajero: ");
                    scanf("%d", &newPassenger.typePassenger);
                }

                system("cls");
                printf("Ingrese Codigo de Vuelo: ");
                fflush(stdin);
                gets(auxCad);
                strcpy(newPassenger.flycode, auxCad);

                system("cls");
                printf("Ingrese Precio: ");
                scanf("%f", &newPassenger.price);

                newPassenger.isEmpty = 0;
                newPassenger.id = *pId;
                *pId = *pId + 1;
                vec[indice] = newPassenger;

                itsOk = 1;
            }
        }else{
            system("cls");
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    return itsOk;
}

int findPassengerById(Passenger vec[], int tam, int id, int* pIndex){

    int itsOk = 0;

    if (vec != NULL && tam > 0 && pIndex != NULL && id > 0){
        *pIndex = -1;
        for (int i=0; i<tam; i++){
            if (vec[i].isEmpty == 0 && vec[i].id == id){
                *pIndex = i;
                break;
            }
        }

        itsOk = 1;
    }

    return itsOk;
}

int removePassenger(Passenger vec[], int tam){

    int itsOk = 0;
    int indice;
    int id;
    char confirma;

    if (vec != NULL && tam > 0){
        printPassengers(vec, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if (findPassengerById(vec, tam, id, &indice)){
            if (indice == -1){
                printf("No hay pasajero con id %d\n", id);
            }else{
                printPassenger(vec[indice]);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if (confirma != 'S' && confirma != 's'){
                    printf("Baja cancelada por el usuario\n");
                }else{
                    vec[indice].isEmpty = 1;
                    printf("Baja realizada con exito!!!\n");

                    itsOk = 1;
                }
            }
        }else{
            printf("Ocurrio un problema al buscar un pasajero\n");
        }
    }

    return itsOk;
}

int modifyPassenger(Passenger vec[], int tam){

    int itsOk = 0;
    int indice;
    int id;
    char auxCad[100];
    char salir = 'n';

    if (vec != NULL && tam > 0){
        printPassengers(vec, tam);
        printf("Ingrese Id: ");
        scanf("%d", &id);

        if (findPassengerById(vec, tam, id, &indice)){
            if (indice == -1){
                printf("No hay pasajero con id %d\n", id);
            }else{

                printPassenger(vec[indice]);

                do{
                    switch (subMenuModify()){
                        case 1:
                            system("cls");
                            printf("Ingrese nuevo nombre: ");
                            fflush(stdin);
                            gets(auxCad);
                            strcpy(vec[indice].name, auxCad);

                            while (strlen(auxCad) >= 51){
                                printf("Nombre demasiado largo. Reingrese nombre: ");
                                fflush(stdin);
                                gets(auxCad);
                                strcpy(vec[indice].name, auxCad);
                            }

                            printf("El nombre se ha modificado con exito!!!\n");
                            break;
                        case 2:
                            system("cls");
                            printf("Ingrese nuevo Apellido: ");
                            fflush(stdin);
                            gets(auxCad);
                            strcpy(vec[indice].lastName, auxCad);

                            while (strlen(auxCad) >= 51){
                                printf("Apellido demasiado largo. Reingrese apellido: ");
                                fflush(stdin);
                                gets(auxCad);
                                strcpy(vec[indice].lastName, auxCad);
                            }

                            printf("El apellido se a modificado con exito!!!\n");
                            break;
                        case 3:
                            system("cls");
                            printf("1- Infante (menor de 2)\n");
                            printf("2- Menor (2 a 12)\n");
                            printf("3- Adulto (12 a 59)\n");
                            printf("4- Senector (+60)\n\n");
                            printf("Ingrese nuevo Tipo de Pasajero: ");
                            scanf("%d", &vec[indice].typePassenger);

                            while(vec[indice].typePassenger >= 5 || vec[indice].typePassenger <= 0){
                                printf("Esta opcion no existe. Reingrese Tipo de Pasajero: ");
                                scanf("%d", &vec[indice].typePassenger);
                            }

                            printf("El tipo de pasajero se ha modificado con exito!!!\n");
                            break;
                        case 4:
                            system("cls");
                            printf("Ingrese nuevo Codigo de Vuelo: ");
                            fflush(stdin);
                            gets(auxCad);
                            strcpy(vec[indice].flycode, auxCad);
                            printf("El codigo de vuelo se ha modificado con exito!!!\n");
                            break;
                        case 5:
                            system("cls");
                            printf("Ingrese nuevo precio: ");
                            scanf("%f", &vec[indice].price);
                            printf("El precio se ha modificado con exito!!!\n");
                            break;
                        case 6:
                            system("cls");
                            printf("Ingrese nuevo Nombre: ");
                            fflush(stdin);
                            gets(auxCad);
                            strcpy(vec[indice].name, auxCad);

                            printf("Ingrese nuevo Apellido: ");
                            fflush(stdin);
                            gets(auxCad);
                            strcpy(vec[indice].lastName, auxCad);

                            while (strlen(auxCad) >= 51){
                                printf("Nombre demasiado largo. Reingrese nombre: ");
                                fflush(stdin);
                                gets(auxCad);
                                strcpy(vec[indice].name, auxCad);

                                printf("Apellido demasiado largo. Reingrese apellido: ");
                                fflush(stdin);
                                gets(auxCad);
                                strcpy(vec[indice].lastName, auxCad);
                            }
                            system("cls");

                            printf("1- Infante (menor de 2)\n");
                            printf("2- Menor (2 a 12)\n");
                            printf("3- Adulto (12 a 59)\n");
                            printf("4- Senector (+60)\n\n");
                            printf("Ingrese nuevo Tipo de Pasajero: ");
                            scanf("%d", &vec[indice].typePassenger);

                            while(vec[indice].typePassenger >= 5 || vec[indice].typePassenger <= 0){
                                printf("Esta opcion no existe. Reingrese Tipo de Pasajero: ");
                                scanf("%d", &vec[indice].typePassenger);
                            }

                            system("cls");
                            printf("Ingrese nuevo Codigo de Vuelo: ");
                            fflush(stdin);
                            gets(auxCad);
                            strcpy(vec[indice].flycode, auxCad);

                            system("cls");
                            printf("Ingrese nuevo precio: ");
                            scanf("%f", &vec[indice].price);

                            system("cls");
                            printf("Todo se ha modificado con exito!!!\n");
                            break;
                        case 7:
                            salir = 's';
                            break;
                    }
                    salir = 's';
                    system("pause");

                }while(salir != 's');
            }

        }else{
            printf("Ocurrio un problema al buscar un empleado\n");
        }
    }

    return itsOk;
}

int sortPassengers(Passenger vec[], int tam){

    int itsOk = 0;
    int opcionA;
    int opcionB;
    Passenger auxPassenger;

    if(vec != NULL && tam > 0){
        system("cls");
        printf("Que desea Informar?\n");
        printf("1- Apellidos\n");
        printf("2- Tipos de Pasajeros\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcionA);

        while(opcionA <= 0 || opcionA >= 3){
            printf("La opcion que ingresaste no existe. Reingrese Opcion:");
            scanf("%d", &opcionA);
        }

        if(opcionA == 1){
            system("cls");
            printf("Como desea Informar los Apellidos?\n");
            printf("1- Ascendente(A-Z)\n");
            printf("2- Descendente(Z-A)\n\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opcionB);

            while(opcionB <= 0 || opcionB >= 3){
                printf("La opcion que ingresaste no existe. Reingrese Opcion:");
                scanf("%d", &opcionB);
            }

            for(int i=0; i < tam -1; i++){

                if(opcionB == 1){

                    for(int j= i + 1; j < tam; j++){

                        if(strcmp(vec[i].lastName, vec[j].lastName) > 0){
                            auxPassenger = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxPassenger;
                        }
                    }
                }else{

                    for(int j= i + 1; j < tam; j++){

                        if(strcmp(vec[i].lastName, vec[j].lastName) < 0){
                            auxPassenger = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxPassenger;
                        }
                    }
                }
            }
        }else{
            system("cls");
            printf("Como desea Informar los Tipos de Pasajeros?\n");
            printf("1- Ascendente(1-4)\n");
            printf("2- Descendente(4-1)\n\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opcionB);

            while(opcionB <= 0 || opcionB >= 3){
                printf("La opcion que ingresaste no existe. Reingrese Opcion:");
                scanf("%d", &opcionB);
            }

            for(int i=0; i < tam -1; i++){

                if(opcionB == 1){

                    for(int j= i + 1; j < tam; j++){

                        if(vec[i].typePassenger > vec[j].typePassenger){
                            auxPassenger = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxPassenger;
                        }
                    }
                }else{

                    for(int j= i + 1; j < tam; j++){

                        if(vec[i].typePassenger < vec[j].typePassenger){
                            auxPassenger = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxPassenger;
                        }
                    }
                }
            }
        }

        itsOk = 1;
    }
    return itsOk;
}

int sortPassengersByCode(Passenger vec[], int tam){

    int itsOk = 0;
    int opcionA;
    int opcionB;
    Passenger auxPassenger;

    if(vec != NULL && tam > 0){
        system("cls");
        printf("Que desea Informar?\n");
        printf("1- Codigos de Vuelo\n");
        printf("2- Estado de Vuelos 'ACTIVOS'\n\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcionA);

        while(opcionA <= 0 || opcionA >= 2){
            printf("La opcion que ingresaste no existe. Reingrese Opcion:");
            scanf("%d", &opcionA);
        }

        if(opcionA == 1){
            system("cls");
            printf("Como desea Informar los Codigos de Vuelo?\n");
            printf("1- Ascendente(A-Z)\n");
            printf("2- Descendente(Z-A)\n\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &opcionB);

            while(opcionB <= 0 || opcionB >= 3){
                printf("La opcion que ingresaste no existe. Reingrese Opcion:");
                scanf("%d", &opcionB);
            }

            for(int i=0; i < tam -1; i++){

                if(opcionB == 1){

                    for(int j= i + 1; j < tam; j++){

                        if(strcmp(vec[i].flycode, vec[j].flycode) > 0){
                            auxPassenger = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxPassenger;
                        }
                    }
                }else{

                    for(int j= i + 1; j < tam; j++){

                        if(strcmp(vec[i].flycode, vec[j].flycode) < 0){
                            auxPassenger = vec[i];
                            vec[i] = vec[j];
                            vec[j] = auxPassenger;
                        }
                    }
                }
            }
        }

        itsOk = 1;
    }
    return itsOk;
}

int subMenuModify(){

    int opcion;
    system("cls");
    printf("*** Modificacion de Pasajero ***\n\n");
    printf("Que desea modificar?\n\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Tipo de Pasajero\n");
    printf("4- Codigo de Vuelo\n");
    printf("5- Precio\n");
    printf("6- Todo\n");
    printf("7- Cancelar modificacion\n\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
