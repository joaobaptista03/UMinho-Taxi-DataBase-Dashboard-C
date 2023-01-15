/**
 * @file cat_rides.c
 * Este ficheiro contém a função que preenche o catálogo das Rides.
 * 
 */

#include "../include/cat_rides.h"

Ride* inserir_rides(FILE *rides) {
    int nr_rides = 0, cap_malloc = 1;

    // Criar catálogo das Rides
    Ride *rides_cat; rides_cat = malloc(sizeof(Ride));

    char *temp; temp = malloc(1000 * sizeof(char));                                // String temporária que irá armazenar cada linha dos Ficheiros CSV
    for(int i = 0; fgets(temp, 1000, rides); i++) {
        if (i != 0) {
            nr_rides++;
            if (cap_malloc == nr_rides) {
                rides_cat = realloc(rides_cat, 2 * cap_malloc * sizeof(Ride));
                cap_malloc *= 2;
            }

            Ride temp_r;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_r.id, temp_r.date, temp_r.driver, temp_r.user, temp_r.city, temp_r.distance, temp_r.score_user, temp_r.score_driver, temp_r.tip, temp_r.comment);
            
            rides_cat[i] = temp_r;

            strcpy(temp_r.comment, "");
        }
    }

    sprintf(rides_cat[0].id, "%d", nr_rides);
    strcpy(rides_cat[0].date, "");
    strcpy(rides_cat[0].driver, "");
    strcpy(rides_cat[0].user, "");
    strcpy(rides_cat[0].city, "");
    strcpy(rides_cat[0].distance, "");
    strcpy(rides_cat[0].score_user, "");
    strcpy(rides_cat[0].score_driver, "");
    strcpy(rides_cat[0].tip, "");
    strcpy(rides_cat[0].comment, "");

    puts("Catálogo das Rides preenchido");

    Ride *rides_cat_dup; rides_cat_dup = malloc((atoi(rides_cat[0].id) + 1) * sizeof(Ride));
        for(int i = 0; i <= atoi(rides_cat[0].id); i++) rides_cat_dup[i] = rides_cat[i];

    free(rides_cat);
    free(temp);

    return rides_cat_dup;
}