#include <stdio.h>
#include <stdlib.h>

typedef void* STACK;

typedef struct node Node;

struct node{
  char data;
  Node* next;
};

struct stack{
  Node* head;
};

typedef struct stack Stack;

enum status { FAILURE, SUCCESS };

enum boolean { FALSE, TRUE };

typedef enum status Status;

typedef enum boolean Boolean;

STACK stack_init_default(void);

Status stack_push(STACK hStack, char item);

Status stack_pop(STACK hStack);

char stack_top(STACK hStack);

Boolean stack_empty(STACK hStack);

void stack_destroy(STACK* phStack);

void clear_buffer(void);

void check_lines(void);

int main(int argc, char* argv[])
{
	int num_lines, i;

	scanf("%d", &num_lines);
	clear_buffer();
	for (i = 0; i < num_lines; i++)
	{
		check_lines();
	}
	
	return 0;
}

void clear_buffer(void)
{
	char a;
	int conversions;

	conversions = scanf("%c", &a);
	while (conversions == 1 && a != '\n')
	{
		scanf("%c", &a);
	}
	return;
}

void check_lines(void)
{
	STACK hStack;
	
	Status status;

	char brackets;
	int conversions;

	hStack = stack_init_default();
	
	
	conversions = scanf("%c", &brackets);
	while (conversions != EOF && brackets != '\n')
	{
		if (brackets == '(' || brackets == '[' || brackets == '{')
		{
			stack_push(hStack, brackets);
			
		}
		else
		{
			if (stack_top(hStack) == '(' && brackets == ')' || stack_top(hStack) == '[' && brackets == ']' || stack_top(hStack) == '{' && brackets == '}')
			{
				stack_pop(hStack);
			}
			else
			{
				printf("No\n");
				clear_buffer();
				stack_destroy(&hStack);
				return;
			}
		}
		conversions = scanf("%c", &brackets);
	}

	if (stack_empty(hStack))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	stack_destroy(&hStack);

	
	return;
}

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
      return '\0';
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
  Stack* pStack = (Stack*) *phStack;
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

