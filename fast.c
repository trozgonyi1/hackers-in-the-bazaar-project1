#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// variables to keep track of depth
static int* depth_history = NULL;
static int history_size = 0;
static int history_capacity = 0;
static int max_depth = 0;

// track max stack depth
void init_stack_tracking(int initial_capacity) {
    depth_history = malloc(initial_capacity * sizeof(int));
    history_capacity = initial_capacity;
    history_size = 0;
    max_depth = 0;
}

void record_stack_depth(int depth) {
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

int heap_ackermann_peter(int m, int n) {
    // Stack creation
    Stack* stack = stack_create(1<<20);
    stack_push(m, stack);
    
    while(stack->sp != -1) {
        // get current
        record_stack_depth(stack->sp + 1);
        
        stack_pop(stack, &m);

skipStack:
        if (m == 0)
            n = n + 1;
        else if (m == 1)
            n = n + 2;
        else if (m == 2)
            n = (n * 2) + 3;
        else if (n == 0) {
            --m;
            n = 1;
            goto skipStack;
        } else {
            --n;
            stack_push(m - 1, stack);
            goto skipStack;
        }
    }
    
    // record final of 0
    record_stack_depth(0);
    
    return n;
}

void draw_stack_depth_graph() {
    if (history_size == 0) return;
    
    printf("\n╔═══════════════ STACK DEPTH GRAPH ═══════════════╗\n");
    printf("║ Depth over Time (Time →, Depth ↑)               ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");
    
    // graph dimensions, might adjust
    int graph_width = 60;
    int graph_height = 20;
    
    // Scale time axis
    int time_scale = (history_size > graph_width) ? history_size / graph_width : 1;
    
    // draw graph
    for (int y = graph_height; y >= 0; y--) {
        int current_depth = (max_depth * y) / graph_height;
        
        
        printf("%3d|", current_depth);
        
        // Draw the line for this depth level
        for (int x = 0; x < graph_width; x++) {
            int time_point = x * time_scale;
            if (time_point < history_size) {
                if (depth_history[time_point] >= current_depth) {
                    printf("█");
                } else if (depth_history[time_point] >= current_depth - (max_depth / graph_height)) {
                    printf("▓");
                } else {
                    printf(" ");
                }
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    
    
    printf("   +");
    for (int i = 0; i < graph_width; i++) {
        printf("-");
    }
    printf("+\n");
    
    // Print time markers
    printf("   0");
    for (int i = 0; i < graph_width - 10; i++) printf(" ");
    printf("%d calls\n", history_size);
    
    printf("\nMax depth reached: %d\n", max_depth);
    printf("Total function calls: %d\n", history_size);
}

void cleanup_stack_tracking() {
    if (depth_history) {
        free(depth_history);
        depth_history = NULL;
    }
}

void print_stack_bar_graph() {
    if (history_size == 0) return;
    
    printf("\n═══ STACK DEPTH BAR GRAPH ═══\n");
    
    // Sample points to avoid too wide output
    int sample_rate = (history_size > 50) ? history_size / 50 : 1;
    
    for (int i = 0; i < history_size; i += sample_rate) {
        printf("%4d: ", i);
        
        // deaw depth as horozintal bars
        int scaled_depth = (depth_history[i] * 40) / (max_depth > 0 ? max_depth : 1);
        for (int j = 0; j < scaled_depth; j++) {
            printf("█");
        }
        printf(" (depth: %d)\n", depth_history[i]);
    }
    
    printf("Max depth: %d, Total calls: %d\n", max_depth, history_size);
}