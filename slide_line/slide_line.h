#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define SLIDE_LEFT 2
#define SLIDE_RIGHT 3

int slide_line(int *line, size_t size, int direction);

#endif
