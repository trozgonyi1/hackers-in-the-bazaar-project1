// First attempt

#include <stdio.h>
#include <unistd.h>

long long int ackermann_peter(long long int n, long long int m) {
  if (m == 1) {
    return 2*n;
  } else if (m >= 1 && n ==1) {
    return m;
  } else {
    return ackermann_peter(m-1, ackermann_peter(m, n-1));
  }

  return 1;
}
