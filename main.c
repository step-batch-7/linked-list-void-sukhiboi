#include "linkedlist.h"

Element create_int_element(int value);

Element create_int_element(int value)
{
  Int_ptr element = malloc(sizeof(int));
  *element = value;
  return (Element)element;
}

Element create_char_element(char ch)
{
  Int_ptr element = malloc(sizeof(char));
  *element = ch;
  return (Element)element;
}

void display_List(List_ptr list)
{
  Node_ptr p_walker = list->first;
  while (p_walker != NULL)
  {
    printf("%c ", *(char *)(p_walker->element));
    p_walker = p_walker->next;
  }
}

Status int_comparer(Element e1, Element e2)
{
  if (*(Int_ptr)(e1) < *(Int_ptr)(e2))
    return Success;
  return Failure;
}

int main()
{
  List_ptr list = create_list();
  add_to_list(list, create_char_element('s'));
  add_to_list(list, create_char_element('u'));
  add_to_list(list, create_char_element('k'));
  add_to_list(list, create_char_element('h'));
  add_to_list(list, create_char_element('d'));
  add_to_list(list, create_char_element('e'));
  add_to_list(list, create_char_element('v'));
  sort(list, int_comparer);
  display_List(list);
  return 0;
}
