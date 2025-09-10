// main.c
// Tommy Rozgonyi, Shaelin Murphy, Francis Drake

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include "slow1.h"

void print_bar(int percentage) {
//  printf("%d\n", percentage);
  for(int i = 0; i < percentage; i++) {
    printf("█");
  }
  printf("▓");
  printf("░\n");
}

int main (int argc, char **argv) {
  printf("╔═════════════════════════════════════════════════╗\n");
  printf("║         Racing Ackerman-Péter Functions         ║\n");
  printf("╚═════════════════════════════════════════════════╝\n");

  clock_t start = clock();
  long long int ap_value = ackermann_peter(3, 2);
  clock_t end = clock();

  double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
  if (ap_value == 1) {
    printf("Computation failed in %f seconds\n", time_elapsed);
  } else {
    printf("Time taken: %f\n", time_elapsed);
    printf("Result = %lld\n", ap_value);
    print_bar((int)(time_elapsed*10000000));
  }

  return 0;
}

