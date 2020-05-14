#include "linkedlist.h"
#include "my_assert.h"

void test_filter_with_no_elements_in_list(Predicate predicator)
{
    printf("\n-With one element\n");
    List_ptr list = create_list();
    List_ptr filtered = filter(list, predicator);
    assert(filtered->length, 0, "Length of filtered list should be 0");
    ptr_assert(filtered->first, NULL, "Filtered list's first should point to NULL");
    ptr_assert(filtered->last, NULL, "Filtered list's last should point to NULL");
}

void test_filter_with_more_than_one_element_in_list(Element_creator creator, Predicate predicator)
{
    printf("\n-With more than one element\n");
    List_ptr list = create_list();
    add_to_list(list, creator(3));
    add_to_list(list, creator(4));
    List_ptr filtered = filter(list, predicator);
    assert(filtered->length, 1, "Length of filtered list should be 2");
    not_ptr_assert(filtered->first, NULL, "Filtered list's first should not point to NULL");
    not_ptr_assert(filtered->last, NULL, "Filtered list's last should not point to NULL");
    ptr_assert(filtered->first, filtered->last, "Filtered list's first and last should point to same element");
    assert(*(Int_ptr)(filtered->first->element), 4, "Filtered list should contain the only even number of the actual list i.e. 4");
}

void test_filter(Element_creator creator, Predicate predicator)
{
    printf("\nTesting filter\n");
    test_filter_with_no_elements_in_list(predicator);
    test_filter_with_more_than_one_element_in_list(creator, predicator);
}