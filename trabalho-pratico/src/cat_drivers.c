/**
 * @file cat_drivers.c
 * Este ficheiro contém a função que preenche o catálogo dos Drivers.
 * 
 */

#include "../include/cat_drivers.h"

struct Driver {
    char id[13];
    char name[40];
    char birth_date[11];
    char gender[2];
    char car_class[8];
    char license_plate[9];
    char city[10];
    char acc_creation[11];
    char status[9];

};

GHashTable *drivers_hash;
Driver *drivers_cat;

void free_drivers() {
    free(drivers_cat);
    g_hash_table_destroy(drivers_hash);
}

bool isDvalid(Driver driver1) {
    return (
        (strlen(driver1.id) > 0) &&
        (strlen(driver1.name) > 0) &&
        (strlen(driver1.gender) == 1) &&
        (isDate(driver1.birth_date)) &&
        ((stricmp(driver1.car_class, "premium") == 0) || (stricmp(driver1.car_class, "basic") == 0) || (stricmp(driver1.car_class, "green") == 0)) &&
        (strlen(driver1.license_plate) > 0) &&
        (strlen(driver1.city) > 0) &&
        (isDate(driver1.acc_creation)) &&
        ((stricmp(driver1.status,"active") == 0) || (stricmp(driver1.status,"inactive") == 0))
    );
}

int get_n_drivers() {
    return g_hash_table_size(drivers_hash);
}

bool is_driver (char *id) {
    return g_hash_table_contains(drivers_hash, id);
}

int get_driver_i(char *id) {
    return atoi(g_hash_table_lookup(drivers_hash, id));
}

char* get_driver_id(int indice) {
    return strdup(drivers_cat[indice].id);
}

char* get_driver_name(char *id) {
    return strdup(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id))].name);
}

char* get_driver_birth_date(char *id) {
    return strdup(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id))].birth_date);
}

char* get_driver_gender(char *id) {
    return strdup(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id))].gender);
}

char* get_driver_car_class(char *id) {
    return strdup(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id))].car_class);
}

char* get_driver_license_plate(char *id) {
    return strdup(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id))].license_plate);
}

char* get_driver_city(char *id) {
    return strdup(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id))].city);
}

char* get_driver_acc_creation(char *id) {
    return strdup(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id))].acc_creation);
}

char* get_driver_status(char *id) {
    return strdup(drivers_cat[atoi(g_hash_table_lookup(drivers_hash, id))].status);
}

void inserir_drivers(FILE *drivers) {
    puts("");
    int nr_drivers = 1, cap_malloc = 1;

    drivers_cat = malloc(sizeof(Driver));
    drivers_hash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);

    Driver generic_d;
            strcpy(generic_d.id, "");
            strcpy(generic_d.name, "");
            strcpy(generic_d.birth_date, "");
            strcpy(generic_d.gender, "");
            strcpy(generic_d.car_class, "");
            strcpy(generic_d.license_plate, "");
            strcpy(generic_d.city, "");
            strcpy(generic_d.acc_creation, "");
            strcpy(generic_d.status, "");

    char *temp; temp = malloc(1000 * sizeof(char));
    for(int i = 0; fgets(temp, 1000, drivers); i++) {
        if (i != 0) {
            if (cap_malloc == nr_drivers) {
                drivers_cat = realloc(drivers_cat, 2 * cap_malloc * sizeof(Driver));
                cap_malloc *= 2;
            }

            Driver temp_d;
            sscanf(temp, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", 
                temp_d.id, temp_d.name, temp_d.birth_date, temp_d.gender, temp_d.car_class, temp_d.license_plate, temp_d.city, temp_d.acc_creation, temp_d.status);

            if (isDvalid(temp_d)) {
                drivers_cat[i] = temp_d;
                g_hash_table_insert(drivers_hash, g_strdup(temp_d.id), g_strdup_printf("%i", i));
                nr_drivers++;

                insert_driver_status(temp_d.status);
            }
            else i--;

            temp_d = generic_d;
        }
    }

    init_stats_d(g_hash_table_size(drivers_hash));

    strcpy(drivers_cat[0].id, "");
    strcpy(drivers_cat[0].name, "");
    strcpy(drivers_cat[0].birth_date, "");
    strcpy(drivers_cat[0].gender, "");
    strcpy(drivers_cat[0].car_class, "");
    strcpy(drivers_cat[0].license_plate, "");
    strcpy(drivers_cat[0].city, "");
    strcpy(drivers_cat[0].acc_creation, "");
    strcpy(drivers_cat[0].status, "");

    puts("Catálogo dos Drivers preenchido");

    free(temp);
}