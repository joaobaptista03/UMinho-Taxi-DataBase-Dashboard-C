/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include "../include/files.h"
#include "../include/cat_drivers.h"
#include "../include/cat_users.h"
#include "../include/cat_rides.h"
#include "../include/inputs.h"

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("\nNúmero de argumentos inválido (%i).\n", argc);
        return -1;
    }
    else puts("\nNúmero de argumentos válido! (3)");

    puts("");
    system("mkdir Resultados");                                               // Criar diretório para os Resultados
    puts("Diretório Resultados criado\n");

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    FILE *drivers = open_files(argv[1], "/drivers.csv");
    FILE *users = open_files(argv[1], "/users.csv");
    FILE *rides = open_files(argv[1], "/rides.csv");
    FILE *inputs; inputs = fopen(argv[2], "r");

    Driver *drivers_cat = inserir_drivers(drivers);
    return_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
        if (drivers != NULL) puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");

    handle_inputs(drivers_cat, users_struct.userscat, users_struct.usershash, rides_cat, inputs);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Programa Terminado (%f segundos)\n\n", cpu_time_used );

    fclose(inputs);
        if (inputs != NULL) puts("Ficheiro dos Inputs fechado\n");
    
    return 0;
}
