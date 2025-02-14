/* The file stack.c */
#include "stack.h"
#include <stdio.h>

static Stack stack;

void stack_init(void) {
    stack.size = 0;
}

int stack_size(void) {
    return stack.size;
}

int stack_is_empty(void) {
    return stack.size == 0;
}

int stack_top(void) {
    if (stack_is_empty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack.values[stack.size - 1];
}

int stack_pop(void) {
    if (stack_is_empty()) {
        printf("Stack is empty! Cannot pop.\n");
        return -1;
    }
    return stack.values[--stack.size]; 
}

void stack_push(int n) {
    if (stack.size >= MAX_SIZE) {
        printf("Stack overflow! Cannot push %d.\n", n);
        return;
    }
    stack.values[stack.size++] = n;
}

/* Print tous les éléments de la pile*/
void stack_display(void) {
    printf("Stack (size = %d): ", stack.size);
    int i;
    for (i = 0; i < stack.size; i++) {
        printf("%d ", stack.values[i]);
    }
    printf("\n");
}


/* Affiche l'élement associé à index dans la pile */
int stack_get_element(int index) {
    if (index < 0 || index >= stack.size) {
        printf("Invalid index!\n");
        return -1;
    }
    return stack.values[index];
}

/* Effectue l'opération modulo entre les deux derniers éléments de la pile */
void stack_modulo(void) {
    if (stack.size < 2) {
        printf("Erreur: pas assez d'éléments pour le modulo.\n");
        return;
    }
    int b = stack_pop();
    int a = stack_pop();
    if (b == 0) {
        printf("Erreur: division par zéro dans le modulo.\n");
        return;
    }
    stack_push(a % b);
}

/* Calcule la factorielle du dernier élément de la pile */
void stack_factorial(void) {
    if (stack.size < 1) {
        printf("Erreur: pas assez d'éléments pour la factorielle.\n");
        return;
    }
    int n = stack_pop();
    if (n < 0) {
        printf("Erreur: factorielle d'un nombre négatif non définie.\n");
        return;
    }
    int result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    stack_push(result);
}

