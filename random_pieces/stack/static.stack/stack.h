#ifndef __STACK__
#define __STACK__

#include <stdlib.h>

#define MAX_STACK_SIZE 300

typedef int elem;


typedef struct { 
  size_t size;
  elem elements[MAX_STACK_SIZE];
} Stack;

void create(Stack *s);
void empty(Stack *s);

int size(Stack *s);
int getTop(Stack *s, elem *e);

int isEmpty(Stack *s);
int isFull(Stack *s);

int push(Stack *s, elem e);
int pop(Stack *s, elem *e);

#endif
