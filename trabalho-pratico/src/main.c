/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include <stdio.h>
#include <string.h>

#include "../include/catalog.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Número de argumentos inválido (%i).\n", argc);
        return -1;
    }
    else puts("Número de argumentos válido! (3)");

    FILE *drivers;
        char *driverspath;
        driverspath = (char *) malloc(1000 * sizeof(char));
        strcpy(driverspath, argv[1]);
        strcat(driverspath, "drivers.csv");
        drivers = fopen(driverspath, "r");
        free(driverspath);
        if (drivers != NULL) puts("Ficheiro dos Drivers aberto");
    FILE *users;
        char *userspath;
        userspath = (char *) malloc(1000 * sizeof(char));
        strcpy(userspath, argv[1]);
        strcat(userspath, "users.csv");
        users = fopen(userspath, "r");
        free(userspath);
        if (users != NULL) puts("Ficheiro dos Users aberto");
    FILE *rides;
        char *ridespath;
        ridespath = (char *) malloc(1000 * sizeof(char));
        strcpy(ridespath, argv[1]);
        strcat(ridespath, "rides.csv");
        rides = fopen(ridespath, "r");
        free(ridespath);
        if (rides != NULL) puts("Ficheiro das Rides aberto");
    FILE *inputs;
        inputs = fopen(argv[2], "r");
        if (inputs != NULL) puts("Ficheiro dos Inputs aberto");

    system("mkdir Resultados");                                               // Criar diretório para os Resultados

    inserir_dados(drivers, users, rides, inputs);                             // Inserir dados nos catálogos

    fclose(drivers);
        if (drivers != NULL) puts("Ficheiro dos Drivers aberto");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides aberto");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users aberto");
    fclose(inputs);
        if (inputs != NULL) puts("Ficheiro dos Inputs aberto");
    
    return 0;
}
