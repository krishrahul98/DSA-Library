// Stack Implementation
// Stores void *, cast to any type.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INIT_STACK_LENGTH 4
#define EMPTY (-1)

#define STACK_CREATE(name)                                                     \
  stack name;                                                                  \
  stack_create(&name)
#define STACK_PUSH(stack, value) stack_push(&stack, (void*)&value)
#define STACK_POP(stack) stack_pop(&stack)
#define STACK_SIZE(stack) stack_size(&stack)
#define STACK_EMPTY(stack) stack_empty(&stack)
#define STACK_FREE(stack) stack_free(&stack)

typedef struct stack stack;

static void stack_resize(stack *s, size_t new_capacity);

struct stack {
  void **elements;
  size_t size;
  size_t capacity;
  int top;
};

void stack_create(stack *s) {
  s->size = 0;
  s->capacity = INIT_STACK_LENGTH;
  s->top = EMPTY;
  s->elements = malloc(sizeof(void*) * s->capacity);
}

bool stack_push(stack* s, void *value) {
  if (s->capacity == s->size) {
    stack_resize(s, s->capacity * 2);
  }

  s->top++;
  s->elements[s->top] = value;
  s->size++;
  return true;
}

void *stack_pop(stack* s) {
  if (s->top == EMPTY) return false;
  
  void * top = s->elements[s->top];
  s->elements[s->top] = NULL;
  s->top--;
  s->size--;

  if (s->size > 0 && s->size == s->capacity / 4) {
    stack_resize(s, s->capacity / 2);
  }
  return top;
}

size_t stack_size(stack* s) {return s->size;}

bool stack_empty(stack* s) { return s->size == 0;}

void stack_free(stack* s) { free(s->elements); }


static void stack_resize(stack *s, size_t new_capacity) {
  void **elements = realloc(s->elements, sizeof(void*)*new_capacity);
  if (elements) {
    s->elements = elements;
    s->capacity = new_capacity;
    s->top = s->size - 1;
  }
}


int main(void) {
  // Some test code

  float data[10] = {
    100.,65.,1.,4.2,45.,134,1,1245,4,31
  };
  
  STACK_CREATE(my_stack);

  for (int i = 0; i < 10; ++i) {
    STACK_PUSH(my_stack, data[i]);
    printf("%f pushed to stack\n", data[i]);
    printf("\ttop: %d\n", my_stack.top);
    printf("\tsize: %lu\n", STACK_SIZE(my_stack));
  }


  for (int i = 0; i < 10; ++i) {

    float top = *(float *)STACK_POP(my_stack);

    printf("top (popped) : %f\n", top);
    printf("\tsize: %lu\n", STACK_SIZE(my_stack));
  }
 

  STACK_FREE(my_stack);

}
