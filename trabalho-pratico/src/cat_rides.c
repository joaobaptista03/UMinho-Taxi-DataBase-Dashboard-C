/**
 * @file cat_rides.c
 * Este ficheiro contém a função que preenche o catálogo das Rides.
 * 
 */

#include "../include/cat_rides.h"

struct Ride {
    char id[13];
    char date[11];
    char driver[13];
    char user[50];
    char city[10];
    char distance[10];
    char score_user[5];
    char score_driver[5];
    char tip[6];
    char comment[100];

};

Ride *rides_cat;

void free_rides() {
    free(rides_cat);
}

int get_nr_rides() {
    return atoi(rides_cat[0].id);
}

char *get_ride_id(int indice) {
    return rides_cat[indice].id;
}

char *get_ride_date(int indice) {
    return rides_cat[indice].date;
}

char *get_ride_driver(int indice) {
    return rides_cat[indice].driver;
}

char *get_ride_user(int indice) {
    return rides_cat[indice].user;
}

char *get_ride_city(int indice) {
    return rides_cat[indice].city;
}

char *get_ride_distance(int indice) {
    return rides_cat[indice].distance;
}

char *get_ride_score_user(int indice) {
    return rides_cat[indice].score_user;
}

char *get_ride_score_driver(int indice) {
    return rides_cat[indice].score_driver;
}

char *get_ride_tip(int indice) {
    return rides_cat[indice].tip;
}

bool isRvalid (Ride ride1) {
    return (
        (strlen(ride1.id) > 0) &&
        (isDate(ride1.date)) &&
        (strlen(ride1.driver) > 0) &&
        (strlen(ride1.user) > 0) &&
        (strlen(ride1.city) > 0) &&
        (isInt(ride1.distance)) && (atoi(ride1.distance) > 0) &&
        isInt(ride1.score_user) && (atoi(ride1.score_user) > 0) &&
        isInt(ride1.score_driver) && (atoi(ride1.score_driver) > 0) &&
        isFloat(ride1.tip) && (atof(ride1.tip) >= 0)
    );
}

void inserir_rides(FILE *rides) {
    int nr_rides = 1, cap_malloc = 1;

    rides_cat = malloc(sizeof(Ride));

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

    char *temp; temp = malloc(1000 * sizeof(char));
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

                insert_stats_gender(get_driver_gender(temp_r.driver), get_user_gender(temp_r.user), i);
                double tot_gasto_auferido = total_gasto_auferido(get_driver_car_class(temp_r.driver), atoi(temp_r.distance), atof(temp_r.tip));
                insert_stats_c(temp_r.city, i, tot_gasto_auferido - atof(temp_r.tip));
                insert_stats_d(get_driver_i(temp_r.driver), atoi(temp_r.score_driver), tot_gasto_auferido);
                insert_stats_u(get_user_i(temp_r.user), atoi(temp_r.score_user), tot_gasto_auferido);

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

    sorted_rides();

    puts("Catálogo das Rides preenchido");

    free(temp);
}