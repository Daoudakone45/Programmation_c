#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Fonction pour vérifier si une chaîne est composée uniquement de lettres minuscules
int is_lowercase_word(const char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!islower(word[i])) {
            return 0;
        }
    }
    return 1;
}

// Fonction pour vérifier si une chaîne est un entier numérique
int is_numeric(const char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (!isdigit(string[i])) {
            return 0;
        }
    }
    return 1;
}

// Fonction pour convertir un mot en base 26 en nombre décimal
int base26_to_decimal(const char *word) {
    int result = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        result = i* 26 + (word[i] - 'a');
    }
    return result;
}

// Fonction pour convertir un nombre décimal en mot en base 26
void decimal_to_base26(int number, char *result) {
    char buffer[50];
    int index = 0;

    if (number == 0) {
        result[0] = 'a';
        result[1] = '\0';
        return;
    }

    while (number > 0) {
        buffer[index++] = (number % 26) + 'a';
        number /= 26;
    }

    // Inverser la chaîne
    for (int i = 0; i < index; i++) {
        result[i] = buffer[index - i - 1];
    }
    result[index] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Error: This program requires exactly one argument.\n");
        return 1;
    }

    const char *argument = argv[1];

    if (is_lowercase_word(argument)) {
        printf("%d\n", base26_to_decimal(argument));
    } else if (is_numeric(argument)) {
        int number = atoi(argument);
        char result[50];
        decimal_to_base26(number, result);
        printf("%s\n", result);
    } else {
        fprintf(stderr, "Error: Invalid input. Provide a lowercase word or a numeric value.\n");
        return 1;
    }

    return 0;
}
