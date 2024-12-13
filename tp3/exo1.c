#include <stdio.h>

int power(int a, int n) {
    int result = 1; // Initialisation du résultat
    while (n > 0) {
        result *= a; // Multiplie le résultat par 'a'
        n--;         // Décrémente 'n'
    }
    return result; // Retourne le résultat final
}


int power2(int a, int n){
    if(n == 0){
        return 1;
    }

    if( n== 1){
        return a;
    }
    return a*power(a, n-1);
}


int main() {
    int a;
    int n;

    // Lecture des valeurs de 'a' et 'n'
    printf("Entrez un entier a : ");
    scanf("%d", &a);
    printf("Entrez un entier positif non nul n : ");
    scanf("%u", &n);

    // Appel de la fonction et affichage du résultat
    printf("%d puissance %u = %d\n", a, n, power2(a, n));

    return 0;
}


