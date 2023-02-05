/**
 * @file query8.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 8.
 * 
 */

#include "../include/query8.h"

void query8 (int counter, char *input, int mode) {
    
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    char genero[1]; genero[0] = *input; genero[1] = '\0';
    int anos = atoi(input + 2);

    int *ridesr = malloc(2 * sizeof(int));
    int cap = 2;
    int rides_n = 0;

    for (int i = 0; i < get_gender_nr_rides(genero); i++) {

        char *genderridedriver = get_gender_ride_driver(genero, i); char *driveracccreation = get_driver_acc_creation(genderridedriver);
        char *genderrideuser = get_gender_ride_user(genero, i); char *useracccreation = get_user_acc_creation(genderrideuser);
        if ((age(driveracccreation) >= anos) && (age(useracccreation) >= anos)) {
              if (rides_n == cap) {
                cap *= 2;
                ridesr = realloc(ridesr, cap * sizeof(int));
              }
              
              ridesr[rides_n] = get_gender_ride_i_i(genero, i);
              rides_n++;
        }
        free(genderridedriver); free(driveracccreation);
        free(genderrideuser); free(useracccreation);
    }
    
    if (mode == 1) puts("\nForma do Resultado: id_condutor;nome_condutor;username_utilizador;nome_utilizador");

    if (rides_n == 0) {
        if (mode == 1) puts("\nResultado: Não existe nenhuma viagem.\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        if ((mode == 1) || (mode == 3)) printf("Fim da Q8 - %f segundos (input nº %i)\n", cpu_time_used, counter);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        return;
    }

    qsort(ridesr, rides_n, sizeof(int), first_ride);

    for (int i = 0; i < rides_n; i++) {
        char output[150];
        char *ridedriver = get_ride_driver(ridesr[i]); char *drivername = get_driver_name(ridedriver);
        char *rideuser = get_ride_user(ridesr[i]); char *username = get_user_name(rideuser);
        sprintf(output, "%s;%s;%s;%s\n", ridedriver, drivername, rideuser, username);
        free(ridedriver); free(drivername); free(rideuser); free(username);
        if (mode == 1) printf("%s",output);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);
    }

    free(ridesr);
   
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    if ((mode == 1) || (mode == 3)) printf("Fim da Q8 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}