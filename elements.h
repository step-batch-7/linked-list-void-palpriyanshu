#ifndef __ELEMENTS_H_
#define __ELEMENTS_H_

#include <stdio.h>
#include <stdlib.h>

typedef int *Int_ptr;
typedef char *Char_ptr;
typedef void* Element;

Int_ptr create_int_element(int value);
Char_ptr create_char_element(char value);

void display_int(Element element);
void display_char(Element element);

#endif