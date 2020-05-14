#include "linkedlist.h"
#include "my_assert.h"

void test_remove_from_start_when_list_has_more_than_one_elements(Element_creator creator)
{
    printf("\n-Testing remove_from_start when list has more than one elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(23));
    add_to_list(list, creator(43));
    Element removed_element = remove_from_start(list);
    assert(list->length, 1, "Length of list should be 1");
    ptr_assert(list->first, list->last, "List's first and last should point to same element");
    not_ptr_assert(list->first, NULL, "List's first should not point to NULL");
    not_ptr_assert(list->last, NULL, "List's last should not point to NULL");
    assert(*(Int_ptr)(list->first->element), 43, "List's first element should be the reaming element in the list");
    assert(*(Int_ptr)(list->last)->element, 43, "List's last element should be the reaming element in the list");
    assert(*(Int_ptr)(removed_element), 23, "Value of remove_element should be 23");
}

void test_remove_from_start_when_list_has_one_elements(Element_creator creator)
{
    printf("\nTesting remove_from_start when list has one element\n");
    List_ptr list = create_list();
    add_to_list(list, creator(23));
    Element removed_element = remove_from_start(list);
    assert(list->length, 0, "Length of list should be 0");
    ptr_assert(list->first, list->last, "List's first and last should point to same element");
    ptr_assert(list->first, NULL, "List's first should not point to NULL");
    ptr_assert(list->last, NULL, "List's last should not point to NULL");
    assert(*(Int_ptr)(removed_element), 23, "Value of remove_element should be 23");
}

void test_remove_from_start_when_list_has_no_elements()
{
    printf("\nTesting remove_from_start when list has no element\n");
    List_ptr list = create_list();
    Element removed_element = remove_from_start(list);
    assert(list->length, 0, "Length of list should be 0");
    ptr_assert(list->first, list->last, "List's first and last should point to same element");
    ptr_assert(list->first, NULL, "List's first should not point to NULL");
    ptr_assert(list->last, NULL, "List's last should not point to NULL");
    ptr_assert(removed_element, NULL, "removed element should point to NULL");
}

void test_remove_from_start(Element_creator creator)
{
    printf("\nTesting remove_from_start\n");
    test_remove_from_start_when_list_has_more_than_one_elements(creator);
    test_remove_from_start_when_list_has_one_elements(creator);
    test_remove_from_start_when_list_has_no_elements();
}