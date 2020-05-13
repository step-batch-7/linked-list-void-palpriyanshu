#include <stdlib.h>
#include "test_lib.h"
#include "../linkedlist.h"
#include "tests.h"


void test_insert_at(void){
  describe("# INSERT_AT");
  List_ptr list = create_list();

  int_ptr element1 = create_int_element(6);
  assert_int_equal(insert_at(list, element1, 0), Success);
  assert_int_equal(list->length, 1);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element1);

  it("* should insert at last position in the list");
  int_ptr element2 = create_int_element(7);
  assert_int_equal(insert_at(list, element2, 1), Success);
  assert_int_equal(list->length, 2);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element2);

  it("* should insert at first position in the list");
  int_ptr element3 = create_int_element(8);
  assert_int_equal(insert_at(list, element3, 0), Success);
  assert_int_equal(list->length, 3);
  assert_void_int_equal(list->first->element, element3);
  assert_void_int_equal(list->last->element, element2);

  it("* should insert a number at any position in the list");
  int_ptr element4 = create_int_element(9);
  assert_int_equal(insert_at(list, element4, 1), Success);
  assert_int_equal(list->length, 4);
  assert_void_int_equal(list->first->element, element3);
  assert_void_int_equal(list->last->element, element2);

  it("* should not insert at position which is less than list count");
  assert_int_equal(insert_at(list, element4, -1), Failure);
  assert_int_equal(list->length, 4);
  assert_void_int_equal(list->first->element, element3);
  assert_void_int_equal(list->last->element, element2);

  it("* should not insert at position which is more than list count");
  assert_int_equal(insert_at(list, element4, 6), Failure);
  assert_int_equal(list->length, 4);
  assert_void_int_equal(list->first->element, element3);
  assert_void_int_equal(list->last->element, element2);

  clear_list(list);
};