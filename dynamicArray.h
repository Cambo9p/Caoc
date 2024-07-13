#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct  {
    int maxSize;
    int currSize;
    char **ptr;
}CharArray_t;

// returns an initialised dynamic array with a given size
void initArrayWithSize(CharArray_t *array, int size);

// returns an initialised dynamic array
void initArray(CharArray_t *array);

// appends to the end of the array
void appendArray(CharArray_t *array, const char *element);

// free the array
void freeArray(CharArray_t *array);

// prints the array
void printArray(CharArray_t *array);

#endif
