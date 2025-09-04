## Ackermann-Péter Function

The Ackermann-Péter function was developed by German Mathemetician Wilhelm Ackermann and improved by Hungarian Mathemetician Rózsa Péter.
It was one of the first examples of a total computable function that is not primitively recursive. This means that there is an
algorithm to compute it, but it cannot be done with a series of `for` loops.

# Definition

A(0,n) = n+1

A(m+1, 0) = A(m,1)

A(m+1, n+1) = A(m, A(m+1, n))
