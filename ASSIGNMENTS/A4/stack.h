#ifndef STACK_H
#define STACK_H
#include "status.h"

typedef void* STACK;
//init
STACK stack_init_default(void);

//push
Status stack_push(STACK hStack, char item);

//pop
Status stack_pop(STACK hStack);

//top
char stack_top(STACK hStack);

//empty
Boolean stack_empty(STACK hStack);

//destroy
void stack_destroy(STACK* phStack);
