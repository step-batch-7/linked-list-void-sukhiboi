#include "linkedlist.h"
#include "my_assert.h"

void test_map_with_no_elements_in_list(Mapper mapper)
{
    printf("\n-With no elements in list\n");
    List_ptr list = create_list();
    List_ptr mapped = map(list, mapper);
    assert(mapped->length, 0, "Length of mapped list should be 0");
    ptr_assert(mapped->first, NULL, "Mapped list's first should point to NULL");
    ptr_assert(mapped->last, NULL, "Mapped list's last should point to NULL");
}

void test_map_with_more_than_one_elements_in_list(Element_creator creator, Mapper mapper)
{
    printf("\n-With more than one elements in list\n");
    List_ptr list = create_list();
    add_to_list(list, creator(9));
    add_to_list(list, creator(3));
    List_ptr mapped = map(list, mapper);
    assert(mapped->length, 2, "Length of mapped list should be 2");
    not_ptr_assert(mapped->first, NULL, "Mapped list's first should not point to NULL");
    not_ptr_assert(mapped->last, NULL, "Mapped list's last should not point to NULL");
    not_ptr_assert(mapped->first, mapped->last, "Mapped list's first and last should not be same");
    assert(*(Int_ptr)(mapped->first->element), 81, "Value of first element of mapped list should be square of 9");
    assert(*(Int_ptr)(mapped->last->element), 9, "Value of first element of mapped list should be square of 3");
}

void test_map(Element_creator creator, Mapper mapper)
{
    printf("\nTesting map\n");
    test_map_with_no_elements_in_list(mapper);
    test_map_with_more_than_one_elements_in_list(creator, mapper);
}