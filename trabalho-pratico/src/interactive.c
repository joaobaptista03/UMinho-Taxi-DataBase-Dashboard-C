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

    int counter = 1;

    FILE *drivers = open_files(csvs, "/drivers.csv");
    FILE *users = open_files(csvs, "/users.csv");
    FILE *rides = open_files(csvs, "/rides.csv");

    if ((drivers == NULL) || (users == NULL) || (rides == NULL)) {
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

    puts("\nAgora, insere os input's 1 a 1 da seguinte forma: <query> <arg1> <arg2> <arg3>. Exemplo: 1 anTonioFaARIA10\n");

    char *input; input = malloc(100 * sizeof(char));
    while ((fgets(input, 100, stdin)) && (stricmp(input, "EXIT\n") != 0)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                                                                // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') query1(counter, drivers_cat, users_struct.userscat, users_struct.usershash, rides_cat, input + 2);
        else if (input[0] == '2') query2(counter, drivers_cat, rides_cat, input + 2);
        else if (input[0] == '3') query3(counter, users_struct.userscat, users_struct.usershash, rides_cat, input + 2);
        else if (input[0] == '4') query4(counter, drivers_cat, rides_cat, input + 2);
        else if (input[0] == '5') query5(counter, drivers_cat, rides_cat, input + 2, input + 13);
        else if (input[0] == '6') query6(counter, rides_cat, input + 2);      
        /*
        if (input[0] == '7') query7(counter, drivers_cat_dup, users_cat_dup, rides_cat_dup, input + 2);                             // Tem de fazer parsing porque o tamanho da city varia
        if (input[0] == '8') query8(counter, drivers_cat_dup, users_cat_dup, rides_cat_dup, input + 2, input + 4);
        if (input[0] == '9') query9(counter, drivers_cat_dup, users_cat_dup, rides_cat_dup, input + 2, input + 13);
        */
        counter++;
        puts("--------------------------------------------");
    }

    system("rm -r Resultados");   

    free(input);
}