/**
 * @file file_rides.c
 * Este ficheiro abre o ficheiro rides.csv.
 * 
 */

#include "../include/file_rides.h"

FILE* open_file_rides(char *csv_path) {
    
    FILE *rides;
        char *ridespath;
        ridespath = (char *) malloc(1000 * sizeof(char));
        strcpy(ridespath, csv_path);
        strcat(ridespath, "/rides.csv");
        rides = fopen(ridespath, "r");
        free(ridespath);
        if (rides != NULL) puts("Ficheiro das Rides aberto");
        else puts("Erro na abertura do ficheiro das Rides");

    return rides;
}