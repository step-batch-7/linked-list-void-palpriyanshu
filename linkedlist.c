#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "elements.h"

Status match_num(Element num1, Element num2){
  return *(Int_ptr)num1 == *(Int_ptr)num2;
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

Prev_current_pair_ptr create_prev_current_pair(List_ptr list) {
  Prev_current_pair_ptr pair = malloc(sizeof(Prev_current_pair));
  pair->prev = NULL;
  pair->current = list->first;
  return pair;
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

Status add_to_start(List_ptr list, Element element){
  return insert_at(list, element, 0);
}

Status add_to_list(List_ptr list, Element element){
  return insert_at(list, element, list->length);
};

Status add_unique(List_ptr list, Element element, Matcher matcher){
  Node_ptr p_walk = list->first;
  while(p_walk != NULL){
    if((*matcher)(p_walk->element, element)){
      return Failure;
    }
    p_walk = p_walk->next;
  } 
  return add_to_list(list, element);
};

Element remove_from_start(List_ptr list){
  if(list->length == 0){
    return NULL;
  }
  if(list->length == 1){
    list->last = NULL;
  }
  Node_ptr p_walk = list->first;
  Element element = p_walk->element;
  list->first = p_walk->next;
  list->length--;
  free(p_walk);
  p_walk = NULL;
  return element;
};

Element remove_from_end(List_ptr list){
  if(list->length <= 1){
    return remove_from_start(list);
  }
  Node_ptr p_walk = list->first;
  while(p_walk->next != NULL){
     list->last = p_walk;
    p_walk = p_walk->next;
  }
  Element element = p_walk->element;
  list->last->next = NULL;
  list->length--;
  free(p_walk);
  p_walk = NULL;
  return element;
};

Element remove_at(List_ptr list, int position)
{
  if(position < 0 || position > (list->length - 1)) {
    return NULL;
  }
  Prev_current_pair_ptr pair = create_prev_current_pair(list);
  if(position == 0) {
    return remove_from_start(list);
  }
  if(position == (list->length-1)) {
    return remove_from_end(list);
  }
  int index = 1;
  while (index != position) {
    pair->current = pair->current->next;
    index++;
  }
  pair->prev = pair->current->next;
  pair->current->next = pair->prev->next;
  Element element = pair->prev->element;
  list->length--;
  free(pair->prev);
  pair->prev = NULL;
  return element;
};

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher) {
  Prev_current_pair_ptr pair = create_prev_current_pair(list);
  for (int position = 0; pair->current != NULL; position++)
  {
    if ((*matcher)(pair->current->element, element))
    {
      pair->current = pair->prev;
      return remove_at(list, position);
    }
    pair->prev = pair->current;
    pair->current = pair->current->next;
  }
  return NULL;
};

List_ptr remove_all_occurrences(List_ptr list, Element element, Matcher matcher) 
{
  List_ptr removed_element_list = create_list();
  Element removed_element = remove_first_occurrence(list, element, matcher);
  while (removed_element != NULL)
  {
    add_to_list(removed_element_list, removed_element);
    removed_element = remove_first_occurrence(list, element, matcher);
  }
  return removed_element_list;
};

List_ptr map(List_ptr list, Mapper mapper){
  List_ptr mapped_list = create_list();
  Node_ptr p_walk = list->first;
  for (int index = 0; index < list->length; index++)
  {
    add_to_list(mapped_list, (*mapper)(p_walk->element));
    p_walk = p_walk->next;
  }
  return mapped_list;
};

List_ptr filter(List_ptr list, Predicate predicate){
  List_ptr filtered_list = create_list();
  Node_ptr p_walk = list->first;
  for (int index = 0; index < list->length; index++)
  {
    Status isSuccess =  (*predicate)(p_walk->element);
    if(isSuccess){
      add_to_list(filtered_list, p_walk->element);
    }
    p_walk = p_walk->next;
  }
  return filtered_list;
};

Element reduce(List_ptr list, Element init, Reducer reducer){
  Element element = init;
  Node_ptr p_walk = list->first;
  for (int index = 0; index < list->length; index++)
  {
    element = (*reducer)(element, p_walk->element);
    p_walk = p_walk->next;
  }
  return element;
};

List_ptr reverse(List_ptr list){
  List_ptr reversed_list = create_list();
  Node_ptr p_walk = list->first;
  while(p_walk != NULL){
    add_to_start(reversed_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return reversed_list;
};

void forEach(List_ptr list, ElementProcessor processor){
  Node_ptr p_walk = list->first;
  while(p_walk != NULL){
    (*processor)(p_walk->element);
    p_walk = p_walk->next;
  }
};

void display(List_ptr list, Displayer displayer){
  Node_ptr p_walk = list->first;
  while (p_walk != NULL ) {
    (*displayer)(p_walk->element);
    p_walk = p_walk->next;
  }
}

Status clear_list(List_ptr list) {
  Node_ptr p_walk = list->first;
  Node_ptr node = NULL;

  while(p_walk != NULL) {
    node = p_walk;
    p_walk = node->next;
    free(node);
  }
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return Success;
};

void destroy_list(List_ptr list) {
  Status status = clear_list(list);
  free(list);
  list = NULL;
};