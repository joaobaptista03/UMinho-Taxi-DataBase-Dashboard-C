/**
 * @file catalog.c
 * Este ficheiro contém o contrúdo das funções relacionadas com as structs.
 * 
 */

#include "../include/catalog.h"
#include "../include/inputs.h"

void inserir_dados(FILE *drivers, FILE *users, FILE *rides, FILE *inputs) {

    // Variáveis temporárias que serão usadas para o While Fgets
    char temp_gender[5];            // Gender temporário, que posteriormente será transformado de STRING para CHAR
    char temp[1000];                // String temporária que irá armazenar cada linha dos Ficheiros CSV


    // Criar catálogo dos Drivers
    Driver *drivers_cat;
    drivers_cat = malloc(10001*sizeof(Driver));
    int i = 1;
    while(fgets(temp, 1000, drivers)) {
        Driver temp_d;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_d.id, temp_d.name, temp_d.birth_date, temp_gender, temp_d.car_class, temp_d.license_plate, temp_d.city, temp_d.acc_creation, temp_d.status);
            
            temp_d.gender = temp_gender[0];

        drivers_cat[i] = temp_d;
        i++;
    }

    // Criar catálogo dos Users
    User *users_cat;
    users_cat = malloc(100001*sizeof(User));
    i = 1;
    while(fgets(temp, 1000, users)) {
        User temp_u;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_u.user, temp_u.name, temp_gender, temp_u.birth_date, temp_u.acc_creation, temp_u.pay_method, temp_u.status);

            temp_u.gender = temp_gender[0];

        users_cat[i] = temp_u;
        i++;
    }

    // Criar catálogo das Rides
    Ride *rides_cat;
    rides_cat = malloc(1000001*sizeof(Ride));
    i = 1;
    while(fgets(temp, 1000, rides)) {
        Ride temp_r;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_r.id, temp_r.date, temp_r.driver, temp_r.user, temp_r.city, temp_r.distance, temp_r.score_user, temp_r.score_driver, temp_r.tip, temp_r.comment);
        
        rides_cat[i] = temp_r;
        i++;
        strcpy(temp_r.comment, "");
    }


    // Criar cópias dos catálogos para encapsulamento
    Driver *new_drivers_cat;
        new_drivers_cat = malloc(10001*sizeof(Driver));
        for (i = 1; i <= 10000; i++) new_drivers_cat[i] = drivers_cat[i];
    User *new_users_cat;
        new_users_cat = malloc(100001*sizeof(Driver));
        for (i = 1; i <= 100000; i++) new_users_cat[i] = users_cat[i];
    Ride *new_rides_cat;
        new_rides_cat = malloc(1000001*sizeof(Driver));
        for (i = 1; i <= 1000000; i++) new_rides_cat[i] = rides_cat[i];

    // Libertar memória dos catálogos originais
    free(drivers_cat);
    free(users_cat);
    free(rides_cat);

    handle_inputs(new_drivers_cat, new_users_cat, new_rides_cat, inputs);
}