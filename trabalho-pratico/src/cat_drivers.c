/**
 * @file cat_drivers.c
 * Este ficheiro contém a função que preenche o catálogo dos Drivers.
 * 
 */

#include "../include/cat_drivers.h"

Driver* inserir_drivers(FILE *drivers) {

    // Criar catálogo dos Drivers
    Driver *drivers_cat; drivers_cat = malloc(10001*sizeof(Driver));

    char *temp; temp = malloc(1000 * sizeof(char));             // String temporária que irá armazenar cada linha dos Ficheiros CSV
    for(int i = 0; fgets(temp, 1000, drivers); i++) {
        if (i != 0) {
            Driver temp_d;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_d.id, temp_d.name, temp_d.birth_date, temp_d.gender, temp_d.car_class, temp_d.license_plate, temp_d.city, temp_d.acc_creation, temp_d.status);

            drivers_cat[i] = temp_d;    
        }
    }
    puts("Catálogo dos Drivers preenchido");

    Driver *drivers_cat_dup; drivers_cat_dup = malloc(10001*sizeof(Driver));
        for(int i = 1; i <= 10000; i++) drivers_cat_dup[i] = drivers_cat[i];

    free(drivers_cat);
    free(temp);

    return drivers_cat_dup;
}