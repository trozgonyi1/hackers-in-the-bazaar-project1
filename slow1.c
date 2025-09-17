#include <stdio.h>
#include <unistd.h>


unsigned long long ackermann_peter(long long int m, long long int n) {
    if (m == 1) {
        return 2*n;
    } else if (m >= 1 && n==1) {
        return m;
    } else {
        return ackermann_peter(m - 1, ackermann_peter(m, n - 1));
    }

    return 1;
}
