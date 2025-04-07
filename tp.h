#ifndef TP_H
#define TP_H
#include <stdalign.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    char nom[20];
    int code;
    int date_fabrication;
    int date_peremption;
    int prix;
    int unite;
    int stock_restant;
}Medicament;

int tri_a_bulles(Medicament *tab, int n);
void recherche_dichotomique(Medicament *tab, int n);
void medicament_le_plus_cher(Medicament *tab, int n);


#endif