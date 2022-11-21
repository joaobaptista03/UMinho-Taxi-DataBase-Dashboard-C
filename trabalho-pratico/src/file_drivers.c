/**
 * @file file_drivers.c
 * Este ficheiro abre o ficheiro drivers.csv.
 * 
 */

#include "../include/file_drivers.h"

FILE* open_file_drivers(char *csv_path) {
    
    FILE *drivers;
        char *driverspath;
        driverspath = (char *) malloc(1000 * sizeof(char));
        strcpy(driverspath, csv_path);
        strcat(driverspath, "/drivers.csv");
        drivers = fopen(driverspath, "r");
        free(driverspath);
        if (drivers != NULL) puts("Ficheiro dos Drivers aberto");
        else puts("Erro na abertura do ficheiro dos Drivers");

    return drivers;
}