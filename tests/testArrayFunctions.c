#include <stdlib.h>
#include "test_lib.h"
#include "../linkedlist.h"
#include "tests.h"

Element increment(Element num);
Element to_lower_case(Element letter);
Status is_odd(Element num);
Status is_vowel(Element letter);
Element sum(Element num1, Element num2);

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

Status is_odd(Element num){
  return *(int_ptr)num % 2;
}

Status is_vowel(Element letter){
  char alphabet = *(Char_ptr)letter;
  Status lower_case_vowels = alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u';
  Status upper_case_vowels = alphabet == 'A' || alphabet == 'E' || alphabet == 'I' || alphabet == 'O' || alphabet == 'U';
  return lower_case_vowels || upper_case_vowels;
}; 

Element sum(Element num1, Element num2){
  int_ptr sum = malloc(sizeof(int));
  *sum = *(int_ptr)num1 + *(int_ptr)num2;
  return sum;
};

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


void test_for_is_odd(void){
  it("* should filter odd numbers");
  List_ptr list = create_list();
  Element num1 = create_int_element(5);
  Element num2 = create_int_element(6);
  Element num3 = create_int_element(7);
  Element num4 = create_int_element(8);
  add_to_list(list, num1);
  add_to_list(list, num2);
  add_to_list(list, num3);
  add_to_list(list, num4);
  
  List_ptr filtered_list = filter(list, is_odd);
  assert_int_equal(filtered_list->length, 2);
  assert_int_equal(*(Int_ptr)filtered_list->first->element, 5);
  assert_int_equal(*(Int_ptr)filtered_list->last->element, 7);
  destroy_list(filtered_list);
  destroy_list(list);
}

void test_for_is_vowel(void){
  it("* should filter vowels");
  List_ptr list = create_list();
  Element letter1 = create_char_element('A');
  Element letter2 = create_char_element('b');
  Element letter3 = create_char_element('i');
  Element letter4 = create_char_element('K');
  add_to_list(list, letter1);
  add_to_list(list, letter2);
  add_to_list(list, letter3);
  add_to_list(list, letter4);

  List_ptr filtered_list = filter(list, is_vowel);
  assert_int_equal(filtered_list->length, 2);
  assert_char_equal(*(Char_ptr)filtered_list->first->element, 'A');
  assert_char_equal(*(Char_ptr)filtered_list->last->element, 'i');
  destroy_list(filtered_list);
  destroy_list(list);
}

void test_for_no_true(void){
  it("* should give empty array when no value is true");
  List_ptr list = create_list();
  Element num1 = create_int_element(4);
  Element num2 = create_int_element(6);
  Element num3 = create_int_element(2);
  Element num4 = create_int_element(8);
  add_to_list(list, num1);
  add_to_list(list, num2);
  add_to_list(list, num3);
  add_to_list(list, num4);
  
  List_ptr filtered_list = filter(list, is_odd);
  assert_int_equal(filtered_list->length, 0);
  assert_null(filtered_list->first);
  assert_null(filtered_list->last);
  destroy_list(filtered_list);
  destroy_list(list);
}

void test_filter(){
  describe("# FILTER");
  test_for_is_odd();
  test_for_is_vowel();
  test_for_no_true();
};


void test_for_empty_array(void){
  it("* should return pointer to initial value for empty array");
  List_ptr list = create_list();
  Element init = create_int_element(0);
  Element element = reduce(list, init, sum); 
  assert_void_int_equal(element, init);
  destroy_list(list);
}

void test_for_reducing_int_array(void){
  it("* should return pointer to sum of numbers");
  List_ptr list = create_list();
  Element num1 = create_int_element(1);
  Element num2 = create_int_element(2);
  Element num3 = create_int_element(3);
  Element num4 = create_int_element(4);
  add_to_list(list, num1);
  add_to_list(list, num2);
  add_to_list(list, num3);
  add_to_list(list, num4);
  
  Element init = create_int_element(0);
  Element element = reduce(list, init, sum); 
  assert_int_equal(*(Int_ptr)element, 10);
  destroy_list(list);
}

void test_reduce(void){
  describe("# REDUCE");
  test_for_empty_array();
  test_for_reducing_int_array();
}