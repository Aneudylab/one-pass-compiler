#include <stdio.h>                  // carga las rutinas IO
#include <ctype.h>                  // carga las rutinas de prueba de caracteres
#include <string.h>                 // carga las rutinas de cadena de caracteres

#define BSIZE 128                   // tamaño del buffer
#define NONE -1
#define EOS '\0'

#define NUM     256
#define DIV     257
#define MOD     258
#define ID      259
#define DONE    260

int tokenval;                       // atributo valor del token
int lineno;                         // número de línea

struct entry {                      // forma de la tabla de símbolos
    char *lexptr;
    int token;
};

struct entry symtable[];            // tabla de símbolos

