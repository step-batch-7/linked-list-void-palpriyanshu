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
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_clear_list();
  test_map();
}

int main() {
  printf("TESTS_START_______________\n");
  runTests();
  printf("\n\nTESTS_END_______________\n");
  return 0;
}