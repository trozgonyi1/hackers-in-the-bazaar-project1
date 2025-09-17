// main.c
// Tommy Rozgonyi, Shaelin Murphy, Francis Drake

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "slow1.h"
#include "fast.h"
#include "stack.h"

void print_bar(int percentage) {
/*  for(int i = 0; i < percentage; i++) {
    printf("█");
  }
  printf("▓");
  printf("░\n");*/
}


int main (int argc, char **argv) {
  if (argc != 4) {
    printf("USAGE: ./ackermann m n --(all|slow|fast)\n");
    return 1;
  }
  printf("╔═════════════════════════════════════════════════╗\n");
  printf("║         Racing Ackerman-Péter Functions         ║\n");
  printf("╚═════════════════════════════════════════════════╝\n");

  int m = atol(argv[1]);
  int n = atol(argv[2]);

  
  clock_t start = clock();

  long long int ap_value = -1;
  int depth = 0;
  if (strcmp(argv[3], "--slow") == 0 || strcmp(argv[3], "--all") == 0) {
    ap_value = ackermann_peter(m, n, depth);
  }
  clock_t end = clock();
  // Final redraw (ensure last point + axes visible)
  

  double time_elapsed_1 = (double)(end - start) / CLOCKS_PER_SEC;

  start = clock();
  int heap_ap_value = -1;
  if (strcmp(argv[3], "--fast")  == 0 || strcmp(argv[3], "--all") == 0) {
    heap_ap_value = heap_ackermann_peter(m, n);
  }
  end = clock();

  double time_elapsed_2 = (double)(end - start) / CLOCKS_PER_SEC;

  if (ap_value == 1) {
    printf("Computation failed in %f seconds\n", time_elapsed_1);
  } else {
    printf("Time taken: %f\n", time_elapsed_1);
    printf("Result = %lld\n", ap_value);
    // scale the bar arbitrarily based on time
    int bar = (int)(time_elapsed_1 * 10);
    if (bar < 1) bar = 1;
    if (bar > 100) bar = 100;
    print_bar(bar);
    if (strcmp(argv[3], "--slow") == 0 || strcmp(argv[3], "--all") == 0)
      printf("Time taken for slow: %f\n", time_elapsed_1);

    if (strcmp(argv[3], "--fast") == 0 || strcmp(argv[3], "--all") == 0)
      printf("Time taken for fast: %f\n", time_elapsed_2);

    if (strcmp(argv[3], "--slow") == 0 || strcmp(argv[3], "--all") == 0)
      printf("Result = %lld\n", ap_value);
    else if (strcmp(argv[3], "--fast") == 0)
      printf("Result = %d\n", heap_ap_value);
//      print_bar((int)(time_elapsed_1*10000000));
//      print_bar((int)(time_elapsed_2*10000000));
  }
  return 0;
}
