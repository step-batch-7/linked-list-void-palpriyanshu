#include <stdio.h>
#include "test_lib.h"
#include "../linkedlist.h"
#include "tests.h"

void runTests(void);

void runTests(void){
  test_create_list();
}

int main() {
  printf("TESTS_START_______________\n");
  runTests();
  printf("\n\nTESTS_END_______________\n");
  return 0;
}