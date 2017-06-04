#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "my_string.h"
#include "status.h"

struct my_string{
  int size;
  int capacity;
  char* data;
};

typedef struct my_string My_string;

MY_STRING my_string_init_default(void)
{
  My_string* pMy_string = (My_string*) malloc(sizeof(My_string));
  
  if(pMy_string != NULL)
    {
      pMy_string->size = 0;
      pMy_string->capacity = 7;
      pMy_string->data = (char*) malloc(sizeof(char) * pMy_string->capacity);
      if(pMy_string->data == NULL)
	{
	  free(pMy_string);
	  pMy_string = NULL;
	}
    }
  
  return (MY_STRING)pMy_string; 
}

void my_string_destroy(MY_STRING* phMy_string)
{
  My_string* pMy_string = (My_string*) *phMy_string;

  if(pMy_string)
    {
      free(pMy_string->data);
      free(pMy_string);
      *phMy_string = NULL;
    }
  
}

MY_STRING my_string_init_c_string(const char* c_string)
{
  My_string* pMy_string;
  int i, count = 0;

  while(c_string[count] != '\0')
    {
      count++;
    }
  
  pMy_string = (My_string*) malloc(sizeof(My_string));
  if(pMy_string != NULL)
    {
      pMy_string->size = count;
      pMy_string->capacity = count + 1;
      pMy_string->data = (char*) malloc(sizeof(char) * pMy_string->capacity);
      if(pMy_string->data == NULL)
	{
	  free(pMy_string);
	  pMy_string = NULL;
	}
      for(i = 0; i < count; i++)
	{
	  pMy_string->data[i] = c_string[i];
	}
    }
  
  return (MY_STRING) pMy_string; 
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;

  if(pMy_string)
    {
      return pMy_string->capacity;
    }
}

int my_string_get_size(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;

  if(pMy_string)
    {
      return pMy_string->size;
    }
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  My_string* pLeft_string = (My_string*) hLeft_string;
  My_string* pRight_string = (My_string*) hRight_string;

  int i, length;

  if(my_string_get_size(hLeft_string) < my_string_get_size(hRight_string))
    {
    length = my_string_get_size(hLeft_string);
    }
  else
    {
    length = my_string_get_size(hRight_string);
    }

  for(i = 0; i < length; i++)
    {
      if(pLeft_string->data[i] < pRight_string->data[i])
	{
	return -1;
	}
      else if(pLeft_string->data[i] > pRight_string->data[i])
	{
	return 1;
	}
    }

  if (my_string_get_size(hLeft_string) < my_string_get_size(hRight_string))
    {
      return -1;
    }
  else if(pLeft_string->data[i] > pRight_string->data[i])
    {
      return 1;
    }
  else
    {
      return 0;
    }

}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
    My_string* pMy_string = (My_string*)hMy_string;
    char c;

    if (pMy_string == NULL)
    {
        return FAILURE;
    }
    if( fp == NULL)
    {
        printf("Invalid file name!\n");
        exit(1);
    }
    else
    {
        pMy_string->size = 0;
        while(fscanf(fp,"%c", &c) != EOF)
        {
            if(pMy_string->size != 0 && isspace(c))
            {
                ungetc(c,fp);
                break;
            }
            else
            {
                if(!isspace(c))
                {
                    pMy_string->data[pMy_string->size] = c;
                    pMy_string->size++;
                    if(pMy_string->size == pMy_string->capacity)
                    {
                        if(my_string_resize(pMy_string) == FAILURE)
                        {
                            return  FAILURE;
                        }
                    }
                }
            }
        }
        if (pMy_string->size == 0){
            return FAILURE;
        }
        else
        {
            return SUCCESS;
        }
    }        
}

Status my_string_resize(MY_STRING hMy_string)
{
    My_string* pMy_string = (My_string*)hMy_string;
    char* temp;
    int i;
    
    if (pMy_string == NULL)
    {
        return FAILURE;
    }
    
    pMy_string->capacity *= 2;
    temp = (char*)malloc(sizeof(char)*pMy_string->capacity);
    if(temp)
    {
      for(i = 0; i < my_string_get_size(pMy_string); i++)
	{
	  temp[i] = pMy_string->data[i];
	}

      free(pMy_string->data);
      pMy_string->data = temp;
      return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}


Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
    My_string* pMy_string = (My_string*)hMy_string;
    int i = 0;
    int ch;
    
    if (pMy_string == NULL)
    {
        return FAILURE;
    }
    if( fp == NULL)
    {
        printf("Invalid file name\n");
        return FAILURE;
    }
    else
    {
        for ( i = 0; i < (pMy_string->size); i++)
        {
            ch = (pMy_string->data[i]);
            if(fputc(ch, fp)==EOF)
            {
                printf("Error writing file\n");
                return FAILURE;
            }
            else
                continue;
        }
        return SUCCESS;
    }
}

Status my_string_push_back(MY_STRING hMy_string, char item)
{
  My_string* pMy_string = (My_string*) hMy_string;

  pMy_string->data[pMy_string->size] = item;
  pMy_string->size++;
  if(pMy_string->size == pMy_string->capacity)
    {
      if(my_string_resize(pMy_string) == FAILURE)
	{
	  return FAILURE;
        }
    }
    
  return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;

  if(pMy_string->size == 0)
    {
      return FAILURE;
    }
  else
    {
      pMy_string->size--;
      return SUCCESS;
    }
  
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  My_string* pMy_string = (My_string*) hMy_string;

  if(index < 0 && index >= pMy_string->size)
    {
      return NULL;
    }
  
  return &(pMy_string->data[index]);
  
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  My_string* phResult = (My_string*) hResult;
  My_string* phAppend = (My_string*) hAppend;
  int i = 0;

  while(phAppend->data[i] != '\0')
    {
      phResult->data[phResult->size] = phAppend->data[i];
      phResult->size++;
      i++;
      if(phResult->size == phResult->capacity)
	{
	  if(my_string_resize(phResult) == FAILURE)
	    {
	      return FAILURE;
	    }
	}
    }
  return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;

  return (Boolean) (pMy_string->size == 0);

}

char* my_string_c_str(MY_STRING hMy_string)
{
  My_string* pMy_string = (My_string*) hMy_string;

  pMy_string->data[pMy_string->size] = '\0';

  return pMy_string->data;
}
