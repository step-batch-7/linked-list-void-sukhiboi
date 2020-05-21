#include "linkedlist.h"
#include "my_assert.h"

void test_sort_with_no_element_in_list(Comparer compare)
{
    printf("\nTesting sort with no elements\n");
    List_ptr list = create_list();
    sort(list, compare);
    assert(list->length, 0, "Length of list list should be 0");
    ptr_assert(list->first, NULL, "List's first should point to NULL");
    ptr_assert(list->last, NULL, "List's last should point to NULL");
}

void test_sort_with_one_element_in_list(Element_creator creator, Comparer compare)
{
    printf("\nTesting sort with one elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(23));
    assert(list->length, 1, "Length of list list should be 1");
    not_ptr_assert(list->first, NULL, "List's first should not point to NULL");
    not_ptr_assert(list->last, NULL, "List's last should not point to NULL");
    assert(*(Int_ptr)(list->first->element), 23, "List's first elements should be same as passed value before sorting");
    assert(*(Int_ptr)(list->last->element), 23, "List's last elements should be same as passed value before sorting");
    sort(list, compare);
    assert(*(Int_ptr)(list->first->element), 23, "List's first elements should be same as passed value after sorting");
    assert(*(Int_ptr)(list->last->element), 23, "List's last elements should be same as passed value after sorting");
}

void test_sort_with_more_than_one_element_in_list(Element_creator creator, Comparer compare)
{
    printf("\nTesting sort with more than one elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(23));
    add_to_list(list, creator(7));
    assert(list->length, 2, "Length of list list should be 2");
    not_ptr_assert(list->first, NULL, "List's first should not point to NULL");
    not_ptr_assert(list->last, NULL, "List's last should not point to NULL");
    assert(*(Int_ptr)(list->first->element), 23, "List's first elements should be same as first passed value before sorting");
    assert(*(Int_ptr)(list->last->element), 7, "List's last elements should be same as last passed value before sorting");
    sort(list, compare);
    assert(*(Int_ptr)(list->first->element), 7, "List's first elements should be same as last passed value after sorting");
    assert(*(Int_ptr)(list->last->element), 23, "List's last elements should be same as first passed value after sorting");
}

void test_sort(Element_creator creator, Comparer compare)
{
    printf("\nTesting sort\n");
    test_sort_with_no_element_in_list(compare);
    test_sort_with_one_element_in_list(creator, compare);
    test_sort_with_more_than_one_element_in_list(creator, compare);
}