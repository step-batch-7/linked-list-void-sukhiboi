#include "linkedlist.h"
#include "my_assert.h"

void test_remove_at_when_removing_from_first_position_while_list_is_empty(Element_creator creator)
{
    printf("\n-After removeing at 0th position when list is empty\n");
    List_ptr list = create_list();
    Element removed_element = remove_at(list, 0);
    assert(list->length, 0, "Length of list should be 0");
    ptr_assert(list->first, NULL, "List's first should be NULL");
    ptr_assert(list->last, NULL, "List's last should be NULL");
    ptr_assert(removed_element, NULL, "removed element should point to NULL");
}

void test_remove_at_when_removing_from_first_position_while_list_has_one_element(Element_creator creator)
{
    printf("\n-After removeing at 0th position when list has 1 element\n");
    List_ptr list = create_list();
    add_to_list(list, creator(34));
    Element removed_element = remove_at(list, 0);
    assert(list->length, 0, "Length of list should be 0");
    ptr_assert(list->first, NULL, "List's first should be NULL");
    ptr_assert(list->last, NULL, "List's last should be NULL");
    assert(*(Int_ptr)(removed_element), 34, "Value of removed element should be 34");
}

void test_remove_at_when_removing_from_first_position_while_list_has_more_than_one_element(Element_creator creator)
{
    printf("\n-After removeing at first position when list has more than 1 elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(34));
    add_to_list(list, creator(78));
    Element removed_element = remove_at(list, 0);
    assert(list->length, 1, "Length of list should be 1");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    ptr_assert(list->first, list->last, "List's first and last should point to same node");
    assert(*(Int_ptr)(list->first->element), 78, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 78, "Value of last element should be same as passed");
    assert(*(Int_ptr)(removed_element), 34, "Value of removed element should be 34");
}

void test_remove_at_when_removing_from_any_position_except_first_and_last(Element_creator creator)
{
    printf("\n-After removeing for any position except first and last\n");
    List_ptr list = create_list();
    add_to_list(list, creator(34));
    add_to_list(list, creator(78));
    add_to_list(list, creator(88));
    Element removed_element = remove_at(list, 1);
    assert(list->length, 2, "Length of list should be 2");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    not_ptr_assert(list->first, list->last, "List's first and last should not point to same node");
    assert(*(Int_ptr)(list->first->element), 34, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 88, "Value of last element should be same as passed to remove_at");
    assert(*(Int_ptr)(removed_element), 78, "Value of removed element should be 78");
}

void test_remove_at_when_removing_from_last_position(Element_creator creator)
{
    printf("\n-After removeing for last position\n");
    List_ptr list = create_list();
    add_to_list(list, creator(34));
    add_to_list(list, creator(78));
    Element removed_element = remove_at(list, 1);
    assert(list->length, 1, "Length of list should be 1");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    ptr_assert(list->first, list->last, "List's first and last should point to same node");
    assert(*(Int_ptr)(list->first->element), 34, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 34, "Value of last element should be same as passed to remove_at");
    assert(*(Int_ptr)(removed_element), 78, "Value of removed element should be 78");
}

void test_remove_at_when_removing_from_invalid_position(Element_creator creator)
{
    printf("\n-After removeing for last position\n");
    List_ptr list = create_list();
    add_to_list(list, creator(34));
    Element removed_element = remove_at(list, 1);
    assert(list->length, 1, "Length of list should be 1");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    ptr_assert(list->first, list->last, "List's first and last should point to same node");
    assert(*(Int_ptr)(list->first->element), 34, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 34, "Value of last element should be same as passed to remove_at");
    ptr_assert(removed_element, NULL, "removed element should point to NULL");
}

void test_remove_at(Element_creator creator)
{
    printf("\nTesting remove_at\n");
    test_remove_at_when_removing_from_first_position_while_list_is_empty(creator);
    test_remove_at_when_removing_from_first_position_while_list_has_one_element(creator);
    test_remove_at_when_removing_from_first_position_while_list_has_more_than_one_element(creator);
    test_remove_at_when_removing_from_any_position_except_first_and_last(creator);
    test_remove_at_when_removing_from_last_position(creator);
    test_remove_at_when_removing_from_invalid_position(creator);
}