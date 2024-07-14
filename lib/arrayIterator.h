#ifndef ARRAYITERATOR_H
#define ARRAYITERATOR_H
#include "dynamicArray.h"
#include <stdbool.h>


typedef struct {
    Array_t *array;
    int currIndex;
} ArrayIterator_t;

// initialises the iterator
void initIterator(ArrayIterator_t *iterator, Array_t *array);

bool hasNext(ArrayIterator_t *iterator);

// gets the next char
void *next(ArrayIterator_t *iterator);

// returns the iterator to 0 0
void resetIterator(ArrayIterator_t *iterator);

#endif
/*


typedef struct {
    CharArray_t *array;
    int currIndex;
    int currLine;
} ArrayIterator_t;

// initialises the iterator
void initIterator(ArrayIterator_t *iterator, CharArray_t *array);

// Returns true if the array has another line
bool hasNextline(ArrayIterator_t *iterator);

// Returns true if there is another char in the line
bool hasNextCharInLine(ArrayIterator_t *iterator);

// gets the next char
char next(ArrayIterator_t *iterator);

// gets the first char in the next line
char nextLine(ArrayIterator_t *iterator);

// returns the iterator to 0 0
void resetIterator(ArrayIterator_t *iterator);

// frees iterator, doesnt free array
void freeIterator(ArrayIterator_t *iterator);

 
 * */
