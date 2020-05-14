#include "linkedlist.h"
#include "my_assert.h"

Element create_int_element(int);
Status int_matcher(Element, Element);

Element create_int_element(int value)
{
    Int_ptr element = malloc(sizeof(int));
    *element = value;
    return (Element)element;
}

Status int_matcher(Element e1, Element e2)
{
    if (*(Int_ptr)(e1) == *(Int_ptr)(e2))
        return Success;
    return Failure;
}

Element int_square_map(Element element)
{
    int value = *(Int_ptr)(element);
    return create_int_element(value * value);
}

Status is_even(Element element)
{
    if (*(Int_ptr)(element) % 2 == 0)
        return Success;
    return Failure;
}

Element int_sum(Element e1, Element e2)
{
    int sum = *(Int_ptr)(e1) + *(Int_ptr)(e2);
    return create_int_element(sum);
}

void add_one(Element element)
{
    *(Int_ptr)(element) += 1;
}

void test_create_node(Element_creator);
void test_create_list(void);
void test_add_to_list(Element_creator);
void test_add_to_start(Element_creator);
void test_insert_at(Element_creator);
void test_add_unique(Element_creator, Element_matcher);
void test_remove_from_start(Element_creator);
void test_remove_at(Element_creator);
void test_remove_from_end(Element_creator);
void test_remove_first_occurrence(Element_creator, Element_matcher);
void test_remove_all_occurrences(Element_creator, Element_matcher);
void test_reverse(Element_creator);
void test_map(Element_creator, Mapper);
void test_filter(Element_creator, Predicate);
void test_reduce(Element_creator, Reducer);
void test_forEach(Element_creator, ElementProcessor);

int main()
{
    test_create_node(&create_int_element);
    test_create_list();
    test_add_to_list(&create_int_element);
    test_add_to_start(&create_int_element);
    test_insert_at(&create_int_element);
    test_add_unique(&create_int_element, &int_matcher);
    test_remove_from_start(&create_int_element);
    test_remove_at(&create_int_element);
    test_remove_from_end(&create_int_element);
    test_remove_first_occurrence(&create_int_element, &int_matcher);
    test_remove_all_occurrences(&create_int_element, &int_matcher);
    test_reverse(&create_int_element);
    test_map(&create_int_element, &int_square_map);
    test_filter(&create_int_element, &is_even);
    test_reduce(&create_int_element, &int_sum);
    test_forEach(&create_int_element, &add_one);
}