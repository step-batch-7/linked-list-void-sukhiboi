#include "linkedlist.h"

Node_ptr create_node(Element element)
{
    Node_ptr new_node = malloc(sizeof(Node));
    new_node->element = element;
    new_node->next = NULL;
    return new_node;
}

List_ptr create_list(void)
{
    List_ptr list = malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    list->length = 0;
    return list;
}

Status add_to_list(List_ptr list, Element element)
{
    Node_ptr new_node = create_node(element);
    if (list->first == NULL)
    {
        list->first = new_node;
    }
    else
    {
        list->last->next = new_node;
    }
    list->last = new_node;
    list->length++;
    return Success;
}