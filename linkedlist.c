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

Status add_to_start(List_ptr list, Element element)
{
    if (list->first == NULL)
    {
        return add_to_list(list, element);
    }
    Node_ptr new_node = create_node(element);
    new_node->next = list->first;
    list->first = new_node;
    list->length++;
    return Success;
}

Node_ptr get_node(List_ptr list, int position)
{
    Node_ptr p_walker = list->first;
    for (int i = 0; i < list->length; i++)
    {
        if (i == position)
        {
            return p_walker;
        }
        p_walker = p_walker->next;
    }
    return NULL;
}

Status insert_at(List_ptr list, Element element, int position)
{
    if (position == list->length)
    {
        return add_to_list(list, element);
    }
    Node_ptr node = get_node(list, position);
    if (node == NULL)
    {
        return Failure;
    }
    if (position == 0)
    {
        return add_to_start(list, element);
    }
    Node_ptr previous_node = get_node(list, position - 1);
    Node_ptr new_node = create_node(element);
    new_node->next = previous_node->next;
    previous_node->next = new_node;
    list->length++;
    return Success;
}

Status is_element_available(List_ptr list, Element element, Matcher matcher)
{
    Node_ptr p_walker = list->first;
    for (int i = 0; i < list->length; i++)
    {
        if (matcher(p_walker->element, element))
        {
            return Success;
        }
        p_walker = p_walker->next;
    }
    return Failure;
}

Status add_unique(List_ptr list, Element element, Matcher matcher)
{
    if (is_element_available(list, element, matcher))
        return Failure;
    return add_to_list(list, element);
}

Element remove_from_start(List_ptr list)
{
    if (list->first == NULL)
    {
        return NULL;
    }
    Node_ptr to_be_removed = list->first;
    list->first = list->first->next;
    if (list->first == NULL)
    {
        list->last = NULL;
    }
    list->length--;
    Element removed_element = to_be_removed->element;
    free(to_be_removed);
    return removed_element;
}

Element remove_at(List_ptr list, int position)
{
    Node_ptr to_be_removed = get_node(list, position);
    if (to_be_removed == NULL)
    {
        return NULL;
    }
    if (position == 0)
    {
        return remove_from_start(list);
    }
    Node_ptr previous_node = get_node(list, position - 1);
    previous_node->next = previous_node->next->next;
    if (previous_node->next == NULL)
    {
        list->last = previous_node;
    }
    list->length--;
    Element removed_element = to_be_removed->element;
    free(to_be_removed);
    return removed_element;
}

Element remove_from_end(List_ptr list)
{
    return remove_at(list, list->length - 1);
}