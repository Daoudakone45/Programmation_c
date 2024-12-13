#include <stdio.h>

int main() {
    // Nom du fichier source
    const char* filename = __FILE__; // __FILE__ contient le nom du fichier source
    FILE* file = fopen(filename, "r"); // Ouvre le fichier en mode lecture
    
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    // Lecture caractère par caractère et affichage
    char c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file); // Fermer le fichier
    return 0;
}
