#include "linkedlist.h"
#include "my_assert.h"

void test_clear_list_with_no_elements_in_list()
{
    printf("\nWith no elements\n");
    List_ptr list = create_list();
    Status result = clear_list(list);
    assert(result, 1, "Operation should be successfull");
    assert(list->length, 0, "Length of the list should be 0");
    ptr_assert(list->first, NULL, "List's first should point to NULL");
    ptr_assert(list->last, NULL, "List's last should point to NULL");
}

void test_clear_list_with_more_than_one_elements_in_list(Element_creator creator)
{
    printf("\nWith more than one elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(10));
    add_to_list(list, creator(20));
    Status result = clear_list(list);
    assert(result, 1, "Operation should be successfull");
    assert(list->length, 0, "Length of the list should be 0");
    ptr_assert(list->first, NULL, "List's first should point to NULL");
    ptr_assert(list->last, NULL, "List's last should point to NULL");
}

void test_clear_list(Element_creator creator)
{
    printf("\nTesting clear_list\n");
    test_clear_list_with_no_elements_in_list();
    test_clear_list_with_more_than_one_elements_in_list(creator);
}