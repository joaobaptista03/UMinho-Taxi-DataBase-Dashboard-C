/**
 * @file interactive.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com o modo interativo.
 * 
 */

#include "../include/interactive.h"

void interactive () {

    puts("Bem-vindo ao modo Interativo! Para continuar, coloque o caminho do diretório dos ficheiros CSV.\n");

    char csvs[200];
    scanf("%s", csvs);

    FILE *drivers = open_files(csvs, "/drivers.csv");
    FILE *users = open_files(csvs, "/users.csv");
    FILE *rides = open_files(csvs, "/rides.csv");

    if ((drivers == NULL) || (users == NULL) || (rides == NULL)) {
        puts("\nErro na abertura de um dos ficheiros! Verifica os caminhos introduzido.");
        return;
    }

    inserir_drivers(drivers);
    inserir_users(users);
    inserir_rides(rides);

    fclose(drivers);
        if (drivers != NULL) puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");

    puts("\nAgora, insere os input's 1 a 1 da seguinte forma: <query> <arg1> <arg2> <arg3>. Exemplo: 1 anTonioFaARIA10");
    puts("Para sair do modo Interativo apenas precisas de digitar \"exit\"\n");

    handle_input();

    free_drivers();
    free_users();
    free_rides();
    free_all_stats();
}