#include "linkedlist.h"
#include "my_assert.h"

void test_create_list(void)
{
    printf("\nTesting create_list\n");
    List_ptr list = create_list();
    ptr_assert(list->first, NULL, "First element should be NULL");
    ptr_assert(list->last, NULL, "Last element should be NULL");
    assert(list->length, 0, "Length of list should be 0");
}