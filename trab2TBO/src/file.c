#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "assertx.h"
#include "file.h"

FILE* file_open(char* name, char* modifier){
    FILE* f = fopen(name, modifier);

    if(f == NULL){
        //tried to open a file to read
        if(strcmp(modifier, "r")==0){
            assertx(f!=NULL, "NAO ABRI ARQUIVO LEITURA");
        }
        //tried to open a file to write
        if(strcmp(modifier, "w")==0){
            assertx(f!=NULL, "NAO ABRI ARQUIVO ESCRITA");
        }
        assertx(f!=NULL, "NAO ABRI ARQUIVO (NAO SEI QUAL TIPO)");

    }
    return f;
}

FILE* file_close(FILE* f){
    if(f!=NULL)fclose(f);
    return NULL;
}