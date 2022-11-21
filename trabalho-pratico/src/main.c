/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/file_drivers.h"
#include "../include/file_users.h"
#include "../include/file_rides.h"
#include "../include/file_inputs.h"
#include "../include/catalog.h"

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

    FILE *drivers = open_file_drivers(argv[1]);
    FILE *users = open_file_users(argv[1]);
    FILE *rides = open_file_rides(argv[1]);
    FILE *inputs = open_file_inputs(argv[2]);

    inserir_dados(drivers, users, rides, inputs);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Programa Terminado (%f segundos)\n\n", cpu_time_used );

    fclose(drivers);
        if (drivers != NULL) puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");
    fclose(inputs);
        if (inputs != NULL) puts("Ficheiro dos Inputs fechado\n");
    
    return 0;
}
