// Hopefully fast one

// Testing out the stack approach to simulate recursion
// In the process of converting c++ logic to c logic

#include <stdio.h>
#include "stack.h"

int heap_ackermann_peter(int m, int n) {
// stack creation
  Stack* stack = stack_create(1<<20);
  stack_push(m, stack);
        
  while(stack->sp != -1) {
    stack_pop(stack, &m);

skipStack:
    if (m == 0)
      n = n + 1;
    else if (m == 1)
      n = n + 2;
    else if (m == 2)
      n = (n * 2) + 3;
    else if (n == 0) {
      --m;
      n = 1;
      goto skipStack;
    } else {
      --n;
      stack_push(m - 1, stack);
      goto skipStack;
    }
  }

  return n;
}
