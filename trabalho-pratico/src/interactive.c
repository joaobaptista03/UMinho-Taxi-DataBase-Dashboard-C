/**
 * @file interactive.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com o modo interativo.
 * 
 */

#include "../include/interactive.h"

void interactive () {

    puts("Bem-vindo ao modo Interativo! Para continuar, coloque o caminho do diretório dos ficheiros CSV. De seguida, após clicar em ENTER, coloque o caminho para o ficheiro dos inputs!\n");

    char csvs[200];
    scanf("%s", csvs);
    char input_file[200];
    scanf("%s", input_file);

    FILE *drivers = open_files(csvs, "/drivers.csv");
    FILE *users = open_files(csvs, "/users.csv");
    FILE *rides = open_files(csvs, "/rides.csv");
    FILE *inputs; inputs = fopen(input_file, "r");

    if ((drivers == NULL) || (users == NULL) || (rides == NULL) || (inputs == NULL)) {
        puts("\nErro na abertura de um dos ficheiros! Verifica os caminhos introduzido.");
        return;
    }

    Driver *drivers_cat = inserir_drivers(drivers);
    return_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
        if (drivers != NULL) puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");

    char *input; input = malloc(100 * sizeof(char));
    while ((scanf("%s", input)) && (stricmp(input, "EXIT") != 0)) {

        

    }

    fclose(inputs);
        if (inputs != NULL) puts("Ficheiro dos Inputs fechado\n");

    free(input);
}