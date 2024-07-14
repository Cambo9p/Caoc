#include <stdio.h>
#include "dynamicArray.h"
#include "arrayIterator.h"

struct Cord {
    int type; // 1 for num other for symbol
    int y;
    int start;
    int end;
};

int solvep1() {
    FILE *fp = fopen("input.txt", "r");
    ssize_t read;
    char *line = NULL;
    size_t len = 0;

    CharArray_t lines;
    initArray(&lines);

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        appendArray(&lines, line);
    }
    // now we can do stuff 

    ArrayIterator_t iter;
    initIterator(&iter, &lines);

    while (hasNextline(&iter)) {
        while (hasNextCharInLine(&iter)) {
            char ch = next(&iter);
            printf("%c", ch);
        }
        printf("\n");

        if (hasNextline(&iter)) {
            nextLine(&iter);
        }
    }


    freeArray(&lines);

    return 1;
}
