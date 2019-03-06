#include "global.h"

emit (int t, int tval)                          // genera salida
{
    switch (t) {
        case '+': case '-': case '*': case '/': 
            printf("%c ", t); break;
        case ';':
            putchar('\n'); break;
        case DIV:
            printf("DIV "); break;
        case MOD:
            printf("MOD "); break;
        case NUM:
            printf("%d ", tval); break;
        case ID:
            printf("%s ", symtable[tval].lexptr); break;
        default:
            printf("token %d, tokenval %d ", t, tval);
    }
}
