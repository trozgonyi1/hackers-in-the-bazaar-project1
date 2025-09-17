#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *stack_create(int size){
  Stack *ackermann_stack = malloc(sizeof(Stack));
  ackermann_stack->stack = calloc(size/sizeof(int), size);
  ackermann_stack->sp = -1;
  ackermann_stack->capacity = size/sizeof(int);
  if (ackermann_stack == NULL || ackermann_stack->stack == NULL){
    return NULL;
  }
  return ackermann_stack;
}

void stack_free(Stack *stack) {
  free(stack->stack);
  free(stack);
}

int stack_push(int x, Stack *a_stack) {
  if (a_stack->sp == a_stack->capacity) {
    printf("STACK OVERFLOW\n");
    return 1;
  }

  a_stack->sp += 1;
  a_stack->stack[a_stack->sp] = x;

  return 0;
}

int stack_pop(Stack *stack, int *m) {
  if (stack->sp == -1) {
    printf("Popping from empty stack\n");
    return 1;
  }
  
  *m = stack->stack[stack->sp];
  stack->sp--;
  return 0;
}
