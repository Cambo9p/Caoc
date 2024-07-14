#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdlib.h>

typedef struct  {
    int maxSize;
    int currSize;
    void **ptr;
    size_t elementSize;
}Array_t;

// returns an initialised dynamic array with a given size
void initArrayWithSize(Array_t *array, int size, size_t elementSize);

// returns an initialised dynamic array
void initArray(Array_t *array, size_t elementSize);

// appends to the end of the array
void appendArray(Array_t *array, const char *element);

// free the array
void freeArray(Array_t *array, void (*freeElement)(void *));

// prints the array
void printArray(Array_t *array, void (*printElement)(void *));

#endif
