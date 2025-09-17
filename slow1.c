#include <stdio.h>
#include <unistd.h>


unsigned long long ackermann_peter(long long int m, long long int n) {
    if (m == 0) {
        return n+1;
    } else if (m >= 0 && n==0) {
        return ackermann_peter(m-1, 1);
    } else {
        return ackermann_peter(m - 1, ackermann_peter(m, n - 1));
    }

    return 1;
}
