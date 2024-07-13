#include "dynamicArray.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void initArrayWithSize(CharArray_t *array, int size) {
    array->maxSize = size;
    array->currSize = 0;
    array->ptr = (char **)calloc(size, sizeof(char *));
    if (array->ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void initArray(CharArray_t *array) {
    initArrayWithSize(array, 10);
}

void appendArray(CharArray_t *array, const char *element) {
    // check that we will not go out of bounds
    if (array->currSize == array->maxSize) {
        int newSize = array->maxSize * 2;
        char **newPtr = (char **)realloc(array->ptr, newSize * sizeof(char *));
        if (newPtr == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        array->ptr = newPtr;
        array->maxSize = newSize;
    }

    array->ptr[array->currSize] = (char *)malloc((strlen(element) + 1) * sizeof(char));
    if (array->ptr[array->currSize] == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(1);
    }
    strcpy(array->ptr[array->currSize], element);
    array->currSize++;
}

void freeArray(CharArray_t *array) {
    for (int i = 0; i < array->currSize; i++) {
        free(array->ptr[i]);
    }
    // Free the array itself
    free(array->ptr);
    array->ptr = NULL;
    array->currSize = 0;
    array->maxSize = 0;
}

void printArray(CharArray_t *array) {
    for (int i = 0; i < array->currSize; i++) {
        printf("%s\n", array->ptr[i]);
    }
}
