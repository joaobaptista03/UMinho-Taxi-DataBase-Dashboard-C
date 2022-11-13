/**
 * @file structs.h
 * Este ficheiro contém as structs do Projeto.
 * 
 */

#ifndef STRUCTS
#define STRUCTS

char temp_id[20];
char temp_gender[5];
char temp_distance[10];
char temp_score_driver[5];
char temp_tip[5];

typedef struct
{
    int id;
    char name[100];
    char birth_date[10];
    char gender;
    char car_class[50];
    char licence_plate[10];
    char city[20];
    char acc_creation[10];
    char status[10];

} Driver;

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

typedef struct
{
    int id;
    char date[10];
    char driver[100];
    char user[100];
    char city[20];
    int distance;
    int score_driver;
    float tip;
    char comment[100];

} Ride;

void inserir_dados(); // Função que insere os dados dos drivers, users e rides nos catálogos respetivos.

#endif