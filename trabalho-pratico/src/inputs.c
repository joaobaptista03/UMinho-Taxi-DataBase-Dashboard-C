/**
 * @file inputs.c
 * Este ficheiro contém a função que trata de cada input e redireciona-os para a query correspondente
 * 
 */

#include "../include/inputs.h"
#include "../include/query1.h"

void handle_inputs(FILE *inputs) {
    int counter = 1;                                                    // Contador do input em que está

    char input[100];                                                    // String para qual cada linha de input irá ser copiada
    while(fgets(input, 100, inputs)) {                                  // Loop While que irá fazer certas coisas (em cada loop) a cada linha do ficheiros de inputs
        if (strchr(input, '\n')) *strchr(input, '\n') = '\0';           // Trocar '\n' por '\0' na string input
        /*
        if (input[0] == '1') query1(counter, input + 2);                // Chamar a query1 se for o caso
        if (input[0] == '2') query2(counter, input + 2);
        if (input[0] == '3') query3(counter, input + 2);
        if (input[0] == '4') query4(counter, input + 2);
        if (input[0] == '5') query5(counter, input + 2, input + 13);
        if (input[0] == '6') query6(counter, input + 2); // Tem de fazer parsing porque o tamanho da city varia
        if (input[0] == '7') query7(counter, input + 2); // Tem de fazer parsing porque o tamanho da city varia
        if (input[0] == '8') query8(counter, input + 2, input + 4);
        if (input[0] == '9') query9(counter, input + 2, input + 13);
        */
       counter++;                                                       // Incrementar nº de inputs
    }
}