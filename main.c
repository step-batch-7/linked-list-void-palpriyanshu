#include <stdio.h>
#include "linkedlist.h"

int main()
{
  List_ptr list = create_list();
  Element num = create_int_element(6);
  Element letter = create_char_element('a');
  Status status = insert_at(list, num, 0);
  printf("%d\n", status);
  status = add_to_start(list,letter);
  printf("%d\n", status);
  clear_list(list);
  return 0;
}
