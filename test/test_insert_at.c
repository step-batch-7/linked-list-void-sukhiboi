#include "linkedlist.h"
#include "my_assert.h"

void test_insert_at_when_addding_to_first_position_while_list_is_empty(Element_creator creator)
{
    printf("\n-After inserting at 0th position when list is empty\n");
    List_ptr list = create_list();
    insert_at(list, creator(20), 0);
    assert(list->length, 1, "Length of list should be 1");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    ptr_assert(list->first, list->last, "List's first and last should point to same node");
    assert(*(Int_ptr)(list->first->element), 20, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 20, "Value of last element should be same as passed");
}

void test_insert_at_when_addding_to_first_position_while_list_is_not_empty(Element_creator creator)
{
    printf("\n-After inserting at 0th position when list is not empty\n");
    List_ptr list = create_list();
    add_to_list(list, creator(34));
    insert_at(list, creator(20), 0);
    assert(list->length, 2, "Length of list should be 2");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    not_ptr_assert(list->first, list->last, "List's first and last should not point to same node");
    assert(*(Int_ptr)(list->first->element), 20, "Value of first element should be same as passed to insert_at");
    assert(*(Int_ptr)(list->last->element), 34, "Value of last element should be same as passed");
}

void test_insert_at_when_addding_to_last_position_while_list_is_not_empty(Element_creator creator)
{
    printf("\n-After inserting at last position when list is not empty\n");
    List_ptr list = create_list();
    add_to_list(list, creator(34));
    add_to_list(list, creator(78));
    insert_at(list, creator(20), 1);
    assert(list->length, 3, "Length of list should be 3");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    not_ptr_assert(list->first, list->last, "List's first and last should not point to same node");
    assert(*(Int_ptr)(list->first->element), 34, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->first->next->element), 20, "Value of second element should be same as passed to insert_at");
    assert(*(Int_ptr)(list->last->element), 78, "Value of last element should be same as passed");
}

void test_insert_at_when_addding_to_next_to_last_position_while_list_is_not_empty(Element_creator creator)
{
    printf("\n-After inserting at next to last position when list is not empty\n");
    List_ptr list = create_list();
    add_to_list(list, creator(34));
    add_to_list(list, creator(78));
    insert_at(list, creator(20), 2);
    assert(list->length, 3, "Length of list should be 3");
    not_ptr_assert(list->first, NULL, "List's first should not be NULL");
    not_ptr_assert(list->last, NULL, "List's last should not be NULL");
    not_ptr_assert(list->first, list->last, "List's first and last should not point to same node");
    assert(*(Int_ptr)(list->first->element), 34, "Value of first element should be same as passed");
    assert(*(Int_ptr)(list->first->next->element), 78, "Value of second element should be same as passed");
    assert(*(Int_ptr)(list->last->element), 20, "Value of last element should be same as passed to insert_at");
}

void test_insert_at(Element_creator creator)
{
    printf("\nTesting insert_at\n");
    test_insert_at_when_addding_to_first_position_while_list_is_empty(creator);
    test_insert_at_when_addding_to_first_position_while_list_is_not_empty(creator);
    test_insert_at_when_addding_to_last_position_while_list_is_not_empty(creator);
    test_insert_at_when_addding_to_next_to_last_position_while_list_is_not_empty(creator);
}