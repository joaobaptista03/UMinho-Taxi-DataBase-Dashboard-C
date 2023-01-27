/**
 * @file query9.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 9.
 * 
 */

#include "../include/query9.h"

void query9 (int counter, char *data1, char* data2, int mode) {
    //printf("\nA executar Q9 (linha de input %i)\n", counter);
    if (mode == 1) printf("\n");

    /*
    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    */
    
    int *ridesd = malloc(2 * sizeof(int));
    int capd = 2;
    int rides_d = 0;
    int contadord = 0;

     for (int i = 1; i <= get_nr_rides(); i++) {                                                  // Percorrer o catálogo das rides
         if (
             (most_recent(get_ride_date(i), data1) == 1 || most_recent(get_ride_date(i), data1) == 3)
         &&  (most_recent(get_ride_date(i), data2) == 2 || most_recent(get_ride_date(i), data2) == 3)) {
              rides_d++;
              if (rides_d > capd) {
                  ridesd = realloc(ridesd, 2 * capd * sizeof(int));
                  capd *= 2;
              }
              ridesd[contadord] = i;
              contadord++; 

        }
    }

    if (mode == 1) puts("Forma do Resultado: id_viagem;data_viagem;distancia;cidade;valor_gorjeta");
    for (int i = 0; i < contadord - 1; i++) {                                    // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[150];
        sprintf(output, "%012d;%s;%s;%s;%s\n", ridesd[i], get_ride_date(ridesd[i]), get_ride_distance(ridesd[i]), get_ride_city(ridesd[i]), get_ride_tip(ridesd[i]));
        if (mode == 1) printf("%s",output);
        if (mode == 0) handle_outputs(counter, output);
    }

    free(ridesd);

    /*
    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    printf("Fim da Q9 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
    */
}