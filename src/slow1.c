#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// variables to track depth for graphing
static int* depth_history = NULL;
static int history_size = 0;
static int history_capacity = 0;
static int max_depth = 0;

void init_depth_tracking(int initial_capacity) {
    depth_history = malloc(initial_capacity * sizeof(int));
    history_capacity = initial_capacity;
    history_size = 0;
    max_depth = 0;
}

// get depth
void record_depth(int depth) {
    if (history_size >= history_capacity) {
        history_capacity *= 2;
        depth_history = realloc(depth_history, history_capacity * sizeof(int));
    }
    
    depth_history[history_size] = depth;
    history_size++;
    
    if (depth > max_depth) {
        max_depth = depth;
    }
}
// 
unsigned long long ackermann_peter(long long int m, long long int n, int depth) {
    // get current depth
    record_depth(depth);
    
    if (m == 0) {
        return n+1;
    } else if (m >= 0 && n==0) {
        return ackermann_peter(m-1, 1, depth + 1);
    } else {
        return ackermann_peter(m - 1, ackermann_peter(m, n - 1, depth + 1), depth + 1);
    }

    return 1;
}

void print_depth_bar_graph() {
    if (history_size == 0) return;
    
    printf("\n═══ DEPTH BAR GRAPH ═══\n");
    
    // Sample points to avoid too wide output
    int sample_rate = (history_size > 50) ? history_size / 50 : 1;
    
    for (int i = 0; i < history_size; i += sample_rate) {
        printf("%8d: ", i);
        
        // draw horizontal bars
        int scaled_depth = (depth_history[i] * 40) / (max_depth > 0 ? max_depth : 1);
        for (int j = 0; j < scaled_depth; j++) {
            printf("█");
        }
        printf(" (depth: %d)\n", depth_history[i]);
    }
    
    printf("Max depth: %d, Total calls: %d\n", max_depth, history_size);
}

void cleanup_depth_tracking() {
    if (depth_history) {
        free(depth_history);
        depth_history = NULL;
    }
}
