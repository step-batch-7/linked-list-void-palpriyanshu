#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

List_ptr create_list(void){
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
};

Int_ptr create_int_data(int value){
  Int_ptr data = malloc(sizeof(int));
  *data = value;
  return data;
};