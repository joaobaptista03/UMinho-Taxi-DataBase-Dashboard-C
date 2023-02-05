/**
 * @file query9.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 9.
 * 
 */

#include "../include/query9.h"

void query9 (int counter, char *data1, char* data2, int mode) {

    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    int *ridesd = malloc(2 * sizeof(int));
    int capd = 2;
    int rides_d = 0;

    for (int i = 0; (i < get_nr_rides()); i++) {
        char *sortedridedate = get_sorted_ride_date(i);

        if (most_recent(data1, sortedridedate) == 1) {
            free(sortedridedate);
            break;
        }

        char *sortedridetip = get_sorted_ride_tip(i);
         if ((most_recent(sortedridedate, data2) == 2 || most_recent(sortedridedate, data2) == 3) && (atof(sortedridetip) > 0)) {
              
              if (rides_d + 1 > capd) {
                  ridesd = realloc(ridesd, 2 * capd * sizeof(int));
                  capd *= 2;
              }
              
              ridesd[rides_d] = get_sorted_ride_i(i);
              rides_d++;
        }
        free(sortedridedate); free(sortedridetip);
    }

    if (mode == 1) puts("\nForma do Resultado: id_viagem;data_viagem;distancia;cidade;valor_gorjeta");

    if (rides_d == 0) {
        if (mode == 1) puts("\nResultado: Não existe nenhuma viagem.\n");
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        if ((mode == 1) || (mode == 3)) printf("Fim da Q9 - %f segundos (input nº %i)\n", cpu_time_used, counter);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, "");
        free(ridesd);
        return;
    }

    qsort(ridesd, rides_d, sizeof(int), first_ride9);

    for (int i = 0; i < rides_d; i++) {
        char output[150];
        char *rideid = get_ride_id(ridesd[i]), *ridedate = get_ride_date(ridesd[i]), *ridedistance = get_ride_distance(ridesd[i]), *ridecity = get_ride_city(ridesd[i]), *ridetip = get_ride_tip(ridesd[i]);
        sprintf(output, "%s;%s;%s;%s;%s00\n", rideid, ridedate, ridedistance, ridecity, ridetip);
        free(rideid); free(ridedate); free(ridedistance); free(ridecity); free(ridetip);
        if (mode == 1) printf("%s",output);
        if ((mode == 0) || (mode == 3)) handle_outputs(counter, output);
    }

    free(ridesd);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    if ((mode == 1) || (mode == 3)) printf("Fim da Q9 - %f segundos (input nº %i)\n", cpu_time_used, counter);
}