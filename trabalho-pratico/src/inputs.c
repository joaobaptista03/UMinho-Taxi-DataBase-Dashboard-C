/**
 * @file inputs.c
 * Este ficheiro contém a função que trata de cada input e redireciona-os para a query correspondente
 * 
 */

#include "../include/inputs.h"

void handle_inputs(Driver *drivers_cat, User *users_cat, Ride *rides_cat, FILE *inputs) {
    
    /*
    // Criar cópias dos catálogos para encapsulamento
    Driver *new_drivers_cat;
        new_drivers_cat = malloc(10001*sizeof(Driver));
        for (int i = 1; i <= 10000; i++) new_drivers_cat[i] = drivers_cat[i];
    User *new_users_cat;
        new_users_cat = malloc(100001*sizeof(Driver));
        for (int i = 1; i <= 100000; i++) new_users_cat[i] = users_cat[i];
    Ride *new_rides_cat;
        new_rides_cat = malloc(1000001*sizeof(Driver));
        for (int i = 1; i <= 1000000; i++) new_rides_cat[i] = rides_cat[i];
    */

    int counter = 1;                                                    // Contador do input em que está
    char input[100];                                                    // String para qual cada linha de input irá ser copiada
    while(fgets(input, 100, inputs)) {                                  // Loop While que irá fazer certas coisas (em cada loop) a cada linha do ficheiros de inputs  
        if (strchr(input, '\n')) *(strchr(input, '\n') - 1) = '\0';           // Trocar '\n' por '\0' na string input
        char new_input[100];
        strcpy(new_input, input);                                       // Encapsulamento
        if (new_input[0] == '1') query1(counter, drivers_cat, users_cat, rides_cat, new_input + 2);                // Chamar a query1 se for o caso
        if (new_input[0] == '2') query2(counter, drivers_cat, users_cat, rides_cat, new_input + 2);
        /*
        if (new_input[0] == '3') query3(counter, drivers_cat, users_cat, rides_cat, new_input + 2);
        if (new_input[0] == '4') query4(counter, drivers_cat, users_cat, rides_cat, new_input + 2);
        if (new_input[0] == '5') query5(counter, drivers_cat, users_cat, rides_cat, new_input + 2, input + 13);
        if (new_input[0] == '6') query6(counter, drivers_cat, users_cat, rides_cat, new_input + 2); // Tem de fazer parsing porque o tamanho da city varia
        if (new_input[0] == '7') query7(counter, drivers_cat, users_cat, rides_cat, new_input + 2); // Tem de fazer parsing porque o tamanho da city varia
        if (new_input[0] == '8') query8(counter, drivers_cat, users_cat, rides_cat, new_input + 2, input + 4);
        if (new_input[0] == '9') query9(counter, drivers_cat, users_cat, rides_cat, new_input + 2, input + 13);
        */
       counter++;                                                       // Incrementar nº de inputs
    }
}