#include <stdio.h>
#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  Element num1 = create_int_element(6);
  Element num2 = create_char_element(7);
  insert_at(list, num1, 0);
  add_to_start(list, num2);
  add_to_list(list, num2);
  display(list, display_int);
  destroy_list(list);
  return 0;
}
