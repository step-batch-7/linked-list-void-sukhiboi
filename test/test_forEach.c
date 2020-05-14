#include "linkedlist.h"
#include "my_assert.h"

void test_forEach_with_no_elements_in_list(ElementProcessor processor)
{
    printf("\nWith no elements in list\n");
    List_ptr list = create_list();
    forEach(list, processor);
    assert(list->length, 0, "Length of list list should be 0");
    ptr_assert(list->first, NULL, "List's first should point to NULL");
    ptr_assert(list->last, NULL, "List's last should point to NULL");
}

void test_forEach_with_more_than_one_elements_in_list(Element_creator creator, ElementProcessor processor)
{
    printf("\nWith more than one elements in list\n");
    List_ptr list = create_list();
    add_to_list(list, creator(12));
    add_to_list(list, creator(34));
    forEach(list, processor);
    assert(list->length, 2, "Length of list list should be 2");
    not_ptr_assert(list->first, NULL, "List's first should not point to NULL");
    not_ptr_assert(list->last, NULL, "List's last should not point to NULL");
    assert(*(Int_ptr)(list->first->element), 13, "List's first element should be previous value plus 1");
    assert(*(Int_ptr)(list->last->element), 35, "List's last element should be previous value plus 1");
}

void test_forEach(Element_creator creator, ElementProcessor processor)
{
    printf("\nTesting forEach\n");
    test_forEach_with_no_elements_in_list(processor);
    test_forEach_with_more_than_one_elements_in_list(creator, processor);
}