/**
 * @file cat_rides.c
 * Este ficheiro contém a função que preenche o catálogo das Rides.
 * 
 */

#include "../include/cat_rides.h"

Ride* inserir_rides(FILE *rides) {

    // Criar catálogo das Rides
    Ride *rides_cat; rides_cat = malloc(1000001*sizeof(Ride));

    char *temp; temp = malloc(1000 * sizeof(char));                                // String temporária que irá armazenar cada linha dos Ficheiros CSV
    for(int i = 0; fgets(temp, 1000, rides); i++) {
        if (i != 0) {
            Ride temp_r;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_r.id, temp_r.date, temp_r.driver, temp_r.user, temp_r.city, temp_r.distance, temp_r.score_user, temp_r.score_driver, temp_r.tip, temp_r.comment);
            
            rides_cat[i] = temp_r;

            strcpy(temp_r.comment, "");
        }
    }
    puts("Catálogo das Rides preenchido");

    Ride *rides_cat_dup; rides_cat_dup = malloc(1000001*sizeof(Ride));
        for(int i = 1; i <= 1000000; i++) rides_cat_dup[i] = rides_cat[i];
    free(rides_cat);
    
    free(temp);

    return rides_cat_dup;
}