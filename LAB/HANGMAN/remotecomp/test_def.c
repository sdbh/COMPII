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
