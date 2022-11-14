#ifndef FILE_H
#define FILE_H

#include <stdlib.h>
#include <stdio.h>

FILE* file_open(char* name, char* modifier);

FILE* file_close(FILE* f);
#endif