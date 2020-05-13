#include <stdio.h>
#include "test_lib.h"
#include "../linkedlist.h"
#include "tests.h"

void runTests(void);

void runTests(void){
  test_create_list();
  test_create_int_element();
  test_create_char_element();
  test_create_node();
  test_insert_at();
  test_add_to_start();
  test_add_to_list();
  test_add_unique();
  test_clear_list();
}

int main() {
  printf("TESTS_START_______________\n");
  runTests();
  printf("\n\nTESTS_END_______________\n");
  return 0;
}