#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{

  char sup[] = "Hey there";
  char fup[] = "Concat this";
  MY_STRING hMy_string1 = NULL;
  MY_STRING hMy_string2 = NULL;

  hMy_string1 = my_string_init_c_string(sup);

  hMy_string2 = my_string_init_c_string(fup);

  my_string_concat(hMy_string1, hMy_string2);

  my_string_insertion(hMy_string1, stdout);
  printf("\n");
  
  while(my_string_pop_back(hMy_string1))
    {
       my_string_insertion(hMy_string1, stdout);
       printf("\n");
    }

  my_string_push_back(hMy_string1, 'h');
  my_string_insertion(hMy_string1, stdout);
  printf("\n");
  my_string_push_back(hMy_string1, 'e');
  my_string_insertion(hMy_string1, stdout);
  printf("\n");
  my_string_push_back(hMy_string1, 'y');
  my_string_insertion(hMy_string1, stdout);
  printf("\n");

  printf("%c\n", *(my_string_at(hMy_string1, 2)));
  
			    
  my_string_destroy(&hMy_string1); 
  my_string_destroy(&hMy_string2); 

  return 0;
}
