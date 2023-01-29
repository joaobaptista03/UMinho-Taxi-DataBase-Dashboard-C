/**
 * @file tests.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com os testes funcionais e de desempenho.
 * 
 */

#ifndef TESTS_H
#define TESTS_H

#include <time.h>

#include "query1.h"
#include "query2.h"
#include "query3.h"
#include "query4.h"
#include "query5.h"
#include "query6.h"
#include "query7.h"
#include "query8.h"
#include "query9.h"

void q1_test(int counter, char *id);
void q2_test(int counter, char *id);
void q3_test(int counter, char *id);
void q4_test(int counter, char *id);
void q5_test(int counter, char *id);
void q6_test(int counter, char *id);
void q7_test(int counter, char *id);
void q8_test(int counter, char *id);
void q9_test(int counter, char *id);

int main();

#endif