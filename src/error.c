#include "global.h"

void error(char *m)                 // Genera todos los mensajes de error
{
    fprintf(stderr, "line %d: %s\n", lineno, m);
    exit(1);                        // terminación no exitosa
}
