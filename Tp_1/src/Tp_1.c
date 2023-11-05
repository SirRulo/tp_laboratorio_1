#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"

int main(){
    setbuf (stdout, NULL);
    int kilometros;
    int precioAerolineas;
    int precioLatam;
    float precioUnitarioAerolineas;
    float precioUnitarioLatam;
    float tarjetaDebitoAerolineas;
    float tarjetaCreditoAerolineas;
    float tarjetaDebitoLatam;
    float tarjetaCreditoLatam;
    float bitcoinAerolineas;
    float bitcoinLatam;
    float diferenciaPrecio;
    int opcion;
    char salir = 'n';
    //holis
    do{
        opcion = menu();
        switch(opcion){             tarjetaDebitoAerolineas = descuento(precioAerolineas);
                tarjetaCreditoAerolineas = aumento(precioAerolineas);
                tarjetaDebitoLatam = descuento(precioLatam);
                tarjetaCreditoLatam = aumento(precioLatam);
                bitcoinAerolineas = convertir(precioAerolineas);
                bitcoinLatam = convertir(precioLatam);
                precioUnitarioAerolineas = dividirEnteros(precioAerolineas,kilometros);
                precioUnitarioLatam = dividirEnteros(precioLatam,kilometros);
                diferenciaPrecio = diferencia(precioAerolineas, precioLatam);

                printf("Todos los costos han sido calculados correctamente.\n\n");
                system("pause");
                break;
            case 4:
            	system("cls");
                printf("Km Ingresados: %d\n\n", kilometros);
                printf("Precio de Latam: %d\n", precioLatam);
                printf("El precio con tarjeta de debito es de: %.2f\n", tarjetaDebitoLatam);
                printf("El precio con tarjeta de credito es de: %.2f\n", tarjetaCreditoLatam);
                printf("El precio en bitcoins es de: %.2f\n", bitcoinLatam);
                printf("El precio unitario para Latam es: %.2f\n\n", precioUnitarioLatam);
                printf("Precio de Aerolineas: %d\n", precioAerolineas);
                printf("Precio con tarjeta de debito: %.2f\n", tarjetaDebitoAerolineas);
                printf("El precio con tarjeta de credito es de: %.2f\n", tarjetaCreditoAerolineas);
                printf("El precio en bitcoins es de: %.2f\n", bitcoinAerolineas);
                printf("El precio unitario para aerolineas es: %.2f\n\n", precioUnitarioAerolineas);
                printf("La diferencia de precio es de: %.2f\n\n", diferenciaPrecio);
                system("pause");
                break;
            case 5:
            	system("cls");
                kilometros = 7090;
                precioLatam = 159339;
                precioAerolineas = 162965;
                tarjetaDebitoAerolineas = descuento(precioAerolineas);
                tarjetaCreditoAerolineas = aumento(precioAerolineas);
                tarjetaDebitoLatam = descuento(precioLatam);
                tarjetaCreditoLatam = aumento(precioLatam);
                bitcoinAerolineas = convertir(precioAerolineas);
                bitcoinLatam = convertir(precioLatam);
                precioUnitarioAerolineas = dividirEnteros(precioAerolineas,kilometros);
                precioUnitarioLatam = dividirEnteros(precioLatam,kilometros);
                diferenciaPrecio = diferencia(precioAerolineas, precioLatam);
                printf("Km Ingresados: %d\n\n", kilometros);
                printf("Precio de Latam: %d\n", precioLatam);
                printf("El precio con tarjeta de debito es de: %.2f\n", tarjetaDebitoLatam);
                printf("El precio con tarjeta de credito es de: %.2f\n", tarjetaCreditoLatam);
                printf("El precio en bitcoins es de: %.2f\n", bitcoinLatam);
                printf("El precio unitario para Latam es: %.2f\n\n", precioUnitarioLatam);
                printf("Precio de Aerolineas: %d\n", precioAerolineas);
                printf("Precio con tarjeta de debito: %.2f\n", tarjetaDebitoAerolineas);
                printf("El precio con tarjeta de credito es de: %.2f\n", tarjetaCreditoAerolineas);
                printf("El precio en bitcoins es de: %.2f\n", bitcoinAerolineas);
                printf("El precio unitario para aerolineas es: %.2f\n\n", precioUnitarioAerolineas);
                printf("La diferencia de precio es de: %.2f\n\n", diferenciaPrecio);
                system("pause");
                break;
            case 6:
            	system("cls");
                printf("Esta seguro que quiere salir? Para salir ingrese 's': ");
                fflush(stdin);
                scanf("%c", &salir);
                break;
            default:
                do{
                	system("cls");
                    printf("La opcion que ingresaste no es valida. Reingrese para volver al menu de opciones: ");
                    scanf("%d", &opcion);
                }while(opcion<1 || opcion>6);

                break;
        }
    }while(salir!='s');

    return 0;
}
