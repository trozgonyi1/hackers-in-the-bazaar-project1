<<<<<<< HEAD
// First attempt
// Time complexity = O(m * ackermann_peter(m, n))

=======
>>>>>>> 82c2ab1 (-)
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "slow1.h"


// size of window
#define MAX_Y   20                
#define MAX_X   80               
#define X_PER_SEC 10.0             

// Canvas and timing
static char canvas[MAX_Y][MAX_X];
static double t0 = 0.0;

// Get monotonic time in seconds
static double now_sec(void){
#if defined(CLOCK_MONOTONIC)
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
#else
  return (double)clock() / (double)CLOCKS_PER_SEC; // fallback to CPU time
#endif
}

static void init_canvas(void){
  for(int r=0;r<MAX_Y;r++)
    for(int c=0;c<MAX_X;c++)
      canvas[r][c] = ' ';
  t0 = now_sec();
}

// Map a raw value to y row 
static int scale_y(long long val){
  if (val < 0) val = 0;
  if (val > MAX_Y) val = MAX_Y;

  
  double frac = (double)val / (double)MAX_Y;
  int row = (int)(frac * (MAX_Y - 1) + 0.5);
  return row;
}

// Draw axes and canvas
static void render_canvas(void){
  // Clear screen and home cursor 
  printf("\033[H\033[J");

  // Print from top row to bottom row
  for(int r = MAX_Y-1; r >= 0; r--){
    // Y axis tick every 5 rows
    if (r % 5 == 0){
      printf("%2d |", r);
    } else {
      printf("   |");
    }
    for(int c=0;c<MAX_X;c++){
      putchar(canvas[r][c]);
    }
    putchar('\n');
  }

  // X-axis
  printf("    +");
  for(int c=0;c<MAX_X;c++) putchar('-');
  printf("\n     ");
  for(int c=0;c<MAX_X;c++){
    putchar((c%10)==0 ? '|' : ' ');
  }
  printf("\n     time →  (%.2f cols/sec)\n", X_PER_SEC);
  fflush(stdout);
}

// Plot one point at time 
static void plot_live_point(long long int depth){
  double t = now_sec() - t0;
  int x = (int)(t * X_PER_SEC);
  if (x < 0) x = 0;
  if (x >= MAX_X) x = MAX_X - 1;

  int y = scale_y(depth);       // depth
  canvas[y][x] = '/';

  render_canvas();
}


// ackermann
long long int ackermann_peter(long long int n, long long int m, int step) {
  
  plot_live_point(step);

  long long int result;
  if (m == 1) {
    result = 2 * n;
  } else if (m >= 1 && n == 1) {
    result = m;
  } else {
    result = ackermann_peter(m - 1, ackermann_peter(m, n - 1, step + 1), step + 1);
  }


  
  usleep(120000);
  return result;
}


void ack_plot_begin(void){ init_canvas(); render_canvas(); }
void ack_plot_end(void){ render_canvas(); }
