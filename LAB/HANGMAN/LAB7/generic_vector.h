#ifndef INT_VECTOR_H
#define INT_VECTOR_H
#include "generic.h"
#include "status.h"

typedef void* GENERIC_VECTOR;

struct vector
{
	Status(*item_assignment)(Item*, Item);
	void(*item_destroy)(Item*);
	int size;
	int capacity;
	Item* data;
};
typedef struct vector Vector;


GENERIC_VECTOR generic_vector_init_default(Status(*item_assignment)(Item*, Item),
	void (*item_destroy)(Item*));


Status generic_vector_push_back(GENERIC_VECTOR hVector, Item item);

//Accessor functions
int generic_vector_get_size(GENERIC_VECTOR hVector);
int generic_vector_get_capacity(GENERIC_VECTOR hVector);


//remove things
Status generic_vector_pop_back(GENERIC_VECTOR hVector);

//shrink_to_fit
//make the size and capacity the same by resizing if needed.

//empty?
Boolean generic_vector_empty(GENERIC_VECTOR hVector);

//clear
//just set the size to zero...

//view the numbers in the container
Item generic_vector_at(GENERIC_VECTOR hVector, unsigned int index); 

void generic_vector_destroy(GENERIC_VECTOR* phVector);

#endif
