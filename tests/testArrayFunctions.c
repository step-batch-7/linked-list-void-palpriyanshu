#include <stdlib.h>
#include "test_lib.h"
#include "../linkedlist.h"
#include "tests.h"

Element increment(Element num);
Element increment(Element letter);

Element increment(Element num){
  int_ptr incremented = malloc(sizeof(int));
  *incremented = *(int_ptr)num + 1;
  return incremented;
}

Element to_lower_case(Element letter){
  char alphabet = *(Char_ptr)letter;
  Char_ptr lower_cased = malloc(sizeof(char));
  *lower_cased = alphabet >= 65 && alphabet <= 90 ? alphabet + 32 : alphabet;
  return lower_cased;
}


void test_for_increment_numbers(void){
  it("* should increment each number by 1");
  List_ptr list = create_list();
  Element num1 = create_int_element(5);
  Element num2 = create_int_element(6);
  Element num3 = create_int_element(7);
  Element num4 = create_int_element(8);
  add_to_list(list, num1);
  add_to_list(list, num2);
  add_to_list(list, num3);
  add_to_list(list, num4);
  
  List_ptr mapped_list = map(list, increment);
  assert_int_equal(mapped_list->length, 4);
  assert_int_equal(*(Int_ptr)mapped_list->first->element, 6);
  assert_int_equal(*(Int_ptr)mapped_list->last->element, 9);
  destroy_list(mapped_list);
  destroy_list(list);
}

void test_for_to_lower_case(void){
  it("* should convert to lower case each alphabet");
  List_ptr list = create_list();
  Element letter1 = create_char_element('A');
  Element letter2 = create_char_element('b');
  Element letter3 = create_char_element('G');
  Element letter4 = create_char_element('K');
  add_to_list(list, letter1);
  add_to_list(list, letter2);
  add_to_list(list, letter3);
  add_to_list(list, letter4);
  
  List_ptr mapped_list = map(list, to_lower_case);
  assert_int_equal(mapped_list->length, 4);
  assert_char_equal(*(Char_ptr)mapped_list->first->element, 'a');
  assert_char_equal(*(Char_ptr)mapped_list->last->element, 'k');
  destroy_list(mapped_list);
  destroy_list(list);
};

void test_map(void){
  describe("# MAP");
  test_for_increment_numbers();
  test_for_to_lower_case();
}