#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "../lib/dynamicArray.h"
#include "../lib/arrayIterator.h"

struct Cord {
    int type; // 1 for num other for symbol
    int y;
    int start;
    int end;
};

void freeString(void* element) {
    free((char *)element);
}

void printString(void *element) {
    printf("%s\n", (char *)element);
}

int solvep1() {
FILE *fp = fopen("input.txt", "r");
ssize_t read;
char *line = NULL;
size_t len = 0;

Array_t lines;
initArray(&lines, sizeof(char *));

while ((read = getline(&line, &len, fp)) != -1) {
    if (line[read - 1] == '\n') {
        line[read - 1] = '\0';
    }
    char *lineCopy = strdup(line);
    appendArray(&lines, lineCopy);
}
free(line);
fclose(fp);

ArrayIterator_t iter;
initIterator(&iter, &lines);

while (hasNext(&iter)) {
    char *line = (char *)next(&iter);
    int i = 0;
    while (line[i] != '\0') {
        char ch = line[i];
        printf("%c", ch);
            if (!isdigit(ch) && ch != '.' ) { // its a symbol
                printf("found symbol %c at line %d pos %d", ch, iter.currIndex, i);
            }
            i++;
        }
        printf("\n");

    }

    freeArray(&lines, freeString);

    return 0;
}
