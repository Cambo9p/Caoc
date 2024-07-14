#include "arrayIterator.h"
#include "dynamicArray.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void initIterator(ArrayIterator_t *iterator, Array_t *array) {
    iterator->array = array;
    iterator->currIndex = 0;
}

bool hasNext(ArrayIterator_t *iterator) {
    return iterator->currIndex < iterator->array->currSize;
}

void *next(ArrayIterator_t *iterator) {
    if (!hasNext(iterator)) {
        fprintf(stderr, "Index out of bounds, no index %d \n",
                iterator->currIndex + 1);
        exit(1);
    }

    return iterator->array->ptr[iterator->currIndex++];
}

void resetIterator(ArrayIterator_t *iterator) {
    iterator->currIndex = 0;
} 

/*

void initIterator(ArrayIterator_t *iterator, CharArray_t *array) {
    iterator->array = array;
    iterator->currLine = 0;
    iterator->currIndex = 0;
}

bool hasNextline(ArrayIterator_t *iterator) {
    return iterator->currLine < iterator->array->currSize;
}

bool hasNextCharInLine(ArrayIterator_t *iterator) {
    char *line = iterator->array->ptr[iterator->currLine];
    int lineLen = strlen(line); // TODO: may be better to store this info so we dont need to look it up

    return iterator->currIndex < lineLen - 1; // - 1 so we ignore the \0
}

char next(ArrayIterator_t *iterator) {
    if (!hasNextCharInLine(iterator)) {
        fprintf(stderr, "Index out of bounds, no index %d at line %d\n",
                iterator->currIndex + 1, iterator->currLine);
        exit(1);
    }

    return iterator->array->ptr[iterator->currLine][++iterator->currIndex];
}

char nextLine(ArrayIterator_t *iterator) {
    if (!hasNextline(iterator)) {
        fprintf(stderr, "Index out of bounds, no line number %d\n",
                iterator->currLine + 1);
        exit(1);
    }

    char ch = iterator->array->ptr[iterator->currLine++][0];
    iterator->currIndex = 0;
    return ch;
}

void resetIterator(ArrayIterator_t *iterator) {
    iterator->currLine = 0;
    iterator->currIndex = 0;
} 
 
 * */
