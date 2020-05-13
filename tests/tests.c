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

void test_create_char_element(void){
  describe("# CREATE_CHAR_ELEMENT");
  it("* should create a char element");
  Element element = create_char_element('a');
  assert_char_equal(*(Char_ptr)element, 'a');
  free(element);
};

void test_create_int_element(void){
  describe("# CREATE_INT_ELEMENT");
  it("* should create a int element");
  Element element = create_int_element(5);
  assert_int_equal(*(int_ptr)element, 5);
  free(element);
};

void test_create_node(void){
  describe("# CREATE_NODE");
  int_ptr element = create_int_element(5);
  Node_ptr node = create_node(element);

  it("* should create a node with given value");
  assert_void_int_equal(node->element, element);
  assert_null(node->next);
  free(node);
};