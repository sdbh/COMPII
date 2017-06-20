#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
  Status (*tests[])(char*, int) =
    {
      test_init_default_returns_nonNULL,
      test_get_size_on_init_default_returns_0,
      test_shayes_get_capacity_on_init_default_returns_7,
      test_shayes_get_size_on_my_string_init_c_string_returns_5,
      test_shayes_get_capacity_on_my_string_init_c_string_returns_6,
      test_shayes_my_string_empty_on_init_default_returns_true,
      test_shayes_my_string_empty_on_init_c_string_returns_false,
      test_shayes_add_null_byte_with_my_string_c_str,
      test_shayes_my_string_compare_returns_left_string_greater_than_right,
      test_shayes_my_string_compare_returns_left_string_less_than_right,
      test_shayes_my_string_compare_returns_left_string_equal_to_than_right,
      test_shayes_my_string_push_back_successfully_pushes_character,
      test_shayes_my_string_pop_back_successfully_removes_character,
      test_shayes_my_string_pop_back_returns_FAILURE_on_empty_string_object,
      test_shayes_my_string_concat_successfully_appends_two_string_objects,
      test_shayes_fully_pop_back_concatenated_string_objects,
      test_shayes_my_string_extraction_returns_success,
      test_shayes_my_string_insertion_only_insert_words_29_characters_long,
      test_shayes_my_string_push_back_pushes_until_resize,
      test_shayes_my_string_at_returns_NULL_on_out_of_bounds,
      test_shayes_destroy_string_object_after_init_default,
      test_shayes_my_string_extraction_returns_FAILURE_on_uninitialized_string_object,
      test_shayes_my_string_insertion_returns_FAILURE_on_uninitialized_string_object,
      test_shayes_my_string_get_size_returns_obscure_int_on_uninitialized_string_object,
      test_shayes_my_string_get_capacity_returns_obscure_int_on_uninitialized_string_object
    };
  int number_of_functions = sizeof(tests) / sizeof(tests[0]);
  int i;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;

  for(i = 0; i < number_of_functions; i++)
    {
      if(tests[i](buffer,500) == FAILURE)
	{
	  printf("FAILED: Test %d failed\n", i);
	  printf("\t%s\n", buffer);
	  failure_count++;
	}
      else
	{
	  printf("SUCCESS: Test %d succeeded\n", i);
	  printf("\t%s\n", buffer);
	  success_count++;
	}
    }
  return 0;
}
