/**
 * @file stats.c
 * Este ficheiro contém as funções que fazem as Estatísticas das viagens.
 * 
 */

#include "../include/stats.h"

int *nr_viagens_d;
int *nr_viagens_u;
int *av_total_d;
int *av_total_u;
int *dist_total_u;
double *tot_auferido;
double *tot_gasto;
GHashTable *citieshash;
city* cities;
int nr_cities = 0;
int *rides_m, nr_rides_m = 0, cap_rides_m = 0;
int *rides_f, nr_rides_f = 0, cap_rides_f = 0;
int *sortedrides;
int *sorteddrivers;
int *sortedusers;
char **recent_ride_d;
char **recent_ride_u;
int active_drivers = 0;


struct city {
    char *name;
    int nr_viagens;
    int cap;
    double total_price;
    int *rides;
};

//--------------------------------------------------------------------------------------------------------------------------------

int get_driver_nr_active() {
    return active_drivers;
}

int get_driver_nr_viagens(int indice) {
    return nr_viagens_d[indice];
}

int get_user_nr_viagens(int indice) {
    return nr_viagens_u[indice];
}

int get_driver_av_total(int indice) {
    return av_total_d[indice];
}

int get_user_av_total(int indice) {
    return av_total_u[indice];
}

int get_user_dist_total(int indice) {
    return dist_total_u[indice];
}

double get_tot_auferido(int indice) {
    return tot_auferido[indice];
}

double get_tot_gasto(int indice) {
    return tot_gasto[indice];
}

double get_city_preco_medio(char *name) {
    char *ind = g_hash_table_lookup(citieshash, name);
    int ind_i = atoi(ind);
    if (ind != NULL) return cities[ind_i].total_price / (double) cities[ind_i].nr_viagens;
    return 0;
}

int get_city_nr_rides(char *name) {
    char *ind = g_hash_table_lookup(citieshash, name);
    if (ind != NULL) return cities[atoi(ind)].nr_viagens;
    return 0;
}

char* get_city_ride_driver (char *name, int indice) {
    char *ind = g_hash_table_lookup(citieshash, name);
    if (ind != NULL) return get_ride_driver(cities[atoi(ind)].rides[indice]);
    return NULL;
}

char* get_city_ride_score_driver (char *name, int indice) {
    char *ind = g_hash_table_lookup(citieshash, name);
    if (ind != NULL) return get_ride_score_driver(cities[atoi(ind)].rides[indice]);
    return NULL;
}

char *get_city_i_ride_date(char *cidade, int indice) {
    char *ind = g_hash_table_lookup(citieshash, cidade);
    if (ind != NULL) return get_ride_date(cities[atoi(ind)].rides[indice]);
    return NULL;
}

char *get_city_i_ride_distance(char *cidade, int indice) {
    char *ind = g_hash_table_lookup(citieshash, cidade);
    if (ind != NULL) return get_ride_distance(cities[atoi(ind)].rides[indice]);
    return NULL;
}

int get_gender_nr_rides(char *gender) {
    if (stricmp(gender, "m") == 0) return nr_rides_m;
    else if (stricmp(gender, "f") == 0) return nr_rides_f;
    return 0;
}

char *get_gender_ride_driver(char *gender, int indice) {
    if (stricmp(gender, "m") == 0) return get_ride_driver(rides_m[indice]);
    if (stricmp(gender, "f") == 0) return get_ride_driver(rides_f[indice]);
    return NULL;
}

char *get_gender_ride_user(char *gender, int indice) {
    if (stricmp(gender, "m") == 0) return get_ride_user(rides_m[indice]);
    if (stricmp(gender, "f") == 0) return get_ride_user(rides_f[indice]);
    return NULL;
}

int get_gender_ride_i_i (char *gender, int indice) {
    if (stricmp(gender, "m") == 0) return rides_m[indice];
    if (stricmp(gender, "f") == 0) return rides_f[indice];
    return -1;
}

