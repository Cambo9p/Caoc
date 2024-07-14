#include "dynamicArray.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initArrayWithSize(Array_t *array, int size, size_t elementSize) {
    array->maxSize = size;
    array->currSize = 0;
    array->elementSize = elementSize;
    array->ptr = (void **)calloc(size, sizeof(void *));
    if (array->ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void initArray(Array_t *array, size_t elementSize) {
    initArrayWithSize(array, 10, elementSize);
}

void appendArray(Array_t *array, const char *element) {
    // check that we will not go out of bounds
    if (array->currSize == array->maxSize) {
        int newSize = array->maxSize * 2;
        void **newPtr = (void **)realloc(array->ptr, newSize * sizeof(void *));
        if (newPtr == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        array->ptr = newPtr;
        array->maxSize = newSize;
    }

    array->ptr[array->currSize] = malloc(array->elementSize);
    if (array->ptr[array->currSize] == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(1);
    }
    memcpy(array->ptr[array->currSize], element, array->elementSize);
    array->currSize++;
}

void freeArray(Array_t *array, void (*freeElement)(void *)) {
    for (int i = 0; i < array->currSize; i++) {
        freeElement(array->ptr[i]);
    }
    // Free the array itself
    free(array->ptr);
    array->ptr = NULL;
    array->currSize = 0;
    array->maxSize = 0;
}

void printArray(Array_t *array, void (*printElement)(void *)) {
    for (int i = 0; i < array->currSize; i++) {
        printElement(array->ptr[i]);
    }
}
