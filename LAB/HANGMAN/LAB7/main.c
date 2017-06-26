#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"
#include "status.h"
#include "my_string.h"
int main(int argc, char* argv[])
{
 GENERIC_VECTOR hVector[30] = { NULL };
 MY_STRING hString = NULL;

 FILE* fp = NULL;
 int i;

  fp = fopen("dictionary.txt", "r");
  if (fp == NULL) 
  {
    printf("Did not open file\n");
    exit(1);
  }
 
 hString = my_string_init_default();
 if (hString == NULL)
  {
    printf("Unable to initialize MY_STRING handle.\n");
    exit(1);
  }
  
  for (i = 0; i < 30; i++) 
  {
    hVector[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
    if (hVector[i] == NULL) 
	{
      printf("Unable to initialize GENERIC_VECTOR handle.\n");
      exit(1);
	}
  }

  while(my_string_extraction(hString, fp) == SUCCESS) 
  {
    if (my_string_get_size(hString) < 30) {
      generic_vector_push_back(hVector[my_string_get_size(hString)], hString);
    }
  }
  
  for (i = 0; i < 30; i++) 
  {
    printf("Words of length %d, occur %d times.\n", i, generic_vector_get_size(hVector[i]));
  }

  for (i = 0; i < 30; i++) 
  {
    generic_vector_destroy(&(hVector[i]));
  }

  fclose(fp);
  my_string_destroy(&hString);

  return 0;
} 
