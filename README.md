# Ackermann-Péter Function

The Ackermann-Péter function was developed by German Mathemetician Wilhelm Ackermann (originally with 3 variables) and improved by Hungarian Mathemetician Rózsa Péter (to now contain only 2 variables). It was one of the first examples of a total computable function that is not prim-
itively recursive. Any computable function can be solved using a Turing machine, and a total function is any function defined over all inputs of a chosen numerical set.

Richard Dedekind made the assumption that any function that could be defined in terms of itself could also be defined iteratively when he
was making the case for recursive functions as a unique function class. Though the Ackermann-Péter function was the second counterexample
(the Sudan function being the first), it was the most well-known. Rózsa Péter is responsible for coining the term `primitive recursion`, differentiating between functions like the Fibonacci which can be done recursively or iteratively with a series of `for` loops and ones that
have no possible iterative definition.


## Definition

A(0,n) = n+1

A(m+1, 0) = A(m,1)

A(m+1, n+1) = A(m, A(m+1, n))


## Sources
https://medium.com/the-modern-scientist/from-recursion-to-very-large-numbers-the-ackermann-function-c32e02d00741 
https://stackoverflow.com/questions/12186672/how-can-i-prevent-my-ackerman-function-from-overflowing-the-stack 
