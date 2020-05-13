#include <stdlib.h>
#include "test_lib.h"
#include "../linkedlist.h"
#include "tests.h"

void test_remove_from_start(){
  List_ptr list = create_list();
  describe("# REMOVE_FROM_START");
  it("* should not remove a number from empty list");
  assert_null(remove_from_start(list));
  assert_int_equal(list->length, 0);

  int_ptr element1 = create_int_element(6);
  int_ptr element2 = create_int_element(7);
  add_to_start(list, element1);
  add_to_list(list, element2);

  it("* should remove a number from beginning of list");
  assert_void_int_equal(remove_from_start(list), element1);
  assert_int_equal(list->length, 1);
  assert_void_int_equal(list->first->element, element2);
  assert_void_int_equal(list->last->element, element2);

  destroy_list(list);
}

void test_remove_from_end(){
  describe("# REMOVE_FROM_END");
  List_ptr list = create_list();
  it("* should not remove a number from empty list");
  assert_null(remove_from_end(list));
  assert_int_equal(list->length, 0);

  int_ptr element1 = create_int_element(6);
  int_ptr element2 = create_int_element(7);
  add_to_start(list, element1);
  add_to_list(list, element2);

  it("* should remove a number from end of list");
  assert_void_int_equal(remove_from_end(list), element2);
  assert_int_equal(list->length, 1);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element1);

  destroy_list(list);
}

void test_remove_at(){
  List_ptr list = create_list();
  describe("# REMOVE_AT");
  it("* should not remove a number from empty list");
  assert_null(remove_from_start(list));
  assert_int_equal(list->length, 0);

  int_ptr element1 = create_int_element(1);
  int_ptr element2 = create_int_element(2);
  int_ptr element3 = create_int_element(3);
  int_ptr element4 = create_int_element(4);
  int_ptr element5 = create_int_element(5);

  add_to_list(list, element1);
  add_to_list(list, element2);
  add_to_list(list, element3);
  add_to_list(list, element4);
  add_to_list(list, element5);

  it("* should remove a number from a given position in the list");
  assert_void_int_equal(remove_at(list, 2), element3);
  assert_int_equal(list->length, 4);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element5);

  it("* should remove a number from beginning of list");
  assert_void_int_equal(remove_at(list, 0), element1);
  assert_int_equal(list->length, 3);
  assert_void_int_equal(list->first->element, element2);
  assert_void_int_equal(list->last->element, element5);

  it("* should remove a number from end of list");
  assert_void_int_equal(remove_at(list, 2), element5);
  assert_int_equal(list->length, 2);
  assert_void_int_equal(list->first->element, element2);
  assert_void_int_equal(list->last->element, element4);

  it("* should not remove a number from list if position is less than list count");
  assert_null(remove_at(list, -1));
  assert_int_equal(list->length, 2);
  assert_void_int_equal(list->first->element, element2);
  assert_void_int_equal(list->last->element, element4);

  it("* should not remove a number from list if position is more than list count");
  assert_null(remove_at(list, 3));
  assert_int_equal(list->length, 2);
  assert_void_int_equal(list->first->element, element2);
  assert_void_int_equal(list->last->element, element4);

  destroy_list(list);
};