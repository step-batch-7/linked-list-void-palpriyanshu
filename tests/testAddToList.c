#include <stdlib.h>
#include "test_lib.h"
#include "../linkedlist.h"
#include "tests.h"

Status match_num(Element element1, Element element2);

Status match_num(Element element1, Element element2){
  return *(Int_ptr)element1 == *(Int_ptr)(element2);
};

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

  destroy_list(list);
};

void test_add_to_start(void){
  describe("# ADD_TO_START");
  List_ptr list = create_list();
  it("* should add a number to empty list");
  int_ptr element1 = create_int_element(5);
  assert_int_equal(add_to_start(list, element1), Success);
  assert_int_equal(list->length, 1);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element1);

  it("* should add a number to the beginning of list");
  Char_ptr element2 = create_char_element('a');
  assert_int_equal(add_to_start(list, element2), Success);
  assert_int_equal(list->length, 2);
  assert_void_char_equal(list->first->element, element2);
  assert_void_int_equal(list->last->element, element1);
  
  destroy_list(list);
};

void test_add_to_list(void){
  describe("# ADD_TO_LIST");
  List_ptr list = create_list();
  it("* should add a number to empty list");
  int_ptr element1 = create_int_element(6);
  assert_int_equal(add_to_list(list, element1), Success);
  assert_int_equal(list->length, 1);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element1);

  it("* should add a number to the end of list");
  Char_ptr element2 = create_char_element('a');
  assert_int_equal(add_to_list(list, element2), Success);
  assert_int_equal(list->length, 2);
  assert_void_int_equal(list->first->element, element1);
  assert_void_char_equal(list->last->element, element2);

  destroy_list(list);
};

void test_add_unique(void){
  describe("# ADD_UNIQUE");
  List_ptr list = create_list();
  it("* should add number at first position in the empty list");
  int_ptr element1 = create_int_element(6);
  assert_int_equal(add_unique(list, element1, match_num), Success);
  assert_int_equal(list->length, 1);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element1);

  it("* should add number at last in the list if it does not exist already");
  int_ptr element2 = create_int_element(7);
  assert_int_equal(add_unique(list, element2, match_num), Success);
  assert_int_equal(list->length, 2);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element2);

  it("* should not add number in the list if it exist already");
  assert_int_equal(add_unique(list, element1, match_num), Failure);
  assert_int_equal(list->length, 2);
  assert_void_int_equal(list->first->element, element1);
  assert_void_int_equal(list->last->element, element2);
  
  destroy_list(list);
};
