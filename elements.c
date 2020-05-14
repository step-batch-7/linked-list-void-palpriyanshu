#include <stdlib.h>
#include <stdio.h>
#include "elements.h"

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

void display_int(Element element){
  printf("%d ", *(Int_ptr)element);
};

void display_char(Element element){
  printf("%d ", *(Char_ptr)element);
};