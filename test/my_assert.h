#include "linkedlist.h"

typedef Element(*Element_creator)(int);

void assert(int expectation, int actual, char *test_name);
void ptr_assert(Node_ptr expectation, Node_ptr actual, char *test_name);
void not_ptr_assert(Node_ptr expectation, Node_ptr actual, char *test_name);
void print_result(int result, char *test_name);
