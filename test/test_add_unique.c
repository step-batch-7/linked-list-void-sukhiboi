#include "linkedlist.h"
#include "my_assert.h"

Status int_matcher(Element e1, Element e2)
{
    if (*(Int_ptr)(e1) == *(Int_ptr)(e2))
        return Success;
    return Failure;
}

void test_add_unique_when_element_passed_is_not_present_in_the_list(Element_creator creator)
{
    printf("\n-Testing when element passed is not present in list\n");
    List_ptr list = create_list();
    add_to_list(list, creator(10));
    add_unique(list, creator(20), &int_matcher);
    assert(list->length, 2, "Length of list should be 2");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    not_ptr_assert(list->first, list->last, "List's first and last should not point to same node");
    assert(*(Int_ptr)(list->first->element), 10, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 20, "Value of last element should be same as passed");
}

void test_add_unique_when_element_passed_is_present_in_the_list_one_time(Element_creator creator)
{
    printf("\n-Testing when element passed is present in list\n");
    List_ptr list = create_list();
    add_to_list(list, creator(20));
    add_unique(list, creator(20), &int_matcher);
    assert(list->length, 1, "Length of list should be 1");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    ptr_assert(list->first, list->last, "List's first and last should point to same node");
    assert(*(Int_ptr)(list->first->element), 20, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 20, "Value of last element should be same as passed");
}

void test_add_unique(Element_creator creator)
{
    printf("\nTesting add_unique\n");
    test_add_unique_when_element_passed_is_not_present_in_the_list(creator);
    test_add_unique_when_element_passed_is_present_in_the_list_one_time(creator);
}