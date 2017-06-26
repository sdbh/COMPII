#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic.h"

int main(int argc, char* argv[])
{
  int i;
  MY_STRING hMy_String_Array[100] = {NULL};
  
  hMy_String_Array[0] = my_string_init_c_string("COPY ME!");
  
  for (i = 1; i < 100; ++i)
    {
      my_string_assignment((Item*)&hMy_String_Array[i],(Item)hMy_String_Array[0]);
    }

  for (i = 0; i < 100; ++i)
    {
      my_string_insertion(hMy_String_Array[i], stdout);
      printf("\n");
      my_string_destroy((Item*)&hMy_String_Array[i]);
    }
  
  return 0;

}
