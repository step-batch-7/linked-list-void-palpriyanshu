#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Int_ptr create_int_element(int value){
  Int_ptr element = malloc(sizeof(int));
  *element = value;
  return element;
};

Char_ptr create_char_element(char value){
  Char_ptr element = malloc(sizeof(char));
  *element = value;
  return element;
};

List_ptr create_list(void){
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
};

Node_ptr create_node(Element element){
  Node_ptr new_node = malloc(sizeof(Node));
  new_node->element = element;
  new_node->next = NULL;
  return new_node;
};

