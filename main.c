// main.c
// Tommy Rozgonyi, Shaelin Murphy, Francis Drake

#include <stdio.h>
#include <time.h>
#include "slow1.h"
#include "fast.h"
#include "stack.h"

void print_bar(int percentage) {
  for(int i = 0; i < percentage; i++) {
    printf("█");
  }
  printf("▓");
  printf("░\n");
}

// Forward decls for plotting helpers
void ack_plot_begin(void);
void ack_plot_end(void);

int main (int argc, char **argv) {
  printf("╔═════════════════════════════════════════════════╗\n");
  printf("║         Racing Ackerman-Péter Functions         ║\n");
  printf("╚═════════════════════════════════════════════════╝\n");

  heap_ackermann_peter(1,1);

  clock_t start = clock();
  long long int ap_value = ackermann_peter(3, 2, 0);
  clock_t end = clock();

  // Final redraw (ensure last point + axes visible)
  ack_plot_end();

  double time_elapsed = (double)(end - start) / CLOCKS_PER_SEC;
  if (ap_value == 1) {
    printf("Computation failed in %f seconds\n", time_elapsed);
  } else {
    printf("Time taken: %f\n", time_elapsed);
    printf("Result = %lld\n", ap_value);
    // scale the bar arbitrarily based on time
    int bar = (int)(time_elapsed * 10);
    if (bar < 1) bar = 1;
    if (bar > 100) bar = 100;
    print_bar(bar);
  }
  return 0;
}
