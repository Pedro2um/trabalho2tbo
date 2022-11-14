#include <stdlib.h>
#include <stdio.h>
#include "assertx.h"

/**
 * @brief Garante que condição é verdadeira.
 * Se for falsa, imprime um erro em stdout e termina o programa.
 *
 * @param condition Condição a ser verificada.
 * @param message Erro a ser impresso.
 */
void assertx(int condition, char* message){

    if(!condition){
        fprintf(stderr, "\nASSERTX: %s\n", message);
        exit(1);
    }
}