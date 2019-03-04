#include "global.h"

#define STRMAX 999                  // tamaño del arreglo de lexemas
#define SYMMAX 100                  // tamaño de la tabla de simbolos

char lexemes [STRMAX];
int lastchar = -1;                  // última posición en lexemas
struct entry symtable[SYMMAX];
int lastentry = 0;                  // última posición en la tabla de símbolos

int lookup (char s[])               // devuelve la posición de s
{
    int p;
    for (p = lastentry; p > 0; p = p-1) 
        if (strcmp(symtable[p].lexptr, s) == 0)
            return p;
    return 0;
}

int insert (char s[], int tok)
{
    int len;
    len = strlen (s);
    if (lastentry + 1 >= SYMMAX)
        error ("symbol table full");
    if (lastchar + len + 1 >= STRMAX)
        error ("lexemes array full");
    lastentry = lastentry + 1;
    symtable[lastentry].token = tok;
    symtable[lastentry].lexptr = &lexemes[lastchar + 1];
    lastchar = lastchar + len + 1;
    strcpy(symtable[lastentry].lexptr, s);
    return lastentry;
}
