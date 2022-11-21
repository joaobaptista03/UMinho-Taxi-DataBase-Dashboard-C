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

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    FILE *drivers;
        char *driverspath;
        driverspath = (char *) malloc(1000 * sizeof(char));
        strcpy(driverspath, argv[1]);
        strcat(driverspath, "/drivers.csv");
        drivers = fopen(driverspath, "r");
        free(driverspath);
        if (drivers != NULL) puts("Ficheiro dos Drivers aberto");
        else puts("Erro na abertura do ficheiro dos Drivers");
    FILE *users;
        char *userspath;
        userspath = (char *) malloc(1000 * sizeof(char));
        strcpy(userspath, argv[1]);
        strcat(userspath, "/users.csv");
        users = fopen(userspath, "r");
        free(userspath);
        if (users != NULL) puts("Ficheiro dos Users aberto");
        else puts("Erro na abertura do ficheiro dos Users");
    FILE *rides;
        char *ridespath;
        ridespath = (char *) malloc(1000 * sizeof(char));
        strcpy(ridespath, argv[1]);
        strcat(ridespath, "/rides.csv");
        rides = fopen(ridespath, "r");
        free(ridespath);
        if (rides != NULL) puts("Ficheiro das Rides aberto");
        else puts("Erro na abertura do ficheiro das Rides");
    FILE *inputs;
        inputs = fopen(argv[2], "r");
        if (inputs != NULL) puts("Ficheiro dos Inputs aberto");

    system("mkdir Resultados");                                               // Criar diretório para os Resultados
    puts("");

    inserir_dados(drivers, users, rides, inputs);                             // Inserir dados nos catálogos

    fclose(drivers);
        if (drivers != NULL) puts("Ficheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");
    fclose(inputs);
        if (inputs != NULL) puts("Ficheiro dos Inputs fechado\n");

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Programa Terminado (%f segundos)\n", cpu_time_used );
    
    return 0;
}
