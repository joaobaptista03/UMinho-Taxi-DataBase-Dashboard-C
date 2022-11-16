/**
 * @file query3.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 3.
 * 
 */

#include "../include/query3.h"

/* TO DO - ORDEM DE DESENPATE:
    1 - VIAGEM MAIS RECENTE
    2 - USERNAME DO UTILIZADOR POR ORDEM CRESCENTE
*/

void query3 (int counter, Driver *drivers_cat, User *users_cat, Ride *rides_cat, char *N_arg) {
    int N = atoi(N_arg);                                                      // Converter argumento N string para int


    double tot_distancia[10001];
    double tot_distancia_cpy[10001];

    for (int i = 1; i <= 10000; i++) {                                              // Percorrer o catálogo das rides
        char username[30]= users_cat[i].username;                                   // Calcular índice do driver pretendido
                       // Aumentar o total de avaliações do driver pretendido
        num_viagens[ind_driver]++;                                                    // Incrementar o número de viagens do driver pretendido
    }