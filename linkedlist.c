#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Int_ptr create_int_data(int value){
  Int_ptr data = malloc(sizeof(int));
  *data = value;
  return data;
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

