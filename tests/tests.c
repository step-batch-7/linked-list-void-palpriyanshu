#include <stdlib.h>
#include "test_lib.h"
#include "../linkedlist.h"
#include "tests.h"

void test_create_list(void){
  describe("# CREATE_LIST");
  it("* should create a list");
  List_ptr list = create_list();
  assert_null(list->first);
  assert_null(list->last);
  assert_int_equal(list->length, 0);
};