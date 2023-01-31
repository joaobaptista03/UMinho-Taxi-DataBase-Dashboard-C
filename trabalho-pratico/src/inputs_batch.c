/**
 * @file inputs_batch.c
 * Este ficheiro contém a função que trata de cada input e redireciona-os para a query correspondente
 * 
 */

#include "../include/inputs_batch.h"

void handle_inputs(FILE *inputs) {

    int counter = 1;
    char *input; input = malloc(100 * sizeof(char));

    while(fgets(input, 100, inputs)) {
        if (strchr(input, '\n')) *(strchr(input, '\n')) = '\0';
        
        if (input[0] == '1') query1(counter, input + 2, 0);
        else if (input[0] == '2') query2(counter, input + 2, 0);
        else if (input[0] == '3') query3(counter, input + 2, 0);
        else if (input[0] == '4') query4(counter, input + 2, 0);
        else if (input[0] == '5') query5(counter, input + 2, input + 13, 0);
        else if (input[0] == '6') query6(counter, input + 2, 0);                 
        else if (input[0] == '7') query7(counter, input + 2, 0);
        else if (input[0] == '8') query8(counter, input + 2, 0);
        else if (input[0] == '9') query9(counter, input + 2, input + 13, 0);

       counter++;
    }

    free(input);
}
