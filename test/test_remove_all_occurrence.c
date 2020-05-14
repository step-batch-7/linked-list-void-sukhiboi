#include "linkedlist.h"
#include "my_assert.h"

void test_remove_all_occurrences_with_empty_list(Element_creator creator, Element_matcher matcher)
{
    printf("\n-With empty list\n");
    List_ptr list = create_list();
    List_ptr removed_element_list = remove_all_occurrences(list, creator(56), matcher);
    assert(removed_element_list->length, 0, "Length of the list should be 0");
    ptr_assert(removed_element_list->first, NULL, "List's first should point to NULL");
    ptr_assert(removed_element_list->last, NULL, "List's last should point to NULL");
}

void test_remove_all_occurrences_when_the_passed_element_is_not_in_list(Element_creator creator, Element_matcher matcher)
{
    printf("\n-When passed element is not in list\n");
    List_ptr list = create_list();
    add_to_list(list, creator(23));
    add_to_list(list, creator(90));
    List_ptr removed_element_list = remove_all_occurrences(list, creator(56), matcher);
    assert(removed_element_list->length, 0, "Length of the list should be 0");
    ptr_assert(removed_element_list->first, NULL, "List's first should point to NULL");
    ptr_assert(removed_element_list->last, NULL, "List's last should point to NULL");
}

void test_remove_all_occurrences_when_then_passed_element_is_in_the_list(Element_creator creator, Element_matcher matcher)
{
    printf("\n-When passed element is in list\n");
    List_ptr list = create_list();
    add_to_list(list, creator(23));
    add_to_list(list, creator(90));
    List_ptr removed_element_list = remove_all_occurrences(list, creator(90), matcher);
    assert(list->length, 1, "Length of the list should be 1");
    ptr_assert(list->first, list->last, "List's first and last should point to same element");
    not_ptr_assert(list->first, NULL, "List's first should not point to NULL");
    not_ptr_assert(list->last, NULL, "List's last should not point to NULL");
    assert(removed_element_list->length, 1, "Length of removed element list should be 1");
    ptr_assert(removed_element_list->first, removed_element_list->last, "Removed element list's first and last should point to same element");
    not_ptr_assert(removed_element_list->first, NULL, "Removed element list's first should not point to NULL");
    not_ptr_assert(removed_element_list->last, NULL, "Removed element list's last should not point to NULL");
    assert(*(Int_ptr)(removed_element_list->first->element), 90, "Value of the only removed element should be 90");
}

void test_remove_all_occurrences_when_the_passed_element_ouccur_twice(Element_creator creator, Element_matcher matcher)
{
    printf("\n-When passed element is in list and occur twice\n");
    List_ptr list = create_list();
    add_to_list(list, creator(23));
    add_to_list(list, creator(90));
    add_to_list(list, creator(90));
    List_ptr removed_element_list = remove_all_occurrences(list, creator(90), matcher);
    assert(list->length, 1, "Length of the list should be 1");
    ptr_assert(list->first, list->last, "List's first and last should point to same element");
    not_ptr_assert(list->first, NULL, "List's first should not point to NULL");
    not_ptr_assert(list->last, NULL, "List's last should not point to NULL");
    assert(removed_element_list->length, 2, "Length of removed element list should be 2");
    not_ptr_assert(removed_element_list->first, removed_element_list->last, "Removed element list's first and last should not point to same element");
    not_ptr_assert(removed_element_list->first, NULL, "Removed element list's first should not point to NULL");
    not_ptr_assert(removed_element_list->last, NULL, "Removed element list's last should not point to NULL");
    assert(*(Int_ptr)(removed_element_list->first->element), 90, "Value of the first removed element should be 90");
    assert(*(Int_ptr)(removed_element_list->last->element), 90, "Value of the second removed element should be 90");
}

void test_remove_all_occurrences(Element_creator creator, Element_matcher matcher)
{
    printf("\nTesting remove_all_occurrences\n");
    test_remove_all_occurrences_with_empty_list(creator, matcher);
    test_remove_all_occurrences_when_the_passed_element_is_not_in_list(creator, matcher);
    test_remove_all_occurrences_when_then_passed_element_is_in_the_list(creator, matcher);
    test_remove_all_occurrences_when_the_passed_element_ouccur_twice(creator, matcher);
}