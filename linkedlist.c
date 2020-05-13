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

Status insert_at(List_ptr list, Element element, int position) {
  if(position < 0 || position > list->length){
    return Failure;
  }
  Node_ptr node = create_node(element);

  if(position == list->length || list->length == 0){
    list->last = node;
  }
  if(position == 0){
    node->next = list->first;
    list->first = node;
    list->length++;
    return Success;
  }
  
  Node_ptr p_walk = list->first;
  int index = 1;
  while (index != position)
  {
    p_walk = p_walk->next;
    index++;
  }
  node->next = p_walk->next;
  p_walk->next = node;
  list->last->next = NULL;
  list->length++;
  return Success;
};

