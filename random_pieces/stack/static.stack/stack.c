#include "stack.h"


void create(Stack *s){ s -> size = 0; }
void empty(Stack *s){ create(s); }

int size(Stack *s) { return s -> size; }

int isEmpty(Stack *s) { return (size(s) == 0) ? 1 : 0; }
int isFull(Stack *s) { return (size(s) == MAX_STACK_SIZE) ? 1 : 0; }

int getTop(Stack *s, elem *e) {
  if (isEmpty(s)) return -1;

  *e = s -> elements[s->size - 1];
  return 0;
}

int push(Stack *s, elem e) {
  if (isFull(s)) return 1;

  s -> elements[s->size++] = e;
  return 0;
}

int pop(Stack *s, elem *e) {
  if (isEmpty(s)) return 1;

  *e = s -> elements[s->size-- - 1];

  return 0;
}
