#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "slow1.h"
#include "fast.h"
#include "stack.h"

void init_depth_tracking(int initial_capacity);
void print_depth_bar_graph(void);
void cleanup_depth_tracking(void);

void print_bar(int percentage) {
   
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
    
    if (strcmp(argv[3], "--slow") == 0 || strcmp(argv[3], "--all") == 0) {
        // initialize depth tracking
        init_depth_tracking(10000);
        
        ap_value = ackermann_peter(m, n, 0);  
        
        // Print depth bar graph
        print_depth_bar_graph();
        
        cleanup_depth_tracking();
    }
    
    clock_t end = clock();
    double time_elapsed_1 = (double)(end - start) / CLOCKS_PER_SEC;

    // Fast version with stack tracking
    start = clock();
    int heap_ap_value = -1;
    if (strcmp(argv[3], "--fast")  == 0 || strcmp(argv[3], "--all") == 0) {
        // init tracking 
        init_stack_tracking(10000);
        
        heap_ap_value = heap_ackermann_peter(m, n);
        
        // Draw stack depth bar graph
        print_stack_bar_graph();
        
        cleanup_stack_tracking();
    }
    end = clock();
    double time_elapsed_2 = (double)(end - start) / CLOCKS_PER_SEC;

    // Print results
    if (ap_value == 1) {
        printf("Computation failed in %f seconds\n", time_elapsed_1);
    } else {
        printf("Time taken: %f\n", time_elapsed_1);
        printf("Result = %lld\n", ap_value);
        
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
    }
    
    return 0;
}