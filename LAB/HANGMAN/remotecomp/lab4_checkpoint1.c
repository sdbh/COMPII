#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

int main(int argc, char* argv[])
{
  char sup[] = "Hey there";
  char fup[] = "Concat this";
  MY_STRING hMy_string1 = NULL;
  MY_STRING hMy_string2 = NULL;

  if(my_string_empty(hMy_string1) && my_string_empty(hMy_string2))
    {
      hMy_string1 = my_string_init_c_string(sup);
      hMy_string2 = my_string_init_c_string(fup);

      my_string_concat(hMy_string1, hMy_string2);
      my_string_insertion(hMy_string1, stdout);    

    }
			    
  my_string_destroy(&hMy_string1); 
  my_string_destroy(&hMy_string2);
  
  return 0;
}
