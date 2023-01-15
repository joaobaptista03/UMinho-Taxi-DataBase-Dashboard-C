/**
 * @file cat_drivers.c
 * Este ficheiro contém a função que preenche o catálogo dos Drivers.
 * 
 */

#include "../include/cat_drivers.h"

Driver* inserir_drivers(FILE *drivers) {
    int nr_drivers = 0, cap_malloc = 1;

    // Criar catálogo dos Drivers
    Driver *drivers_cat; drivers_cat = malloc(sizeof(Driver));

    char *temp; temp = malloc(1000 * sizeof(char));             // String temporária que irá armazenar cada linha dos Ficheiros CSV
    for(int i = 0; fgets(temp, 1000, drivers); i++) {
        if (i != 0) {
            nr_drivers++;
            if (cap_malloc == nr_drivers) {
                drivers_cat = realloc(drivers_cat, 2 * cap_malloc * sizeof(Driver));
                cap_malloc *= 2;
            }

            Driver temp_d;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_d.id, temp_d.name, temp_d.birth_date, temp_d.gender, temp_d.car_class, temp_d.license_plate, temp_d.city, temp_d.acc_creation, temp_d.status);

            drivers_cat[i] = temp_d;
        }
    }

    sprintf(drivers_cat[0].id, "%d", nr_drivers);
    strcpy(drivers_cat[0].name, "");
    strcpy(drivers_cat[0].birth_date, "");
    strcpy(drivers_cat[0].gender, "");
    strcpy(drivers_cat[0].car_class, "");
    strcpy(drivers_cat[0].license_plate, "");
    strcpy(drivers_cat[0].city, "");
    strcpy(drivers_cat[0].acc_creation, "");
    strcpy(drivers_cat[0].status, "");

    puts("Catálogo dos Drivers preenchido");

    Driver *drivers_cat_dup; drivers_cat_dup = malloc((1 + atoi(drivers_cat[0].id))*sizeof(Driver));
        for(int i = 0; i <= atoi(drivers_cat[0].id); i++) drivers_cat_dup[i] = drivers_cat[i];

    free(drivers_cat);
    free(temp);

    return drivers_cat_dup;
}