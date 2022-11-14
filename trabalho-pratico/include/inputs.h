/**
 * @file inputs.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com os inputs.
 * 
 */

#ifndef INPUTS_H
#define INPUTS_H

#include <string.h>
#include <stdio.h>

int counter = 1;        // Contador do input em que está

/**
 *
 * Este é o header da função que faz o tratamento dos inputs e redireciona-os para as query's correspondentes.
 * 
 */
void handle_inputs(FILE *inputs);

#endif