char *get_sorted_ride_date(int indice) {
    return get_ride_date(sortedrides[indice]);
}

char *get_sorted_ride_driver(int indice) {
    return get_ride_driver(sortedrides[indice]);
}

char *get_sorted_ride_distance(int indice) {
    return get_ride_distance(sortedrides[indice]);
}

char *get_sorted_ride_city(int indice) {
    return get_ride_city(sortedrides[indice]);
}

char *get_sorted_ride_tip(int indice) {
    return get_ride_tip(sortedrides[indice]);
}

int get_sorted_ride_i(int indice) {
    return sortedrides[indice];
}

char* get_driver_recdate (int indice) {
    return strdup(recent_ride_d[indice]);
}

char* get_user_recdate (int indice) {
    return strdup(recent_ride_u[indice]);
}

int get_sorted_driver(int indice) {
    return sorteddrivers[indice];
}

int get_sorted_user(int indice) {
    return sortedusers[indice];
}

//--------------------------------------------------------------------------------------------------------------------------------

void init_stats_d(int nr_drivers) {
    nr_viagens_d = calloc(nr_drivers + 1, sizeof(int));
    av_total_d = calloc(nr_drivers + 1, sizeof(int));
    tot_auferido = calloc(nr_drivers + 1, sizeof(double));

    recent_ride_d = malloc((1 + get_n_drivers()) * sizeof(char*));
    for (int i = 0; i < (1 + get_n_drivers()); i++)
        recent_ride_d[i] = malloc((11+1) * sizeof(char));
    for (int i = 0; i <= get_n_drivers(); i++) strcpy(recent_ride_d[i], "00/00/0000");
}

void init_stats_u(int nr_users) {
    nr_viagens_u = calloc(nr_users + 1, sizeof(int));
    av_total_u = calloc(nr_users + 1, sizeof(int));
    tot_gasto = calloc(nr_users + 1, sizeof(double));
    dist_total_u = calloc(nr_users + 1, sizeof(double));

    recent_ride_u = malloc((1 + get_nr_users()) * sizeof(char*));
    for (int i = 0; i < (1 + get_nr_users()); i++)
        recent_ride_u[i] = malloc((11+1) * sizeof(char));
    for (int i = 0; i <= get_nr_users(); i++) strcpy(recent_ride_u[i], "00/00/0000");
}

void init_stats_c() {
    citieshash = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
}

//--------------------------------------------------------------------------------------------------------------------------------

void insert_stats_d(int indice, int aval, double val, char* date) {
    nr_viagens_d[indice]++;
    av_total_d[indice] += aval;
    tot_auferido[indice] += val;

    if (most_recent(date, recent_ride_d[indice]) == 1) 
        strcpy(recent_ride_d[indice], date);
}

void insert_driver_status(char *status) {
    if (stricmp(status, "active") == 0) active_drivers++;
}

void insert_stats_u(int indice, int aval, double val, char *date, int dist) {
    nr_viagens_u[indice]++;
    av_total_u[indice] += aval;
    tot_gasto[indice] += val;
    dist_total_u[indice] += dist;

    if (most_recent(date, recent_ride_u[indice]) == 1) 
        strcpy(recent_ride_u[indice], date);
}

void insert_stats_c(char *name, int indice, double price) {
    for(int i = 0; i < nr_cities; i++) {
        if (stricmp(cities[i].name, name) == 0) {
            cities[i].nr_viagens++;
            if (cities[i].nr_viagens > cities[i].cap) {
                cities[i].cap *= 2;
                cities[i].rides = realloc(cities[i].rides, cities[i].cap * sizeof(int));   
            }
            (cities[i].rides)[cities[i].nr_viagens - 1] = indice;
            cities[i].total_price += price;
            return;
        }
    }

    city temp;
    temp.name = malloc((strlen(name) + 1) * sizeof(char));
    strcpy(temp.name, name);
    temp.nr_viagens = 1;
    temp.total_price = price;
    temp.rides = malloc(sizeof(int));
    temp.cap = 1;
    (temp.rides)[0] = indice;

    nr_cities++;
    cities = realloc(cities, nr_cities * sizeof(struct city));
    cities[nr_cities - 1] = temp;
    g_hash_table_insert(citieshash, g_strdup(name), g_strdup_printf("%d", nr_cities-1));
}

