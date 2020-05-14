#include "linkedlist.h"
#include "my_assert.h"

Element create_int_element(int value);

Element create_int_element(int value)
{
    Int_ptr element = malloc(sizeof(int));
    *element = value;
    return (Element)element;
}

void test_create_node(Element_creator);
void test_create_list(void);

int main()
{
    test_create_node(&create_int_element);
    test_create_list();
}