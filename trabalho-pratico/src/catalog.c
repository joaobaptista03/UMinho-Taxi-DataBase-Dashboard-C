/**
 * @file catalog.c
 * Este ficheiro contém o contrúdo das funções relacionadas com as structs.
 * 
 */

#include "../include/catalog.h"
#include "../include/inputs.h"

void inserir_dados(FILE *drivers, FILE *users, FILE *rides, FILE *inputs) {

    char *temp; temp = malloc(1000 * sizeof(char));                                // String temporária que irá armazenar cada linha dos Ficheiros CSV

    // Criar catálogo dos Drivers
    Driver *drivers_cat; drivers_cat = malloc(10001*sizeof(Driver));

    for(int i = 1; fgets(temp, 1000, drivers); i++) {
        Driver temp_d;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_d.id, temp_d.name, temp_d.birth_date, temp_d.gender, temp_d.car_class, temp_d.license_plate, temp_d.city, temp_d.acc_creation, temp_d.status);

        drivers_cat[i] = temp_d;
    }
    puts("Catálogo dos Drivers preenchido");

    // Criar catálogo dos Users
    User *users_cat; users_cat = malloc(100001*sizeof(User));

    GHashTable *users_hash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);

    for(int i = 1; fgets(temp, 1000, users); i++) {
        User temp_u;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_u.user, temp_u.name, temp_u.gender, temp_u.birth_date, temp_u.acc_creation, temp_u.pay_method, temp_u.status);

        users_cat[i] = temp_u;

        g_hash_table_insert(users_hash, g_strdup(temp_u.user), g_strdup_printf("%i", i));
    }
    puts("Catálogo dos Users preenchido");

    // Criar catálogo das Rides
    Ride *rides_cat; rides_cat = malloc(1000001*sizeof(Ride));

    for(int i = 1; fgets(temp, 1000, rides); i++) {
        Ride temp_r;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_r.id, temp_r.date, temp_r.driver, temp_r.user, temp_r.city, temp_r.distance, temp_r.score_user, temp_r.score_driver, temp_r.tip, temp_r.comment);
        
        rides_cat[i] = temp_r;

        strcpy(temp_r.comment, "");
    }
    puts("Catálogo das Rides preenchido");

    Driver *drivers_cat_dup; drivers_cat_dup = malloc(10001*sizeof(Driver));
        for(int i = 1; i <= 10000; i++) drivers_cat_dup[i] = drivers_cat[i];
    User *users_cat_dup; users_cat_dup = malloc(100001*sizeof(User));
        for(int i = 1; i <= 100000; i++) users_cat_dup[i] = users_cat[i];
    Ride *rides_cat_dup; rides_cat_dup = malloc(1000001*sizeof(Ride));
        for(int i = 1; i <= 1000000; i++) rides_cat_dup[i] = rides_cat[i];

    free(drivers_cat);
    free(users_cat);
    free(rides_cat);

    GHashTable *users_hash_dup = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    void new_hash(gpointer key, gpointer value, gpointer u_data) {
        g_hash_table_insert(users_hash_dup, g_strdup(key), g_strdup(value));
    }
    g_hash_table_foreach(users_hash, new_hash, NULL);
    g_hash_table_destroy(users_hash);

    handle_inputs(drivers_cat_dup, users_cat_dup, users_hash_dup, rides_cat_dup, inputs);

    free(temp);
}