void insert_stats_gender(char *gender1, char *gender2, int indice) {
    char *ridedriver = get_ride_driver(indice);
    char *driverstatus = get_driver_status(ridedriver);
    char *rideuser = get_ride_user(indice);
    char *userstatus = get_user_status(rideuser);
    if ((stricmp(gender1, gender2) == 0) && 
        (stricmp(driverstatus, "active") == 0) &&
        (stricmp(userstatus, "active") == 0)) {
            if (stricmp(gender1, "m") == 0) {
                nr_rides_m++;
                if (nr_rides_m > cap_rides_m) {
                    if (cap_rides_m != 0) cap_rides_m *= 2;
                        else cap_rides_m = 1;
                    rides_m = realloc(rides_m, cap_rides_m * sizeof(int));
                }
                rides_m[nr_rides_m - 1] = indice;
            }
            else if (stricmp(gender1, "f") == 0) {
                nr_rides_f++;
                if (nr_rides_f > cap_rides_f) {
                    if (cap_rides_f != 0) cap_rides_f *= 2;
                        else cap_rides_f = 1;
                    rides_f = realloc(rides_f, cap_rides_f * sizeof(int));
                }
                rides_f[nr_rides_f - 1] = indice;
            }
    }
    free(ridedriver); free(driverstatus); free(rideuser); free(userstatus);
}

void sorted_rides() {
    sortedrides = calloc(get_nr_rides(), sizeof(int));
    for(int i = 0; i < get_nr_rides(); i++) sortedrides[i] = i + 1;
    qsort(sortedrides, get_nr_rides(), sizeof(int), sort_rides);

    for(int i = 0; i < nr_cities; i++)
        qsort(cities[i].rides, cities[i].nr_viagens, sizeof(int), sort_rides);
}

void sorted_drivers() {
    sorteddrivers = calloc(get_n_drivers(), sizeof(int));
    for(int i = 0; i < get_n_drivers(); i++) {
        char *driver_id = get_driver_id(i+1);
        sorteddrivers[i] = atoi(driver_id);
        free(driver_id);
    }
    qsort(sorteddrivers, get_n_drivers(), sizeof(int), sort_drivers);
}

void sorted_users() {
    sortedusers = calloc(get_nr_users(), sizeof(int));
    for(int i = 0; i < get_nr_users(); i++) sortedusers[i] = i + 1;
    qsort(sortedusers, get_nr_users(), sizeof(int), sort_users);
}

//--------------------------------------------------------------------------------------------------------------------------------

void free_cities() {
    for (int i = 0; i < nr_cities; i++) {
        free(cities[i].name);
        free(cities[i].rides);
    }
    free(cities);
}

void free_gender() {
    free(rides_m);
    free(rides_f);
}

void free_recent_rides() {
    for(int i = 0; i <= get_n_drivers(); i++) free(recent_ride_d[i]);
    free(recent_ride_d);
    for(int i = 0; i <= get_nr_users(); i++) free(recent_ride_u[i]);
    free(recent_ride_u);
}

void free_all_stats() {
    free(nr_viagens_d);
    free(nr_viagens_u);
    free(av_total_d);
    free(av_total_u);
    free(dist_total_u);
    free(tot_auferido);
    free(tot_gasto);
    free(sortedrides);
    free(sorteddrivers);
    free(sortedusers);
    free_cities();
    free_gender();
    free_recent_rides();
    g_hash_table_destroy(citieshash);
}