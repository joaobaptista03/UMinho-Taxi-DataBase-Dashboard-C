/**
 * @file stats.h
 * Este ficheiro contém os headers das funções que fazem as Estatísticas das viagens.
 * 
 */

#ifndef STATS_H
#define STATS_H

#include "cat_drivers.h"
#include "cat_users.h"
#include "cat_rides.h"

/**
 *
 * Esta é a Struct que define o que é uma City, e contém todas as informações dela. Será inserida nas Estatísticas.
 * 
 */
typedef struct city city;

/**
 *
 * Este é o header da função que devolve o número de viagens de um dado Driver.
 * 
 */
int get_driver_nr_viagens(int indice);

/**
 *
 * Este é o header da função que devolve o número de viagens de um dado User.
 * 
 */
int get_user_nr_viagens(int indice);

/**
 *
 * Este é o header da função que devolve a avaliação total de um dado Driver.
 * 
 */
int get_driver_av_total(int indice);

/**
 *
 * Este é o header da função que devolve a avaliação total de um dado User.
 * 
 */
int get_user_av_total(int indice);

/**
 *
 * Este é o header da função que devolve a distância total de um dado User.
 * 
 */
int get_user_dist_total(int indice);

/**
 *
 * Este é o header da função que devolve o total auferido de um dado Driver.
 * 
 */
double get_tot_auferido(int indice);

/**
 *
 * Este é o header da função que devolve o total gasto de um dado User.
 * 
 */
double get_tot_gasto(int indice);

/**
 *
 * Este é o header da função que devolve o preço médio de uma Cidade.
 * 
 */
double get_city_preco_medio(char *name);

/**
 *
 * Este é o header da função que devolve número de Rides de uma dada City.
 * 
 */
int get_city_nr_rides(char *name);

/**
 *
 * Este é o header da função que devolve o Driver de uma Ride de uma dada City
 * 
 */
char* get_city_ride_driver (char *name, int indice);

/**
 *
 * Este é o header da função que devolve o Score Driver de uma Ride de uma dada City
 * 
 */
char* get_city_ride_score_driver (char *name, int indice);

/**
 *
 * Este é o header da função que devolve a Data de uma Ride de uma dada City
 * 
 */
char *get_city_i_ride_date(char *cidade, int indice);

/**
 *
 * Este é o header da função que devolve a distância de uma Ride de uma dada City
 * 
 */
char *get_city_i_ride_distance(char *cidade, int indice);

/**
 *
 * Este é o header da função que devolve o número de Rides de um dado género.
 * 
 */
int get_gender_nr_rides(char *gender);

/**
 *
 * Este é o header da função que devolve o Driver de uma dada Ride de um dado Gender.
 * 
 */
char *get_gender_ride_driver(char *gender, int indice);

/**
 *
 * Este é o header da função que devolve o User de uma dada Ride de um dado Gender.
 * 
 */
char *get_gender_ride_user(char *gender, int indice);

/**
 *
 * Este é o header da função que devolve a data da Ride mais recente de um dado Driver.
 * 
 */
char* get_driver_recdate (int indice);

/**
 *
 * Este é o header da função que devolve a data da Ride mais recente de um dado User.
 * 
 */
char* get_user_recdate (int indice);

/**
 *
 * Este é o header da função que devolve o id do N maior Driver para as Q2 e Q7.
 * 
 */
int get_sorted_driver(int indice);

/**
 *
 * Este é o header da função que devolve o id do N maior User para a Q3.
 * 
 */
int get_sorted_user(int indice);

/**
 *
 * Este é o header da função que insere os dados do Gender nas Estatísticas.
 * 
 */
void insert_stats_gender(char *gender1, char *gender2, int indice);

/**
 *
 * Este é o header da função que devolve o índice da Ride dado o índice da Ride na array de um dado Gender.
 * 
 */
int get_gender_ride_i_i (char *gender, int indice);

/**
 *
 * Este é o header da função que ordena uma array auxiliar pela data da Ride.
 * 
 */
void sorted_rides();

/**
 *
 * Este é o header da função que ordena a array dos Drivers.
 * 
 */
void sorted_drivers();

/**
 *
 * Este é o header da função que ordena a array dos Users.
 * 
 */
void sorted_users();

/**
 *
 * Este é o header da função que devolve a data da Ride dado um índice da array das Rides ordenadas.
 * 
 */
char *get_sorted_ride_date(int indice);

/**
 *
 * Este é o header da função que devolve o Driver da Ride dado um índice da array das Rides ordenadas.
 * 
 */
char *get_sorted_ride_driver(int indice);

/**
 *
 * Este é o header da função que devolve a distância da Ride dado um índice da array das Rides ordenadas.
 * 
 */
char *get_sorted_ride_distance(int indice);

/**
 *
 * Este é o header da função que devolve a cidade da Ride dado um índice da array das Rides ordenadas.
 * 
 */
char *get_sorted_ride_city(int indice);

/**
 *
 * Este é o header da função que devolve a Tip da Ride dado um índice da array das Rides ordenadas.
 * 
 */
char *get_sorted_ride_tip(int indice);

/**
 *
 * Este é o header da função que devolve o índice da Ride dado um índice da array das Rides ordenadas.
 * 
 */
int get_sorted_ride_i(int indice);

/**
 *
 * Este é o header da função que insere os dados de um Driver nas Estatísticas.
 * 
 */
void insert_stats_d(int indice, int aval, double val, char* date);

/**
 *
 * Este é o header da função que insere os dados de um User nas Estatísticas.
 * 
 */
void insert_stats_u (int indice, int aval, double val, char *date, int dist);

/**
 *
 * Este é o header da função que insere os dados de uma City nas Estatísticas.
 * 
 */
void insert_stats_c(char *name, int indice, double price);

/**
 *
 * Este é o header da função que liberta a memória alocada para todas as Estatísticas.
 * 
 */
void free_all_stats();

/**
 *
 * Este é o header da função que inicializa as Estatísticas dos Drivers.
 * 
 */
void init_stats_d(int nr_drivers);

/**
 *
 * Este é o header da função que inicializa as Estatísticas dos Users.
 * 
 */
void init_stats_u(int nr_users);

/**
 *
 * Este é o header da função que inicializa as Estatísticas das Cidades.
 * 
 */
void init_stats_c();

#endif