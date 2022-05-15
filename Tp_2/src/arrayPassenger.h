#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;

} Passenger;

void printPassenger(Passenger p);
int initPassengers(Passenger vec[], int tam);
int printPassengers(Passenger vec[], int tam);
int findFreePassenger(Passenger vec[], int tam, int* pIndex);
int addPassenger(Passenger vec[], int tam, int* pId);
int findPassengerById(Passenger vec[], int tam, int id, int* pIndex);
int removePassenger(Passenger vec[], int tam);
int modifyPassenger(Passenger vec[], int tam);
int sortPassengers(Passenger vec[], int tam);
int sortPassengersByCode(Passenger vec[], int tam);
int subMenuModify();

#endif
