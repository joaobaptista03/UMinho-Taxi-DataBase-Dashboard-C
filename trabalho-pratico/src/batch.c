/**
 * @file batch.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com o modo Batch.
 * 
 */

#include "../include/batch.h"

struct driver_struct {
    Driver* driverscat;
    GHashTable* drivershash;
};

struct user_struct {
    User* userscat;
    GHashTable* usershash;
};

void batch (char **argv) {
    FILE *drivers = open_files(argv[1], "/drivers.csv");
    FILE *users = open_files(argv[1], "/users.csv");
    FILE *rides = open_files(argv[1], "/rides.csv");
    FILE *inputs; inputs = fopen(argv[2], "r");

    driver_struct drivers_struct = inserir_drivers(drivers);
    user_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
        if (drivers != NULL) puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");

    handle_inputs(inputs);

    free(drivers_struct.driverscat);
    free(users_struct.userscat);
    free(rides_cat);
    g_hash_table_destroy(users_struct.usershash);
    g_hash_table_destroy(drivers_struct.drivershash);
    
    fclose(inputs);
        if (inputs != NULL) puts("\nFicheiro dos Inputs fechado\n");
}