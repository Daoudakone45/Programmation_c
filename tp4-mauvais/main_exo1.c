/* The file main of exercise 1*/

/* main.c */
#include "stack.h"
#include <stdio.h>

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
