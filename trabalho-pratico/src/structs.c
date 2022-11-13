/**
 * @file structs.c
 * Este ficheiro contém o contrúdo das funções relacionadas com as structs.
 * 
 */

#include "../include/structs.h"
#include "../include/main.h"

void inserir_dados() {

    char temp[1000];
    while(fgets(temp, 1000, drivers)) {
        Driver temp_d;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_id, temp_d.name, temp_d.birth_date, temp_gender, temp_d.car_class, temp_d.licence_plate, temp_d.city, temp_d.acc_creation, temp_d.status);

            temp_d.id = atoi(temp_id);
            temp_d.gender = temp_gender[0];

        // inserir temp no catálogo de drivers
    }
    while(fgets(temp, 1000, users)) {
        User temp_u;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_u.user, temp_u.name, temp_gender, temp_u.birth_date, temp_u.acc_creation, temp_u.pay_method, temp_u.status);

            temp_u.gender = temp_gender[0];

        // inserir temp no catálogo de users
    }
    while(fgets(temp, 1000, rides)) {
        Ride temp_r;
        sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
            temp_id, temp_r.date, temp_r.driver, temp_r.user, temp_r.city, temp_distance, temp_score_driver, temp_tip, temp_r.comment);
            
            temp_r.id = atoi(temp_id);
            temp_r.distance = atoi(temp_distance);
            temp_r.score_driver = atoi(temp_score_driver);
            temp_r.tip = atof(temp_tip);

        // inserir temp no catálogo de rides
    }
}