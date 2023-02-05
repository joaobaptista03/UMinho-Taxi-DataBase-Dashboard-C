/**
 * @file batch.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com o modo Batch.
 * 
 */

#include "../include/batch.h"

void batch (char **argv) {
    FILE *drivers = open_files(argv[1], "/drivers.csv");
        if (drivers == NULL) return;
    FILE *users = open_files(argv[1], "/users.csv");
        if (users == NULL) return;
    FILE *rides = open_files(argv[1], "/rides.csv");
        if (rides == NULL) return;
    FILE *inputs; inputs = open_files(argv[2], "");
        if (inputs == NULL) return;

    inserir_drivers(drivers);
    inserir_users(users);
    inserir_rides(rides);

    fclose(drivers);
        puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        puts("Ficheiro dos Rides fechado");
    fclose(users);
        puts("Ficheiro dos Users fechado");

    handle_inputs(inputs);

    free_all_stats();
    free_drivers();
    free_users();
    free_rides();

    fclose(inputs);
        if (inputs != NULL) puts("\nFicheiro dos Inputs fechado\n");
}