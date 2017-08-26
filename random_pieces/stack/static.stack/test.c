#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include <assert.h>

int test_create();
int test_isEmpty();
int test_size();
int test_isFull();
int test_empty();
int test_getTop();
int test_pop();
int test_push();

int main() {
  char test_string[] = "Runnig Test to: %s\nResult: %s\n";

  printf(test_string, "Create", (test_create()) ? "Fail" : "Ok");
  printf(test_string, "Empty", (test_empty()) ? "Fail" : "Ok");
  printf(test_string, "Size", (test_size()) ? "Fail" : "Ok");
  printf(test_string, "IsEmpty", (test_isEmpty()) ? "Fail" : "Ok");
  printf(test_string, "IsFull", (test_isFull()) ? "Fail" : "Ok");
  printf(test_string, "Push", (test_push()) ? "Fail" : "Ok");
  printf(test_string, "Pop", (test_pop()) ? "Fail" : "Ok");

  return (EXIT_SUCCESS);
}

int test_create() {
  Stack s;

  create(&s);

  return (s.size != 0) ? EXIT_FAILURE : EXIT_SUCCESS;
}

int test_isEmpty() {
  Stack s;

  create(&s);

  return (isEmpty(&s) != 1) ? EXIT_FAILURE : EXIT_SUCCESS;
}

int test_isFull() {
  Stack s;

  create(&s);

  // Simulate a full stack
  s.size = MAX_STACK_SIZE -1;

  return (isFull(&s) != 1) ? EXIT_FAILURE : EXIT_SUCCESS;
}

int test_size() {
  Stack s;

  create(&s);
  assert(size(&s) == 0);

  s.size = 42;
  assert(size(&s) == 42);

  empty(&s);
  assert(size(&s) == 0);

  return  EXIT_SUCCESS;
}

int test_empty() {
  Stack s;

  create(&s);

  // Simulate a full stack
  s.size = MAX_STACK_SIZE -1;
  empty(&s);
  assert(s.size == 0);

  // Simulate a empty stack
  s.size = 0;
  empty(&s);
  assert(s.size == 0);

  // Simulate a partial filled stack
  s.size = 42;
  empty(&s);
  assert(s.size == 0);

  return  EXIT_SUCCESS;
}

int test_getTop() {
  Stack s;
  int sample_element = 0;

  create(&s);
  assert(getTop(&s, &sample_element) == -1);

  for (int i = 0; i < MAX_STACK_SIZE; ++i) {
    push(&s, i);

    // the value on stack top, is the last value?
    assert(getTop(&s, &sample_element) == i);
  }

  return  EXIT_SUCCESS;
}

int test_push() {
  Stack s;

  create(&s);

  for (int i = 0; i < MAX_STACK_SIZE; ++i) {
    // any error occurred?
    assert(push(&s, i) == 0);

    // the value on stack top, is the last value?
    assert(s.elements[s.size - 1] == i);
  }

  // try push an element into a full stack
  assert(push(&s, 42) == 1);

  return  EXIT_SUCCESS;
}

int test_pop() {
  Stack s;

  create(&s);

  for (int i = 0; !isFull(&s); ++i) push(&s, i);

  // how many items we got
  int count_elements = 0;
  while (!isEmpty(&s)) {
    int item;
    // any error occurred?
    assert(pop(&s, &item) == 0);

    // the last item is MAX_STACK_SIZE - 1
    assert(item == (MAX_STACK_SIZE - 1 - count_elements++));
  }

  // try pop an element into a empty stack
  int sample_value ;
  assert(pop(&s, &sample_value) == 1);

  return  EXIT_SUCCESS;
}

