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
Status test_shayes_add_null_byte_with_my_string_c_str(char* buffer, int length);
Status test_shayes_my_string_compare_returns_left_string_greater_than_right(char* buffer, int length);
Status test_shayes_my_string_compare_returns_left_string_less_than_right(char* buffer, int length);
Status test_shayes_my_string_compare_returns_left_string_equal_to_than_right(char* buffer, int length);
Status test_shayes_my_string_push_back_successfully_pushes_character(char* buffer, int length);
Status test_shayes_my_string_pop_back_successfully_removes_character(char* buffer, int length);
Status test_shayes_my_string_pop_back_returns_FAILURE_on_empty_string_object(char* buffer, int length);
Status test_shayes_my_string_concat_successfully_appends_two_string_objects(char* buffer, int length);
Status test_shayes_fully_pop_back_concatenated_string_objects(char* buffer, int length);
Status test_shayes_my_string_extraction_returns_success(char* buffer, int length);
Status test_shayes_my_string_insertion_only_insert_words_29_characters_long(char* buffer, int length);
Status test_shayes_my_string_push_back_pushes_until_resize(char* buffer, int length);
Status test_shayes_my_string_at_returns_NULL_on_out_of_bounds(char* buffer, int length);
Status test_shayes_destroy_string_object_after_init_default(char* buffer, int length);
Status test_shayes_my_string_extraction_returns_FAILURE_on_uninitialized_string_object(char* buffer, int length);
Status test_shayes_my_string_insertion_returns_FAILURE_on_uninitialized_string_object(char* buffer, int length);
Status test_shayes_my_string_get_size_returns_obscure_int_on_uninitialized_string_object(char* buffer, int length);
Status test_shayes_my_string_get_capacity_returns_obscure_int_on_uninitialized_string_object(char* buffer, int length);

#endif
