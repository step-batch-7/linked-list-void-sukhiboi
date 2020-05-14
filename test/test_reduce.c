#include "linkedlist.h"
#include "my_assert.h"

void test_reduce_with_no_element_in_list(Element_creator creator, Reducer reducer)
{
    printf("\nWith no elements\n");
    List_ptr list = create_list();
    Element context = creator(10);
    Element result = reduce(list, context, reducer);
    assert(*(Int_ptr)(result), 10, "Result should be the same as the context");
}

void test_reduce_with_more_than_one_elements_in_list(Element_creator creator, Reducer reducer)
{
    printf("\nWith more than one elements\n");
    List_ptr list = create_list();
    add_to_list(list, creator(23));
    add_to_list(list, creator(42));
    Element context = creator(10);
    Element result = reduce(list, context, reducer);
    assert(*(Int_ptr)(result), 75, "Result should be the some of all the value sin the list plus the context");
}

void test_reduce(Element_creator creator, Reducer reducer)
{
    printf("\nTesting reduce\n");
    test_reduce_with_no_element_in_list(creator, reducer);
    test_reduce_with_more_than_one_elements_in_list(creator, reducer);
}