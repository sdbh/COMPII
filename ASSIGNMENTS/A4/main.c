#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/**********************************************************************
	Program:        673 Solution
	Author:	        Sean Hayes
	Date:		5/27/2017
	Time spent:	3 hrs
	Purpose:   	The purpose of this program is to solve the
                        matching parentheses problem.
***********************************************************************/

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
			hStack->push(hStack, brackets);
			
		}
		else
		{
			if (hStack->top(hStack, &status) == '(' && brackets == ')' || hStack->top(hStack, &status) == '[' && brackets == ']' || hStack->top(hStack, &status) == '{' && brackets == '}')
			{
				hStack->pop(hStack);
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

	if (hStack->empty(hStack))
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
