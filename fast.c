// Hopefully fast one

// Testing out the stack approach to simulate recursion
// In the process of converting c++ logic to c logic

#include <stdio.h>

long long int Ackermann(long long m, long long n)
    {
        // declare stack
        Stack<BigInteger> stack = new Stack<BigInteger>();

        // push m
        stack.Push(m);

        while(stack.Count != 0)
        {
            m = stack.Pop();

        // recurse down 
        skipStack:
            // pattern for the first few m's
            if(m == 0)
                n = n + 1;
            else if(m == 1)
                n = n + 2;
            else if(m == 2)
                n = n * 2 + 3;
            else if(n == 0)
            {
                --m;
                n = 1;
                goto skipStack;
            }
            else
            {
                stack.Push(m - 1);
                --n;
                goto skipStack;
            }
        }
        return n;
    }
s