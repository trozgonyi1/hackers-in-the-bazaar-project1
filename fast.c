// Hopefully fast one

// Testing out the stack approach to simulate recursion
// In the process of converting c++ logic to c logic

#include <stdio.h>
#include "stack.h"

long long int Ackermann(long long m, long long n)
    {
        // stack creation
        Stack* stack = createStack(1000000);
        push(stack, m)

        while(!not_empty(stackx)) {
            pop(stack, &m);

        if (m == 0)
            n = n + 1;
        else if (m == 1)
            n = n + 2;
        else if (m == 2)
            n = (n * 2) + 3;
        else if (n == 0) {
            --m;
            n = 1;
            goto skipStack
        } else {
            --n;
            push(stack, m - 1)
            goto skipStack
        }
        }

        return n;
    }
s