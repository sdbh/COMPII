#include <stdio.h>
#include <string.h>
#include "status.h"
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  if(hString == NULL)
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_init_default_returns_nonNULL\n"
	      "my_string_init_default returns NULL", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy(&hString);
      strncpy(buffer, "test_init_default_returns_nonNULL\n", length);
      return SUCCESS;
    }
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  if(my_string_get_size(hString) != 0)
    {
      status = FAILURE;
      printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
	      "Did not receive 0 from get_size after init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_get_size_on_init_default_returns_0\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  if(my_string_get_capacity(hString) != 7)
    {
      status = FAILURE;
      printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
      strncpy(buffer, "test_shayes_get_capacity_on_init_default_returns_7\n"
	      "Did not receive 7 from get_capacity after init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_get_capacity_on_init_default_returns_7\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_get_size_on_my_string_init_c_string_returns_5(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  char c_str[] = "Hello";

  hString = my_string_init_c_string(c_str);
  if(my_string_get_size(hString) != 5)
    {
      status = FAILURE;
      printf("Expected a size of 5 but got %d\n", my_string_get_size(hString));
      strncpy(buffer, "test_shayes_get_size_on_my_string_init_c_string_returns_5\n"
	      "Did not receive 5 from get_size after my_string_init_c_string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_get_size_on_my_string_init_c_string_returns_5\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_get_capacity_on_my_string_init_c_string_returns_6(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  char c_str[] = "Hello";

  hString = my_string_init_c_string(c_str);
  if(my_string_get_capacity(hString) != 6)
    {
      status = FAILURE;
      printf("Expected a capacity of 6 but got %d\n", my_string_get_capacity(hString));
      strncpy(buffer, "test_shayes_get_capacity_on_my_string_init_c_string_returns_6\n"
	      "Did not receive 6 from get_capacity after my_string_init_c_string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_get_capacity_on_my_string_init_c_string_returns_6\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_empty_on_init_default_returns_true(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  if(my_string_empty(hString) != TRUE)
    {
      status = FAILURE;
      printf("Expected an empty string got %d\n", (int) my_string_empty(hString));
      strncpy(buffer, "test_shayes_my_string_empty_on_init_default_returns_true\n"
	      "String object was not empty after my_string_init_default\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_my_string_empty_on_init_default_returns_true\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_empty_on_init_c_string_returns_false(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  char c_str[] = "Hello";

  hString = my_string_init_c_string(c_str);
  if(my_string_empty(hString) != FALSE)
    {
      status = FAILURE;
      printf("Expected an non empty string got %d\n", (int) my_string_empty(hString));
      strncpy(buffer, "test_shayes_my_string_empty_on_init_c_string_returns_false\n"
	      "String object was not empty after my_string_init_c_string\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_my_string_empty_on_init_c_string_returns_false\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_add_null_byte_with_my_string_c_str(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  char c_str[] = "Hello";

  hString = my_string_init_c_string(c_str);
  my_string_c_str(hString);
  if(*(my_string_at(hString, my_string_get_size(hString))) != '\0')
    {
      status = FAILURE;
      printf("Expected an null byte at hString->size but got %c\n", *(my_string_at(hString, my_string_get_size(hString))));
      strncpy(buffer, "test_shayes_add_null_byte_with_my_string_c_str\n"
	      "String object did not contain null byte at end of string after my_string_c_str\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_add_null_byte_with_my_string_c_str added null byte to end of string\n", length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_compare_returns_left_string_greater_than_right(char* buffer, int length)
{
  MY_STRING hLeft_string = NULL;
  MY_STRING hRight_string = NULL;
  char r_str[] = "Hel";
  char l_str[] = "Hello";

  hLeft_string = my_string_init_c_string(l_str);
  hRight_string = my_string_init_c_string(r_str);
 
  if(my_string_compare(hLeft_string, hRight_string) != 1)
    {
      strncpy(buffer, "test_shayes_my_string_compare_returns_left_string_greater_than_right\n"
	      "test_shayes_my_string_compare_returns_left_string_greater_than_right doesn't return 1\n", length);
      my_string_destroy(&hLeft_string);
      my_string_destroy(&hRight_string);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_shayes_my_string_compare_returns_left_string_greater_than_right returns 1\n", length);
      my_string_destroy(&hLeft_string);
      my_string_destroy(&hRight_string);
      return SUCCESS;
    }
}

Status test_shayes_my_string_compare_returns_left_string_less_than_right(char* buffer, int length)
{
  MY_STRING hLeft_string = NULL;
  MY_STRING hRight_string = NULL;
  char r_str[] = "Hello";
  char l_str[] = "Hel";

  hLeft_string = my_string_init_c_string(l_str);
  hRight_string = my_string_init_c_string(r_str);
 
  if((my_string_compare(hLeft_string, hRight_string) != -1))
    {
      strncpy(buffer, "test_shayes_my_string_compare_returns_left_string_less_than_right\n"
	      "test_shayes_my_string_compare_returns_left_string_less_than_right doesn't return -1\n", length);
      my_string_destroy(&hLeft_string);
      my_string_destroy(&hRight_string);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_shayes_my_string_compare_returns_left_string_less_than_right returns -1\n", length);
      my_string_destroy(&hLeft_string);
      my_string_destroy(&hRight_string);
      return SUCCESS;
    }
}

Status test_shayes_my_string_compare_returns_left_string_equal_to_than_right(char* buffer, int length)
{
  MY_STRING hLeft_string = NULL;
  MY_STRING hRight_string = NULL;
  char r_str[] = "Hello";
  char l_str[] = "Hello";

  hLeft_string = my_string_init_c_string(l_str);
  hRight_string = my_string_init_c_string(r_str);
 
  if(my_string_compare(hLeft_string, hRight_string) != 0)
    {
      strncpy(buffer, "test_shayes_my_string_compare_returns_left_string_equal_to_than_right\n"
	      "test_shayes_my_string_compare_returns_left_string_equal_to_than_right doesnt return 0\n", length);
      my_string_destroy(&hLeft_string);
      my_string_destroy(&hRight_string);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "test_shayes_my_string_compare_returns_left_string_equal_to_than_right returns 0\n", length);
      my_string_destroy(&hLeft_string);
      my_string_destroy(&hRight_string);
      return SUCCESS;
    }
}

Status test_shayes_my_string_push_back_successfully_pushes_character(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  my_string_push_back(hString, 'c');
  if(*my_string_at(hString, 0) != 'c')
    {
      status = FAILURE;
      printf("Expected a character %c\n", *my_string_at(hString, 0));
      strncpy(buffer, "test_shayes_my_string_push_back_successfully_pushes_character\n"
	      "Did not receive the correct character from my_string_push_back\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_my_string_push_back_successfully_pushes_character\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_pop_back_successfully_removes_character(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  my_string_push_back(hString, 'c');
  my_string_pop_back(hString);
  if(my_string_get_size(hString) != 0)
    {
      status = FAILURE;
      printf("Expected a single character to be poppped but the size is %d", my_string_get_size(hString));
      strncpy(buffer, "test_shayes_my_string_pop_back_successfully_removes_character\n"
	      "Did not empty the string after a single push my_string_pop_back\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_my_string_pop_back_successfully_removes_character\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_pop_back_returns_FAILURE_on_empty_string_object(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  if(my_string_pop_back(hString) != FAILURE)
    {
      status = FAILURE;
      printf("my_string_pop_back successfully popped back on an empty string object\n");
      strncpy(buffer, "test_shayes_my_string_pop_back_returns_FAILURE_on_empty_string_object returned SUCCESS\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_my_string_pop_back_returns_FAILURE_on_empty_string_object\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_concat_successfully_appends_two_string_objects(char* buffer, int length)
{
  MY_STRING hResult = NULL;
  MY_STRING hAppend = NULL;
  char l_str[] = "Hello";
  char r_str[] = "There";
  Status status;
  
  hResult = my_string_init_c_string(l_str);
  hAppend = my_string_init_c_string(r_str);
  
  if(my_string_concat(hResult, hAppend) == FAILURE)
    {
      status = FAILURE;
      printf("my_string_concat did not successfully append two string objects\n");
      strncpy(buffer, "test_shayes_my_string_concat_successfully_appends_two_string_objects returned FAILURE\n", length);
    }
  else
    {
      status = SUCCESS;
      printf("The size is %d\n", my_string_get_size(hResult));
      strncpy(buffer, "test_shayes_my_string_concat_successfully_appends_two_string_objects\n",
	      length);
    }

  my_string_destroy(&hResult);
  my_string_destroy(&hAppend);
  return status;
}

Status test_shayes_fully_pop_back_concatenated_string_objects(char* buffer, int length)
{
  MY_STRING hResult = NULL;
  MY_STRING hAppend = NULL;
  char l_str[] = "Hello";
  char r_str[] = "There";
  Status status;
  
  hResult = my_string_init_c_string(l_str);
  hAppend = my_string_init_c_string(r_str);
  my_string_concat(hResult, hAppend);

  while(my_string_pop_back(hResult))
    {
      printf("Character: %c has been popped off\t", *my_string_at(hResult, my_string_get_size(hResult)));
    }
	     
  if(my_string_get_size(hResult) != 0)
    {
      status = FAILURE;
      printf("test_shayes_fully_pop_back_concatenated_string_objects\n");
      strncpy(buffer, "test_shayes_fully_pop_back_concatenated_string_objects did not pop back fully\n", length);
    }
  else
    {
      status = SUCCESS;
      printf("The size is %d\n", my_string_get_size(hResult));
      strncpy(buffer, "test_shayes_fully_pop_back_concatenated_string_objects\n",
	      length);
    }

  my_string_destroy(&hResult);
  my_string_destroy(&hAppend);
  return status;
}

Status test_shayes_my_string_extraction_returns_success(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;
  FILE* fp;

  fp = fopen("dictionary.txt", "r");
  hString = my_string_init_default();
  
  if(my_string_extraction(hString, fp) == FAILURE)
    {
      status = FAILURE;
      printf("test_shayes_my_string_extraction_returns_success did not extract\n");
      strncpy(buffer, "test_shayes_my_string_extraction_returns_success returned FAILURE\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_my_string_extraction_returns_success\n",
	      length);
    }

  fclose(fp);
  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_insertion_only_insert_words_29_characters_long(char* buffer, int length)
{
  MY_STRING hString = NULL;
  FILE* fp;

  fp = fopen("dictionary.txt", "r");
  hString = my_string_init_default();  

  while(my_string_extraction(hString,fp))
    {
      if(my_string_get_size(hString) == 29)
	{
	  my_string_insertion(hString, stdout);
	  printf("\n");
	  strncpy(buffer, "test_shayes_my_string_insertion_only_insert_words_29_characters_long\n",
	      length);
	  fclose(fp);
	  my_string_destroy(&hString);
	  return SUCCESS;
	}
    }
      	  printf("test_shayes_my_string_insertion_only_insert_words_29_characters_long did not insert words 29 characters long\n");
	  strncpy(buffer, "test_shayes_my_string_insertion_only_insert_words_29_characters_long returned FAILURE\n", length);
	  fclose(fp);
	  my_string_destroy(&hString);
	  return FAILURE;
}

Status test_shayes_my_string_push_back_pushes_until_resize(char* buffer, int length)
{
  MY_STRING hString = NULL;
  int i;
  char c = 65;

  hString = my_string_init_default();

  for(i = 0; i < 10; i++)
    {
      my_string_push_back(hString, c);
      printf("%c\t", *my_string_at(hString, i));
      c++;
    }
  printf("\n");

  if(my_string_get_size(hString) == 10)
    {
      strncpy(buffer, "test_shayes_my_string_push_back_pushes_until_resize SUCCEEDED\n",
	      length);
      my_string_destroy(&hString);
      return SUCCESS;
    }
  else
    {
      printf("test_shayes_my_string_push_back_pushes_until_resize did not resize\n");
      strncpy(buffer, "test_shayes_my_string_push_back_pushes_until_resize FAILED\n", length);
      my_string_destroy(&hString);
      return SUCCESS;
    }
}

Status test_shayes_my_string_at_returns_NULL_on_out_of_bounds(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  my_string_push_back(hString, 'c');
  if(*my_string_at(hString, 10) != 0)
    {
      status = FAILURE;
      printf("Expected a return value of NULL, instead received %d\n", *my_string_at(hString, 10));
      strncpy(buffer, "test_shayes_my_string_at_returns_NULL_on_out_of_bounds FAILED\n"
	      "Did not return a value of NULL\n", length);
    }
  else
    {
      status = SUCCESS;
      strncpy(buffer, "test_shayes_my_string_at_returns_NULL_on_out_of_bounds\n",
	      length);
    }

  my_string_destroy(&hString);
  return status;
}

Status test_shayes_destroy_string_object_after_init_default(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  hString = my_string_init_default();
  my_string_destroy(&hString);
  if(hString)
    {
      status = FAILURE;
      strncpy(buffer, "test_shayes_destroy_string_object_after_init_default FAILED\n",
	      length);
      my_string_destroy(&hString);
    }
  else
    {
      status = SUCCESS;
      printf("String object was successfully destroyed\n");
      strncpy(buffer, "test_shayes_destroy_string_object_after_init_default SUCCEEDED\n", length);
    }
  return status;
}

Status test_shayes_my_string_extraction_returns_FAILURE_on_uninitialized_string_object(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  if(my_string_extraction(hString, stdin) != FAILURE)
    {
      status = FAILURE;
      strncpy(buffer, "test_shayes_my_string_extraction_returns_FAILURE_on_uninitialized_string_object returned SUCCESS\n",
	      length);
    }
  else
    {
      status = SUCCESS;
      printf("test_shayes_my_string_extraction_returns_FAILURE_on_uninitialized_string_object returned FAILURE\n");
      strncpy(buffer, "test_shayes_my_string_extraction_returns_FAILURE_on_uninitialized_string_object\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_insertion_returns_FAILURE_on_uninitialized_string_object(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  if(my_string_insertion(hString, stdout) != FAILURE)
    {
      status = FAILURE;
      strncpy(buffer, "test_shayes_my_string_insertion_returns_FAILURE_on_uninitialized_string_object returned SUCCESS\n",
	      length);
    }
  else
    {
      status = SUCCESS;
      printf("test_shayes_my_string_insertion_returns_FAILURE_on_uninitialized_string_object returned FAILURE\n");
      strncpy(buffer, "test_shayes_my_string_insertion_returns_FAILURE_on_uninitialized_string_object\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_get_size_returns_obscure_int_on_uninitialized_string_object(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  if(my_string_get_size(hString) != -3213452)
    {
      status = FAILURE;
      strncpy(buffer, "test_shayes_my_string_get_size_returns_obscure_int_on_uninitialized_string_object returns size\n",
	      length);
    }
  else
    {
      status = SUCCESS;
      printf("test_shayes_my_string_get_size_returns_obscure_int_on_uninitialized_string_object returned obscure int\n");
      strncpy(buffer, "test_shayes_my_string_get_size_returns_obscure_int_on_uninitialized_string_object\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

Status test_shayes_my_string_get_capacity_returns_obscure_int_on_uninitialized_string_object(char* buffer, int length)
{
  MY_STRING hString = NULL;
  Status status;

  if(my_string_get_capacity(hString) != -3213452)
    {
      status = FAILURE;
      strncpy(buffer, "test_shayes_my_string_get_capacity_returns_obscure_int_on_uninitialized_string_object returns size\n",
	      length);
    }
  else
    {
      status = SUCCESS;
      printf("test_shayes_my_string_get_capacity_returns_obscure_int_on_uninitialized_string_object\n");
      strncpy(buffer, "test_shayes_my_string_get_capacity_returns_obscure_int_on_uninitialized_string_object\n", length);
    }
  my_string_destroy(&hString);
  return status;
}

