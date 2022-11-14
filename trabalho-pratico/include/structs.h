/**
 * @file structs.h
 * Este ficheiro contém as structs do Projeto.
 * 
 */

#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 *
 * Esta é a Struct que define o que é um Driver, e contém todas as informações dele. Será inserida no catálogo das Drivers.
 * 
 */
typedef struct
{
    char id[15];
    char name[100];
    char birth_date[10];
    char gender;
    char car_class[50];
    char licence_plate[10];
    char city[20];
    char acc_creation[10];
    char status[10];

} Driver;

/**
 *
 * Esta é a Struct que define o que é um User, e contém todas as informações dele. Será inserida no catálogo dos Users.
 * 
 */
typedef struct
{
    char user[30];
    char name[100];
    char gender;
    char birth_date[10];
    char acc_creation[10];
    char pay_method[20];
    char status[10];

} User;

/**
 *
 * Esta é a Struct que define o que é uma Ride, e contém todas as informações dela. Será inserida no catálogo das Rides.
 * 
 */
typedef struct
{
    char id[15];
    char date[10];
    char driver[100];
    char user[100];
    char city[20];
    int distance;
    int score_driver;
    double tip;
    char comment[100];

} Ride;


/**
 *
 * Este é o header da função que insere os dados dos drivers, users e rides nos catálogos respetivos.
 * 
 */
void inserir_dados();

#endif