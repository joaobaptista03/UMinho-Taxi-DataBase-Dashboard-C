/**
 * @file query8.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 8.
 * 
 */

#include "../include/query8.h"

void query8 (int counter, char *input, int mode) {
    //printf("\nA executar Q8 (linha de input %i)\n", counter);
    if (mode == 1) printf("\n");

    /*
    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    */

    char genero = input[0];
    int anos = atoi(input + 2);

    int *ridesr = malloc(2 * sizeof(int));
    int cap = 2;
    int rides_n = 0;

    for (int i = 1; i <= get_nr_rides(); i++) {                                                  // Percorrer o catálogo das rides
        if ((stricmp(get_driver_status(get_ride_driver(i)), "active") == 0) 
            && (stricmp(get_user_status(get_ride_user(i)), "active") == 0)
            && (get_driver_gender(get_ride_driver(i))[0] == genero)
            && (get_user_gender(get_ride_user(i))[0] == genero)
            && (age(get_driver_acc_creation(get_ride_driver(i))) >= anos)
            && (age(get_user_acc_creation(get_ride_user(i))) >= anos)
            ) {
              if (rides_n == cap) {
                cap *= 2;
                ridesr = realloc(ridesr, cap * sizeof(int));
              }
              ridesr[rides_n] = i;
              rides_n++;

        }
    }

    if (mode == 1) puts("Forma do Resultado: id_condutor;nome_condutor;username_utilizador;nome_utilizador");
    for (int i = 0; i < rides_n; i++) {                                    // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[150];
        sprintf(output, "%s;%s;%s;%s\n", get_ride_driver(ridesr[i]), get_driver_name(get_ride_driver(ridesr[i])), get_ride_user(ridesr[i]), get_user_name(get_ride_user(ridesr[i])));
        if (mode == 1) printf("%s",output);
        if (mode == 0) handle_outputs(counter, output);
    }

    free(ridesr);
   
    /*
    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    printf("Fim da Q8 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
    */
}