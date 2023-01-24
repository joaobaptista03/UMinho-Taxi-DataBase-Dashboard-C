/**
 * @file query9.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com as Query 9.
 * 
 */

#include "../include/query9.h"

void query9 (int counter, Ride *rides_cat,  char *data1, char* data2, int mode) {
    printf("\nA executar Q9 (linha de input %i)\n", counter);
    if (mode == 1) printf("\n");

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    
    Ride *ridesd = malloc(2 * sizeof(Ride));
    int capd = 2;
    int rides_d = 0;
    int contadord = 0;

     for (int i = 1; i <= atoi(rides_cat[0].id); i++) {                                                  // Percorrer o catálogo das rides
         if (//(atof ((rides_cat[i].tip) > 0))
          (most_recent(rides_cat[i].date, data1) == 1 || most_recent(rides_cat[i].date, data1) == 3)
         &&  (most_recent(rides_cat[i].date, data2) == 2 || most_recent(rides_cat[i].date, data2) == 3)){
              rides_d++;
              if (rides_d > capd) {
                  ridesd = realloc(ridesd, 2 * capd * sizeof(Ride));
                  capd *= 2;
              }
              ridesd[contadord] = rides_cat[i];
              contadord++; 

        }
    }

    if (mode == 1) puts("Forma do Resultado: id_viagem;data_viagem;distancia;cidade;valor_gorjeta");
    for (int i = 0; i < contadord - 1; i++) {                                    // For loop que irá criar a string de output e passá-la para a handle_outputs
        char output[150];
        sprintf(output, "%s;%s;%s;%s;%s\n", ridesd[i].id, ridesd[i].date, ridesd[i].distance, ridesd[i].city, ridesd[i].tip);
        if (mode == 1) printf("%s",output);
        if (mode == 0) handle_outputs(counter, output);
    }

    free(ridesd);

   
   
   
    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    if (mode == 1) printf("\n");
    printf("Fim da Q9 - %f segundos (linha de input %i)\n", cpu_time_used, counter);
}