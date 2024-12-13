#include <stdio.h>
#include <stdlib.h>

// Exercice 2

int main(int argc, char *argv[]) {
    //int nombre1, nombre2, somme;

    // Demande à l'utilisateur de saisir deux entiers
    //printf("Entrez le premier entier : ");
    //scanf("%d", &nombre1);

    //printf("Entrez le deuxième entier : ");
    //scanf("%d", &nombre2);

    int nombre1 = atoi(argv[1]);
    int nombre2 = atoi(argv[2]);

    // Calcul de la somme
    int somme = nombre1 + nombre2;

    // Affichage du résultat
    printf("La somme de %d et %d est : %d\n", nombre1, nombre2, somme);

    return 0;
}
