#include <stdio.h>
#include "dynamicArray.h"

struct Cord {
    int type; // 1 for num other for symbol
    int y;
    int start;
    int end;
};


int solvep1() {
    FILE *fp = fopen("input.txt", "r");
    ssize_t read;
    char *line;
    size_t len = 0;

    CharArray_t lines;
    initArray(&lines);

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
        }
        appendArray(&lines, line);
    }
    printArray(&lines);
    // now we can do stuff 

    freeArray(&lines);

    return 1;
}
