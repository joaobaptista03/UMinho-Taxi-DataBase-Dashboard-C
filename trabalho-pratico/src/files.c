/**
 * @file files.c
 * Este ficheiro contém o contrúdo das funções relacionadas com os files.
 * 
 */

#include "../include/files.h"

void open_files(char *csv_path, char *inputs_path) {
    
    FILE *drivers;
        char *driverspath;
        driverspath = (char *) malloc(1000 * sizeof(char));
        strcpy(driverspath, csv_path);
        strcat(driverspath, "/drivers.csv");
        drivers = fopen(driverspath, "r");
        free(driverspath);
        if (drivers != NULL) puts("Ficheiro dos Drivers aberto");
        else puts("Erro na abertura do ficheiro dos Drivers");

    FILE *users;
        char *userspath;
        userspath = (char *) malloc(1000 * sizeof(char));
        strcpy(userspath, csv_path);
        strcat(userspath, "/users.csv");
        users = fopen(userspath, "r");
        free(userspath);
        if (users != NULL) puts("Ficheiro dos Users aberto");
        else puts("Erro na abertura do ficheiro dos Users");

    FILE *rides;
        char *ridespath;
        ridespath = (char *) malloc(1000 * sizeof(char));
        strcpy(ridespath, csv_path);
        strcat(ridespath, "/rides.csv");
        rides = fopen(ridespath, "r");
        free(ridespath);
        if (rides != NULL) puts("Ficheiro das Rides aberto");
        else puts("Erro na abertura do ficheiro das Rides");

    FILE *inputs;
        inputs = fopen(inputs_path, "r");
        if (inputs != NULL) puts("Ficheiro dos Inputs aberto\n");

    inserir_dados(drivers, users, rides, inputs);                             // Inserir dados nos catálogos

    fclose(drivers);
        if (drivers != NULL) puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");
    fclose(inputs);
        if (inputs != NULL) puts("Ficheiro dos Inputs fechado\n");
}