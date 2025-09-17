typedef struct {
  int *stack;
  size_t sp;
  size_t capacity;
} Stack;

Stack *stack_create(int size);
void stack_free(Stack *stack);
int stack_push(int x, Stack *stack);
int stack_pop(Stack *stack, int *m);
