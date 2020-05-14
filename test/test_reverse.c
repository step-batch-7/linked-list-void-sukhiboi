#include "linkedlist.h"
#include "my_assert.h"

void test_reverse_when_list_has_no_elements()
{
    printf("\nReverse list with no elements\n");
    List_ptr list = create_list();
    List_ptr reversed_list = reverse(list);
    assert(reversed_list->length, 0, "Length of the reversed list should be 0");
    ptr_assert(list->first, NULL, "List's first should point to NULL");
    ptr_assert(list->last, NULL, "List's last should point to NULL");
}

void test_reverse_when_list_has_one_elements(Element_creator creator)
{
    printf("\nReverse list with one element elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(78));
    List_ptr reversed_list = reverse(list);
    assert(reversed_list->length, 1, "Length of the reversed list should be 1");
    not_ptr_assert(reversed_list->first, NULL, "Reversed List's first should not point to NULL");
    not_ptr_assert(reversed_list->last, NULL, "Reversed List's last should not point to NULL");
    ptr_assert(reversed_list->first, reversed_list->last, "Reversed List's first and end should point to the same element");
    assert(*(Int_ptr)(reversed_list->first->element), 78, "Value of the fist element of reversed list should be the same as of actual list");
}

void test_reverse_when_list_has_more_than_one_elements(Element_creator creator)
{
    printf("\nReverse list with more than one element elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(78));
    add_to_list(list, creator(23));
    List_ptr reversed_list = reverse(list);
    assert(reversed_list->length, 2, "Length of the reversed list should be 2");
    not_ptr_assert(reversed_list->first, NULL, "Reversed List's first should not point to NULL");
    not_ptr_assert(reversed_list->last, NULL, "Reversed List's last should not point to NULL");
    not_ptr_assert(reversed_list->first, reversed_list->last, "Reversed List's first and end should not point to the same element");
    assert(*(Int_ptr)(reversed_list->first->element), 23, "Value of the fist element of reversed list should be the same as last value of actual list");
    assert(*(Int_ptr)(reversed_list->last->element), 78, "Value of the last element of reversed list should be the same as first value of actual list");
}

void test_reverse(Element_creator creator)
{
    printf("\nTesting reverse\n");
    test_reverse_when_list_has_no_elements();
    test_reverse_when_list_has_one_elements(creator);
    test_reverse_when_list_has_more_than_one_elements(creator);
}