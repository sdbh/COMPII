#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node{
  char data;
  Node* next;
};

typedef struct node Node;

struct stack{
  Node* head;
};

typedef struct stack Stack;

STACK stack_init_default(void)
{
  Stack* pStack = (Stack*) malloc(sizeof(Stack));
  if (pStack != NULL)
    {
      pStack->head = NULL;
    }
      return (STACK) pStack;
}

Status stack_push(STACK hStack, char item)
{
  Stack* pStack = (Stack*) hStack;
  Node* temp;

  temp = (Node*) malloc(sizeof(Node));
  if (temp == NULL)
    {
      return FAILURE;
    }
  else
    {
      temp->data = item;
      temp->next = pStack->head;
      pStack->head = temp;
    }
  
  return SUCCESS;
}

Status stack_pop(STACK hStack)
{
  Stack* pStack = (Stack*)hStack;
  Node* temp;

  if (pStack->head == NULL)
    {
      return FAILURE;
    }
  else
    {
      temp = pStack->head;
      pStack->head = pStack->head->next;
      free(temp);
    }
  return SUCCESS;
}

char stack_top(STACK hStack)
{
  Stack* pStack = (Stack*)hStack;

  if (stack_empty(hStack))
    {
      return ?;
    }
  else
    {
      return pStack->head->data;
    }
}

Boolean stack_empty(STACK hStack)
{
  Stack* pStack = (Stack*)hStack;
  
  return (Boolean)(pStack->head == NULL);
  
}

void stack_destroy(STACK* phStack)
{
  Stack* pStack = (Stack*)*phStack;
  Node* temp;
  if (pStack != NULL)
    {
      while (pStack->head != NULL)
	{
	  temp = pStack->head;
	  pStack->head = pStack->head->next;
	  free(temp);
	}
      free(pStack);
      *phStack = NULL;
    }
}
  
  
