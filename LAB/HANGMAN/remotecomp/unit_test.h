#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_shayes_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_shayes_get_size_on_my_string_init_c_string_returns_5(char* buffer, int length);
Status test_shayes_get_capacity_on_my_string_init_c_string_returns_6(char* buffer, int length);
Status test_shayes_my_string_empty_on_init_default_returns_true(char* buffer, int length);
Status test_shayes_my_string_empty_on_init_c_string_returns_false(char* buffer, int length);

#endif
