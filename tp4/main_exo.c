/* The file main of exercise 1*/

/* main.c */
#include "stack.h"
#include <stdio.h>
/*
int main() {
    stack_init();
    
    stack_display();
    stack_push(10);
    stack_push(20);
    stack_push(30);
    
    stack_display();
    
    printf("Top element: %d\n", stack_top());
    printf("Popped element: %d\n", stack_pop());
    
    stack_display();
    
    printf("Element at index 0: %d\n", stack_get_element(0));
    
    return 0;
}
*/


int main() {

    stack_init();
    
    printf("Test de la pile avec modulo et factorielle:\n");

    // Test du modulo
    //stack_push(10);
    //stack_push(3);
    //printf("Avant modulo:\n");
    //stack_display();
    //stack_modulo();
    //printf("Après modulo (10 %% 3):\n");
    //stack_display();

    // Test de la factorielle
    stack_push(5);
    printf("Avant factorielle:\n");
    stack_display();
    stack_factorial();
    printf("Après factorielle (5!):\n");
    stack_display();

    return 0;
}

