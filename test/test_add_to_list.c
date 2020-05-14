#include "linkedlist.h"
#include "my_assert.h"

void test_when_list_is_empty(Element_creator creator)
{
    printf("\n-After adding one element\n");
    List_ptr list = create_list();
    add_to_list(list, creator(20));
    assert(list->length, 1, "Length should be 1");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    ptr_assert(list->first, list->last, "List's first and last should point to same node");
    assert(*(Int_ptr)(list->first->element), 20, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 20, "Value of last element should be same as passed");
}

void test_when_list_is_has_one_element(Element_creator creator)
{
    printf("\n-After adding two elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(20));
    add_to_list(list, creator(21));
    assert(list->length, 2, "Length should be 2");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    not_ptr_assert(list->first, list->last, "List's first and last should not point to same node");
    assert(*(Int_ptr)(list->first->element), 20, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 21, "Value of last element should be same as passed");
}

void test_when_list_is_has_more_than_one_element(Element_creator creator)
{
    printf("\n-After adding three elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(20));
    add_to_list(list, creator(21));
    add_to_list(list, creator(22));
    assert(list->length, 3, "Length should be 3");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    not_ptr_assert(list->first, list->last, "List's first and last should not point to same node");
    not_ptr_assert(list->last, list->first->next, "List's last should not point to second node");
    assert(*(Int_ptr)(list->first->element), 20, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->first->next->element), 21, "Value of second element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 22, "Value of last element should be same as passed");
}

void test_add_to_list(Element_creator creator)
{
    printf("\nTesting add_to_list\n");
    test_when_list_is_empty(creator);
    test_when_list_is_has_one_element(creator);
    test_when_list_is_has_more_than_one_element(creator);
}