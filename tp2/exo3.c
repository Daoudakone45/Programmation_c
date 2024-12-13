#include <stdio.h>
/*
void afficher_sequence(int n) {
    // Affichage des nombres de n à 1
    for (int i = n; i >= 1; i--) {
        printf("%d ", i);
    }

    // Affichage des nombres de 1 à n
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    // Saut de ligne à la fin
    printf("\n");
}
*/

void affiche_monter(int n){
    if (n > 0){
        printf("%d ", n);
        affiche_monter(n-1);

    }
    
}

void affiche_descente(int n, int compteur){
    if (compteur <= n){
        printf("%d ",compteur);
        affiche_descente(n,compteur + 1);
    }
}

void affiche_recurrence(int n){
    affiche_monter(n);
    affiche_descente(n,1);
    printf("\n");
}


int main() {
    int n = 10; // Exemple avec n = 10
    //afficher_sequence(n);
    affiche_recurrence(n);
    return 0;
}
