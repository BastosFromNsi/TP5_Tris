#include "tp.h"
#include <stdlib.h>
#include <stdio.h>

int tri_a_bulles(Medicament *tab, int n)
{
    if (tab == NULL || n <= 0)
    {
        return 1;
    }

    int i, j;
    Medicament temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (tab[j + 1].date_peremption < tab[j].date_peremption)
            {
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }

    return 0;
}

void recherche_dichotomique(Medicament *tab, int n)
{

    int debut = 0;
    int fin = n - 1;
    int milieu;
    int trouve = 0;
    char nom_medoc[20];
    fgets(nom_medoc, sizeof(nom_medoc), stdin);
    getchar();
    while (trouve != 1 && debut <= fin)
    {
        milieu = ((debut + fin) / 2);
        if ((tab[milieu]).nom == nom_medoc)
        {
            trouve = 1;
        }
        else
        {
            if (nom_medoc > (tab[milieu].nom))
            {
                debut = milieu + 1;
            }
            else
            {
                fin = milieu - 1;
            }
        }
    }

    if (trouve == 1)
    {
        printf(" La valeur %s est au rang %d /n", nom_medoc, milieu);
    }
    else
    {
        printf("La valeur %s n'est pas dans le tableau", nom_medoc);
    }
}

void medicament_le_plus_cher(Medicament *tab, int n)
{
    if (tab == NULL || n <= 0)
    {
        return;
    }

    Medicament max = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i].prix > max.prix)
        {
            max = tab[i];
        }
    }

    printf("Le medicament le plus cher est : %s, code : %d, prix : %d\n", max.nom, max.code, max.prix);
}

int main()
{

    int n = 4;

    Medicament tab[] = {
        {"Paracetamol", 101, 20230101, 20220302, 100, 1, 50},
        {"Ibuprofène", 102, 20230201, 20240701, 200, 2, 30},
        {"Aspirine", 103, 20230401, 20240301, 150, 1, 20},
        {"Fluoxétine", 104, 20230301, 20240401, 250, 3, 10},
    };

    printf("Tableau avant le tri :\n");
    for (int i = 0; i < n; i++)
    {
        printf(" Nom : %s, Code : %d, Date de fabrication : %d, Date de peremption : %d, Prix : %d, Unite : %d, Stock restant : %d\n",
               tab[i].nom, tab[i].code, tab[i].date_fabrication, tab[i].date_peremption, tab[i].prix, tab[i].unite, tab[i].stock_restant);
    }

    tri_a_bulles(tab, n);

    printf(" Tableau apres le tri : \n");

    for (int i = 0; i < n; i++)
    {
        printf(" Nom : %s, Code : %d,  : %d, Date de fabrication : %d, Prix : %d, Unite : %d, Stock restant : %d\n",
               tab[i].nom, tab[i].code, tab[i].date_fabrication, tab[i].date_peremption, tab[i].prix, tab[i].unite, tab[i].stock_restant);
    }

    recherche_dichotomique(tab, n);

    medicament_le_plus_cher(tab, n);

    return 0;
}
