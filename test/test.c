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
void test_add_to_list(Element_creator);
void test_add_to_start(Element_creator);
void test_insert_at(Element_creator);
void test_add_unique(Element_creator);
void test_remove_from_start(Element_creator);
void test_remove_at(Element_creator);

int main()
{
    test_create_node(&create_int_element);
    test_create_list();
    test_add_to_list(&create_int_element);
    test_add_to_start(&create_int_element);
    test_insert_at(&create_int_element);
    test_add_unique(&create_int_element);
    test_remove_from_start(&create_int_element);
    test_remove_at(&create_int_element);
}