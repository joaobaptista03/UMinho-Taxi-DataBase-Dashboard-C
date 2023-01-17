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

    driver_struct drivers_struct = inserir_drivers(drivers);
    user_struct users_struct = inserir_users(users);
    Ride* rides_cat = inserir_rides(rides);

    fclose(drivers);
        if (drivers != NULL) puts("\nFicheiro dos Drivers fechado");
    fclose(rides);
        if (rides != NULL) puts("Ficheiro dos Rides fechado");
    fclose(users);
        if (users != NULL) puts("Ficheiro dos Users fechado");

    // Encapsulamento Catálogos
    Driver *drivers_cat_dup; drivers_cat_dup = malloc((1 + atoi(drivers_struct.driverscat[0].id))*sizeof(Driver));
        for(int i = 0; i <= atoi(drivers_struct.driverscat[0].id); i++) drivers_cat_dup[i] = drivers_struct.driverscat[i];
    free(drivers_struct.driverscat);
    User *users_cat_dup; users_cat_dup = malloc((1 + atoi(users_struct.userscat[0].user))*sizeof(User));
        for(int i = 0; i <= atoi(users_struct.userscat[0].user); i++) users_cat_dup[i] = users_struct.userscat[i];
    free(users_struct.userscat);
    Ride *rides_cat_dup; rides_cat_dup = malloc((1 + atoi(rides_cat[0].id))*sizeof(Ride));
        for(int i = 0; i <= atoi(rides_cat[0].id); i++) rides_cat_dup[i] = rides_cat[i];
    free(rides_cat);
    // Encapsulamento Hash Table Users
    GHashTable *users_hash_dup = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    void new_hash_u(gpointer key, gpointer value, gpointer u_data) {
        g_hash_table_insert(users_hash_dup, g_strdup(key), g_strdup(value));
    }
    g_hash_table_foreach(users_struct.usershash, new_hash_u, NULL);
    g_hash_table_destroy(users_struct.usershash);
    // Encapsulamento Hash Table Drivers
    GHashTable *drivers_hash_dup = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    void new_hash_d(gpointer key, gpointer value, gpointer u_data) {
        g_hash_table_insert(drivers_hash_dup, g_strdup(key), g_strdup(value));
    }
    g_hash_table_foreach(drivers_struct.drivershash, new_hash_d, NULL);
    g_hash_table_destroy(drivers_struct.drivershash);

    puts("\nAgora, insere os input's 1 a 1 da seguinte forma: <query> <arg1> <arg2> <arg3>. Exemplo: 1 anTonioFaARIA10\n");

    char *input; input = malloc(100 * sizeof(char));
    while ((fgets(input, 100, stdin)) && (stricmp(input, "EXIT\n") != 0)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';                                                                // Trocar '\n' por '\0' na string input
        
        if (input[0] == '1') query1(counter, drivers_cat_dup, drivers_hash_dup, users_cat_dup, users_hash_dup, rides_cat_dup, input + 2);
        else if (input[0] == '2') query2(counter, drivers_cat_dup, drivers_hash_dup, rides_cat_dup, input + 2);
        else if (input[0] == '3') query3(counter, users_cat_dup, users_hash_dup, rides_cat_dup, input + 2);
        else if (input[0] == '4') query4(counter, drivers_cat_dup, drivers_hash_dup, rides_cat_dup, input + 2);
        else if (input[0] == '5') query5(counter, drivers_cat_dup, drivers_hash_dup, rides_cat_dup, input + 2, input + 13);
        else if (input[0] == '6') query6(counter, rides_cat_dup, input + 2);
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
    free(drivers_cat_dup);
    free(users_cat_dup);
    free(rides_cat_dup);
    g_hash_table_destroy(users_hash_dup);
    g_hash_table_destroy(drivers_hash_dup);
}