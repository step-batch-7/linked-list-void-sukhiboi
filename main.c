#include "linkedlist.h"

Element create_int_element(int value);

Element create_int_element(int value)
{
  Int_ptr element = malloc(sizeof(int));
  *element = value;
  return (Element)element;
}

int main()
{
  Node_ptr node = create_node(create_int_element(10));
  return 0;
}
