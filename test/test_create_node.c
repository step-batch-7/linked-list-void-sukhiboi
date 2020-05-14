#include "linkedlist.h"
#include "my_assert.h"

void test_create_node(Element_creator creator)
{
    printf("\nTesting create_node\n");
    Element element = creator(10);
    Node_ptr node = create_node(element);
    assert(*(Int_ptr)(node->element), 10, "Value should be same as element passed");
    ptr_assert(node->next, NULL, "Next should be null");
}