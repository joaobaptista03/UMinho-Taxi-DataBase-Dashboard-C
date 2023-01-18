/**
 * @file cat_rides.c
 * Este ficheiro contém a função que preenche o catálogo das Rides.
 * 
 */

#include "../include/cat_rides.h"

bool isRvalid (Ride ride1) {
    return (
        (strlen(ride1.id) > 0) &&
        (isDate(ride1.date)) &&
        (strlen(ride1.driver) > 0) &&
        (strlen(ride1.user) > 0) &&
        (strlen(ride1.city) > 0) &&
        (isInt(ride1.distance)) && (atoi(ride1.distance) > 0) &&
        isFloat(ride1.score_user) && (atof(ride1.score_user) >= 0) &&
        isFloat(ride1.score_driver) && (atof(ride1.score_driver) >= 0) &&
        isFloat(ride1.tip) && (atof(ride1.tip) >= 0)
    );
}

Ride* inserir_rides(FILE *rides) {
    int nr_rides = 1, cap_malloc = 1;

    // Criar catálogo das Rides
    Ride *rides_cat; rides_cat = malloc(sizeof(Ride));

    Ride generic_r;
            strcpy(generic_r.id, "");
            strcpy(generic_r.date, "");
            strcpy(generic_r.driver, "");
            strcpy(generic_r.user, "");
            strcpy(generic_r.city, "");
            strcpy(generic_r.distance, "");
            strcpy(generic_r.score_user, "");
            strcpy(generic_r.score_driver, "");
            strcpy(generic_r.tip, "");
            strcpy(generic_r.comment, "");

    char *temp; temp = malloc(1000 * sizeof(char));                                // String temporária que irá armazenar cada linha dos Ficheiros CSV
    for(int i = 0; fgets(temp, 1000, rides); i++) {
        if (i != 0) {
            if (cap_malloc == nr_rides) {
                rides_cat = realloc(rides_cat, 2 * cap_malloc * sizeof(Ride));
                cap_malloc *= 2;
            }

            Ride temp_r;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_r.id, temp_r.date, temp_r.driver, temp_r.user, temp_r.city, temp_r.distance, temp_r.score_user, temp_r.score_driver, temp_r.tip, temp_r.comment);
            
            if (isRvalid(temp_r)) { 
                rides_cat[i] = temp_r;
                nr_rides++;
            }
            else i--;

            temp_r = generic_r;
        }
    }

    sprintf(rides_cat[0].id, "%d", nr_rides - 1);
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