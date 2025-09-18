#ifndef SLOW1_H
#define SLOW1_H

unsigned long long ackermann_peter(long long int m, long long int n, int depth);
void init_depth_tracking(int initial_capacity);
void print_depth_bar_graph(void);
void cleanup_depth_tracking(void);

#endif